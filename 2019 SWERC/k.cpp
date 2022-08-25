#include<bits/stdc++.h>
#define MXN 100005
using namespace std;

vector<int> rootgrp(MXN, 0);
set<int> travel[MXN];
vector<vector<int>> edge(MXN);
void dfs(int x, int rt){
    if (travel[x].size() > 1 || travel[x].count(rt))  //有一條路徑以上或有環
        return;
    travel[x].emplace(rt);  //能夠走到根節點的節點記錄下來
    for(int it:edge[x]){
        dfs(it, rt);
    }
}
int main(){
    int n, m, t, u, v;
    cin >> n >> m >> t;
    vector<int> pot, ans;
    for (int i = 0; i < m;i++){
        cin >> u >> v;
        if(u==t)
            continue;
        if(v==t){
            pot.push_back(u);
            rootgrp[u] = 1;
            continue;
        }
        edge[v].push_back(u);
    }
    for(int it:pot){
        dfs(it, it);
    }
    for(int i:pot){
        if(travel[i].size()==1)
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << "\n";
    }
}