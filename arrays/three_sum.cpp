class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        vector<vector<int>> ans;
        for(int i =0; i<n; i++){
            if(i-1>=0 and nums[i]== nums[i-1]) continue;
            int j = i+1,k = n-1;
            while(j<k){
                int sum= nums[i]+nums[j]+nums[k];
                if(sum <0) j++;
                else if(sum >0) k--;
                else{
                    vector<int> vec = {nums[i],nums[j],nums[k]};
                    ans.push_back(vec);
                    int x = nums[k];
                    while(k>j and nums[k] ==x) k--;
                    x = nums[j];
                    while(j<k and nums[j]==x) j++;
                }
            }
        }
        return ans;
    }
};
