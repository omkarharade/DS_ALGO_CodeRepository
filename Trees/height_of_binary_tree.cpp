#include <bits/stdc++.h>
using namespace std;
#define nline "\n";
struct Node{
    Node *left, *right;
    int data;

    Node(int data){
        left = right = NULL;
        this -> data = data;
    }
};

int height(Node* root){

    if(root == NULL) return -1;

    return max(height(root -> left), height(root -> right)) +1;
}


int main() {

    // Contrust the Tree
    //      1
    //     /  \
    //    2    3
    //   / \    
    //  4   5

    struct Node *root = new Node(1);
    root->left    = new Node(2);
    root->right    = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 

    cout << "height of the binary tree is\n" << height(root) << nline;


    
    return 0;
}