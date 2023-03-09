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
struct TreeNode
{
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
void PreOrder(TreeNode* root) {
    cout << root->data << ' ';
    if (root->left != NULL) PreOrder(root->left);
    if (root->right != NULL) PreOrder(root->right);
}
int main() {
    TreeNode* t = NULL;
    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        t = Insert(t, a);
    }
    PreOrder(t);
    return 0;
}