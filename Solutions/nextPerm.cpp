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
    int a, n, t;
    string b;
    map<int, string> m;
    cin >> n;
    t = n;
    while (n--) {
        cin >> a >> b;
        m.insert({a, b});
    }
    for (int i = 1; i <= t; i++) {
        string res = m[i];
        cout << i << ' ';
        if (next_permutation(res.begin(), res.end()))
            cout << res << endl;
        else cout << "BIGGEST" << endl;
    }
    return 0;
}