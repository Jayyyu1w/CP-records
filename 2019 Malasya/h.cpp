// https://codeforces.com/gym/102219/problem/H
// Geometry: ConvexHull與cross的應用題
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
struct Pt{
    ll x,y;
    Pt(){}
    Pt(ll _x,ll _y){
        x=_x;y=_y;
    }
    Pt operator+(const Pt &a) const{
        return Pt(x+a.x,y+a.y);
    }
    Pt operator-(const Pt &a) const{
        return Pt(x-a.x,y-a.y);
    }
    Pt operator*(const ld &a) const{
        return Pt(x*a,y*a);
    }
    Pt operator/(const ld &a) const{
        return Pt(x/a,y/a);
    }
    ll operator*(const Pt &a) const{
        return x*a.x+y*a.y;
    }
    ll operator^(const Pt &a) const{
        return x*a.y-y*a.x;
    }
    bool operator<(const Pt &a) const{
        return x<a.x ||(x==a.x&&y<a.y);
    }
    friend int cross(const Pt& o,const Pt& a,const Pt& b){
        Pt lhs = o-a;
        Pt rhs = o-b;
        return lhs.x*rhs.y - lhs.y*rhs.x;
    }
    friend bool operator==(const Pt &l,const Pt &r){
        return (r.x==l.x && r.y==l.y);
    }
};
vector<Pt> convex_hull(vector<Pt> hull){
    sort(hull.begin(),hull.end());
    int top=0;
    vector<Pt> stk;
    for(int i=0;i<hull.size();i++){
        while(top>=2&&cross(stk[top-2],stk[top-1],hull[i])<=0){
            stk.pop_back(),top--;
        }
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
bool in_hull(vector<Pt> &hull,Pt p){
    int flag=0;
    for(int i=0;i<hull.size();i++){ // 要判斷點是否都在內側
        if(cross(p,hull[i],hull[(i+1)%hull.size()])>0){ //與凸包上前後兩點作外積，如果夾角在0~180度內，則在內側。
            flag++; 
        }
    }
    if(flag == hull.size()){ // 如果此點都在所有凸包的內側，表示在圈內
        return true;
    } else return false;
}
int main(){
    io
    int t,i,cs=1,c,p,x,y;
    cin >> t;
    while(t--){
        cout << "Case "<<cs++<<"\n";
        vector<Pt> blue;  // blue point (警戒點)
        vector<Pt> black; // black point (判斷點)
        cin >> c >> p; //  c：警戒點，p：要判斷的位置
        // 輸入警戒區資訊
        for(i=0;i<c;i++){
            cin >> x >> y; 
            blue.push_back(Pt{x,y}); // input blue point
        }
        // 利用凸包找出警戒區的外圈
        vector<Pt> hull = convex_hull(blue); // blue point hull(警戒區範圍)
        // 輸出警戒區範圍
        for(auto p1:hull){
            cout << p1.x << " " <<p1.y<<"\n";
        }
        cout << hull[0].x << " "<<hull[0].y;
        // 輸入要判斷的位置
        for(i=0;i<p;i++){
            cin >> x >> y;
            black.push_back(Pt{x,y}); // input black point
        }
        cout << "\n";
        // 判斷點是否安全
        for(auto p1:black){ // black point test
            cout << p1.x << " " <<p1.y;
            if(in_hull(hull,p1)){ // 判斷點是否在警戒區(凸包)內
                cout << " is unsafe!\n";
            }else cout << " is safe!\n";
        }
        cout << "\n";
    }
}