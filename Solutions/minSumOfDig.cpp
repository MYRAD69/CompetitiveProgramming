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
int digSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int main() {
    int n, m, res = 1, minSum;
    cin >> n >> m;
    minSum = digSum(n);
    for (int i = n + 1; i <= m; i++) {
        int s = digSum(i);
        if (s < minSum) {
            res = 1;
            minSum = s;
        }
        elif (s == minSum)
            res++;
    }
    cout << res;
    return 0;
}