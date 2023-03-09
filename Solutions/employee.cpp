#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define pb push_back
using namespace std;
int color[200001];
int main() {
    int n, r;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> r;
        color[r]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << color[i] << endl;
    }
    return 0;
}