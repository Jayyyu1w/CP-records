#include<bits/stdc++.h>
#define N 10000
#define ll long long
#define pb push_back
#define ep emplace
#define mp make_pair
//#define int long long
using namespace std;

signed main(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    bool car=false;
    char ans='.';
    for(int i=0;i<10;i++){
        if(car&&s1[i]!='.'){
            ans=s1[i];
            break;
        }
        if(s1[i]=='='){
            car=true;
        }
    }
    car=false;
    for(int i=0;i<10;i++){
        if(car&&s2[i]!='.'){
            ans=s2[i];
            break;
        }
        if(s2[i]=='='){
            car=true;
        }
    }
    car=false;
    for(int i=0;i<10;i++){
        if(car&&s3[i]!='.'){
            ans=s3[i];
            break;
        }
        if(s3[i]=='='){
            car=true;
        }
    }
    if(ans=='.')cout<<"You shall pass!!!\n";
    else cout<<ans<<"\n";
}