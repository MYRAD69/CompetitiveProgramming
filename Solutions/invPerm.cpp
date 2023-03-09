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
    int n, a[20001], b[20001];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        b[a[i]] = i;
    for (int i = 1; i <= n; i++)
        cout << b[i] << ' ';
    return 0;
}