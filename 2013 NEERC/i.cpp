#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAXN 205
using namespace std;

signed main(){
    io
    int n,i,j,x,y,k;
    vector<set<int>> st(MAXN);
    cin >> n;
    int intersect[MAXN][MAXN]={};
    for(i=0;i<n*(n-1)/2;i++){
        cin >> x >> y >> k;
        intersect[x][y]=k;
        intersect[y][x]=k;
        for(j=1;j<=k;j++){
            int temp;
            cin >> temp;
            st[x].insert(temp);
            st[y].insert(temp);
        }
    }
    bool fail=false;
    for(int x=1;x<=n-1;x++){
        for(int y=x+1;y<=n;y++){
            set<int> s;
            set_intersection(st[x].begin(),st[x].end(),st[y].begin(),st[y].end(),inserter(s,s.begin()));
            if(s.size()!=intersect[x][y]){
                fail=true;
                break;
            }
        }
        if(fail)break;
    }
    // output
    if(!fail){
        cout << "Yes\n";
        for(i=1;i<=n;i++){
            cout << st[i].size() <<" ";
            for(auto out:st[i]){
                cout << out <<" ";
            }cout << "\n";
        }
    }
    else{
        cout << "No\n";
    }
}