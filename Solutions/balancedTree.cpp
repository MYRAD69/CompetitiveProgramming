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
int height(TreeNode* root, int time) {
    if (root == NULL) return time;
    return max(height(root->left, time + 1), height(root->right, time + 1));
}
bool isBalanced(TreeNode* root) {
    if (root == NULL) return true;
    if (abs(height(root->left, 0) - height(root->right, 0)) <= 1 && isBalanced(root->left) && isBalanced(root->right)) return true;
    return false;
}
int main() {
    TreeNode* t = NULL;
    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        t = Insert(t, a);
    }
    bool res;
    res = isBalanced(t);
    cout << res << endl;
    return 0;
}