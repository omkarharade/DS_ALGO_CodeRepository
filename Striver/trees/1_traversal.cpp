#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

struct Node {

	int data;
	struct Node* left;
	struct Node* right;

	Node(int value) {

		data = value;
		left = NULL;
		right = NULL;
	}
};


void inorder(Node* node) {

	if (node == NULL) return;

	inorder(node -> left);
	cout << node -> data;
	inorder(node -> right);
}


void preorder(Node* node) {

	if (node == NULL) return;

	cout << node -> data;
	inorder(node -> left);
	inorder(node -> right);
}


void postorder(Node* node) {

	if (node == NULL) return;

	inorder(node -> left);
	inorder(node -> right);
	cout << node -> data;
}


int main() {

	return 0;
}