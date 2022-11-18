class Solution {
    int partition(vector<int> &vec,int l,int h){
    int pivot = vec[h];
    int i = -1, j = 0;
    while(j<h){
        if(vec[j] > pivot) j++;
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
void qs(vector<int> &vec,int l,int h){
    if(l<h){
    int x = partition(vec,l,h);
    qs(vec,l ,x-1);
    qs(vec,x+1,h);
    }
}
public:
    void sortColors(vector<int>& nums) {
        int h = nums.size()-1;
        qs(nums,0,h);
    }
};
