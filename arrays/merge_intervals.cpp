class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>> vec;
        for(int i = 0; i<intervals.size(); i++){
            vec.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(vec.begin(),vec.end());
        pair<int,int> temp = vec[0];
        vector<vector<int>> ans;
        vec.push_back({1e5,1e5});
        for(int i =1; i<vec.size(); i++){
            if((vec[i].first >= temp.first and vec[i].first <= temp.second) or (vec[i].second >=                temp.first and vec[i].second <= temp.second)){
                temp.first = min(temp.first,vec[i].first);
                temp.second = max(temp.second,vec[i].second);
            }
            else{
                vector<int> t = {temp.first,temp.second};
                ans.push_back(t);
                temp = vec[i];
            }
        }
        // vector<int> t = {temp.first,temp.second};
        //         ans.push_back(t);
        return ans;
    }
};
