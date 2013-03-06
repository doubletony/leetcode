class Solution {
public:

    string removeOthers(string s)
    {
        string t;
        for (int i = 0; i < s.length(); i++)
        {
            if ( ( s[i] <= '9' && s[i] >= '0') || 
                 ( s[i] <= 'z' && s[i] >= 'a') ||
                 ( s[i] <= 'Z' && s[i] >= 'A') )
            {
                if ( s[i] <= 'Z' && s[i] >= 'A' )
                {
                    t.push_back( s[i] - 'A' + 'a' );
                }
                else
                {
                    t.push_back( s[i] );
                }
            }
        }
        return t;
    }

    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string st = removeOthers(s);
        string st2 = st;
        reverse(st2.begin() , st2.end());
        
        return (st == st2);

    }
};