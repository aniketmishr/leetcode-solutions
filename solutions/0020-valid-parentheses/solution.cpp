class Solution {
public:
    bool isOpeningParanthesis(char ch) {
        if (ch=='('||ch=='{'||ch=='[') return true;
        else return false;
    }
    char complementOf(char ch) {
        switch (ch) {
            case ')': return '('; 
            case '}': return '{'; 
            case ']': return '[';
            default: return '0';
        }
    }
    bool isValid(string s) {
        stack<char> st;
        if (!isOpeningParanthesis(s[0])) return false;
        for (char ch: s) {
            if (isOpeningParanthesis(ch)) {
                st.push(ch);
            } else {
                if (!st.empty() && complementOf(ch) == st.top()) {
                    st.pop();
                } else return false; 
            }
        }
        if (st.empty()) return true ;
        else return false; 
    }
};
