#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define pb push_back
using namespace std;
int solve(int a, int b) {
    if (b == 0)
        return a;
    return solve(b, a % b);
}
int main() {
    int x, y, res;
    cin >> x >> y;
    res = solve(max(x, y), min(x, y));
    cout << res;
    return 0;
}