class Solution {
public:

    bool isValid( string s)
    {
        if ( s.length() > 1)
        {
            if( s[0] == '0' ) return false;
        }
        if ( s.length() < 3 && s.length() > 0)
            return true;

        if ( s.length() == 3)
        {
            if ( s[0] < '2')
            {
                return true;
            }
            else if ( s[0] == '2')
            {
                if ( s[1] < '5')
                {
                    return true;
                }
                else if ( s[1] == '5')
                {
                    if ( s[2] <= '5')
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void doIp(string ipstr, int * idx, int cur, vector<string> &ret)
    {

        int start = 0;
        if ( cur > 0) start = idx[cur - 1];

        if ( cur == 3)
        {
            // valid;
            string lastip = ipstr.substr( start, ipstr.length() - start );
            if ( isValid(lastip) )
            {
                string restl;
                restl.append( ipstr.substr( 0, idx[0]) );
                restl.push_back('.');
                restl.append( ipstr.substr( idx[0], idx[1] - idx[0]) );
                restl.push_back('.');
                restl.append( ipstr.substr( idx[1], idx[2] - idx[1]) );
                restl.push_back('.');
                restl.append(lastip);
                ret.push_back( restl);
            }
            return ;
        }

        for (int i = 1; i <= 3; i++)
        {
            if ( start + i > ipstr.length())
            {
                break;
            }
            string suip = ipstr.substr( start, i);
            if ( isValid(suip) )
            {
                idx[cur] = start+i;
                doIp(ipstr, idx, cur+1, ret);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int idx[3];
        vector<string> ret;
        
        doIp(s, idx, 0, ret );
        return ret;
    }
};