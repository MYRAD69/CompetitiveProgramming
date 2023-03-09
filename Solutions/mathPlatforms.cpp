#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define pb push_back
#define uns unsigned
#define INF 20000000000000007
#define ff first
#define ss second
#define N 4001
using namespace std;
ll n, h[N], d[N], color[N];
void dijkstra(int s) {
    for (int i = 1; i <= n; i++) d[i] = INF;
    d[s] = 0;
    for (int i = 2; i <= n; i++) {
        ll min = INF, w = -1;
        for (int j = 1; j <= n; j++)
            if (color[j] == 0 && d[j] < min) {
                min = d[j];
                w = j;
            }
        if (w < 0) break;
        for (int j = 1; j <= n; j++) {
            ll energy = (w - j) * (w - j) * (h[w] - h[j]) * (h[w] - h[j]);
            if (color[j] == 0 && d[j] > d[w] + energy) d[j] = d[w] + energy;
        }
        color[w] = 1;
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    dijkstra(1);
    cout << d[n];
    return 0;
}