#include <bits/stdc++.h>
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace::std;

int n;
vector<vector<vector<int>>> child(2005);
vector<int> branch(2005),brn(2005);
vector<vector<int>> cnt(2005);
vector<vector<string>> cut(2005);
vector<pair<int,int>> ans;
vector<vector<pair<int,int>>> whose(2005);

void input(){
    string rel;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>rel;
        int st=0;
        for(int j=0;j<rel.length();j++){
            if(rel[j]=='-'){
                cut[i].push_back(rel.substr(st,j-st));
                st=j+1;
            }
        }
        cut[i].push_back(rel.substr(st,rel.length()-st));
    }
}
void cutStr(){
    for(int i=1;i<=n;i++){
        vector<vector<int>> tmp(cut[i].size());
        for(int j=0;j<cut[i].size();j++){
            branch[i]++;
            string sub;
            int c=0;
            for(int k=0;k<cut[i][j].length();k++){
                if(cut[i][j][k]==':'){
                    sub=cut[i][j].substr(k+1,cut[i][j].length()-k-1);
                    break;
                }
            }
            int st=0;
            for(int k=0;k<sub.length();k++){
                if(sub[k]==','){
                    tmp[j].push_back(stoi(sub.substr(st,k-st)));
                    c++;
                    whose[stoi(sub.substr(st,k-st))].push_back({i,j});
                    st=k+1;
                }
            }
            tmp[j].push_back(stoi(sub.substr(st,sub.length()-st)));
            whose[stoi(sub.substr(st,sub.length()-st))].push_back({i,j});
            c++;
            cnt[i].push_back(c);
        }
        child[i]=tmp;
    }
}
void solve(){
    brn=branch;
    for(int i=1;i<=n;i++){
        if(branch[i]==1){
            for(auto who:whose[i]){
                cnt[who.first][who.second]--;
                if(cnt[who.first][who.second]==0){
                    ans.push_back({i,who.first});
                    branch[who.first]--;
                }
            }
            branch[i]--;
            i=1;
        }
    }
}
void print(){
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}
vector<int> fa(2005);
int Find(int x){
    return fa[x]==x ? x: fa[x]=Find(fa[x]);
}
void Union(int x,int y){
    int f1=Find(x);
    int f2=Find(y);
    if(f1!=f2)fa[f2]=f1;
}
bool yes=true;
vector<vector<int>> conn(2005);
vector<bool> pass(2005,0);
void dfs(int x,int f){
    pass[x]=true;
    //cout<<x<<"\n";
    if(fa[x]!=f){
        yes=false;
        return;
    }
    for(auto num:conn[x]){
        if(!pass[num]){
            dfs(num,f);
        }
    }
}
void init(){
    for(int i=1;i<=2*n;i++){
        fa[i]=i;
        pass[i]=0;
    }
}
bool check(){
    for(int i=0;i<ans.size();i++){
        conn[ans[i].first].push_back(ans[i].second);
        conn[ans[i].second].push_back(ans[i].first);
    }
    for(int i=1;i<=n;i++){
        init();
        for(int j=0;j<child[i].size();j++){
            for(int k=0;k<child[i][j].size();k++){
                Union(j+n+1,child[i][j][k]);
            }
        }
        //for(int i=1;i<=n;i++)cout<<i<<" "<<fa[i]<<"\n";
        pass[i]=true;
        for(auto num:conn[i]){
            dfs(num,fa[num]);
            if(!yes){
                break;
            }
        }
        if(!yes)break;
    }
    if(yes){
        vector<int> connect(2005,0);
        for(int i=0;i<ans.size();i++){
            connect[ans[i].first]++;
            connect[ans[i].second]++;
        }
        for(int i=1;i<=n;i++){
            if(brn[i]!=connect[i]){
                yes=false;
                break;
            }
        }
    }
    if(yes)return true;
    else return false;
}
signed main(){
    io
    input();
    cutStr();
    solve();
    if(check())print();
    else cout<<"-1\n";
}