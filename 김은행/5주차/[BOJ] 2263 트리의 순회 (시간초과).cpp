#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> values;

class Node {
public:
	int key;
	int value;
	Node* par;
	Node* left;
	Node* right;

	Node(int k) {
		key = k;
		par = NULL;
		left = NULL;
		right = NULL;
	}

	void setValue(int v) {
		value = v;
	}
};

class Tree {
public:
	vector<Node*> nodes;
	Node* root;
	Node* dummy = new Node(0);

	Tree() {
		Node* r = new Node(1);
		r->left = dummy;
		r->right = dummy;
		root = r;
		nodes.push_back(root);
	}

	void insert(int k) {
		Node* nn = new Node(k);
		nodes.push_back(nn);
		nn->left = dummy;
		nn->right = dummy;

		Node* cur = root;
		bool isLeft = true;
		queue<Node*> q;
		q.push(root);

		while (!q.empty()) {
			cur = q.front();
			q.pop();

			if (cur->left != dummy) {
				q.push(cur->left);
			}
			else {
				isLeft = true;
				break;
			}

			if (cur->right != dummy) {
				q.push(cur->right);
			}
			else {
				isLeft = false;
				break;
			}
		}

		if (isLeft) {
			//cout << "left attached\n";
			cur->left = nn;
			nn->par = cur;
		}
		else {
			//cout << "right attached\n";
			cur->right = nn;
			nn->par = cur;
		}
	}

	void printNodes() {
		for (int i = 0; i < nodes.size(); i++) {
			cout << nodes[i]->key << " ";
		}
		cout << endl;
	}
};

void postOrder(Node * node, Tree k) {
	if (node->left != k.dummy) {
		postOrder(node->left, k);
	}

	if (node->right != k.dummy) {
		postOrder(node->right, k);
	}

	node->setValue(values.front());
	values.pop();
}

void preOrder(Node* node, Tree k) {
	//cout << node->key << " ";
	cout << node->value << " ";

	if (node->left != k.dummy) {
		preOrder(node->left, k);
	}

	if (node->right != k.dummy) {
		preOrder(node->right, k);
	}
}
 
int main() {

	Tree bank;
	int T, dumy;
	cin >> T;
	cin >> dumy;

	for (int i = 0; i < T - 1; i++) {
		int ky;
		cin >> ky;

		bank.insert(ky);
	}

	
	for (int i = 0; i < T; i++) {
		int val;
		cin >> val;

		values.push(val);
	}

	postOrder(bank.root, bank);

	preOrder(bank.root, bank);
	

	return 0;
}