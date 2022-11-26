class Solution {
public:
    map<string ,int> prec;
    void p(){
        prec["*"]=prec["/"]=prec["%"]=13;
        prec["+"]=prec["-"]=12;
    }
    int e(int x,int y, string op){
        if(op=="+") return y+x;
        if(op=="-") return (y-x);
        if(op=="*") return y*x;
        if(op=="/") return y/x;
        return 0;
    }
    vector<string> fn(string s){

        stack<string> st;
        vector<string> ans;
        for(int i=0; i<s.length(); i++){
            if(s[i]==' ') continue;
            if(isdigit(s[i])){
                string x = "";
                x.push_back(s[i]);
                while(i+1<s.length() and isdigit(s[i+1])){
                   x.push_back(s[i+1]);
                   i++;
                }
                ans.push_back(x);
            }
            else{
                string x = "";
                x.push_back(s[i]);
                if(st.empty()) st.push(x);
                else{
                    while(!st.empty() and prec[st.top()]>=prec[x]){
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(x);
                }
            }

        }   
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    int calculate(string s) {
        p();
        vector<string>exp = fn(s);
        stack<int> st;
        for(auto it:exp){
            if(it !="+" and it !="-" and it !="/" and it !="*"){
                int x = stoi(it);
                st.push(x);
            }
            else{
                int x = st.top();
                st.pop();
                int y =  st.top();
                st.pop();
                
                
                st.push(e(x,y,it));
            }
        }
        return st.top();
    }
};
