#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define vi vector<int>
#define elif else if
#define mp make_pair
#define vp vector<pair<int, int>>
#define pb push_back
#define uns unsigned
using namespace std;
int color[9][9], dis[9][9];
void initialize();
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(mp(x, y));
    initialize();
    while (q.size() != 0) {
        pair<int, int> p = q.front();
        int i, j;
        i = p.first;
        j = p.second;
        if(i - 2 > 0 && j - 1 > 0 && color[i-2][j-1] == 0){
            q.push(make_pair(i-2, j-1));
            dis[i-2][j-1] = dis[i][j] + 1;
        }
        if(i - 2 > 0 && j + 1 <= 8 && color[i-2][j+1] == 0){
            q.push(make_pair(i-2, j+1));
            dis[i-2][j+1] = dis[i][j] + 1;
        }
        if(i - 1 > 0 && j + 2 <= 8 && color[i-1][j+2] == 0){
            q.push(make_pair(i-1, j+2));
            dis[i-1][j+2] = dis[i][j] + 1;
        }
        if(i + 1 <= 8 && j + 2 <= 8 && color[i+1][j+2] == 0){
            q.push(make_pair(i+1, j+2));
            dis[i+1][j+2] = dis[i][j] + 1;
        }
        if(i + 2 <= 8 && j + 1 <= 8 && color[i+2][j+1] == 0){
            q.push(make_pair(i+2, j+1));
            dis[i+2][j+1] = dis[i][j] + 1;
        }
        if(i + 2 <= 8 && j - 1 > 0 && color[i+2][j-1] == 0){
            q.push(make_pair(i+2, j-1));
            dis[i+2][j-1] = dis[i][j] + 1;
        }
        if(i + 1 <= 8 && j - 2 > 0 && color[i+1][j-2] == 0){
            q.push(make_pair(i+1, j-2));
            dis[i+1][j-2] = dis[i][j] + 1;
        }
        if(i - 1 > 0 && j - 2 > 0 && color[i-1][j-2] == 0){
            q.push(make_pair(i-1, j-2));
            dis[i-1][j-2] = dis[i][j] + 1;
        }
        q.pop();
        color[i][j] = 1;
    }
}
void initialize(){
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            color[i][j] = dis[i][j] = 0;
        }
    }
}
int main() {
    char sx, sy, fx, fy;
    while (cin >> sx >> sy >> fx >> fy) {
        int x, y;
        x = sx - 'a' + 1;
        y = sy - '0';
        bfs(x, y);
        cout << "To get from " << sx << sy << " to " << fx << fy << " takes " << dis[fx - 'a' + 1][fy - '0'] << " knight moves." << endl;
    }
    return 0;
}