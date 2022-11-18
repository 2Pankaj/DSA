#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;  cin>>n;
    vector<int>vec(n);
    for(int i=0; i<n; i++) cin>>vec[i];
    for(int i=0; i<n-1; i++){
        int min_idx = i;
        for(int j = i+1; j<n; j++){
            min_idx = (vec[min_idx]> vec[j] ? j : min_idx);
        }
        swap(vec[i],vec[min_idx]);
    }
    for(auto it:vec) cout<<it<<endl;
}