#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;  cin>>n;
    vector<int>vec(n);
    for(int i=0; i<n; i++) cin>>vec[i];
    for(int i =0; i<n-1; i++){
        bool flag = false;
        for(int j = 0; j<n-i-1; j++){
            if(vec[j]>vec[j+1]) swap(vec[j],vec[j+1]), flag = true;
        }
        if(!flag) break;
    }
    for(auto it:vec) cout<<it<<" ";
}
