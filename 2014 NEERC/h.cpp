#include<bits/stdc++.h>
using namespace std;

stack<pair<char,int>> st;
vector<pair<int,int>> ans;

bool cmp1(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
bool cmp2(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}

int main(){
    string str;
    int n;
    cin>>n>>str;
    int ind=0;
    for(int i=0;i<str.length();i++){
        if(!st.empty()&&str[i]+32==st.top().first){
            //cout<<"in"<<st.top().first<<" "<<st.top().second<<" "<<i<<"\n";
            ans.push_back({i,st.top().second});
            st.pop();
        }else if(!st.empty()&&str[i]-32==st.top().first){
            //cout<<"in"<<st.top().first<<" "<<st.top().second<<" "<<i<<"\n";
            ans.push_back({st.top().second,i});
            st.pop();
        }else{
            //cout<<str[i]<<" "<<ind<<"\n";
            st.push({str[i],i});
        }
    }
    if(!st.empty()){
        cout<<"Impossible\n";
    }else{
        sort(ans.begin(),ans.end(),cmp1);
        for(int i=0;i<n;i++){
            ans[i].second=i+1;
        }
        sort(ans.begin(),ans.end(),cmp2);
        for(int i=0;i<n;i++){
            cout<<ans[i].second<<" ";
        }
        cout<<"\n";
    }
}