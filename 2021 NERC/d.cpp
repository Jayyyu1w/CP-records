#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define ld long double
#define MAXN 1000005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define cl(x) (x*2)
#define cr(x) (x*2+1)
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main(){
    io
    int n;
    cin>>n;
    string s1,s2;
    while(n--){
        cin>>s1>>s2;
        map<char,int> exist;
        for(int i=0;i<s2.length();i++){
            exist[s2[i]]++;
        }
        string ans;
        for(int i=s1.length()-1;i>=0;i--){
            if(exist[s1[i]]>0){
                ans+=s1[i];
                exist[s1[i]]--;
            }
        }
        //cout<<ans<<"\n";
        reverse(ans.begin(),ans.end());
        if(ans==s2)cout<<"YES\n";
        else cout<<"NO\n";
    }
}