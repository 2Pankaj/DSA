class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        sort(nums4.begin(),nums4.end());
        int ans =0,n  = nums1.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            for(int j =0; j<n; j++){
                long long sum = nums1[i]+nums2[j];
                mp[sum]++;
            }
        }
        for(int i=0; i<n; i++){
            for(int j =0; j<n; j++){
                long long sum = nums3[i]+nums4[j];
                ans += mp[-sum];
            }
        }
        return ans;
    }
};
