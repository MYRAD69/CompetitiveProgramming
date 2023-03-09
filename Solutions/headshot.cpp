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
int ceilM(int a, int b) {
    if (a % b == 0) return a / b;
    return a / b + 1;
}
int solve(int n, int m, int a, int b) {
    a = min(a, b * m);
    return min(ceilM(n, m) * a, n / m * a + (n % m) * b);
}
int main() {
    int n, m, a, b;
    int res;
    cin >> n >> m >> a >> b;
    res = solve(n, m, a, b);
    cout << res + n << endl;
    return 0;
}