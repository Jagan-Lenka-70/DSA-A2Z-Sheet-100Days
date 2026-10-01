class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        if(s.size() == 1) return false;
     for(char ch : s){
        if(ch == '(' || ch == '{' || ch == '['){
            str.push(ch);
        }else{
            if(str.empty()) return false;

            char top = str.top();
            str.pop();
            if(ch == ')' && top != '(') return false;
             if(ch == '}' && top != '{') return false;
              if(ch == ']' && top != '[') return false;
        }
     }
     return str.empty();
    }
};