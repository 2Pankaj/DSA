#include<bits/stdc++.h>
using namespace std;
vector<int> cs(vector<int> vec){
    vector<int> cf(10);
    for(auto it:vec) cf[it%10]++;
    for(int i =0; i<10; i++){
        if(i) cf[i] += cf[i-1];
    }
    int n = vec.size();
    vector<int> ans(n,0);
    for(int i=n-1; i>=0; i--){
    if(cf[vec[i]]) ans[(cf[vec[i]]--)-1] = vec[i];
    }
}
void rs(vector<int> vec,int cnt,int t){
    if(cnt == t) return;
    vector<int> v = cs(vec);
    rs(v,cnt+1,t);
}
int main(){
    int n;  cin>>n;
    vector<int>vec(n);
    for(int i=0; i<n; i++) cin>>vec[i];
    int x = *max_element(vec.begin(),vec.end());
    int t = ceil(log10(x));
    rs(vec,1,t);
    for(auto it:vec) cout<<it<<endl;
}