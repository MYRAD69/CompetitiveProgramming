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
int fact(int n) {
    if (n == 0 || n == 1) return 1;
    return n * fact(n - 1);
}
void solve(string str, int k) {
    int n, index;
    vector<char> s;
    n = str.length();
    cout << str << ' ' << k << ' ' << '=' << ' ';
    if (k > fact(n)) {
        cout << "No permutation";
        return;
    }
    for (int i = 1; i <= n; i++)
        s.pb(str[i - 1]);
    for (int i = 1; i <= n; i++) {
        int f = fact(n - i);
        if (k % f == 0) index = k / f;
        else index = k / f + 1;
        for (int j = 0; j < n; j++) {
            if (j + 1 == index) {
                cout << s[j];
                s.erase(s.begin() + j);
                break;
            }
        }
        k -= ((index - 1) * f);
    }
}
int main() {
    string s;
    int n;
    while (cin >> s >> n) {
        solve(s, n);
        cout << endl;
    }
    return 0;
}