#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define pb push_back
using namespace std;
int prod(int num) {
    int res = 1;
    while (num > 0) {
        res *= num % 10;
        num /= 10;
    }
    return res;
}
void solve(int n) {
    int cnt = 0;
    while (n >= 10) {
        n = prod(n);
        cnt++;
    }
    cout << cnt << endl;
}
int main() {
    int n;
    while (cin >> n)
        solve(n);
    return 0;
}