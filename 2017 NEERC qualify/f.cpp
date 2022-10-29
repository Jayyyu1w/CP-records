// cf847-f greedy
#include<bits/stdc++.h>
#define int long long
#define MAXN 105
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
struct node{
    int idx,c,ti=-1;
};
bool cmp(node a,node b){
    return a.c==b.c?a.ti<b.ti:a.c>b.c;
}
vector<node> c(MAXN);
int n,k,m,a;
int test(int now,int ti,int rank,int idx){ 
    int remain = m-a;
    if(now==0 && remain==0)return 3;
    if(c[k].c >=  (now+remain) && c[k].idx != idx ){
        if(remain==0){
            if(now > c[k].c||(now==c[k].c&&idx<c[k].idx))return 1;
            else return 3;
        }else{
            return 3;
        }
    }
        int i = k-rank+1, sum = 0;
        for(int j=1;j<=i;j++){
            if(rank+j>n && now!=0) return 1;
            else{
                sum += (now-c[rank+j].c+1);
            }
        }
        if(sum<=remain || now==0){
            return 2;
        }else{
            return 1;
        }
}
signed main(){
    io
    int i;
    cin >> n >> k >> m >> a;
    for(i=1;i<=n;i++){
        node temp;
        temp.c = 0; temp.idx=i; temp.ti = 0;
        c[i]=temp;
    }
    for(i=0;i<a;i++){
        int temp; cin >> temp;
        c[temp].c++;
        c[temp].ti=i;
    }
    sort(c.begin()+1,c.begin()+1+n,cmp);
    vector<int> ans(n+1);
    for(i=1;i<=n;i++){
        ans[c[i].idx]=test(c[i].c,c[i].ti,i,c[i].idx);
    }
    for(i=1;i<=n;i++){
        cout << ans[i] <<" ";
    }
}