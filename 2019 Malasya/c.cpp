#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct puzzles{
    ll f, t;
    puzzles(){}
    puzzles(ll _f, ll _t){
        f=_f,t=_t;
    }
};
int main(){
    ll d, cas=1;
    cin>>d;
    while(d--){
        ll n,s;
        cin>>n>>s;
        vector<puzzles>v;
        for(int i=0;i<n;i++){
            ll f,t;
            cin>>f>>t;
            v.push_back(puzzles(f,t));
        }
        ll happiness=INT_MIN;
        for(int i=0;i<n;i++){
            if(v[i].t>s)
                happiness=max(happiness,v[i].f-(v[i].t-s));
            else
                happiness=max(happiness,v[i].f);
        }
        cout<<"Case #"<<cas<<": "<<happiness<<"\n";
        cas++;
    }
}