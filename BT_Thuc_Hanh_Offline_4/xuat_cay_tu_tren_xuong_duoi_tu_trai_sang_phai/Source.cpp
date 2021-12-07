#include <iostream>
using namespace std;

struct node_tree {
	int val;
	node_tree* left, * right;
};
struct node_queue {
	node_tree* val;
	node_queue* next;
};
struct queue {
	node_queue* head, * tail;
};

node_tree* get_node(int x)
{
	node_tree* t = new node_tree;
	t->val = x;
	t->left = t->right = NULL;
	return t;
}

int empty(queue q) {
	if (q.head == NULL) return 1;
	return 0;
}

node_queue* get_node_queue(node_tree* x)
{
	node_queue* q = new node_queue;
	q->val = x;
	q->next = NULL;
	return q;
}
void add_queue(queue& q, node_tree *x)
{
	node_queue* t = get_node_queue(x);
	if (q.head == NULL) q.head = q.tail = t;
	else {
		q.tail->next = t;
		q.tail = t;
	}
}
void add_node(node_tree*& root, int x)
{
	if (root == NULL) root = get_node(x);
	else if (x < root->val) add_node(root->left, x);
	else if (x > root->val) add_node(root->right, x);
}
void output_ngang(node_tree* root)
{
	queue q;
	q.head = q.tail = NULL;
	add_queue(q, root);
	node_queue* t = q.head;
	while (t != NULL)
	{
		if (t->val->left != NULL) add_queue(q, t->val->left);
		if(t->val->right != NULL) add_queue(q, t->val->right);
		cout << t->val->val << " ";
		t = t->next;
	}
}
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	node_tree* root = NULL;
	int x;
	while (true)
	{
		cin >> x;
		if (x == 0)
		{
			output_ngang(root);
			break;
		}
		else add_node(root, x);
	}
	return 0;
}