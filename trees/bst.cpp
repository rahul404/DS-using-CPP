#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Bst{
    public:
        struct Node{
            Node *left;
            Node *right;
            T data;
        };
        Node *root;
        typedef Node Node;
        Bst(T element);
        void insert(T element);
        void remove(T element);
        static void remove(Node *root, T element);
        static void inorder(Node *root);
        void inorder();
        static void preorder(Node *root);
        void preorder();
        static void postorder(Node *root);
        void postorder();
        T minimum();
        T maximum();
        T find(T element);
        Node* findParent(T element);
};

template<typename T>
T Bst<T>::find(T element){
    Node *key = NULL;
    Node *current = this;
    Node *follow = NULL;
    while(current != NULL){
        follow = current;
        if (current->data == element){
            key = current;
            break;
        }
        else if(element < current->data){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    return key->data;
}

template<typename T>
void Bst<T>::remove(T element){
    Node *current = root;
    Node *follow = NULL;
    while(current != NULL){
        if (current->data == element){
            break;
        }
        follow = current;
        if(element < current->data){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    if (current == NULL){
        cout << "\nelemet "<< element << " not found\n";
        return;
    }
    // has both right and left subtree
    if(current->left && current->right){
        Node *pnode = current;
        //find inorder successor
        follow = current;
        current = current->right;
        while(current->left){
            follow = current;
            current  = current->left;
        }
        // swap pnode and current data 
        T temp = current->data;
        current->data = pnode->data;
        pnode->data = temp;
        //delete current
        if (follow == pnode){
            follow->right = current->right;
        }
        else{
            follow->left = NULL; 
        }
    }
    // has only left subtree
    else if(current->left && !current->right){
        if (!follow){
            root = current->left;
        }
        else if(current == follow->left){
            follow->left = current->left;
        }
        else{
            follow->right = current->left;
        }
    }
    // handles no subtree and only right subtree case
    else{
        if (!follow){
            root = current->right;
        }
        else if(current == follow->left){
            follow->left = current->right;
        }
        else{
            follow->right = current->right;
        }
    }
    current->right = current->left = NULL;
    if (element != 10){
        delete current;
    }
}

template<typename T>
T Bst<T>::minimum(){
    Node *current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current->data;
}

template<typename T>
T Bst<T>::maximum(){
    Node *current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return current->data;
}

template <typename T>
Bst<T>::Bst(T element){
    Node *pnode = new Node();
    pnode->left = NULL;
    pnode->right = NULL;
    pnode->data = element;
    root = pnode;
}

template<typename T>
void Bst<T>::insert(T element){
    Node *node = new Node();
    node->left = NULL;
    node->right = NULL;
    node->data = element;
    Node *current = root;
    Node *follow =  NULL;
    while(current != NULL){
        follow = current;
        if ( node->data < current->data){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    if (node->data < follow->data){
        follow->left = node;
    }
    else{
        follow->right = node;
    }
}

template<typename T>
void Bst<T>::inorder(Node *root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);
}

template<typename T>
void Bst<T>::inorder(){
    inorder(root);
}

template<typename T>
void Bst<T>::preorder(Node *root){
    if (root == NULL){
        return;
    }
    cout << root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}

template<typename T>
void Bst<T>::preorder(){
    preorder(root);
}

template<typename T>
void Bst<T>::postorder(Node *root){
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data <<" ";
}

template<typename T>
void Bst<T>::postorder(){
    postorder(root);
}

int main(){
    Bst<int> bst(10);
    bst.insert(5);
    bst.insert(3);
    bst.insert(6);
    bst.insert(15);
    bst.insert(12);
    bst.insert(17);
    cout << "inorder\n";
    bst.inorder();
    cout << "\npreorder\n";
    bst.preorder();
    cout << "\npostorder\n";
    bst.postorder();
    cout <<"\nminimum: " << bst.minimum() << "\n";
    cout <<"maximum: " << bst.maximum() << "\n";
    int removeElemets[] = {5, 3, 6, 12, 15, 10, 17, 100};
    int n = 8;
    int remove;
    for(int i = 0; i<n ;i++){
        remove = removeElemets[i];
        cout << "\nremoving " << remove << "\n";
        bst.remove(remove);
        cout << "inorder\n";
        bst.inorder();
    }
}

// int main(){
//     Bst<char> bst('d');
//     bst.insert('b');
//     bst.insert('f');
//     bst.insert('a');
//     bst.insert('c');
//     bst.insert('e');
//     bst.insert('g');
//     cout << "inorder\n";
//     bst.inorder();
//     cout << "\npreorder\n";
//     bst.preorder();
//     cout << "\npostorder\n";
//     bst.postorder();
// }