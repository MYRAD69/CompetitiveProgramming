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
struct Matrix {
    long double a, b, c, d;
    void print() {
        cout << a << ' ' << b << endl << c << ' ' << d << endl;
    }
};
Matrix mult(Matrix m1, Matrix m2) {
    Matrix res;
    res.a = m1.a * m2.a + m1.b * m2.c;
    res.b = m1.a * m2.b + m1.b * m2.d;
    res.c = m1.c * m2.a + m1.d * m2.c;
    res.d = m1.c * m2.b + m1.d * m2.d;
    return res;
}
Matrix power(Matrix m, int n) {
    if (n == 1 || n == 0) return m;
    Matrix k = power(m, n / 2);
    if (n % 2) return mult(mult(k, k), m);
    else return mult(k, k);
}
int main() {
    int n;
    cin >> n;
    Matrix f, i;
    i = {1, 1, 1, 0};
    f = power(i, n);
    cout << setprecision(3000) << f.b << endl;
}