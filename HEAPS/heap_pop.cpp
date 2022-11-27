#include<bits/stdc++.h>
using namespace std;
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
void heap_pop(vector<int> &vec){
    swap(vec[1],vec.back());
    vec.pop_back();
    heapify(vec,1);
}
int main(){
    int n;  cin>>n;
    vector<int>vec(n+1);
    for(int i=1; i<=n; i++) cin>>vec[i];
    heap_pop(vec);
    for(auto it:vec) cout<<it<<" ";
    cout<<endl;
}