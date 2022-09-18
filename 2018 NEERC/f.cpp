#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
using namespace std;

int main() {
    io
    ll n, af, tot=0, ts=0;
    string s;
    cin >> n;
    vector<int>alice,bob,non;
    for(int i=0;i<n;i++){
        cin>>s>>af;
        if(s=="11"){
            tot+=af;
            ts++;
        }else if(s=="10"){
            alice.push_back(af);
        }else if(s=="01"){
            bob.push_back(af);
        }else{
            non.push_back(af);
        }
    }
    sort(alice.begin(),alice.end(),greater<int>());
    sort(bob.begin(),bob.end(),greater<int>());
    sort(non.begin(),non.end(),greater<int>());
    int minsup = min(alice.size(), bob.size()), pick = 0;
    for (int i = 0; i < minsup; i++) {
        tot += alice[i];
        tot += bob[i];
    }
    for (int i = 0; i+pick<ts;) {
        int ali = (alice.size() == 0 || alice.size() <= minsup) ? 0 : alice[minsup];
        int bb = (bob.size() == 0 || bob.size() <= minsup) ? 0 : bob[minsup];
        if (i>=non.size() || ali > non[i] || bb > non[i]) {
            tot += max(ali,bb);                
            pick++,minsup++;
        }else{
            tot += non[i++];
        }
    }
    cout << tot << "\n";
}