#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define pb push_back
#define uns unsigned
#define INF 1e9 + 7
#define ff first
#define ss second
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
    else root->left = Insert(root->left, data);
    return root;
}
int minDepth(TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int l, r;
    l = r = INT_MAX;
    if (root->left != NULL)
        l = minDepth(root->left);
    if (root->right != NULL)
        r = minDepth(root->right);
    return min(l, r) + 1;
}
int main() {
    TreeNode* t = NULL;
    int res, n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        t = Insert(t, a);
    }
    res = minDepth(t);
    cout << res << endl;
    return 0;
}