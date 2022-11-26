class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int>mp;
        for(auto it:p) mp[it]++;
        vector<int> ans;
        map<char,int> m;
        int i=0, j=0,k = p.length();
        //map<char,int> m;
        while(j<s.length()){
            m[s[j]]++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(m==mp) ans.push_back(i);
                m[s[i]]--;
                if(m[s[i]]==0) m.erase(s[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
