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


vector<int> iterative_inorder(Node* root) {

	stack<Node*> st;
	Node* node = root;

	vector<int> inorder;

	while (true) {

		if (node != NULL) {

			st.push(node);
			node = node -> left;
		}
		else {

			if (st.size() == 0) break;
			node = st.top();
			st.pop();

			inorder.push_back(node -> data);
			node = node -> right;
		}
	}

	return inorder;
}

vector<int> iterative_preorder(Node* root) {

	stack<Node*> st;
	Node* node = root;

	vector<int> preorder;

	while (true) {

		if (node != NULL) {

			preorder.push_back(node -> data);
			st.push(node);
			node = node -> left;
		}
		else {

			if (st.size() == 0) break;
			node = st.top();
			st.pop();
			node = node -> right;
		}
	}

	return preorder;
}




int main() {

	Node* head = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4);
	Node* node5 = new Node(5);
	Node* node6 = new Node(6);
	Node* node7 = new Node(7);

	head -> left = node2;
	head -> right = node3;
	node2 -> left = node4;
	node2 -> right = node5;
	node5 -> left = node6;
	node5 -> right = node7;

	vector<int> ans = iterative_preorder(head);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	nline;



	return 0;
}