class NumArray {
public:
    int solve(vector<int> & vec,int l,int r){
        if(l) return vec[r]-vec[l-1];
        else return vec[r];
    }
    vector<int> a,b;
    NumArray(vector<int>& nums) {
        for(int i =0; i<nums.size(); i++){
            if(i) nums[i] += nums[i-1];
        }
        a= nums;
    }
    
    int sumRange(int left, int right) {
        
        return solve(a,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
