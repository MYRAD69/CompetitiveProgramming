#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define __lcm(x, y) (x * y) / __gcd(x, y)
#define pb push_back
#define uns unsigned
#define INF 1000000007
#define N 10001
using namespace std;
struct triple {
    int x, y, g;
    void print() {
        cout << x << ' ' << y << ' ' << g;
    }
};
triple extend(int a, int b) {
    if (b == 0)
        return {1, 0, a};
    else {
        triple res = extend(b, a % b);
        return {res.y, res.x - (a / b) * res.y, res.g};
    }
}
int main() {
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    triple ans = extend(a, b);
    ans.print();
}