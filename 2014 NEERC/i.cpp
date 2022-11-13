#include<bits/stdc++.h>
using namespace std;

int re(char c){
    if(c == 'F'){
        return 1;
    }else if(c=='R'){
        return 2;
    }else if(c == 'L'){
        return 3;
    }
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    queue<int>q1,q2;
    for(auto c:s1){
        q1.push(re(c));
    }
    for(auto c:s2){
        q2.push(re(c));
    }
    int ans = 0;
    while(!q1.empty() || !q2.empty()){
        if(q1.front() == q2.front() || (q1.front() == 1 && q2.front() == 2) || (q1.front() == 2 && q2.front() == 1)){
            q1.pop();
            q2.pop();
        }else{
            if(!q1.empty()&&!q2.empty()){
                if(q1.front() == 1 || (q1.front() == 2 && q2.front() == 3)){
                    q1.pop();
                }else if(q2.front() == 1 || (q1.front() == 3 && q2.front() == 2)){
                    q2.pop();
                }
            }else{
                if(q1.empty()){
                    q2.pop();
                }else{
                    q1.pop();
                }
            }
        }
        ans++;
    }
    cout<<ans<<"\n";
}