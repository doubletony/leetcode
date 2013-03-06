class Solution {
public:
    string lookUpTable[9];

    Solution ()
    {
        lookUpTable[0] = "11"; //   1: 11
        lookUpTable[1] = "12"; //   2: 12
        lookUpTable[2] = "13"; //   3: 13
        lookUpTable[3] = "21"; //  11: 21
        lookUpTable[4] = "22"; //  22: 22
        lookUpTable[5] = "23"; //  33: 23
        lookUpTable[6] = "31"; // 111: 31
        lookUpTable[7] = "32"; // 222: 32
        lookUpTable[8] = "33"; // 333: 33
    }

    string lookup(int num)
    {
        switch (num)
        {
        case   1: return lookUpTable[0]; break;
        case   2: return lookUpTable[1]; break;
        case   3: return lookUpTable[2]; break;
        case  11: return lookUpTable[3]; break;
        case  22: return lookUpTable[4]; break;
        case  33: return lookUpTable[5]; break;
        case 111: return lookUpTable[6]; break;
        case 222: return lookUpTable[7]; break;
        case 333: return lookUpTable[8]; break;
        }
        return " "; // error
    }

    string readString(string str)
    {
        string rst;

        string::iterator it = str.begin();
        char c;
        c = *it;
        it++;
        int lookValue = c - '0';
        while ( it < str.end() )
        {
            if ( (*it) == c )
            {
                lookValue = lookValue * 10 + (c - '0');
            }
            else
            {
                rst += lookup(lookValue);
                c = *it;
                lookValue = c - '0';
            }
            it++;
        }
        // read the last one
        rst += lookup(lookValue);
        return rst;

    }

    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( n == 1)
        {
            return "1";
        }

        string rst = "1";
        while( n > 1)
        {
            rst = readString(rst);
            n--;
        }
        return rst;
    }
};