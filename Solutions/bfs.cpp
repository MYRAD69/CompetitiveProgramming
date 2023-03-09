#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define pb push_back
#define uns unsigned
#define N 101
using namespace std;
int n, s, f, adj[N][N], color[N], dis[N];
queue<int> q;
void bfs() {
    q.push(s);
    color[s] = 1;
    while (q.size() != 0) {
        int x = q.front();
        for (int i = 1; i <= n; i++) {
            if (adj[x][i] == 1 && color[i] == 0) {
                color[i] = 1;
                dis[i] = dis[x] + 1;
                q.push(i);
            }
        }
        q.pop();
        color[x] = 2;
    }
}
int main() {
    cin >> n >> s >> f;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> adj[i][j];
    bfs();
    cout << dis[f] << endl;
    return 0;
}