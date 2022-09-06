#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a1 = 0, b1 = 0, c1 = 0, a2 = 0, b2 = 0, c2 = 0;
        string u, v;
        cin >> u >> v;
        for(char c:u){
            if (c == 'A')
                a1++;
            else if (c == 'B')
                b1++;
            else if (c == 'C')
                c1++;
        }
        for(char c:v){
            if (c == 'A')
                a2++;
            else if (c == 'B')
                b2++;
            else if (c == 'C')
                c2++;
        }
        a1 &= 1, b1 &= 1, c1 &= 1, a2 &= 1, b2 &= 1, c2 &= 1;
        if (a1 == a2 && b1 == b2 && c1 == c2){  //ABC的個數奇偶性相同
            string s1, s2;
            for(char c:u){
                if(c == 'A' || c== 'C'){    //B可以忽略不計(AB可以變成BA CB可以變成BC)
                    if (s1.size() && s1.back() == c)
                        s1.pop_back();
                    else
                        s1.push_back(c);
                }
            }
            for(char c:v){
                if(c == 'A' || c== 'C'){
                    if (s2.size() && s2.back() == c)
                        s2.pop_back();
                    else
                        s2.push_back(c);
                }
            }
            s1 == s2 ? cout << "YES\n" : cout << "NO\n";
        }else{
            cout << "NO\n";
        }
    }
}