/*逆序數對*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define int long long
#define pb push_back
#define ep emplace
#define MXN 200010
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp make_pair
using namespace std;

vector<ll> pre_sum(MXN);

struct node{
    ll n1,n2;
    node(){}
    node(ll _n1,ll _n2){
        n1=_n1;
        n2=_n2;
    }
    friend bool operator<(const node& a,const node&b){
        return a.n1<b.n1;
    }
};
int sum=0;
vector<int> sorted(MXN);
void merge(vector<int>&arr, int l, int mid, int r) {
	int left = l, right = mid + 1, idx = 0;
	while (left <= mid && right <= r) {
		if (arr[left] > arr[right]) {
			sorted[idx++] = arr[right++];
			sum += mid - left + 1;
		}
		else {
			sorted[idx++] = arr[left++];
		}
	}
	while (left <= mid) {
		sorted[idx++] = arr[left++];
	}
	while (right <= r) {
		sorted[idx++] = arr[right++];
	}
	idx = 0;
	while (l <= r) {
		arr[l++] = sorted[idx++];
	}
}
void dc(vector<int>&arr, int l,int r){
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    dc(arr,l,mid);
    dc(arr,mid+1,r);
    merge(arr,l,mid,r);
}
void prefixSum(){
    pre_sum[0]=1;
    for(int i=1;i<MXN;i++){
        pre_sum[i]=pre_sum[i-1]+i;
    }
}
ll c(ll n){
    return (n*(n-1))/2;
}
signed main(){
    io
    int x,y,h,v, p1,p2,ans, tot=0;
    cin >> x >> y;
    vector<node> xx,yy;
    cin >> h >> v;
    for(int i=0;i<h;i++){
        cin>>p1>>p2;
        yy.push_back(node(p1,p2));
    }
    for(int i=0;i<v;i++){
        cin>>p1>>p2;
        xx.push_back(node(p1,p2));
    }
    sort(yy.begin(),yy.end());
    sort(xx.begin(),xx.end());
    vector<int>ny(h);
    vector<int>nx(v);
    for(int i=0;i<h;i++){
        ny[i]=yy[i].n2;
    }
    for(int i=0;i<v;i++){
        nx[i]=xx[i].n2;
    }
    dc(ny,0,h - 1);
    tot+=sum;
    sum=0;
    dc(nx,0,v - 1);
    tot+=sum;
    //ans=最大面數-(最大交點數-交點數)
    prefixSum();
    //cout<<pre_sum[h+v]<<" "<<(tot+(h*v))<<"\n";
    ans = pre_sum[h+v]-(c(h+v)-(tot+(h*v)));
    // ans = (((1+h+v)*(h+v)/2)+1)-(c(h+v)-(tot+(h*v)));
    cout<<ans<<"\n";
}