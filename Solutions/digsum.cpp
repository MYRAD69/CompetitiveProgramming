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
int main() {
    int32_t n, res = 0;
    cin >> n;
    n = abs(n);
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    cout << res;
    return 0;
}