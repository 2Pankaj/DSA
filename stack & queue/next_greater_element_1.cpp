class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums2.size(),-1),idx((int) 2e4+100,-1),vec(nums1.size(),-1);
        stack<int>st;
        for(int i = 0; i<nums2.size(); i++){
            if(st.empty()) st.push(i);
            else if(nums2[st.top()]>nums2[i]) st.push(i);
            else{
                while(!st.empty() and nums2[i]>nums2[st.top()]){
                    ans[st.top()] = nums2[i];
                    st.pop();
                }
                //if(st.top()>nums2[i])
                st.push(i);
            }
            
            idx[nums2[i]] = i;
        }
        // for(auto it:ans) cout<<it<<" ";
        // cout<<endl;
        for(int i =0; i<nums1.size(); i++){
            //cout<<idx[nums1[i]]<<" ";
            if(idx[nums1[i]] != -1)
            vec[i] = ans[idx[nums1[i]]];            
        }
        return vec;
    }
};
