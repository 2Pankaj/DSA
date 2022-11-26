class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l(n),r(n);
        r[n-1] = -1;
        for(int i = n-2; i>=0; i--){
            if( max(r[i+1],height[i+1])<= height[i]){
                r[i] = height[i];
            }
            else r[i] = max(r[i+1],height[i+1]);
        }
        l[0] = -1;
        for(int i = 1; i<n; i++) {
            if(height[i] >= max(l[i-1],height[i-1]))
                l[i] = height[i];
            else l[i] = max(l[i-1],height[i-1]);
        }
        int ans =0;
        for(int i=1; i<n-1; i++){
            ans += min(abs(height[i]-l[i]),abs(height[i]-r[i]));
        }
        return ans;
    }
};


// [0,1,0,2,1,0,1,3,2,1,2,1]
// -1 0 0 0 1 0 0 1 2 1 1 1 
//  3 3 3 3 3 3 3 3 2 2 2 -1 


