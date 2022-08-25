#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define ep emplace
#define all(x) x.begin(),x.end()
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;

struct Pt{
    ll x,y;
    Pt(){}
    Pt(ll _x,ll _y){
        x=_x,y=_y;
    }
};

signed main(){
    io
    int n,m,x,y;
    ld ans=0;
    cin >> n;
    while(n--){
        cin >> m;
        vector<Pt> pt;
        while(m--){
            Pt p;
            cin >> p.x >> p.y;
            pt.pb(p);
        }
        
        ll sum=0;
        for(int i=0;i<pt.size();i++){
            //cout << pt[i].x <<" "<<pt[i].y<<"\n";
            sum+=pt[i].x*pt[(i+1)%pt.size()].y-pt[i].y*pt[(i+1)%pt.size()].x;
        }
        ans+=abs(sum/2.0);
    }
    cout<<(ll)floor(ans)<<"\n";
}
