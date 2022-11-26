class Solution {
public:
    bool fn(stack<char> &st, char ch){
        while(!st.empty() and st.top()!= ch) st.pop();
        if(!st.empty() and st.top()==ch) {
            st.pop();
            return true;

        }
        return false;

    }
    bool isValid(string s) {
        //if(s.length()==1) return false;
        stack<char> st;
        for(auto it: s){
            if(it =='(' or it =='{' or it =='[') st.push(it);
            if(it ==')'){
                if(!st.empty() and st.top()=='(') st.pop();
                else st.push(it);
            }
            if(it ==']'){
               if(!st.empty() and st.top()=='[') st.pop();
               else st.push(it);
            }
            if(it =='}'){
                if(!st.empty() and st.top()=='{') st.pop();
                else st.push(it);
            }
            //st.push(it);
        }
        return st.empty() ;
    }
};
