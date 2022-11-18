#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;  cin>>n;
    vector<int>vec(n),cf(1000);
    for(int i=0; i<n; i++) {
       cin>>vec[i];
       cf[vec[i]]++;
    }
    for(int i=0; i<1000; i++) {
        if(i) cf[i] += cf[i-1];
    }
    vector<int> ans(n,0);
    for(int i=n-1; i>=0; i--){
        if(cf[vec[i]]) ans[(cf[vec[i]]--)-1] = vec[i];
    }
    for(auto it:ans) cout<<it<<" ";
}
