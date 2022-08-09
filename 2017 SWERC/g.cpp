/*KM*/
#include <bits/stdc++.h>
#define ll long long
#define MXN 2005
#define INF 0x3f3f3f3f
using namespace std;

struct KM { // max weight, for min negate the weights
    int n, mx[MXN], my[MXN], pa[MXN];
    ll g[MXN][MXN], lx[MXN], ly[MXN], sy[MXN];
    bool vx[MXN], vy[MXN];
    void init(int _n) { // 1-based, N個節點
        n = _n;
        for (int i = 1; i <= n; i++)
            fill(g[i], g[i] + n + 1, 0);
    }
    void addEdge(int x, int y, ll w) { g[x][y] = w; } //左邊的集合節點x連邊右邊集合節點y權重為w
    void augment(int y) {
        for (int x, z; y; y = z)
            x = pa[y], z = mx[x], my[y] = x, mx[x] = y;
    }
    void bfs(int st) {
        for (int i = 1; i <= n; ++i)
            sy[i] = INF, vx[i] = vy[i] = 0;
        queue<int> q;
        q.push(st);
        for (;;) {
            while (q.size()) {
                int x = q.front();
                q.pop();
                vx[x] = 1;
                for (int y = 1; y <= n; ++y)
                    if (!vy[y]) {
                        ll t = lx[x] + ly[y] - g[x][y];
                        if (t == 0) {
                            pa[y] = x;
                            if (!my[y]) {
                                augment(y);
                                return;
                            }
                            vy[y] = 1, q.push(my[y]);
                        }
                        else if (sy[y] > t)
                            pa[y] = x, sy[y] = t;
                    }
            }
            ll cut = INF;
            for (int y = 1; y <= n; ++y)
                if (!vy[y] && cut > sy[y])
                    cut = sy[y];
            for (int j = 1; j <= n; ++j) {
                if (vx[j])
                    lx[j] -= cut;
                if (vy[j])
                    ly[j] += cut;
                else
                    sy[j] -= cut;
            }
            for (int y = 1; y <= n; ++y)
                if (!vy[y] && sy[y] == 0) {
                    if (!my[y]) {
                        augment(y);
                        return;
                    }
                    vy[y] = 1, q.push(my[y]);
                }
        }
    }
    ll solve() { // 回傳值為完美匹配下的最大總權重
        fill(mx, mx + n + 1, 0); fill(my, my + n + 1, 0);
        fill(ly, ly + n + 1, 0); fill(lx, lx + n + 1, -INF);
        for (int x = 1; x <= n; ++x) for (int y = 1; y <= n; ++y)
            lx[x] = max(lx[x], g[x][y]);
        for (int x = 1; x <= n; ++x) bfs(x);
        ll ans = 0;
        for (int y = 1; y <= n; ++y) ans += g[my[y]][y];
        return ans;
    }
}graph;
int dist(pair<int, int>a, pair<int, int>b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
void solve() {
    int n, m;
    cin >> n >> m;
    graph.init(m + n - 1);
    vector<pair<int, int>> wines(n + 1), courier(m + 1);
    pair<int, int> restaurant;
    for (int i = 1; i <= n; i++) {
        cin >> wines[i].first >> wines[i].second;
    }
    for (int i = 1; i <= m; i++) {
        cin >> courier[i].first >> courier[i].second;
    }
    cin >> restaurant.first >> restaurant.second;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            graph.addEdge(i, j, (-1) * (dist(courier[i], wines[j]) + dist(restaurant, wines[j])));
        }
    }
    for (int i = 1; i <= n - 1;i++){    //建n-1個餐廳到酒的邊(因為至少有一個得為送貨員至餐聽)
        for (int j = 1; j <= n; j++){
            graph.addEdge(m + i, j, (-2) * (dist(restaurant, wines[j])));
        }
    }
    ll ans = graph.solve();
    ans *= (-1);
    cout << ans << "\n";
}
int main() {
    solve();
}