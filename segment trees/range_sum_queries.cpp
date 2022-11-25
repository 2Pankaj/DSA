class NumArray {
public:
    vector<int> st,vec;
   int ss;
    void buildsegtree(vector<int> &nums,int st_idx,int start,int end){
        if(start>end) return;
        if(start==end){
            st[st_idx] = nums[start];
            return;
        }
        int mid = start +(end-start)/2;
        buildsegtree(nums,2*st_idx,start,mid);
        buildsegtree(nums,2*st_idx+1,mid+1,end);
        st[st_idx] = st[2*st_idx] + st[2*st_idx+1];
    }
    int sum(vector<int> &st,int s,int e,int qs,int qe,int st_idx){
        if(e<qs or s>qe) return 0;
        if(s>= qs and e <= qe) return(st[st_idx]);
        int mid = s + (e-s)/2;
        int x = sum(st,s,mid, qs,qe,2*st_idx);
        int y = sum(st,mid+1,e, qs,qe,2*st_idx+1);
        return x+y;
    }
    void up(vector<int> &st,int start, int end, int idx, int val,int st_idx){
        if(idx < start or idx > end) return;
        if(start== end){
            if(start== idx) st[st_idx] = val;
            return;
        }
        int mid = start + (end-start)/2;
        up(st,start,mid,idx,val,2*st_idx);
        up(st,mid+1,end,idx,val,2*st_idx+1);
        st[st_idx] = st[2*st_idx] + st[2*st_idx+1];
    }
    NumArray(vector<int>& nums) {
        int n = nums.size();
        ss = n;
        st.resize(4*n);
        int start =0, end = n-1;
         int st_idx  =1;
        buildsegtree(nums,st_idx,start,end);
    }
    
    void update(int index, int val) {
        up(st,0,ss-1,index,val,1);
    }
    
    int sumRange(int left, int right) {
        return sum(st,0,ss-1,left,right,1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
