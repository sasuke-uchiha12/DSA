#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * left;
    Node * right;

    Node(int d): data(d), left(nullptr), right(nullptr){} 
};

Node * buildTree(){
    int d;
    cin >> d;

    if(d == -1){
        return nullptr;
    }

    Node * n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void printPreOrder(Node * root){
    if(root == nullptr){
        return;
    }

    cout << root->data << " -> ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}


void printInOrder(Node * root){
    if(root == nullptr){
        return;
    }

    printInOrder(root->left);
    cout << root->data << " -> ";
    printInOrder(root->right);
}

void printPostOrder(Node * root){
    if(root == nullptr){
        return;
    }

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " -> ";
}
int main() {
    Node * root = buildTree();
    printPreOrder(root);
    cout << endl;
    printInOrder(root);
    cout << endl;
    printPostOrder(root);
    cout << endl;
    return 0;
}