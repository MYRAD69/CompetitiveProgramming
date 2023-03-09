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
void solve(int *a) {
    int res;
    sort(a, a + 5);
    bool ans = false;
    do {
        for (int i = 0; i < 81; i++) {
            int x = i;
            res = a[0];
            for (int j = 1; j < 5; j++) {
                if (x % 3 == 0) res += a[j];
                elif (x % 3 == 1) res -= a[j];
                else res *= a[j];
                x /= 3;
            }
            if (res == 23) {
                ans = true;
                break;
            }
        }
    } while (next_permutation(a, a + 5));
    if (ans) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}
int main() {
    int input[5];
    bool check;
    while (1) {
        check = false;
        for (int i = 0; i < 5; i++) {
            cin >> input[i];
            if (input[i] != 0) check = true;
        }
        if (!check) break;
        solve(input);
    }
    return 0;
}