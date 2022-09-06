/*tree,greedy*/
#include<bits/stdc++.h>
#define MXN 100005
using namespace std;

struct treeinfo{
    int rt, sz;
    vector<int> orphan;
    treeinfo(){}
    treeinfo(int _rt,int _sz,vector<int>v){
        rt = _rt, sz = _sz, orphan = v;
    }
    friend bool operator<(const treeinfo&a,const treeinfo &b){
        return a.sz > b.sz;
    }
};
int n, teams = 0;
vector<vector<int>> edge(MXN);
vector<int> root, orphan, mainorp, tag(MXN, 0), fa(MXN);
vector<treeinfo>suborp;
void dfs(int x, int f){
    for(auto i:edge[x]){
        if(i == f)
            continue;
        dfs(i, x);
        if(tag[i]==0&&tag[x]==0){   //將未分組的兩點標記為已分組
            tag[i] = tag[x] = 1;
            teams++;
        }else if(tag[i]==0&&tag[x]==1){
            orphan.push_back(i);
        }
    }
}
void solve(){
    int v;
    cin >> n;
    root.push_back(1);
    fa[1] = 1;
    for (int i = 2; i <= n;i++){
        cin >> v;
        fa[i] = v;
        if(v==0){
            root.push_back(i);
        }else{
            edge[i].push_back(v);
            edge[v].push_back(i);
        }
    }
    for(auto it:root){
        orphan.clear();
        dfs(it, it);
        if(it==1||tag[it]){     //是主樹或其他樹的根結點有被分到組
            fa[it] = 1;
            for (auto i:orphan){    //沒被分配到的點推入主樹
                mainorp.push_back(i);
            }
            if(it==1&&!tag[it]){    //如果1還沒有被配對
                mainorp.push_back(it);
            }
        }else{      //非主樹且根結點未被分組
            suborp.push_back(treeinfo(it, orphan.size(), orphan));
        }
    }
    sort(suborp.begin(), suborp.end());     //從子樹未分配節點最大的開始指定
    for(auto it:suborp){
        if(!mainorp.empty()){   //主樹未分配節點不為空
            fa[it.rt] = mainorp.back();     //子樹根結點接至主樹未分配節點
            mainorp.pop_back();
            teams++;
        }else{      //主樹未分配節點為空
            fa[it.rt] = 1;
            mainorp.push_back(it.rt);   //子樹根結點接至1，根結點推入主樹
        }
        for(auto i:it.orphan){  //將子樹未分配節點推入主樹
            mainorp.push_back(i);
        }
    }
    cout << teams << "\n";
    for (int i = 2; i <= n;i++){
        if(i!=2)
            cout << " ";
        cout << fa[i];
    }
    cout << "\n";
}
int main(){
    /*
    freopen("hidden.in", "r", stdin);
    freopen("hidden.out", "w", stdout);
    */
    solve();
}