#include<bits/stdc++.h>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define int long long
#define MXN 1e5+5
using namespace std;

int ti = 0, lgN;
vector<int> dist(MXN), fa(MXN), uni(MXN), dep(MXN);
vector<pair<int, int>> startend(MXN);
vector<vector<int>> anc(MXN, vector<int>(__lg((int)MXN) + 5, 0));
vector<vector<pair<int, int>>> edge(MXN);
void init(int n){
    for (int i = 0; i <= n + 1;i++){
        startend[i] = {0, 0};
        uni[i] = i;
        dist[i] = 0;
        dep[i] = 0;
        edge[i].clear();
    }
}
void dfs(int x,int f, int deep){
    fa[x] = f;
    startend[x].first = ti++;
    dep[x] = deep;
    for(auto it:edge[x]){
        if(it.first == f)
            continue;
        dist[it.first] = dist[x] + it.second;
        dfs(it.first, x, deep + 1);
    }
    startend[x].second = ti++;
}
bool isanc(int u,int v){
    return startend[u].first <= startend[v].first && startend[u].second >= startend[v].second;
}
int lca(int u, int v){
    if (dep[u] < dep[v])
        swap(u, v);
    if (isanc(u, v))
        return u;
    if(isanc(v, u))
        return v;
    for (int i = lgN; i >= 0;i--){
        if(!isanc(anc[u][i], v)){
            u = anc[u][i];
        }
    }
    return anc[u][0];
}
int dis(int u, int v){
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}
int find(int x){
    return uni[x] == x ? x : uni[x] = find(uni[x]);
}
bool merge(int u,int v){
    int p = find(u);
    int q = find(v);
    if(p != q){
        uni[q] = p;
        return 1;
    }
    return 0;
}
signed main(){
    io
    int t;
    cin >> t;
    while(t--){
        int n, q, u, v, w;
        cin >> n >> q;
        ti = 0;
        lgN = __lg(n) + 1;
        init(n);
        int cycle = -1;
        array<int, 3> rmv;
        for (int i = 0; i < n;i++){
            cin >> u >> v >> w;
            if(!merge(u, v)){
                rmv = {u, v, w};
            }else{
                edge[u].push_back(make_pair(v, w));
                edge[v].push_back(make_pair(u, w));
            }
        }
        dfs(1, 1, 0);
        for (int i = 1; i <= n;i++){
            anc[i][0] = fa[i];
        }
        for (int i = 1; i <= lgN;i++){
            for (int j = 1; j <= n;j++){
                anc[j][i] = anc[anc[j][i - 1]][i - 1];
            }
        }
        
        while(q--){     //判斷是否需要用拔掉的邊才能取到最小值
            int x, y, ans;
            cin >> x >> y;
            ans = dis(x, y);
            //x到拔掉邊的u,y到拔掉邊的v,加上拔掉邊的邊權
            ans = min(ans, dis(x, rmv.at(0)) + dis(y, rmv.at(1)) + rmv.at(2));
            //x到拔掉邊的v,y到拔掉邊的u,加上拔掉邊的邊權
            ans = min(ans, dis(x, rmv.at(1)) + dis(y, rmv.at(0)) + rmv.at(2));
            cout << ans << "\n";
        }
    }
}