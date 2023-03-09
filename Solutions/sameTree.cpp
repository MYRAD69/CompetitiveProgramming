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
    TreeNode* left;
    TreeNode* right;
};
TreeNode* getNewNode(int data) {
    TreeNode* newNode = new TreeNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL)
        root = getNewNode(data);
    elif (root->data <= data)
        root->right = insert(root->right, data);
    else root->left = insert(root->left, data);
    return root;
}
bool areSame(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    elif ((root1 == NULL) != (root2 == NULL)) return false;
    if (root1->data == root2->data) return (areSame(root1->left, root2->left) && areSame(root1->right, root2->right));
    else return false;
}
int main() {
    TreeNode* t1 = NULL;
    TreeNode* t2 = NULL;
    int n, m, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        t1 = insert(t1, a);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a;
        t2 = insert(t2, a);
    }
    cout << areSame(t1, t2) << endl;
    return 0;
}