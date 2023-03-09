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
#define N 100001
using namespace std;
vp g[N];
ll dis[N], n, eco[N];
void dijkstra(ll s) {
    for (ll i = 1; i <= n; i++)
        dis[i] = eco[i] = INF;
    dis[s] = 0;
    priority_queue<pair<ll, pair<ll, bool>>, vector<pair<ll, pair<ll, bool>>>, greater<pair<ll, pair<ll, bool>>>> pq;
    pq.push({0, {s, false}});
    while (!pq.empty()) {
        ll u, d;
        bool f;
        auto k = pq.top();
        pq.pop();
        u = k.second.first;
        d = k.first;
        f = k.second.second;
        if ((f and eco[u] < d) or (!f and dis[u] < d))
            continue;
        for (auto i : g[u]) {
            ll v, w;
            v = i.first;
            w = i.second;
            if (!f) {
                if (dis[v] > d + w) {
                    dis[v] = d + w;
                    pq.push({dis[v], {v, false}});
                }
                if (eco[v] > d + w / 2) {
                    eco[v] = d + w / 2;
                    pq.push({eco[v], {v, true}});
                }
            }
            else
                if (eco[v] > d + w) {
                    eco[v] = d + w;
                    pq.push({eco[v], {v, true}});
                }
        }
    }
}
int main() {
    ll m, a, b, c;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        g[a].pb({b, c});
    }
    dijkstra(1);
    cout << eco[n] << endl;
}