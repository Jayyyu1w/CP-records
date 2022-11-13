#include<bits/stdc++.h>
using namespace std;

struct rent{
    int val, adv;
};
int main(){
    int zval, zone, ztwo;
    cin >> zval >> zone >> ztwo;
    int f, h;
    cin >> f;
    vector<rent> fr(f);
    for (int i = 0; i < f;i++){
        cin >> fr[i].val >> fr[i].adv;
    }
    int type, rt, a;
    cin >> h;
    pair<int, pair<int, int>> ans = {-1, {-1, -1}};
    for (int i = 0; i < h;i++){
        cin >> type >> rt >> a;
        if(type == 1){
            if (rt <= zval){
                if (ans.first < a + zone){
                    ans.first = a + zone;
                    ans.second = make_pair(i, -1);
                }
            }
        }else if(type == 2){
            if(rt <= zval){
                if (ans.first < a + ztwo){
                    ans.first = a + ztwo;
                    ans.second = make_pair(i, -1);
                }
            }
            for (int j = 0; j < f; j++){
                if (rt <= zval * 2 && rt <= fr[j].val * 2){
                    if (ans.first < a + fr[j].adv){
                        ans.first = a + fr[j].adv;
                        ans.second = make_pair(i, j);
                    }
                }
            }
        }
    }
    if(ans.second.first != -1){
        if(ans.second.second == -1){
            cout << "You should rent the apartment #" << ans.second.first + 1 << " alone.";
        }else{
            cout << "You should rent the apartment #" << ans.second.first + 1 << " with the friend #" << ans.second.second + 1 << ".";
        }
    }else{
        cout << "Forget about apartments. Live in the dormitory.";
    }
}