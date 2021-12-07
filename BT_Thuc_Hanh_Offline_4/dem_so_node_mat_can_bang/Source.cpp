#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left, * right;
};

void add(Node*& root, int x) {
    /*
        Hàm thêm một số vào cây
        Hàm này đã được viết đầy đủ và đảm bảo đúng
        Sinh viên không cần phải viết hàm này
    */
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

//so sanh unbalance
int length(Node* root,int &sosanh) {
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

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Node* root = NULL;

    int x;
    while (cin >> x) {
        if (x == 0) break;
        add(root, x);
    }
    cout << "So node bi mat can bang la " << unbalance(root) ;
    return 0;
}


