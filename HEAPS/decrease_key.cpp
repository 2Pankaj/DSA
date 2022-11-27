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
void inc_key(vector<int> &vec,int idx,int key){
    if(vec[idx] < key) return ;
    //int n = vec.size();
    int i = idx;
    vec[idx]= key;
    //cout<<i<<endl;
    heapify(vec,i);
}
int main(){
    int n;  cin>>n;

    vector<int>vec(n+1);
    for(int i=1; i<=n; i++) cin>>vec[i];

    for(int i =n/2+1; i>0; i--)
    heapify(vec,i);
    cout<<"heap before updation : "<<endl;
    for(auto it:vec) cout<<it<<" ";
    cout<<endl;
    cout<<"enter the value and index"<<endl;
    int k,idx;  cin>>k>>idx;
    //vec.push_back(k);
    inc_key(vec,idx,k);
    cout<<"heap after updation is : "<<endl;
    for(auto it:vec) cout<<it<<" ";
    cout<<endl;
   // heap.resize(4*n);

}
