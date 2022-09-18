#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
using namespace std;

map<string,string> tar;
map<string,ll> cnt;

int main() {
    io
    int n;
    string str;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>str;
        map<string,int> check;
        for(int i=1;i<=str.length();i++){
            for(int j=0;j+i-1<str.length();j++){
                //cerr<<str.substr(j,i)<<"\n";
                if(!check.count(str.substr(j,i))){
                    cnt[str.substr(j,i)]++;
                    tar[str.substr(j,i)]=str;
                    check[str.substr(j,i)]=1;
                }
            }
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>str;
        if(cnt.count(str)){
            cout<<cnt[str]<<" "<<tar[str]<<"\n";
        }else{
            cout<<"0 -\n";
        }
    }
}