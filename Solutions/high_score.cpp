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
#define INF 100000000000007
#define N 2501
using namespace std;
vp g[N];
vi v[N];
ll n, dis[N];
bool cycle[N], vis[N];
void bellmanFord() {
    for (ll i = 1; i <= n; i++)
        dis[i] = INF;
    dis[1] = 0;
    for (int k = 0; k < n; k++)
        for (ll i = 1; i <= n; i++)
            for (auto j : g[i]) {
                if (dis[i] != INF)
                    dis[j.first] = min(dis[j.first], dis[i] + j.second);
            }
    for (ll i = 1; i <= n; i++)
        for (auto j : g[i])
            if (dis[j.first] > dis[i] + j.second)
                cycle[j.first] = true;
}
void dfs(int s) {
    vis[s] = true;
    if (cycle[s] and dis[s] != INF) {
        dis[n] = INF;
        return;
    }
    for (auto i : v[s])
        if (!vis[i])
            dfs(i);
}
int main() {
    ll m, a, b, c;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        c *= -1;
        g[a].pb({b, c});
        v[b].pb(a);
    }
    bellmanFord();
    dfs(n);
    if (dis[n] == INF) dis[n] = 1;
    dis[n] *= -1;
    cout << dis[n] << endl;
}