#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define pb push_back
#define uns unsigned
#define INF 1000000007
#define N 101
using namespace std;
int n, t, color[N][N];
struct Point {
    int x, y;
};
vector<Point> adj, adj_scc;
Point fin[N];
bool inReach(Point p1, Point p2) {
    int dist;
    dist = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    dist = sqrt(dist);
    if (dist == 1) return true;
    return false;
}
void dfs(Point s) {
    color[s.x][s.y] = 1;
    for (auto i : adj)
        if (inReach(s, i) && color[i.x][i.y] == 0)
            dfs(i);
    fin[++t] = s;
}
void dfs_scc(Point s) {
    color[s.x][s.y] = 2;
    for (auto i : adj_scc)
        if (inReach(s, i) && color[i.x][i.y] == 1)
            dfs_scc(i);
}
int main() {
    int x, y, res = 0;
    Point p;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        p.x = x;
        p.y = y;
        adj.pb(p);
        adj_scc.pb(p);
    }
    for (auto i : adj) {
        if (color[i.x][i.y] == 0) {
            p.x = i.x;
            p.y = i.y;
            dfs(p);
        }
    }
    for (int i = t; i >= 1; i--) {
        p = fin[i];
        if (color[p.x][p.y] == 1) {
            res++;
            dfs_scc(p);
        }
    }
    cout << res << endl;
    return 0;
}