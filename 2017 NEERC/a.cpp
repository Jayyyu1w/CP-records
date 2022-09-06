/*greedy挑cp值最高*/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    /*
    freopen("auxiliary.in","r",stdin);    // 讀 file.in 檔
    freopen("auxiliary.out","w",stdout);  // 寫入 file.out 檔
    */

    int n;
    while(cin >> n){
        int a=n/3, ans=0;
        n%=3;
        if(n==0){
            ans=a*7;
        }else if(n==1){
            ans=(a-1)*7+4;
        }else if(n==2){
            ans=a*7+1;
        }
        cout<<ans<<"\n";
    }
}