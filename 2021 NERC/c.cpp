#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ld long double
#define MAXN 1000005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define cl(x) (x*2)
#define cr(x) (x*2+1)
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

struct Pt{
    int x,y;
    Pt(){}
    Pt(int _x,int _y){
        x=_x;
        y=_y;
    }
    friend bool operator<(const Pt &a, const Pt &b){
        if(a.x==b.x)return a.y<b.y;
        return a.x<b.x;
    }
};

signed main(){
    io
    int x,y;
    int n=3;
    vector <Pt> graph;
    while(n--){
        Pt p;
        cin >> p.x >> p.y;
        graph.push_back(p);
    }
    sort(graph.begin(),graph.end());
    if((graph[0].x==graph[1].x&&graph[1].x==graph[2].x)||(graph[0].y==graph[1].y&&graph[1].y==graph[2].y)){
        cout<<"1\n";
        cout<<graph[0].x<<" "<<graph[0].y<<" "<<graph[2].x<<" "<<graph[2].y<<"\n";
    }else if((graph[0].x==graph[1].x&&graph[1].y==graph[2].y)||(graph[0].y==graph[1].y&&graph[1].x==graph[2].x)){
        cout<<"2\n";
        cout<<graph[0].x<<" "<<graph[0].y<<" "<<graph[1].x<<" "<<graph[1].y<<"\n";
        cout<<graph[1].x<<" "<<graph[1].y<<" "<<graph[2].x<<" "<<graph[2].y<<"\n";
    }else if((graph[0].x==graph[1].x&&graph[0].y==graph[2].y)){
        cout<<"2\n";
        cout<<graph[1].x<<" "<<graph[1].y<<" "<<graph[0].x<<" "<<graph[0].y<<"\n";
        cout<<graph[0].x<<" "<<graph[0].y<<" "<<graph[2].x<<" "<<graph[2].y<<"\n";
    }else if((graph[0].y==graph[2].y&&graph[1].x==graph[2].x)){
        cout<<"2\n";
        cout<<graph[0].x<<" "<<graph[0].y<<" "<<graph[2].x<<" "<<graph[2].y<<"\n";
        cout<<graph[2].x<<" "<<graph[2].y<<" "<<graph[1].x<<" "<<graph[1].y<<"\n";
    }
    else{
        if(graph[1].y>=min(graph[2].y,graph[0].y)&&graph[1].y<=max(graph[2].y,graph[0].y)){
            cout<<"4\n";
            cout<<graph[0].x<<" "<<graph[0].y<<" "<<graph[0].x<<" "<<graph[1].y<<"\n";
            cout<<graph[0].x<<" "<<graph[1].y<<" "<<graph[1].x<<" "<<graph[1].y<<"\n";
            cout<<graph[1].x<<" "<<graph[1].y<<" "<<graph[2].x<<" "<<graph[1].y<<"\n";
            cout<<graph[2].x<<" "<<graph[1].y<<" "<<graph[2].x<<" "<<graph[2].y<<"\n";
        }else{
            cout<<"3\n";
            cout<<graph[0].x<<" "<<graph[0].y<<" "<<graph[1].x<<" "<<graph[0].y<<"\n";
            cout<<graph[1].x<<" "<<min(graph[1].y,min(graph[0].y,graph[2].y))<<" "<<graph[1].x<<" "<<max(graph[1].y,max(graph[0].y,graph[2].y))<<"\n";
            cout<<graph[1].x<<" "<<graph[2].y<<" "<<graph[2].x<<" "<<graph[2].y<<"\n";
        }
    }
}