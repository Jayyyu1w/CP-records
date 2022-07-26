#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define int long long
#define pb push_back
#define ep emplace
#define N 1005
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp make_pair
using namespace std;

signed main(){
    io
    int n,m,k,i,j,x,y,temp;
    cin >> n >> m;

    cin >> k;
    bitset<N>bs, init;
    for(i=0;i<k;i++){
        cin >> temp;
        bs[temp]=1;
    }
    init=bs;
    vector<bitset<N>>vec(n);
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>temp;
            vec[i][temp]=1;
        }
    }
    int sw=0;
    bool fail=false;
    while(bs.count()){
        for(int i=0;i<vec.size();i++){
            bs^=vec[i];
            sw++;
            if(bs.count()==0){
                break;
            }
            if(bs==init&&sw%n==0&&sw>=n){
                fail=true;
                break;
            }
        }
        if(fail){
            break;
        }
    }
    fail?cout<<"-1\n":cout<<sw<<"\n";
}