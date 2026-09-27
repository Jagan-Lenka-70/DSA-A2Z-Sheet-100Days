class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch == ')'){
                vector<char> temp;
                while(st.top() != '('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(char c : temp){
                    st.push(c);
                }
            }else{
                st.push(ch);
            }
        }

        string result;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};