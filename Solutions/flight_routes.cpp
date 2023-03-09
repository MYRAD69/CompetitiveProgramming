#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<ll>
#define elif else if
#define mp make_pair
#define vp vector<pair<ll, ll>>
#define __lcm(x, y) (x * y) / __gcd(x, y)
#define pb push_back
#define uns unsigned
#define INF 1000000000000007
#define N 100001
using namespace std;
vp g[N];
ll n, dis[N][10];
priority_queue<pair<ll, ll>, vp, greater<pair<ll, ll>>> pq;
void dijkstra(ll s, ll k) {
    for (ll i = 1; i <= n; i++)
        for (ll j = 0; j < k; j++)
            dis[i][j] = INF;
    pq.push({0, s});
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        ll u = x.second, d = x.first;
        if (dis[u][k - 1] < d) continue;
        for (auto edge : g[u]) {
            ll v = edge.first, w = edge.second;
            if (dis[v][k - 1] > d + w) {
                dis[v][k - 1] = d + w;
                pq.push({dis[v][k - 1], v});
                sort(dis[v], dis[v] + k);
            } 
        }
    }
}
int main() {
    ll m, k, a, b, c;
    cin >> n >> m >> k;
    while (m--) {
        cin >> a >> b >> c;
        g[a].pb({b, c});
    }
    dijkstra(1, k);
    for (ll i = 0; i < k; i++)
        cout << dis[n][i] << ' ';
}