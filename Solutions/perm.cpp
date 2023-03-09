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
int main() {
    int n, a;
    bool check[10001];
    cin >> n;
    for (int i = i; i <= n; i++) check[i] = false;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a <= n)
            check[a] = true;
    }
    for (int i = 1; i <= n; i++)
        if (!check[i]) {
            cout << i << endl;
            return 0;
        }
    cout << 0 << endl;
    return 0;
}