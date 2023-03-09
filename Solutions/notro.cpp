#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define pb push_back
#define vp vector<pair<int, int>>
using namespace std;
int msx(int num, int m) {
    if (num == 1)
        return m;
    if (num % 2 == 0)
        return msx(num / 2, m);
    return msx(num * 3 + 1, max(m, num * 3 + 1));
}
int main() {
    int t;
    vp v;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        v.pb({a, b});
    }
    for (int i = 0; i < v.size(); i++) {
        int res;
        res = msx(v[i].second, v[i].second);
        cout << v[i].first << ' ' << res << endl;
    }
    return 0;
}