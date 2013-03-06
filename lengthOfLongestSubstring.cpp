class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() == 0)
        {
            return 0;
        }
        int table[256];
        for (int i = 0; i < 256; i++)
        {
            table[i] = 0; // not used
        }

        table[s[0]] = 1;
        int left = 0;
        int maxlen = 1;
        int counter = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if ( table[s[i]] == 0 )
            {
                table[s[i]] = 1;
                counter++;
                if (counter > maxlen)
                {
                    maxlen = counter;
                }
            }
            else
            {
                for (int j = left; j < s.length(); j++)
                {
                    table[s[j]] = 0;
                    counter--;
                    if ( s[j] == s[i])
                    {
                        left = j+1;
                        break;
                    }
                }
                table[s[i]] = 1;
                counter++;
            }
        }
        return maxlen;
    }
};