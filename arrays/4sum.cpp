class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i =0; i<n; i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j= i+1; j<n; j++){
                if(j>i+1 and nums[j]== nums[j-1]) continue;
                int s = j+1,e = n-1;
                while(s<e){
                    long long int sum = (long long)nums[i]+nums[j]+nums[s]+nums[e];
                    if(sum <target) s++;
                    else if(sum>target) e--;
                    else{
                        vector<int> vec = {nums[i],nums[j],nums[s],nums[e]};
                        ans.push_back(vec);
                        int x = nums[s];
                        while(s<e and nums[s]==x)s++;
                        x = nums[e];
                        while(s<e and nums[e]==x) e--;
                    }
                }
            }
        }
        return ans;
    }
};
