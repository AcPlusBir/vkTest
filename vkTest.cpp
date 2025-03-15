#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("graph.txt");
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int> > g;
    g.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int s;
    cin >> s;

    queue<int> q;
    vector<int> ans(n, -1);
    q.push(s);
    ans[s] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto to: g[v]) {
            if (ans[to] == -1) {
                ans[to] = ans[v] + 1;
                q.push(to);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
