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
bool comparator(pair<int, int> p1, pair<int, int> p2) {
    if (p1.ss < p2.ss) return false;
    elif (p1.ss == p2.ss && p1.ff >= p2.ff) return false;
    return true;
}
int main() {
    int n, a, b;
    pair<int, int> p[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        p[i] = {a, b};
    }
    sort(p, p + n, comparator);
    for (int i = 0; i < n; i++) {
        cout << p[i].ff << ' ' << p[i].ss << endl;
    }
    return 0;
}