class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        int ans = 0;
        int sign = 1;
        int curr = 0;
        stack<int> st;
        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                int x = s[i]-'0';
                while(i+1<s.length() and isdigit(s[i+1])){
                    x *= 10;
                    x +=(s[i+1]-'0');
                    i++;
                }
                ans += (x*sign);
            }
            else if(s[i]=='-') sign  = -1;
            else if(s[i]=='+') sign  = 1;
            else if(s[i]=='('){
                st.push(ans);
                ans = 0;
                st.push(sign);
                sign = 1;
            }
            else if(s[i]==')'){
                int xs = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                ans = x + ans*xs;
            }
        }
        return ans;
    }
};
