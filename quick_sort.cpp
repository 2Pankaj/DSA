#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> vec,int l,int h){
    int pivot = vec[h];
    int i = -1, j = 0;
    while(j<h){
        if(vec[j] >= pivot) j++;
        else{
            i++;
            swap(vec[i],vec[j]);
            j++;
        }
    }
    i++;
    swap(vec[h],vec[i]);
    return i;
}
void qs(vector<int> vec,int l,int h){
    if(l>=h) return;
    int x = partition(vec,l,h);
    qs(vec,l ,x-1);
    qs(vec,x+1,h);
}
int main(){
    int n;  cin>>n;
    vector<int>vec(n);
    for(int i=0; i<n; i++) cin>>vec[i];
    qs(vec,0,n-1);;
    for(auto it:vec) cout<<it<<" ";
}