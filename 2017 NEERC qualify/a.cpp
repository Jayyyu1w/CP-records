#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main(){
    io    
    int n, l, r;
    cin >> n;
    vector<pair<int,int>>v(n+1);
    vector<int>head, lonely;
    for(int i=1;i<=n;i++){
        cin>>l>>r;
        if(l==0)head.push_back(i);
        v[i].first = l,v[i].second=r;
    }
    while(head.size() > 1){
        int i;
        for(i=head.back();v[i].second != 0;i = v[i].second){
            //cout<<v[i].second<<"\n";
        }
        //cout<<i<<"\n";
        int h = head.back();
        head.pop_back();
        v[head.back()].first=i;
        v[i].second=head.back();
        head.pop_back();
        head.push_back(h);
    }
    
    for(int i=1;i<=n;i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}