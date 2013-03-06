class Solution {
public:

    int checkValid(string s)
    {
        if ( s.length() == 0)
        {
            return 0;
        }

        // exclude starting of '0'
        char lastC = s[0];

        if (lastC == '0')
        {
            return 0;
        }

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] != '0')
            {
                lastC = s[i];
            }
            else
            {
                // can we resolve it?
                int id = (lastC - '0') * 10 + (s[i] - '0');
                if ( id > 26 || id < 10)
                {
                    // we can not resolve it
                    return 0;
                }
                lastC = s[i];
            }
        }

        return 1;
    }

    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // similar to fibonacci.

        int oneStep = 0;
        int twoStep = 0;
        if ( !checkValid(s) )
        {
            return 0;
        }

        if (s.length() == 1)
        {
            return 1;
        }

        string::iterator it = s.begin();
        char lastC = *it;
        it++;
        oneStep = 1;
        twoStep = 1;

        while ( it < s.end() )
        {
            string::iterator nextc = it + 1;
            char curC = *it;

            if ( nextc < s.end())
            {
                if ( (*nextc) == '0' )
                {
                    twoStep = oneStep;
                    it++; // to '0'
                    lastC = '0';
                }
                else
                {
                    if ( lastC != '0' )
                    {
                        int id = (lastC -'0')*10+(curC - '0');
                        if ( id >= 11 && id <= 26)
                        {
                            oneStep = oneStep + twoStep;
                            twoStep = oneStep - twoStep;
                            lastC = *it;
                        }
                        else
                        {
                            twoStep = oneStep;
                            lastC = *it;
                        }
                    }
                    else
                    {
                        twoStep = oneStep;
                        lastC = *it;
                    }
                }
            }
            else
            {
                if ( lastC != '0' )
                {
                    int id = (lastC -'0')*10+(curC - '0');
                    if ( id >= 11 && id <= 26)
                    {
                        oneStep = oneStep + twoStep;
                        twoStep = oneStep - twoStep;
                        lastC = *it;
                    }
                    else
                    {
                        twoStep = oneStep;
                        lastC = *it;
                    }
                }
                else
                {
                    twoStep = oneStep;
                    lastC = *it;
                }
            }
            it++; // the one after '0'

        }

        return oneStep;

    }
};