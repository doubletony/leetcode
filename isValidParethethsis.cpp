class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> counter(3, 0);
        // counter: 0 for '(' ')', 1 for '[', ']', 2 for '{', '}'
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if ( s[i] == '(' || s[i] == '[' || s[i] == '{' )
            {
                st.push( s[i] );
            }
            else
            {
                if ( st.empty() )
                {
                    return false;
                }

                char a = st.top();
                st.pop();

                if ( s[i] == ')' && a != '(' )
                {
                    return false;
                }

                if ( s[i] == ']' && a != '[' )
                {
                    return false;
                }

                if ( s[i] == '}' && a != '{' )
                {
                    return false;
                }
            }
        }
        if ( ! st.empty())
        {
            return false;
        }
        return true;
    }
};