// задача: Обнаружение вирусов (10034)

#include <bits/stdc++.h>
#define see(x) cerr<<#x<<"="<<x<<endl;

using namespace std;

const int N = 3*1e5 + 10;

int n, m, v, used[N], color[N], col, ans[N], mx[N];
vector <int> g[N], gt[N], cond[N], top;

void scc1 (int v) {
	used[v] = 1;

	for (auto i: g[v])
		if (!used[i]) scc1(i);

	top.push_back(v);
}

void scc2 (int v, int c) {
	color[v] = c;

	for (auto i: gt[v])
		if (!color[i]) scc2(i, c);
}

void dfs1 (int v) {
	mx[v] = 0;
	for (auto i: cond[v])
		if (mx[i] != -1) mx[v] = max(mx[v], mx[i] + 1);
		else {
			dfs1(i);
			mx[v] = max(mx[v], mx[i] + 1);
		}
}

void dfs2 (int v) {
	used[v] = 1;
	ans[v] = n - mx[v];
	for (auto i: cond[v])
		if (!used[i] and mx[i] + 1 == mx[v])
			dfs2(i);
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> v;

// cтроим граф и транспортированный граф
    
    while (v --) {
    	int a, b;
    	char c;
    	cin >> a >> c >> b;
    	if (c == '<') {
    		g[a].push_back(b);
    		gt[b].push_back(a);
    	}
    	if (c == '>') {
    		g[b].push_back(a);
    		gt[a].push_back(b);
    	}
    	if (c == '=') {
    		g[a].push_back(b);
    		g[b].push_back(a);
    		gt[a].push_back(b);
    		gt[b].push_back(a);
    	}
    }

// ищем компоненты сильной связности и каждую из них красим в разные цвета

    for (int i = 1; i <= m; ++ i)
    	if (!used[i]) scc1(i);

    for (int i = m-1; i >= 0; -- i)
    	if (!color[top[i]]) scc2(top[i], ++ col);

// конденсируем граф

    for (int i = 1; i <= m; ++ i)
    	for (auto j: g[i])
    		if (color[i] != color[j])
    			cond[color[i]].push_back(color[j]);

// для каждой компоненты находим путь максимальной длины, начинающийся из неё

    for (int i = 1; i <= col; ++ i) mx[i] = -1, used[i] = 0;

    for (int i = 1; i <= col; ++ i)
    	if (mx[i] == -1) {
    		dfs1(i);
    		if (mx[i] == n - 1) dfs2(i);
    	}

    for (int i = 1; i <= m; ++ i)
    	if (ans[color[i]]) cout << "K" << ans[color[i]] << "\n";
    	else cout << "?\n";

    return 0;
}