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
using namespace std;
bool primes[100001];
void sieve(int m) {
    primes[0] = primes[1] = true;
    for (int i = 2; i * i <= m; i++)
        if (!primes[i])
            for (int j = i * i; j <= m; j += i)
                primes[j] = true;
}
int main() {
    int a, b;
    cin >> a >> b;
    sieve(b);
    for (int i = a; i <= b; i++)
        if (!primes[i]) cout << i << ' ';
    return 0;
}