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
#define ff first
#define ss second
#define N 101
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left, *right;
};
TreeNode* GetNewNode(int data) {
    TreeNode* newNode = new TreeNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
TreeNode* Insert(TreeNode* root, int data) {
    if (root == NULL)
        root = GetNewNode(data);
    elif (data < root->data)
        root->left = Insert(root->left, data);
    elif (data > root->data)
        root->right = Insert(root->right, data);
    return root;
}
bool find(TreeNode* root, int data) {
    if (root->data == data) return true;
    elif (data > root->data) {
        if (root->right == NULL) return false;
        else return find(root->right, data);
    }
    else {
        if (root->left == NULL) return false;
        else return find(root->left, data);
    }
}
TreeNode* MinNode(TreeNode* root) {
    TreeNode* t = root;
    while (t && t->left != NULL)
        t = t->left;
    return t;
}
TreeNode* Delete(TreeNode* root, int data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = Delete(root->left, data);
    elif (data > root->data)
        root->right = Delete(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL) return NULL;
        if (root->left == NULL) {
            TreeNode* t = root->right;
            free(root);
            return t;
        }
        if (root->right == NULL) {
            TreeNode* t = root->left;
            free(root);
            return t;
        }
        TreeNode* t = MinNode(root->right);
        root->data = t->data;
        root->right = Delete(root->right, t->data);
    }
}
int main() {
    string op;
    int k;
    vector<string> res;
    TreeNode* root = NULL;
    while (cin >> op >> k) {
        if (op == "insert")
            root = Insert(root, k);
        elif (op == "exists") {
            if (find(root, k)) res.pb("true");
            else res.pb("false");
        }
        elif (op == "delete")
            root = Delete(root, k);
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}