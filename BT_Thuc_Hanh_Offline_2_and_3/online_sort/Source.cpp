#include <iostream>
using namespace std;

struct node {
	int val;
	node* left, * right;
};
node* get_node(int x) {
	node* p = new node;
	p->val = x;
	p->left = p->right = NULL;
	return p;
}
node* add_node(node* &root, int x)
{
	if (root == NULL) {
		root = get_node(x);
	}
	if (root->val > x) add_node(root->left, x);
	else if (root->val < x) add_node(root->right, x);
	else return root;
}

node* find(node *root, int x) {
	if (root == NULL) return NULL;
	if (root->val == x) return root;
	else if (root->val > x) find(root->left, x);
	else find(root->right, x);
}
void output( node* root)
{
	if (root != NULL)
	{
		output(root->left);
		cout << root->val << "\n";
		output(root->right);
	}
}

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	node* a = NULL;
	int x, ms;
	do {
		cin >> x;
		if (x == 0) break;
		cin >> ms;
		if (x == 1) add_node(a, ms);
		else if (x == 2) cout << (find(a, ms) == NULL ? 0 : 1) << "\n";
	} while (x > 0);
}
