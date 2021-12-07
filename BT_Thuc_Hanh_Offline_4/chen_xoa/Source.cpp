#include <iostream>
using namespace std;
struct node {
	int val;
	node* left, * right;
};
node* get_node(int x)
{
	node* t = new node;
	t->val = x;
	t->left = t->right = NULL;
	return t;
}
void add_node(node* &root, int x)
{
	if (root == NULL) root = get_node(x);
	else if (x < root->val) add_node(root->left, x);
	else if (x > root->val) add_node(root->right, x);
}
int check_node(node* root, int x)
{
	if (root != NULL)
	{
		if (root->val == x) return 1;
		else if (x < root->val) return check_node(root->left, x);
		else if (x > root->val) return check_node(root->right, x);
	}
	return 0;
}
void thay_the(node*& t, node*& root)
{
	if (root->left != NULL)
	{
		thay_the(t, root->left);
	}
	else
	{
		t->val = root->val;
		t = root;
		root = root->right;
	}
}
void delete_node(node*& root, int x)
{
	if (root != NULL)
	{
		if (root->val < x) delete_node(root->right, x);
		else {
			if (root->val > x) delete_node(root->left, x);
			else {
				node* t = root;
				if (root->left == NULL) root = root->right;
				else {
					if (root->right == NULL) root = root->left;
					else thay_the(t, root->right);
				}
				delete t;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	node* root = NULL;
	int x, y;
	while (true) {
		cin >> x;
		if (x == 0) break;
		else
		{
			cin >> y;
			if (x == 1) add_node(root, y);
			else if (x == 2) cout << check_node(root, y) << "\n";
			else if (x == 3) delete_node(root, y);
		}
	}
	return 0;
}