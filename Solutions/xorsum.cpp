#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define pb push_back
#define uns unsigned
#define INF 1000000007
#define N 100001
using namespace std;
int main() {
    ll l, r, res;
    cin >> l >> r;
    if (l % 4 == 0) {
        if (r % 4 == 1)
            res = 1;
        elif (r % 4 == 2)
            res = r + 1;
        elif (r % 4 == 3)
            res = 0;
        elif (r % 4 == 0)
            res = r;
    }
    elif (l % 4 == 2) {
        if (r % 4 == 1)
            res = 0;
        elif (r % 4 == 2)
            res = r;
        elif (r % 4 == 3)
            res = 1;
        elif (r % 4 == 0)
            res = r + 1;
    }
    elif (l % 4 == 1) {
        if (r % 4 == 1)
            res = l;
        elif (r % 4 == 2) {
            if (r - l == 1)
                res = 3;
            elif (r % 8 == 6)
                res = r - l + 2;
            elif (r % 8 == 2)
                res = r + l;
        }
        elif (r % 4 == 3)
            res = l - 1;
        elif (r % 4 == 0)
            res = r + l - 1;
    }
    elif (l % 4 == 3) {
        if (r % 4 == 1)
            res = l - 1;
        elif (r % 4 == 2) {
            if (r - l == 1)
                res = r + l;
            elif (r % 8 == 6)
                res = r - l + 1;
            elif (r % 8 == 2)
                res = r - 5 + l;
        }
        elif (r % 4 == 3)
            res = l;
        elif (r % 4 == 0)
            res = r + l;
    }
    cout << res << endl;
    return 0;
}