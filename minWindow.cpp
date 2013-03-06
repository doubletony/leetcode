class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int totalTargetCounter = 0;
        vector< int > targetCounter( 256, 0 );
        vector< int > currentCounter( 256, 0 );

        // initialize the target counter
        for (int i = 0; i < T.length(); i++)
        {
            targetCounter[ T[i] ] += 1;
            totalTargetCounter++;
        }

        int totalCounter = 0;
        int right;
        for (int i = 0; i < S.length(); i++)
        {
            char curChar = S[i];
            currentCounter[curChar] += 1;
            if ( currentCounter[ curChar ]<= targetCounter[ curChar ]  )
            {
                totalCounter++;
                if ( totalCounter == totalTargetCounter)
                {
                    right = i;
                    break;
                }
            }
        }

        if ( totalCounter < totalTargetCounter) return ""; // not find

        int left = 0;
        int minLeft = left;
        int minRight = right;
        left++;
        bool stop = false;
        while ( left < S.length() && (!stop) )
        {
            // shrink the left
            char curChar = S[left - 1];
            currentCounter[curChar] -= 1;
            if ( currentCounter[curChar] < targetCounter[ curChar ] )
            {
                stop = true;
                right++;

                // need to expand right to keep the valid status
                while( right < S.length() )
                {
                    currentCounter[ S[right] ] += 1;
                    if ( S[right] == curChar)
                    {
                        if ( (right - left) < (minRight - minLeft))
                        {
                            minLeft = left;
                            minRight = right;
                        }
                        stop = false;
                        break;
                    }
                    right++;
                }
            }
            else if ( (right - left) < (minRight - minLeft))
            {
                minLeft = left;
                minRight = right;
            }
            left++;
        }
        return S.substr( minLeft, minRight - minLeft + 1);

    }
};