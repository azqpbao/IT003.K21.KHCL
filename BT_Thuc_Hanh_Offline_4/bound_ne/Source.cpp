
#include <iostream>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

node* get_node(int x) {
    node* p = new node;
    p->val = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void add_node(node*& root, int x) {
    if (root == NULL)
        root = get_node(x);
    else if (x < root->val)
        add_node(root->left, x);
    else if (x > root->val)
        add_node(root->right, x);
}

int lower_bound(node* root, int x, node*& t) {
    if (root == NULL) {
        if (t == NULL)
            return -1;
        else
            return t->val;
    }
    if (root->val == x) {
        if (root->left == NULL) {
            if (t == NULL)
                return -1;
            else
                return t->val;
        }
        else {
            root = root->left;
            while (root->right != NULL)
                root = root->right;
            return root->val;
        }
    }
    else if (x < root->val) {
        return lower_bound(root->left, x, t);
    }
    else if (x > root->val) {
        if (root->right == NULL)
            return root->val;
        else {
            t = root;
            return lower_bound(root->right, x, t);
        }
    }
    return -1;
}

int upper_bound(node* root, int x, node*& t) {
    if (root == NULL) {
        if (t == NULL)
            return -1;
        else
            return t->val;
    }
    if (root->val == x) {
        if (root->right == NULL) {
            if (t == NULL)
                return -1;
            else
                return t->val;
        }
        else {
            root = root->right;
            while (root->left != NULL)
                root = root->left;
            return root->val;
        }
    }
    else if (x < root->val) {
        if (root->left == NULL)
            return root->val;
        else {
            t = root;
            return upper_bound(root->left, x, t);
        }
    }
    else if (x > root->val) {
        return upper_bound(root->right, x, t);
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int y, x;
    node* root = NULL;
    do {
        cin >> y;
        if (y == 0) break;
        cin >> x;
        if (y == 1) add_node(root, x);
        if (y == 2) {
            node* t = NULL;
            if (lower_bound(root, x, t) == -1)
                cout << "NULL\n";
            else
                cout << lower_bound(root, x, t) << "\n";
        }

        if (y == 3) {
            node* t = NULL;
            if (upper_bound(root, x, t) == -1)
                cout << "NULL\n";
            else
                cout << upper_bound(root, x, t) << "\n";
        }
    } while (y != 0);
    return 0;
}