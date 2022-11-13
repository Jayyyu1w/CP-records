#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<string,int> mp;

void init(){
    //box1
    mp["Alice"]=0;
    mp["Ariel"]=0;
    mp["Aurora"]=0;
    mp["Phil"]=0;
    mp["Peter"]=0;
    mp["Olaf"]=0;
    mp["Phoebus"]=0;
    mp["Ralph"]=0;
    mp["Robin"]=0;
    //box2
    mp["Bambi"]=1;
    mp["Belle"]=1;
    mp["Bolt"]=1;
    mp["Mulan"]=1;
    mp["Mowgli"]=1;
    mp["Mickey"]=1;
    mp["Silver"]=1;
    mp["Simba"]=1;
    mp["Stitch"]=1;
    //box3
    mp["Dumbo"]=2;
    mp["Genie"]=2;
    mp["Jiminy"]=2;
    mp["Kuzko"]=2;
    mp["Kida"]=2;
    mp["Kenai"]=2;
    mp["Tarzan"]=2;
    mp["Tiana"]=2;
    mp["Winnie"]=2;
}
int main(){
    init();
    int n;
    ll ans=0;
    vector<string> strs;
    cin>>n;
    string s;
    int now=0;
    for(int i=0;i<n;i++){
        cin>>s;
        ans+=abs(mp[s]-now);
        now=mp[s];
    }
    cout<<ans<<"\n";
}