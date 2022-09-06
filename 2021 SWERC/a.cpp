#include <bits/stdc++.h>
#define MAX_V 1010
#define MAXN 105
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define ep emplace
#define all(x) x.begin(),x.end()
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

#define int long long

using namespace std;
signed main() {
    io
    int t;
    cin >> t;
    while(t--){
        int n;
        int a,b;
        cin >> n;
        vector<int> score[MAXN];
        map<int,int> yep;
        int times = 0,sum=0;
        // input
        while(n--){
            cin >> a >> b;
            score[b].pb(a);
            yep[b]++;
            times++;
        }

        //test
        bool MOREPROBLEMS = 0;
        for(int i=1;i<=10;i++){ // yep[1]~yep[10] >= 1
            if(!yep.count(i)){
                MOREPROBLEMS = 1;
            }
        }
        if(MOREPROBLEMS) cout << "MOREPROBLEMS" <<"\n";
        else{
            for(int i=1;i<=10;i++){
                sort(all(score[i]));
                sum += score[i][score[i].size()-1];
            }
            cout << sum <<"\n";
        }
    }

}