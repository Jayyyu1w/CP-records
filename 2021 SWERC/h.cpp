#include<bits/stdc++.h>
#define int long long
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

map<int,int>mp,mp2,mp3;
set<int>ans;

void get(int w,int l){
    for(int i=1;i<=sqrt(w);i++){
        if(w%i==0){
            mp[i]++;
            mp[w/i]++;
        }
    }
    for(int i=1;i<=sqrt(l);i++){
        if(l%i==0){
            mp2[i]++;
            mp2[l/i]++;
        }
    }
    for(auto i:mp){
        if(mp2.count(i.first))
            ans.emplace(i.first);
    }
    mp.clear();
    mp2.clear();
}
void get2(int w,int w2,int l){
    for(int i=1;i<=sqrt(w);i++){
        if(w%i==0){
            mp[i]++;
            mp[w/i]++;
        }
    }
    for(int i=1;i<=sqrt(w2);i++){
        if(w2%i==0){
            mp2[i]++;
            mp2[w2/i]++;
        }
    }
    for(int i=1;i<=sqrt(l);i++){
        if(l%i==0){
            mp3[i]++;
            mp3[l/i]++;
        }
    }
    for(auto i:mp){
        if(mp2.count(i.first)&&mp3.count(i.first))
            ans.emplace(i.first);
    }
    mp.clear();
    mp2.clear();
    mp3.clear();
}

signed main(){ 
    io
    int t;
    cin>>t;
    while(t--){
        int w,l;
        vector<int>w1,l1;
        cin>>w>>l;
        //cout << "test: w=" << w <<" l=" <<l <<"\n";
        get(w-1,l-1);
        get(w-2,l);
        get(w,l-2);
        get2(w,w-2,l-1);
        get2(l,l-2,w-1);
        cout<<ans.size();
        for(auto i:ans){
            cout<<" "<<i;
        }
        cout<<"\n";
        ans.clear();
    }
    return 0;
}