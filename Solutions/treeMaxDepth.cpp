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
struct Tree {
    int data;
    Tree* left;
    Tree* right;
};
Tree* GetNewNode(int data) {
    Tree* newNode = new Tree();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Tree* Insert(Tree* root, int data) {
    if (root == NULL)
        root = GetNewNode(data);
    elif (data < root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}
int height(Tree* root, int time) {
    if (root == NULL) return time;
    return max(height(root->left, time + 1), height(root->right, time + 1));
}
int main() {
    Tree* root = NULL;
    int n, res, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        root = Insert(root, a);
    }
    res = height(root, 0);
    cout << res << endl;
    return 0;
}   