class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>vec(prices.size(),0);
        vec[prices.size()-1] = -1e9;
        for(int i = prices.size()-2; i>=0; i--){
            vec[i] = max(vec[i+1],prices[i+1]);
        }
        int ans = 0;
        // for(auto it:vec) cout<<it<<" ";
        // cout<<endl;
        for(int i =0; i<vec.size(); i++){
            ans = max(ans,vec[i]-prices[i]);
        }
        return ans;
    }
};
// [7,1,5,3,6,4]
// 1 3 3 4 4 1000000000 


