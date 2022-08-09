#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n=5,i;
    string s="ABCDE";
    vector<string> rel;
    string tmp;
    for(int i=0;i<5;i++){
        cin>>tmp;
        if(tmp[1]=='<'){
            swap(tmp[0],tmp[2]);
            tmp[1]='>';
        }
        rel.push_back(tmp);
    }
    string ans;
    bool flag=0;
    do{
        bool yes = 1;
        for(i=0;i<rel.size();i++){
            auto it1 = find(s.begin(),s.end(),rel[i][0]);
            auto it2 = find(s.begin(),s.end(),rel[i][2]);
            int x = it1 - s.begin();
            int y = it2 - s.begin();
            if(x<y){
                yes = 0;
                break;
            }
        }
        if(yes){
            ans = s;
            flag = 1;
            break;
        }
    }  while (next_permutation(s.begin(),s.end()));
    if(flag){
        cout << ans <<"\n";
    }else{
        cout << "impossible\n";
    }
}



/*

a d b
b c
c e
d b

adbce
ecbda

abcde
11111
11121
31121
31221
41221
43221
#define
*/