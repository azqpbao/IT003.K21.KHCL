#include <iostream>
#include <string>
using namespace std;
struct Node {
	string Eng;
	string strange;
	Node* left;
	Node* right;
};
Node* get_node(string a, string b)
{
	Node* t = new Node;
	t->Eng = a;
	t->strange = b;
	t->left = t->right = NULL;
	return t;
}
void add_node(Node*& root, string a, string b)
{
	if (root == NULL)
	{
		root = get_node(a, b);
	}
	else if (b < root->strange)
	{
		add_node(root->left, a, b);
	}
	else if (b > root->strange)
	{
		add_node(root->right, a, b);
	}
}
string checkWord(Node* root, string c)
{
	if (root != NULL)
	{
		if (c.compare(root->strange) == 0) return root->Eng;
		else if (c.compare(root->strange) < 0) return checkWord(root->left, c);
		else if (c.compare(root->strange) > 0) return checkWord(root->right, c);
	}
	else {
		return "eh";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Node* root = NULL;
	string a, b, c;
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		add_node(root, a, b);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> c;
		cout << checkWord(root, c) << "\n";
	}
	return 0;
}