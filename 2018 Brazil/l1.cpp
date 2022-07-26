/*L. Subway Lines 樹鏈剖分 or LCA*/
/*LCA版*/
#include<bits/stdc++.h>
#define MXN 250005
using namespace std;

int n, q, lgN, ti = 0;
int tin[MXN], tout[MXN], fa[MXN];
int dis[MXN];
vector<vector<int>> edge(MXN), anc(MXN, vector<int>(__lg(MXN), 0));
void dfs(int x,int f,int d){
    fa[x] = f;
    tin[x] = ti++;
    dis[x] = d;
    for(auto i:edge[x]){
        if(i==f)
            continue;
        dfs(i, x, d + 1);
    }
    tout[x] = ti++;
}
bool isanc(int u,int v){
    return tin[u] < tin[v] && tout[u] > tout[v];
}
int getlca(int u,int v){
    if(isanc(u,v))
        return u;
    if(isanc(v,u))
        return v;
    for (int i = lgN; i >= 0;i--){
        if(!isanc(anc[u][i],v))
            u = anc[u][i];
    }
    return anc[u][0];
}
int dist(int u,int v){
    return dis[u] + dis[v] - 2 * dis[getlca(u, v)];
}
void solve(){
    int u, v, a, b, c, d;
    cin >> n >> q;
    lgN = __lg(n);
    for (int i = 0; i < n - 1;i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
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
    while(q--){
        cin >> a >> b >> c >> d;
        int x = dist(a, b) + dist(c, d);
        int y = min(dist(a, c) + dist(b, d), dist(a, d) + dist(b, c));
        if(y>x)
            cout << "0\n";
        else
            cout << (x - y) / 2 + 1 << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}