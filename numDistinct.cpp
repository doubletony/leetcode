/*

The idea is simple. Recursively find the matched substring

For example , 'abcabc', 'abc',

the sum is ('bcabc', 'bc') + ('bc', 'bc) ...
and recursivly for the string 'bc'

*/

class Solution {
public:

    std::map <string, int> solMap;

    int checkSame(string S, string T, int sS, int sE, int tS, int tE)
    {
        int len = sE - sS;
        for (int i = 0; i < len; i++)
        {
            if ( S[sS+i] !=  T[tS+i] )
            {
                return 0;
            }
        }
        return 1;
    }

    int countSub(string S, string T, int sS, int sE, int tS, int tE)
    {
        if ( tE == 0 || sE == 0)
        {
            return 0;
        }

        if (  (tE - tS) == 0 )
        {
            return 1;
        }

        if (  (sE - sS) == 0 )
        {
            return 0;
        }

        if ( (sE - sS) < (tE - tS) )
        {
            return 0;
        }

        if ( (sE - sS) == (tE- tS)  )
        {
            return checkSame(S, T, sS, sE, tS, tE);
        }

        // otherwise, search sub strings.
        int count = 0;
        char curC = T[tS];
        string key = S.substr(sS, sE-sS) + string(":") + T.substr(tS, tE - tS);

        if ( solMap.find(key) != solMap.end() )
        {
            return solMap[key];
        }

        for (int i = sS; i < sE; i++)
        {
            if ( S[i] == curC)
            {
                count = count + countSub(S, T, i+1, sE, tS+1, tE); 
            }
        }
        
        
        solMap[key] = count;
        return count;
    }

    // well, since there are insane inputs, we need refine the source.
    string refineSourceString(string S, string T)
    {
        int table[128];
        int lenS, lenT;
        lenS = S.length();
        lenT = T.length();

        for (int i = 0; i < 128; i++)
        {
            table[i] = 0;
        }

        // mark character in target
        for (int i = 0; i < lenT; i++)
        {
            table[T[i]] = 1;
        }

        string refineS;
        for (int i = 0; i < lenS; i++)
        {
            if (  table[ S[i] ] != 0)
            {
                refineS.push_back( S[i] );
            }
        }
        return refineS;

    }

    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        solMap.clear();
        S = refineSourceString(S, T);
        int lenS, lenT;
        lenS = S.length();
        lenT = T.length();
        return countSub(S,T, 0, lenS, 0, lenT );

    }
};