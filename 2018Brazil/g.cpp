#include <bits/stdc++.h>
#define MXN 1000005
#define SZ(x) x.size()
#define PB push_back
using namespace std;

struct Dinic{
    struct Edge{
        int v, f, re;
    };
    int n, s, t, level[MXN];
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t){
        n = _n;
        s = _s;
        t = _t;
        for (int i = 0; i < n; i++)
            E[i].clear();
    }
    void add_edge(int u, int v, int f){
        Edge e;
        e.v = v, e.f = f, e.re = SZ(E[v]);
        E[u].PB(e);
        e.v = u, e.f = 0, e.re = SZ(E[u]) - 1;
        E[v].PB(e);
    }
    bool BFS(){
        for (int i = 0; i < n; i++)
            level[i] = -1;
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while (!que.empty()){
            int u = que.front();
            que.pop();
            for (auto it : E[u]){
                if (it.f > 0 && level[it.v] == -1){
                    level[it.v] = level[u] + 1;
                    que.push(it.v);
                }
            }
        }
        return level[t] != -1;
    }
    int DFS(int u, int nf){
        if (u == t)
            return nf;
        int res = 0;
        for (auto &it : E[u]){
            if (it.f > 0 && level[it.v] == level[u] + 1){
                int tf = DFS(it.v, min(nf, it.f));
                res += tf;
                nf -= tf;
                it.f -= tf;
                E[it.v][it.re].f += tf;
                if (nf == 0)
                    return res;
            }
        }
        if (!res)
            level[u] = -1;
        return res;
    }
    int flow(int res = 0){
        while (BFS())
            res += DFS(s, 2147483647);
        return res;
    }
} flow;
struct edg{
    int u, v, t;
};

int main(){
    int p, r, c, u, v, t, maxt = 0, totgas = 0;
    cin >> p >> r >> c;
    vector<int> gas(p), refine(r);
    vector<edg> e;
    for (int i = 0; i < p;i++){
        cin >> gas[i];
        totgas += gas[i];
    }
    for (int i = 0; i < r;i++){
        cin >> refine[i];
    }
    for (int i = 0; i < c;i++){
        cin >> u >> v >> t;
        edg a;
        u--, v--;
        a.u = u, a.v = p + v, a.t = t;
        e.push_back(a);
        maxt = max(maxt, t);
    }
    int lef = 1, rig = maxt, mid;
    while(lef<rig){
        flow.init(p + r + 2, p + r, p + r + 1);
        mid = (lef + rig) >> 1;
        for (int i = 0; i < p;i++){
            flow.add_edge(p + r, i, gas[i]);
        }
        for (int i = p; i < p + r;i++){
            flow.add_edge(i, p + r + 1, refine[i - p]);
        }
        for (int i = 0; i < c;i++){
            if(e[i].t<=mid){
                flow.add_edge(e[i].u, e[i].v, refine[e[i].v - p]);
            }
        }
        if(flow.flow()>=totgas)
            rig = mid;
        else
            lef = mid + 1;
    }
    flow.init(p + r + 2, p + r, p + r + 1);
    mid = (lef + rig) >> 1;
    for (int i = 0; i < p;i++){
        flow.add_edge(p + r, i, gas[i]);
    }
    for (int i = p; i < p + r;i++){
        flow.add_edge(i, p + r + 1, refine[i - p]);
    }
    for (int i = 0; i < c;i++){
        if(e[i].t<=mid){
            flow.add_edge(e[i].u, e[i].v, refine[e[i].v - p]);
        }
    }
    if(flow.flow()>=totgas)
        rig = mid;
    else
        lef = mid + 1;
    if(lef>rig)
        cout << "-1\n";
    else
        cout << rig << "\n";
}