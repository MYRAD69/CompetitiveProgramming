#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
using namespace std;
int main() {
    int n, k;
    vi v1, v2;
    cin >> n >> k;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            v1.push_back(i);
            if (n / i != i)
                v2.push_back(n / i);
        }
    }
    if (k > v1.size() + v2.size()) {
        cout << -1;
        return 0;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if (k <= v1.size()) {
        cout << v1[k - 1] << endl;
    }
    else {
        cout << v2[k - v1.size() - 1] << endl;
    }
    return 0;
}