class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> vec((int)1e5,0);
        for(auto it:nums)
            vec[it+(int)1e4]++;
        
        int cnt = 0,ans;
        for(int i = vec.size()-1; i>=0; i--){
            cnt += vec[i];
            if(cnt >= k) {
                ans = i;
                break;
            }
        }
        return ans-(int)1e4;
    }
};
