#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define pb push_back
using namespace std;
int main() {
    int n;
    cin >> n;
    ll res = 0;
    n--;
    for (int i = 1; i <= n; i++) {
        res += n / i;
    }
    cout << res << endl;
    return 0;
}