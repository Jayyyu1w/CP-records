#include <bits/stdc++.h>
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MXN 50000
#define PB push_back
#define SZ(x) (int)x.size()

using namespace::std;

int n,m;
vector<pair<int,int>> edge(MXN);
vector<int> give(MXN);

struct Dinic{
    struct Edge{ int v,f,re; };
    int n,s,t,level[MXN];
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t){
        n = _n; s = _s; t = _t;
        for (int i=0; i<n; i++) E[i].clear();
    }
    void add_edge(int u, int v, int f){
        E[u].PB({v,f,SZ(E[v])});
        E[v].PB({u,0,SZ(E[u])-1});
    }
    bool BFS(){
        for (int i=0; i<n; i++) level[i] = -1;
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while (!que.empty()){
            int u = que.front(); que.pop();
            for (auto it : E[u]){
                if (it.f > 0 && level[it.v] == -1){
                    level[it.v] = level[u]+1;
                    que.push(it.v);
                } 
            } 
        }
        return level[t] != -1;
    }
    int DFS(int u, int nf){
        if (u == t) return nf;
        int res = 0;
        for (auto &it : E[u]){
            if (it.f > 0 && level[it.v] == level[u]+1){
            int tf = DFS(it.v, min(nf,it.f));
            res += tf; nf -= tf; it.f -= tf;
            E[it.v][it.re].f += tf;
            if (nf == 0) return res;
        } }
        if (!res) level[u] = -1;
        return res;
    }
    int flow(int res=0){
        while ( BFS() )
            res += DFS(s,2147483647);
        return res;
    } 
}flow;
void input(){
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        edge[i]={a,b};
    }
}
bool check(int x){
    int source=0,sink=n+m+1;//設1~m為邊,n+1~n+m為點
    set<int> s;
    flow.init(n+m+2,source,sink);
    for(int i=1;i<=m;i++)flow.add_edge(source,i,1);
    for(int i=1;i<=m;i++){
        flow.add_edge(i,edge[i].first+m,1);
        flow.add_edge(i,edge[i].second+m,1);
        s.insert(edge[i].first);
        s.insert(edge[i].second);
    }
    for(auto num:s){
        flow.add_edge(num+m,sink,x);
    }
    int tot=flow.flow();
    if(tot==m){
        for(int i=1;i<=m;i++){
            if(flow.E[i][1].f==0) give[i]=2;
            else give[i]=1;
        }
        return true;
    }
    else return false;
}
int bs(){
    int l=0,r=5000;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    return l;
}
void print(int ans){
    cout<<ans<<"\n";
    for(int i=1;i<=m;i++){
        if(give[i]==1)
            cout<<edge[i].second<<" "<<edge[i].first<<"\n";
        else
            cout<<edge[i].first<<" "<<edge[i].second<<"\n";
    }
}
signed main(){
    io
    input();
    int ans=bs();
    print(ans);
}