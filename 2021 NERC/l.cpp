#include<bits/stdc++.h>
#define MXN 200005
using namespace std;

vector<vector<int>> edge(MXN);
int rt[MXN], fa[MXN], t, nt, fin = 0;
void dfs(int x){
    for(auto it:edge[x]){
        if(rt[it] == 0){  //沒跑過
            rt[it] = rt[x];
            fa[it] = x;
            dfs(it);
            if(fin)
                return;
        }else if (rt[it] != rt[x]){ //不同子樹走到同一點就是答案
            nt = x;
            t = it;
            fin = 1;
            return;
        }
    }
}
int main(){
    int n, m, s, u, v;
    cin >> n >> m >> s;
    memset(rt, 0, sizeof(rt));
    memset(fa, 0, sizeof(fa));
    for (int i = 0; i < m;i++){
        cin >> u >> v;
        if(u == s){  //起點連到的每棵子樹
            rt[v] = v;
            fa[v] = u;
        }
        if(v != s)  //連到起點一律不考慮
            edge[u].push_back(v);
    }
    for(auto it:edge[s]){
        dfs(it);
    }
    if(fin){
        vector<int> path1, path2;
        path1.push_back(t);
        for (int i = nt; i;i=fa[i]){    //回朔回起點
            path1.push_back(i);
        }
        for (int i = t; i;i=fa[i]){     //回朔回起點
            path2.push_back(i);
        }
        reverse(path1.begin(), path1.end());
        reverse(path2.begin(), path2.end());
        cout << "Possible\n" << path1.size() << "\n";
        for(auto i:path1){
            cout << i << " ";
        }
        cout << "\n" << path2.size() << "\n";
        for(auto i:path2){
            cout << i << " ";
        }
    }else{
        cout << "Impossible\n";
    }
}