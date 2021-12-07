#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left, * right;
};

void add(Node*& root, int x) {
    if (root == NULL) {
        root = new Node;
        root->val = x;
        root->left = root->right = NULL;
    }
    else {
        if (x < root->val) add(root->left, x);
        else if (x > root->val) add(root->right, x);
    }
}

int length(Node* root, int& sosanh) {
    if (root == NULL) return 0;
    int left = length(root->left, sosanh);
    int right = length(root->right, sosanh);
    if (left - right < -1 || left - right>1) sosanh += 1;
    if (left - right > 0) return 1 + left;
    else return 1 + right;
}

int unbalance(Node* root) {
    int t = 0;
    length(root, t);
    return t;
}

void binary_search_tree(vector<int>&a, Node*& root, int l, int r)
{
    if (r >= l) {
        int m = l + (r - l) / 2;
        add(root, a[m]);
        binary_search_tree(a, root, l, m - 1);
        binary_search_tree(a, root, m + 1, r);
    }
    return;
}
void build(vector<int>a, Node* &root) {
    binary_search_tree(a, root, 0, a.size() - 1);
}

void lnr(Node *root) {
    if (root != NULL) {
        lnr(root->left);
        cout << root->val << "\n";
        lnr(root->right);
    }
}
int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Node* root = NULL;
    vector<int>a;
    int x;
    while (cin >> x) {
        a.push_back(x);
    }

    build(a, root); // Chi can viet ham nay 

    lnr(root);
    cout << "So node bi mat can bang la " << unbalance(root);
    return 0;
}
