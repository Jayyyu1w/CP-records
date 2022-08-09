#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, ai, bi;
    cin>>n;
    vector<int>a(3, 0), color(3, 0);
    for(int i=1;i<=n;i++){  //根據取的餘數分組
        cin>>ai;
        a[i%3]+=ai;
    }
    for(int i=1;i<=n;i++){
        cin>>bi;
        if(i%3==2){
            color[0]+=bi*a[1];            
            color[1]+=bi*a[2];
            color[2]+=bi*a[0];
        }else if(i%3==1){
            color[0]+=bi*a[2];
            color[1]+=bi*a[0];
            color[2]+=bi*a[1];
        }else{
            color[0]+=bi*a[0];
            color[1]+=bi*a[1];
            color[2]+=bi*a[2];
        }
    }
    cout<<color[0]<<" "<<color[1]<<" "<<color[2]<<"\n";
}