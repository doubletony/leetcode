class Solution {
    // the idea is to use a stack to store the location of '('
    // and every time when we get a matched pair of ')', we check
    // the current stack, to update the max length.

public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if (len <=1)
        {
            return 0;
        }

        int start = -1;

        stack<int> stk;
        int i = 0;
        int maxsize = 0;
        while( i < s.length() )
        {
            if ( s[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                if ( !stk.empty() )
                {
                    int loc = stk.top();
                    stk.pop();

                    if ( stk.empty() )
                    {
                        maxsize = max ( maxsize, i - start);
                    }
                    else
                    {
                        maxsize = max ( maxsize, i - stk.top());
                    }
                }
                else
                {
                    start = i;
                }
            }
            i++;
        }
        return maxsize;
    }
};