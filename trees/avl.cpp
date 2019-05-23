#include<bits/stdc++.h>

using namespace std;

template <typename T>
class Avl{
    public:
        struct Node{
            struct Node *left;
            struct Node *right;
            int height;
            T data;
        };
        Avl();
        typedef struct Node Node;
        Node *root;

        void insert(T);
        Node* insert(Node *root, T);
        Node* rotateLeft(Node *);
        Node* rotateRight(Node *);
        int height();
        int height(Node *);
        int calculateHeight(Node *);
        void inorder();
        void inorder(Node *);
        int balanceFactor(Node *);
        int max(int, int);
};

template<typename T>
int Avl<T>::max(int val1, int val2){
    return val1 > val2 ? val1 : val2;
}

template <typename T>
int Avl<T>::balanceFactor(Node *root){
    int lheight = height(root->left);
    int rheight = height(root->right);
    return lheight - rheight;
}

template <typename T>
Avl<T>::Avl(){
    root = NULL;
}

template <typename T>
void Avl<T>::inorder(){
    inorder(root);
}

template <typename T>
void Avl<T>::inorder(Node *root){
    if (!root){
        return;
    }
    inorder(root->left);
    cout << root->data << ":" << root->height <<":" << balanceFactor(root) << " ";
    // cout << root->data << ":" << root->height << " ";
    inorder(root->right);
}

template <typename T>
void Avl<T>::insert(T element){
    root = insert(root, element);
}

template <typename T>
typename Avl<T>::Node* Avl<T>::insert(Node *root, T element){
    if (root == NULL){
        Node *pnode = new Node();
        pnode->left = pnode->right = NULL;
        pnode->height = 1;
        pnode->data = element;
        return pnode;
    }
    if (element < root->data){
        root->left = insert(root->left, element);
    }
    else{
        root->right = insert(root->right, element);
    }
    root->height = max(calculateHeight(root->left), calculateHeight(root->right)) + 1;
    if (balanceFactor(root) < -1){
        //right side is imbalanced
        if (element < root->right->data){
            // right left case
            root->right = rotateRight(root->right);
            inorder();
            root = rotateLeft(root);
            inorder();
        }
        else{
            root = rotateLeft(root);
            // right right case
        }
    }
    else if(balanceFactor(root) > 1){
        //left side is imbalances
        if (element < root->left->data){
            // left left case 
            root = rotateRight(root);
        }
        else{
            // left right case
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
    }
    return root;
}

template<typename T>
typename Avl<T>::Node* Avl<T>::rotateRight(Node *oldRoot){
    Node *newRoot = oldRoot->left;
    oldRoot->left = newRoot->right;
    newRoot->right = oldRoot;
    oldRoot->height = max(calculateHeight(oldRoot->left), calculateHeight(oldRoot->right)) + 1;
    newRoot->height = max(calculateHeight(newRoot->left), calculateHeight(newRoot->right)) + 1;
    return newRoot;
}

template<typename T>
typename Avl<T>::Node* Avl<T>::rotateLeft(Node *oldRoot){
    Node *newRoot = oldRoot->right;
    oldRoot->right = newRoot->left;
    newRoot->left = oldRoot;
    oldRoot->height = max(calculateHeight(oldRoot->left), calculateHeight(oldRoot->right)) + 1;
    newRoot->height = max(calculateHeight(newRoot->left), calculateHeight(newRoot->right)) + 1;
    return newRoot;
}

template<typename T>
int Avl<T>::calculateHeight(Avl<T>::Node *root){
    if (root){
        return root->height;
    }
    return 0;
}

template <typename T>
int Avl<T>::height(){
    return height(root);
}

template <typename T>
int Avl<T>::height(Node *root){
    if (root == NULL){
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    return lheight > rheight ? lheight + 1: rheight + 1;
}

int main(){
    Avl<int> avl;
    avl.insert(5);
    avl.insert(6);
    avl.insert(7);
    avl.insert(4);
    avl.insert(4);
    cout << "\n height: " << avl.height() << "\n";
    avl.inorder();
    // cout << "\n";
}