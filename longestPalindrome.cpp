class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxlen = -1;
        string rslt = "";
        for (int i = 0; i < s.length(); i++)
        {
            int left,right;
            // include odd size
            left = right = i;
            while ( (left >=0) && (right < s.length()) )
            {
                if (  s[left] == s[right])
                {
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
            
            if ( (right - left) > maxlen )
            {
                maxlen = right -left - 1;
                rslt = s.substr(left+1, maxlen);
            }

            // include even size
            left = i;
            right = i+1;
            while ( (left >=0) && (right < s.length()) )
            {
                if (  s[left] == s[right])
                {
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }

            if ( (right - left) > maxlen )
            {
                maxlen = right -left - 1;
                rslt = s.substr(left+1, maxlen);
            }

        }
        return rslt;
    }
};