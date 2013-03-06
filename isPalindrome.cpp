class Solution {
public:
    bool isPalindrome(int x) 
    {
        if ( x >= 0 )
        {
            return isWrapperPalindrome(x);
        }
        else
        {
            return false;
        }
    }

    bool isWrapperPalindrome(unsigned int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (x <= 9)
        {
            return true;
        }

        int last = x % 10;
        int counter, divi;
        counter = 0;
        divi = 1;
        int tmp = x;
        while( tmp >= 10)
        {
            tmp = tmp / 10;
            counter++;
            divi *= 10;
        }
        unsigned int pealoutx;
        pealoutx = x - last * divi;
        if ( pealoutx >= divi)
        {
            return false;
        }

        if ( pealoutx < 0)
        {
            return false;
        }

        pealoutx = pealoutx / 10;
        if (pealoutx == 0)
        {
            return true;
        }
        if ( (pealoutx % 10) == 0 )
        {
            // check zeroes
            int times = 1;
            while( (pealoutx*100) < (divi/times))
            {
                // be clear about why we need multiply it by 100
                times *= 10;
            }

            if ( (pealoutx % times) != 0)
            {
                return false;
            }
            else
            {
                pealoutx = pealoutx / times;
            }
        }
        return isWrapperPalindrome(pealoutx);
    }
};