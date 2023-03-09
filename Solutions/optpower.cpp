#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define pb push_back
using namespace std;
ll power(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2) return power(a, b - 1) * a;
    return power(a * a, b / 2);
}
int main() {
    ll x, n, res;
    cin >> x >> n;
    res = power(x, n);
    cout << res << endl;
    return 0;
}