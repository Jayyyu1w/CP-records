#include<bits/stdc++.h>
using namespace std;

struct xcood{
    int x1,x2,y;
    xcood(){}
    xcood(int _x1, int _x2, int _y){
        x1=_x1,x2=_x2,y=_y;
    }
    friend bool operator<(const xcood&a,const xcood&b){
        return a.y<b.y;
    }
};
struct ycood{
    int y1,y2,x;
    ycood(){}
    ycood(int _y1, int _y2, int _x){
        y1=_y1,y2=_y2,x=_x;
    }
    friend bool operator<(const ycood&a,const ycood&b){
        return a.x<b.x;
    }
};
int main(){
    /*
    freopen("intel.in","r",stdin);    // 讀 file.in 檔
    freopen("intel.out","w",stdout);  // 寫入 file.out 檔
    */
    int n, inia, inib, prea, preb, a, b, minx1=1e6+5, maxx2=0, miny1=1e6+5, maxy2=0;
    cin>>n;
    vector<xcood>line1;
    vector<ycood>line2;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(i==0){
            inia=a,inib=b;
            prea=a,preb=b;
        }else{
            if(a==prea){
                line2.push_back(ycood(b,preb,a));
                miny1=min(miny1,min(b,preb));
                maxy2=max(maxy2,max(b,preb));
            }else if(b==preb){
                line1.push_back(xcood(a,prea,b));
                minx1=min(minx1,min(a,prea));
                maxx2=max(maxx2,max(a,prea));
            }
            prea=a,preb=b;
        }
    }
    if(inia==a){
        line2.push_back(ycood(b,inib,a));
        miny1=min(miny1,min(b,inib));
        maxy2=max(maxy2,max(b,inib));
    }else if(b==inib){
        line1.push_back(xcood(a,inia,b));
        minx1=min(minx1,min(a,inia));
        maxx2=max(maxx2,max(a,inia));
    }
    sort(line1.begin(),line1.end());
    sort(line2.begin(),line2.end());
    int ans=0, maxheight, sum=0;
    maxheight=maxx2-minx1;
    for(int i=0;i<line1.size();i++){
        sum+=abs(line1[i].x1-line1[i].x2);
    }
    ans+=max(2*maxheight,sum)-min(2*maxheight,sum);
    sum=0;
    maxheight=maxy2-miny1;
    for(int i=0;i<line2.size();i++){
        sum+=abs(line2[i].y1-line2[i].y2);
    }
    ans+=max(2*maxheight,sum)-min(2*maxheight,sum);
    cout<<ans<<"\n";
}