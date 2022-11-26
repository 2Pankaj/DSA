class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>vec(n+1,0);
        for(int i=1; i<=n; i++){
           // if(nums[i-1]==0) nums[i-1] = -1;
            vec[i] = vec[i-1]+nums[i-1];
        }
        map<int,int>mp;
        int ans = 0;
        // for(auto it:vec) cout<<it<<" ";
        // cout<<endl;
        for(int i=0; i<vec.size(); i++){
            if(mp.count(vec[i]-k)){
                ans+=mp[vec[i]-k];
                
            }
            mp[vec[i]]++;
        }
        //for(auto it:mp) cout<<it.first<<" "<<it.second<<endl;
        return ans;
    }
};
