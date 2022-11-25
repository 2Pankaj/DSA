#include<bits/stdc++.h>
using namespace std;
vector<int>st;
void buildsegtree(vector<int> &vec, int s, int e, int st_idx){
    if(s>e) return;
    if(s==e){
        st[st_idx] = vec[s];
        return;
    }
    int m=  s+ (e-s)/2;
    buildsegtree(vec,s,m,2*st_idx);
    buildsegtree(vec,m+1,e,2*st_idx+1);
    st[st_idx] = __gcd(st[2*st_idx],st[2*st_idx+1]);
}
int gcd(vector<int> &st, int s, int e, int st_idx,int qs,int qe){
    if(qs>e or qe <s) return 0;
    if(s>=qs and e<= qe) return st[st_idx];
    int mid=  s+  (e-s)/2;
    int x = gcd(st,s,mid,2*st_idx,qs,qe);
    int y = gcd(st,mid+1,e,2*st_idx+1,qs,qe);
    return __gcd(x,y);
}
void update(vector<int> &st, int s, int e, int idx, int val,int st_idx){
    if(idx<s or idx>e) return;
    if(s==e){
        if(s==idx) st[st_idx] = val;
        return;
    }
    int mid=  s + (e-s)/2;
    update(st,s,mid,idx,val,2*st_idx);
    update(st,mid+1,e,idx,val,2*st_idx+1);
    st[st_idx] = __gcd(st[2*st_idx],st[2*st_idx+1]);
}
int main(){
    int n;  cin>>n;
    vector<int>vec(n);
    for(int i=0; i<n; i++) cin>>vec[i];
    st.resize(4*n);
    buildsegtree(vec,0,n-1,1);
    
}