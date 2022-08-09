#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define ep emplace
#define all(x) x.begin(),x.end()
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define MAXN 10005
using namespace std;

int r;
struct Pt{
    ld x,y;
    Pt(){}
    Pt(ld _x,ld _y){
        x=_x;y=_y;
    }
    Pt operator-(const Pt &a) const{
        return Pt(x-a.x,y-a.y);
    }
    bool operator<(const Pt &a) const{
        return x<a.x||(x==a.x&&y<a.y);
    }
    friend bool operator==(const Pt &a,const Pt &b) {
        return (a.x==b.x)&&(a.y==b.y);
    }
    friend ld cross(const Pt &o,const Pt &a,const Pt &b) {
        Pt l=o-a;
        Pt r=o-b;
        return l.x*r.y-l.y*r.x;
    }
};

vector<Pt> gethull(vector<Pt> hull){
    sort(hull.begin(),hull.end());
    int top=0;
    vector<Pt> stk;
    for(int i=0;i<hull.size();i++){
        while(top>=2&&cross(stk[top-2],stk[top-1],hull[i])<=0) 
            stk.pop_back(),top--;
        stk.push_back(hull[i]);
        top++;
    }
    for(int i=hull.size()-2,t=top+1;i>=0;i--){
        while(top>=t&&cross(stk[top-2],stk[top-1],hull[i])<=0) 
            stk.pop_back(),top--;
        stk.push_back(hull[i]);
        top++;
    }
    stk.pop_back();
    return stk;
}
ld dis(Pt i,Pt j){ 
    Pt vt = i-j;
    return sqrt((ld)(vt.x)*vt.x + (ld)(vt.y)*vt.y);
}
ld rot(vector<Pt> hull){
    ld mn = 2.0*r;
    int n = hull.size();
    hull.pb(hull[0]);
    for(int i=0,j=i+2;i<n;i++){
        while((abs(cross(hull[i],hull[i+1],hull[j]))/abs(dis(hull[i],hull[i+1])))<=(abs(cross(hull[i],hull[i+1],hull[(j+1)%n]))/abs(dis(hull[i],hull[i+1])))){
            j=(j+1)%n;
        }
        ld area = cross(hull[i],hull[i+1],hull[j]);
        area = abs(area);
        mn = min(mn,area/abs(dis(hull[i],hull[i+1]))); //平行四邊形面積 除以 底 ＝ 高
    }   
    return mn;
}

signed main(){
    io
    int n,i;
    ld x,y;
    cin >> n >> r;
    vector<Pt> c; //candle
    for(i=0;i<n;i++){
        cin >> x >> y;
        c.pb({x,y});
    }
    vector<Pt> hull = gethull(c);
    if(hull.size()<=2){
        cout << "0.00000000000000000\n";
    }
    else cout << fixed << setprecision(15) <<rot(hull) <<"\n";
}