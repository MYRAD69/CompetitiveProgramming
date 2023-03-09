#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define pb push_back
#define uns unsigned
#define ff first
#define ss second
#define N 101
#define MAX 1000001
using namespace std;
bool primes[MAX];
void sieve() {
    primes[0] = primes[1] = true;
    for (int i = 2; i * i <= MAX; i++)
        if (!primes[i])
            for (int j = i * i; j <= MAX; j += i)
                primes[j] = true;
}
void end(int l, int r) {
    cout << l << ' ' << r << ' ' << 0 << ' ' << 0 << endl;
}
void solve(int l, int r) {
    int x, y, p, f;
    p = f = 0;
    if (l < 0) x = 0;
    else x = l;
    if (r <= 1) end(l, r);
    else y = r;
    for (int i = x; i <= y; i++) {
        if (!primes[i]) {
            p++;
            if (i % 4 == 1)
                f++;
        }
    }
    cout << l << ' ' << r << ' ' << p << ' ' << f << endl;
}
int main() {
    int l, r;
    sieve();
    while (cin >> l >> r) {
        if (l == -1 && r == -1)
            break;
        else solve(l, r);
    }
    return 0;
}