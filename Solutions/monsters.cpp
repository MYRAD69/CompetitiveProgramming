#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define __lcm(x, y) (x * y) / __gcd(x, y)
#define pb push_back
#define uns unsigned
#define INF 1000000007
#define N 1001
using namespace std;
vp monsters;
map<pair<int, int>, pair<int, int>> p;
int n, m, timer[N][N], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
pair<int, int> finish;
queue<vi> q;
bool isValid(int x, int y, int t) {
    if (x <= 0 or y <= 0 or x > n or y > m or timer[x][y] <= t)
        return false;
    return true;
}
bool isEscape(int x, int y, int t) {
    if (!isValid(x, y, t)) return false;
    if (x == 1 or y == 1 or x == n or y == m) return true;
    return false;
}
void bfs1() {
    for (auto m : monsters)
        q.push({0, m.first, m.second});
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int t, x, y;
            t = u[0] + 1;
            x = u[1] + dx[i];
            y = u[2] + dy[i];
            if (isValid(x, y, t)) {
                timer[x][y] = t;
                q.push({t, x, y});
            }
        }
    }
}
bool bfs2(int sx, int sy) {
    q.push({0, sx, sy});
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x, y, t;
            t = u[0] + 1;
            x = u[1] + dx[i];
            y = u[2] + dy[i];
            if (isEscape(x, y, t)) {
                p[{x, y}] = {u[1], u[2]};
                finish = {x, y};
                return true;
            }
            if (isValid(x, y, t)) {
                p[{x, y}] = {u[1], u[2]};
                q.push({t, x, y});
                timer[x][y] = t;
            }
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    char c;
    pair<int, int> player;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> c;
            timer[i][j] = INF;
            if (c == 'M') {
                timer[i][j] = 0;
                monsters.pb({i, j});
            }
            elif (c == 'A') {
                timer[i][j] = 0;
                player = {i, j};
            }
            elif (c == '#')
                timer[i][j] = 0;
        }
    if (player.first == 1 or player.first == n or player.second == 1 or player.second == m) {
        cout << "YES" << endl << 0;
        return 0;
    }
    bfs1();
    if (!bfs2(player.first, player.second)) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<char> ans;
    pair<int, int> e = {-1, -1};
    p[player] = e;
    for (auto i = finish; i != e; i = p[i]) {
        if (p[i].first - i.first == -1)
            ans.pb('D');
        elif (p[i].first - i.first == 1)
            ans.pb('U');
        elif (p[i].second - i.second == -1)
            ans.pb('R');
        elif (p[i].second - i.second == 1)
            ans.pb('L');
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i;
}