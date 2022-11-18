#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct person{
    ll l,r,p,d;
    person(){}
    person(int _l,int _r,int _p,int _d){
        l=_l;
        r=_r;
        p=_p;
        d=_d;
    }
};
signed main(){
    int t;
    ll l,r,p,d,k;
    cin>>t;
    while(t--){
        vector<person> people;
        for(int i=0;i<2;i++){
            cin>>l>>r>>p>>d;
            people.push_back(person(l,r,p,d));
        }
        cin>>k;
        ll ans=0;
        for(int i=0;i<k;i++){
            if(people[0].p==people[0].l&&people[0].d==0)people[0].d=1;
            else if(people[0].p==people[0].r&&people[0].d==1)people[0].d=0;
            if(people[0].d==1){
                people[0].p++;
            }else{
                people[0].p--;
            }
            if(people[1].p==people[1].l&&people[1].d==0)people[1].d=1;
            else if(people[1].p==people[1].r&&people[1].d==1)people[1].d=0;
            if(people[1].d==1){
                people[1].p++;
            }else{
                people[1].p--;
            }
            if(people[0].p==people[1].p)ans++;
        }
        cout<<ans<<"\n";
    }
}