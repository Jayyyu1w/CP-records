#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
    freopen("kotlin.in","r",stdin);    // 讀 file.in 檔
    freopen("kotlin.out","w",stdout);  // 寫入 file.out 檔
    */
    int h,w,n,ans_h,ans_w;
    bool hasAns=false;
    cin>>h>>w>>n;
    vector<vector<char>> mp(h,vector<char>(w,'.'));
    for(int i=1;i<=n;i++){
        if(n%i==0){
            int j=n/i;
            if(i<=h-(h/2)&&j<=w-(w/2)){
                ans_h=i;
                ans_w=j;
                hasAns=true;
                break;
            }
        }
    }
    //cout<<ans_h<<" "<<ans_w<<"\n";
    if(hasAns){
        int cur_i=1,cur_j=1;
        for(int i=0;i<ans_h-1;i++){
            for(int j=0;j<w;j++){
                mp[cur_i][j]='#';
            }
            cur_i+=2;
        }
        for(int i=0;i<ans_w-1;i++){
            for(int j=0;j<h;j++){
                mp[j][cur_j]='#';
            }
            cur_j+=2;
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cout<<mp[i][j];
            }
            cout<<"\n";
        }
    }else{
        cout<<"Impossible\n";
    }
}
