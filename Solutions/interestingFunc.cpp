#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define pb push_back
using namespace std;
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res *= a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}
ll numOfFiv(ll n) {
    ll num = 0;
    while (n != 0) {
        n /= 5;
        num++;
    }
    return num;
}
int main() {
    ll n;
    cin >> n;
    if (n % 2 == 1 || n < 10) {
        cout << 0 << endl;
    }
    else {
        ll res = 0;
        for (ll i = 0; i <= numOfFiv(n); i++) {
            res += n / (power(5, i) * 10);
        }
        cout << res << endl;
    }
    return 0;
}