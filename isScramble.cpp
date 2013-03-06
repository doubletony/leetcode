class Solution {
public:

    bool isSame(string s1, string s2)
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        if (s1 == s2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s1.length();
        if ( s1 == s2)
        {
            return true;
        }

        if ( n == 0)
        {
            return true;
        }

        if ( n == 1)
        {
            if (s1 == s2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }


        if ( n == 2)
        {
            return isSame(s1, s2);
        }

        for (int i  = 1; i < n; i++)
        {
            string tmp1,tmp2;
            string tmp3,tmp4;
            tmp1 = s1.substr(0, i);
            tmp2 = s2.substr(0, i);
            tmp3 = s1.substr(i, n -i);
            tmp4 = s2.substr(i, n -i);

            if ( isSame(tmp1, tmp2) && isSame(tmp3, tmp4) )
            {
                if ( isScramble(tmp1, tmp2) && isScramble(tmp3, tmp4))
                {
                    return true;
                }
            }

            tmp1 = s1.substr(0, i);
            tmp2 = s2.substr(n -i, i);

            tmp3 = s1.substr(i, n-i);
            tmp4 = s2.substr(0, n-i);

            if ( isSame(tmp1, tmp2) && isSame(tmp3, tmp4) )
            {
                if ( isScramble(tmp1, tmp2) && isScramble(tmp3, tmp4))
                {
                    return true;
                }
            }

        }
        return false;
    }
};