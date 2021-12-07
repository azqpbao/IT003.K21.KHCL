#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left, * right;
};

Node* get_node(int x)
{
    Node* p = new Node;
    p->val = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void copy(Node* root, Node*& r2)
{
    if (root == NULL) return;
    add(r2, root->val);
    copy(root->left, r2);
    copy(root->right, r2);
}



int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Node* root = NULL, * r2 = NULL;

    while (true) {
        int x; cin >> x;
        if (x == 0) break;
        /* Hàm add thêm số nguyên x vào cây nhị phân theo nguyên tắc riêng
        * Hàm này đã được viết đầy đủ
        * sinh viên không cần viết hàm này
        */
        add(root, x);
    }

    copy(root, r2); //Cần phải viết hàm này

    /* Hàm check kiểm tra lại 02 cây sau khi copy
    * Hàm này đã được viết đầy đủ
    * sinh viên không cần viết hàm này
    **/
    check(root, r2);

    return 0;
}


