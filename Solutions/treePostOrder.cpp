#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define pb push_back
#define uns unsigned
#define INF 1000000007
#define N 101
using namespace std;
struct TreeNode {
    int data;
    TreeNode *right, *left;
};
TreeNode* GetNewNode(int data) {
    TreeNode* root = new TreeNode();
    root->data = data;
    root->left = root->right = NULL;
    return root;
}
TreeNode* Insert(TreeNode* root, int data) {
    if (root == NULL)
        root = GetNewNode(data);
    elif (data >= root->data)
        root->right = Insert(root->right, data);
    else
        root->left = Insert(root->left, data);
    return root;
}
void PostOrder(TreeNode* root) {
    if (root->left != NULL) PostOrder(root->left);
    if (root->right != NULL) PostOrder(root->right);
    cout << root->data << ' ';
}
int main() {
    int n, a;
    TreeNode* t = NULL;
    cin >> n;
    while (n--) {
        cin >> a;
        t = Insert(t, a);
    }
    PostOrder(t);
    return 0;
}