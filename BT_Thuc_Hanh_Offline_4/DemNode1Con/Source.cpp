#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node* left, * right;
};

Node* get_node(int x)
{
	Node* p = new Node;
	p->val = x;
	p->left = p->right = NULL;
	return p;
}
void add_node(Node *&root, int x)
{
	if (root == NULL)
		root = get_node(x);
	else if (x < root->val)
		add_node(root->left, x);
	else if (x > root->val)
		add_node(root->right, x);
}

int DemNodeMotCon(Node* root)
{
	if (root == NULL) return 0;
	else if (root->left && root->right == NULL) return 1 + DemNodeMotCon(root->left);
	else if (root->left == NULL && root->right ) return 1 + DemNodeMotCon(root->right);
	return DemNodeMotCon(root->left) + DemNodeMotCon(root->right);
}
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	Node* root = NULL;
	int x;
	while(true)
	{
		cin >> x;
		if (x == 0) {
			cout << DemNodeMotCon(root);
			break;
		}
		else 
		{
			add_node(root, x);
		}
	}
	return 0;
}