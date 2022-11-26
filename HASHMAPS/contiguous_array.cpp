class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int>vec(n+1,0);
        for(int i=1; i<=n; i++){
            if(nums[i-1]==0) nums[i-1] = -1;
            vec[i] = vec[i-1]+nums[i-1];
        }
        map<int,int>mp;
        int ans = 0;
        for(int i=0; i<vec.size(); i++){
            if(mp.count(vec[i]-0)){
                ans = max(ans,i-mp[vec[i]-0]);
            }
            else mp[vec[i]] = i;
        }
        return ans;
    }
};
