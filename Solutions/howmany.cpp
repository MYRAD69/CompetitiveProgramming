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
uns ll binomCo(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || n == k) return 1;
    return binomCo(n - 1, k - 1) + binomCo(n - 1, k);
}
int main() {
    int n, k;
    uns ll res;
    cin >> n >> k;
    res = binomCo(n, k);
    cout << res << endl;
    return 0;
}