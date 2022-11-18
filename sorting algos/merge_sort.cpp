#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>vec, int l,int m,int h){
    int i=l, j = m+1;
    while(i<=m and j<=h){
        if(vec[i]<= vec[j]) i++;
        else swap(vec[i],vec[j]) j++;
    }
    while(j>= m+1 and vec[j]< vec[i]) j--;
    while(j<=h){
        if(vec[j]<vec[i]) swap(vec[j],vec[i]),0          
    }

}
void ms(vector<int>vec,int l, int h){
    if(l==h) return;
    int m = l + (h-l)/2;
    ms(vec,l,m);
    ms(vec,m+1,h);
    merge(vec,l,m,h);
}
int main(){
    int n;  cin>>n;
    vector<int>vec(n);
    for(int i=0; i<n; i++) cin>>vec[i];
    
    for(auto it:vec) cout<<it<<" ";
}
 1 2 2 3  5 7 4  
 
 1 2 2 3 4 5 7
 1 2 2 3
 