#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAXN 205
#define int long long
using namespace std;

map<char,int> ch_to_int;
map<int,char> int_to_ch;
map<char,int> mp;
map<char,bool> pass;
string str;

void init(){
    for(int i=0;i<10;i++){
        ch_to_int[i+'0']=i;
        int_to_ch[i]=i+'0';
    }
    for(int i=0;i<=6;i++){
        ch_to_int[i+'A']=i+10;
        int_to_ch[i+10]=i+'A';
    }
}

bool ok(int ind){
    map<char,bool> cnt;
    for(int i=0;i<ind;i++){
        cnt[str[i]]=true;
    }
    bool yes=false;
    for(int i=ch_to_int[str[ind]]+1;i<16;i++){
        if(!cnt[int_to_ch[i]]){
            yes=true;
            break;
        }
    }
    if(yes)return true;
    else return false;
}
string find_ans(int ind){
    map<char,bool> cnt;
    string ans;
    for(int i=0;i<ind;i++){
        cnt[str[i]]=true;
        ans+=str[i];
    }
    for(int i=ch_to_int[str[ind]]+1;i<16;i++){
        if(!cnt[int_to_ch[i]]){
            ans+=int_to_ch[i];
            cnt[int_to_ch[i]]=true;
            break;
        }
    }
    int len=str.length();
    if(ind<0)len++;
    for(int i=0;i<16;i++){
        if(ans.length()==len)break;
        if(!cnt[int_to_ch[i]]){
            ans+=int_to_ch[i];
            cnt[int_to_ch[i]]=true;
        }
    }
    return ans;
}

signed main(){
    io
    int n;
    cin >> str;
    init();
    for(int i=0;i<str.length();i++){
        mp[str[i]]++;
    }
    int carry=str.length()-1;
    for(int i=0;i<str.length();i++){
        if(mp[str[i]]>1&&pass[str[i]]){
            carry=i;
            break;
        }else{
            pass[str[i]]=true;
        }
    }
    while(!ok(carry)){
        carry--;
    }
    cout<<find_ans(carry)<<"\n";
}