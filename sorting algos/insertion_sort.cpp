#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;  cin>>n;
    vector<int>vec(n);
    for(int i =0; i<n; i++) cin>>vec[i];
    for(int i=1; i<n; i++){
        int j = i;
        while(j>0 and vec[j]<vec[j-1]) {
            swap(vec[j], vec[j-1]);
            j--;
        }
    }
    for(auto it:vec) cout<<it<<" ";
}