#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int tung, hoanh;
	node* left, * right;
};
node* get_node(int x, int y)
{
	node* t = new node;
	t->tung = y;
	t->hoanh = x;
	t->left = t->right = NULL;
	return t;
}
void add_node(node*& root, int x, int y)
{
	if (root == NULL) root = get_node(x, y);
	else if (x >= root->hoanh && y < root->tung) add_node(root->right, x, y);
	else if (x > root->hoanh && y >= root->tung) add_node(root->left, x, y);
	else if (x <= root->hoanh && y > root->tung) {
		node* t = get_node(x, y);
		t->right = root;
		root = t;
	}
	else if (x < root->hoanh && y <= root->tung) {
		node* t = get_node(x, y);
		t->left = root;
		root = t;
	}
}
int chieuCao(node* root)
{
	if (root == NULL) return 0;
	return 1 + max(chieuCao(root->left), chieuCao(root->right));
}
void output(node *root)
{
	if (root != NULL)
	{
		cout << "(" << root->hoanh << ", " << root->tung << ") ";
		output(root->left);
		output(root->right);
	}
}
int main()
{
	int x, y;
	node* root = NULL;
	while (true)
	{
		cin >> x;
		if (x == 0) {
			cout << chieuCao(root) << "\n";
			output(root);
			break;
		}
		else {
			cin >> y;
			add_node(root, x, y);
		}
	}
	return 0;
}