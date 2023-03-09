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
int main() {
    int n, say = 0;
    cin >> n;
    for (int i = 1; i < (1 << n); i++) {
        int x = i;
        for (int j = 1; j <= n; j++) {
            if (x % 2) cout << j;
            x /= 2;
        }
        cout << endl;
    }
    return 0;
}