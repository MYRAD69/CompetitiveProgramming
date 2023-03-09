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
int solve(int st, int fin, int tp1, int tp2) {
    int bf, t1, t2;
    bf = abs(st - fin);
    t1 = abs(st - tp1) + abs(fin - tp2);
    t2 = abs(st - tp2) + abs(fin - tp1);
    return min(min(t1, t2), bf);
}
int main() {
    int a, b, x, y, res;
    cin >> a >> b >> x >> y;
    res = solve(a, b, x, y);
    cout << res << endl;
    return 0;
}