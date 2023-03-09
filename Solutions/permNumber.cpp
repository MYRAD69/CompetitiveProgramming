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
int main() {
    int n, k, cnt, index;
    cin >> n >> k;
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        int f = fact(n - i);
        if (k % f == 0) index = k / f;
        else index = k / f + 1;
        for (auto i = s.begin(); i != s.end(); i++) {
            cnt++;
            if (cnt == index) {
                cout << *i << ' ';
                s.erase(i);
                break;
            }
        }
        k -= ((index - 1) * f);
    }
    return 0;
}