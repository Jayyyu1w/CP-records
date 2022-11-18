#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int fail = 0;
        string s1,s2;
        cin>>s1>>s2;
        int n = s1.size();
        for(int i=0;i<s1.size();i++){
            if(s1[i] == s2[i] || s1[i] == s2[n-1-i]){
                continue;
            }else{
                fail = 1;
                break;
            }
        }
        if(!fail){
            int sw = 0, ans = 0;
            for(int i=0;i<s1.size()/2;i++){
                if(!sw){
                    if(s1[i]!=s2[i]){
                        ans++;
                        sw ^= 1;
                    }
                }else{
                    if(s1[i]!=s2[n-1-i]){
                        ans++;
                        sw^=1;
                    }
                }
            }
            cout<<ans<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
}