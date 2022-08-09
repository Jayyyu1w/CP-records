#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define int long long
#define pb push_back
#define ep emplace
#define N 100
#define MXN 100
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp make_pair

using namespace std;

// 10^3 * 10
signed main(){
    io
    string s1,s2;
    int ans=0;
    cin>>s1>>s2;
    for(int i=0;i+s2.length()-1<s1.length();i++){
        bool isAns=true;
        for(int j=0;j<s2.length();j++){
            if(s1[i+j]==s2[j]){
                isAns=false;
                break;
            }
        }
        if(isAns)ans++;
    }
    cout<<ans<<"\n";
}