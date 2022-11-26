class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> l(62);
        for(auto it: s){
            if(it>='a' and it<='z'){
                l[it-'a'].first++;;
                l[it-'a'].second = it;
            }
            else if(it>='A' and it<='Z'){
                l[it-'A'+26].first++;;
                l[it-'A'+26].second = it;
            }
            else{
                l[it-'0'+52].first++;
                l[it-'0'+52].second = it;
            }
        }
        sort(l.begin(),l.end());
        reverse(l.begin(),l.end());
        //sort(u.begin(),u.end());
        string ans;
        for(auto it: l){
            int x = it.first;
            while(x--) ans.push_back(it.second);
        }
        return ans;
    }
};
