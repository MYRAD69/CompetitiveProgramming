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
long fact(int num) {
    if (num == 0 || num == 1) return 1;
    return num * fact(num - 1);
}
set<int> s;
int index(int k) {
    auto it = s.find(k);
    int cnt = 1;
    for (auto i = s.begin(); i != it; i++)
        cnt++;
    return cnt;
}
int main() {
    int n, a, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    for (int i = 1; i <= n; i++) {
        if (i != 1) s.erase(a);
        cin >> a;
        if (s.find(a) == s.begin()) continue;
        res += ((index(a) - 1) * fact(n - i));
    }
    res++;
    cout << res << endl;
    return 0;
}