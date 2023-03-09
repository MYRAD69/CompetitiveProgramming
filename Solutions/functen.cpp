#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define pb push_back
#define uns unsigned
using namespace std;
int func(int a, int b);
int main() {
    int n, m, res;
    cin >> n >> m;
    res = func(min(n, m), max(n, m));
    cout << res << endl;
    return 0;
}
int func(int a, int b) {
    if (a == 0) return 1;
    if (a == b) return 1;
    return func(a - 1, b - 1) + func(a, b - 1);
}