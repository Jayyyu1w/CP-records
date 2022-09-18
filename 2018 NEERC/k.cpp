#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,k,sum=0;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    if(k > n || sum%k != 0){
        cout<<"No\n";
    }else{
        int lim=sum/k,tmp=0;
        vector<int>pos;
        pos.push_back(0);
        for(int i=0;i<n;i++){
            tmp+=v[i];
            if(tmp>=lim){
                tmp=0;
                pos.push_back(i+1);
            }
        }
        if(pos.size()-1!=k){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
            for(int i=1;i<pos.size();i++){
                if(i!=1)cout<<" ";
                cout<<pos[i]-pos[i-1];
            }
            cout<<"\n";
        }
    }
}