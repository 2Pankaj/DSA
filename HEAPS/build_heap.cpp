#include<bits/stdc++.h>
using namespace std;
//vector<int>heap;
void heapify(vector<int>&vec,int i){
    int l = 2*i,r = 2*i+1;
    int max_idx = i;
    if(l<vec.size() and vec[max_idx]<vec[l] ){
        //swap(vec[l],vec[max_idx]);
        max_idx = l;
    }
    if(r<vec.size() and vec[max_idx]<vec[r]){
        //swap(vec[r],vec[max_idx]);
        max_idx = r;
    }
    if(max_idx != i){
        swap(vec[i],vec[max_idx]);
        heapify(vec,max_idx);
    }
}
int main(){
    int n;  cin>>n;
    
    vector<int>vec(n+1);
    for(int i=1; i<=n; i++) cin>>vec[i];
    for(int i =n/2+1; i>0; i--)
    heapify(vec,i);
    for(auto it:vec) cout<<it<<" ";
    cout<<endl; 
   // heap.resize(4*n);
    
}
