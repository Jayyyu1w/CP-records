#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

ll FASTpow(ll x,ll y){
    ll ans =1;
    while(y){
        if(y&1)ans=ans*x;
        x=x*x;
        y>>=1;
    }
    return ans;
}

signed main(){
    /*
    freopen("boolean.in","r",stdin);    // 讀 file.in 檔
    freopen("boolean.out","w",stdout);  // 寫入 file.out 檔
    */
    string str;
    cin >> str;
    map<char,int> T,F,ch;
    int cnt=0;
    bool True=false;
    for(int i=0;i<str.size();i++){
        if(str[i]=='|')continue;
        else if(str[i]=='~'){
            i++;
            if(!ch[str[i]])
                cnt++;
            F[str[i]]++;
            ch[str[i]]++;
            if(F[str[i]]&&T[str[i]])
                True=true;
        }else{
            if(!ch[str[i]])
                cnt++;
            T[str[i]]++;
            ch[str[i]]++;
            if(F[str[i]]&&T[str[i]])
                True=true;
        }
    }
    if(True)
        cout<<FASTpow(2,cnt)<<"\n";
    else
        cout<<FASTpow(2,cnt)-1<<"\n";
}