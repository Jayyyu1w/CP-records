#include <bits/stdc++.h>
#define MAX_V 1010
#define INF 0x3f3f3f3f
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, b, car;
vector<int>veh;
vector<vector<pair<int, int>>>tostat;
vector<pair<int, int>>sta;
struct Edge {
    Edge() {}
    Edge(int _idx, int _w, int _w2) {
        idx = _idx, w = _w, w2 = _w2;
    }
    int idx, w, w2;
};
bool operator<(const Edge& a, const Edge& b) {
    if(a.w==b.w)return a.w2 > b.w2;
    return a.w > b.w;
}
int diss(int x, int y) {
    return (int)ceil(sqrt(x * x + y * y));
}
int dist[105][MAX_V];
vector<vector<Edge> > adj(MAX_V);
void dijkstra(int s) {
    vector <vector<bool>> vis(105, vector<bool>(MAX_V, false));
    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < MAX_V; j++) {
            dist[i][j] = INF;
        }
    }
    dist[0][s] = 0;
    priority_queue <Edge> pq;
    Edge node;
    node.idx = s; node.w = 0; node.w2 = 0;
    pq.emplace(node);
    while (!pq.empty()) {
        Edge u = pq.top(); pq.pop();
        if (vis[u.w2][u.idx])continue;
        vis[u.w2][u.idx] = true;
        for (auto v : adj[u.idx]) {
            if ((u.w2 + v.w2) <= b && !vis[u.w2+v.w2][v.idx] && (dist[u.w2 + v.w2][v.idx] > (dist[u.w2][u.idx] + v.w))) { 
                dist[u.w2 + v.w2][v.idx] = dist[u.w2][u.idx] + v.w;
                node.w = dist[u.w2 + v.w2][v.idx];
                node.w2 = u.w2 + v.w2;
                node.idx = v.idx;
                pq.emplace(node);
            }
        }
    }
}
signed main() {
    io;
    int t, cost, stat, x, y, l, to, mode;
    pair<int, int>st, ed;
    cin >> st.first >> st.second;
    cin >> ed.first >> ed.second;
    cin >> b >> car >> t;
    veh.resize(t + 1);
    for (int i = 1; i <= t; i++) {
        cin >> veh[i];
    }
    cin >> stat;
    tostat.resize(stat + 1);
    sta.resize(stat + 1);
    for (int i = 1; i <= stat; i++) {
        cin >> sta[i].first >> sta[i].second >> l;
        for (int j = 0; j < l; j++) {
            cin >> to >> mode;
            tostat[i].push_back(make_pair(to + 1, mode));
        }
    }
    adj[0].push_back(Edge(stat + 1, diss(st.first - ed.first, st.second - ed.second) * car, diss(st.first - ed.first, st.second - ed.second)));
    /*要推入雙向邊才對QQ*/
    for (int i = 1; i <= stat; i++) {
        adj[0].push_back(Edge(i, diss(st.first - sta[i].first, st.second - sta[i].second) * car, diss(st.first - sta[i].first, st.second - sta[i].second)));
        adj[i].push_back(Edge(0, diss(st.first - sta[i].first, st.second - sta[i].second) * car, diss(st.first - sta[i].first, st.second - sta[i].second)));
        adj[i].push_back(Edge(stat + 1, diss(sta[i].first - ed.first, sta[i].second - ed.second) * car, diss(sta[i].first - ed.first, sta[i].second - ed.second)));
        adj[stat+1].push_back(Edge(i, diss(sta[i].first - ed.first, sta[i].second - ed.second) * car, diss(sta[i].first - ed.first, sta[i].second - ed.second)));
        for (auto it : tostat[i]) {
            adj[i].push_back(Edge(it.first, diss(sta[i].first - sta[it.first].first, sta[i].second - sta[it.first].second) * veh[it.second], diss(sta[i].first - sta[it.first].first, sta[i].second - sta[it.first].second)));
            adj[it.first].push_back(Edge(i, diss(sta[i].first - sta[it.first].first, sta[i].second - sta[it.first].second) * veh[it.second], diss(sta[i].first - sta[it.first].first, sta[i].second - sta[it.first].second)));
        }
    }
    dijkstra(0);
    int ans = INF;
    for (int i = 0; i <= b; i++) {
        ans = min(ans, dist[i][stat + 1]);
    }
    if(ans==INF)
        cout<<"-1\n";
    else
        cout << ans << "\n";
}