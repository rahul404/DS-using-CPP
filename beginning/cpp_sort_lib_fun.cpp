#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> *v = new vector<int>();
    v->push_back(5);
    v->push_back(4);
    v->push_back(3);
    v->push_back(2);
    v->push_back(1);
    sort(v->begin(), v->end());
    for(auto ir = v->begin(); ir != v->end(); ++ir){
        cout << *ir << " ";
    }
}