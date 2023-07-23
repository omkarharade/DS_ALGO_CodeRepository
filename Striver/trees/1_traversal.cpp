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
	cout << node -> data << " ";
	inorder(node -> right);


	// TC : O(N)
	// SC : O(h) height of BT
}


void preorder(Node* node) {

	if (node == NULL) return;

	cout << node -> data << " ";
	inorder(node -> left);
	inorder(node -> right);


	// TC : O(N)
	// SC : O(h) height of BT
}


void postorder(Node* node) {

	if (node == NULL) return;

	inorder(node -> left);
	inorder(node -> right);
	cout << node -> data << " ";


	// TC : O(N)
	// SC : O(h) height of BT
}


vector<vector<int>> levelorder(Node* node) {

	vector<vector<int>> ans;

	if (node == NULL) return ans;

	queue<Node*> q;
	q.push(node);


	while (!q.empty()) {
		int levelSize = q.size();
		vector<int> level;

		for (int i = 0; i < levelSize; i++) {

			Node* front = q.front();

			if (front -> left != NULL) q.push(front -> left);
			if (front -> right != NULL) q.push(front -> right);
			level.push_back(front -> data);
		}

		ans.push_back(level);
	}

	return ans;


	// TC : O(N)
	// SC : O(h) height of BT
}


int main() {

	return 0;
}