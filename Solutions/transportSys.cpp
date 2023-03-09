#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define pb push_back
#define uns unsigned
#define INF 1e9 + 7
#define ff first
#define ss second
#define N 1001
using namespace std;
int n, m;
bool adj[N][N];
void bfs(int s, int *dis) {
    int color[N];
    memset(color, 0, sizeof(color));
    color[s] = 1;
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size() != 0) {
        int x = q.front();
        for (int i = 1; i <= n; i++) {
            if (adj[x][i] && color[i] == 0) {
                q.push(i);
                dis[i] = dis[x] + 1;
                color[i] = 1;
            }
        }
        color[x] = 2;
        q.pop();
    }
}
int main() {
    int s, f, disS[N], disF[N], d, res = 0;
    cin >> n >> m >> s >> f;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = true;
    }
    bfs(s, disS);
    bfs(f, disF);
    d = disS[f];
    int temp1, temp2;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!adj[i][j]) {
                temp1 = disS[i] + 1 + disF[j];
                temp2 = disS[j] + 1 + disF[i];
                if (temp1 >= d && temp2 >= d) res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}