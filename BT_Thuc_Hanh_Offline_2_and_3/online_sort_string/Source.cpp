#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     ios_base::sync_with_stdio(false)

struct node {
	char val[30];
	node* left, * right;
};
node* get_node(char x[]) {
	node* p = new node;
	for (int i = 0; i < 30; ++i) {
		p->val[i] = x[i];
	}
	p->left = p->right = NULL;
	return p;
}
int same(char* a, char* b) {
	int i = 0;
	for (; a[i] != '\0'; i++) {
		if (int(a[i]) != int(b[i])) return 0;
	}
	if (b[i] == '\0') return 1;
	return 0;
}
int compare(char* a, char* b) {
	int i = 0;
	for (i = 0; i < 30; ++i) {
		if (int(a[i]) > int(b[i])) return 0;
		if (int(a[i]) < int(b[i])) return 1;
	}
	return 0;
}
node* add_node(node*& root, char x[])
{
	if (root == NULL) {
		root = get_node(x);
	}
	if (same(root->val, x) == 1) return root;
	if (compare(root->val, x) == 1) add_node(root->left, x);
	else add_node(root->right, x);
}

node* find(node* root, char x[]) {
	if (root == NULL) return NULL;
	if (same(root->val, x) ==1) return root;
	else if (compare(root->val, x) == 1) find(root->left, x);
	else find(root->right, x);
}

int main() {
	cin.tie(0);
	fast_io;
	node* a = NULL;
	int x;
	char ms[30];
	do {
		cin >> x;
		if (x == 0) break;
		cin >> ms;
		if (x == 1) add_node(a, ms);
		else if (x == 2) cout << (find(a, ms) == NULL ? 0 : 1) << "\n";
	} while (x > 0);
}