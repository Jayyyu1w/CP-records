/*最短路+背包*/
#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX_V 15005
#define INF 0x7f7f7f7f
#define int long long
using namespace std;

struct Edge {
    int idx, w, v;
};
bool operator>(const Edge& a, const Edge& b) {
    return a.w > b.w;
}
pair<int, int> dist[MAX_V];
vector<vector<Edge> > adj(MAX_V);
map<string, int>pizzaid;
void dijkstra(int vn, int s) {
    vector <bool> vis(vn, false);
    fill(dist, dist + vn, make_pair(INF, INF));
    dist[s] = { 0,0 };
    priority_queue <Edge, vector<Edge>, greater<Edge> > pq;
    Edge node;
    node.idx = s; node.w = 0; node.v = 0;
    pq.emplace(node);
    while (!pq.empty()) {
        int u = pq.top().idx;
        pq.pop();
        if (vis[u])continue;
        vis[u] = true;
        for (auto v : adj[u]) {
            if (dist[v.idx].first > dist[u].first + v.w) {
                dist[v.idx].first = dist[u].first + v.w;
                dist[v.idx].second = dist[u].second + v.v;
                node.w = dist[v.idx].first;
                node.idx = v.idx;
                node.v = v.v;
                pq.emplace(node);
            }
            else if (dist[v.idx].first == dist[u].first + v.w) {
                if (dist[v.idx].second < dist[u].second + v.v) {
                    dist[v.idx].second = dist[u].second + v.v;
                    node.w = dist[v.idx].first;
                    node.idx = v.idx;
                    node.v = v.v;
                    pq.emplace(node);
                }
            }
        }
    }
}
struct pizza {
    int weight, val;
    string name, base, ingred;
    pizza() {}
    pizza(string _name, string _base, string _ingred, int _weight, int _val) {
        name = _name, base = _base, ingred = _ingred, weight = _weight, val = _val;
    }
};
struct cp {
    int weight, val;
    cp() {}
    cp(int _weight, int _val) {
        weight = _weight, val = _val;
    }
};
signed main() {
    io
    int b, n, a1, a2, idx = 0;
    string s1, s2, s3;
    cin >> b >> n;
    pizzaid["pizza_base"] = idx++;
    vector<pizza>recipe(n);
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> s3 >> a1 >> a2;
        recipe[i] = pizza(s1, s2, s3, a1, a2);
        if (!pizzaid[s1])
            pizzaid[s1] = idx++;
    }
    for (auto it : recipe) {    //基底到比薩建邊
        adj[pizzaid[it.base]].push_back({ pizzaid[it.name],it.weight,it.val });
    }
    dijkstra(idx, 0);
    vector<int>dp(b + 1, 0), heavy(b + 1, 0);
    for (int i = 1; i < idx; i++) {
        for (int j = b; j >= dist[i].first; j--) {
            if (dp[j] < dp[j - dist[i].first] + dist[i].second) {
                dp[j] = dp[j - dist[i].first] + dist[i].second;
                heavy[j] = heavy[j - dist[i].first] + dist[i].first;
            }
        }
    }
    cout << dp[b] << "\n" << heavy[b] << "\n";
}