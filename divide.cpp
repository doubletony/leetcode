//
// Divide two integers without using multiplication, division and mod operator.
// 

class Solution {
public:

    int insaneDivide(int largeIn, int smallIn)
    {
        int negtiveLarge = 1;
        int negtiveSmall = 1;
        unsigned int large, small;

        if ( largeIn < 0)
        {
            negtiveLarge = -1;
            large = - largeIn;
        }
        else
        {
            large = largeIn;
        }

        if ( smallIn < 0)
        {
            negtiveSmall = -1;
            small = -smallIn;
        }
        else
        {
            small = smallIn;
        }

        if ( largeIn ==  0)
        {
            return 0;
        }

        if ( smallIn ==  0)
        {
            // WHAT ?
            return 0;
        }

        // now everything is positive


        if (large < small)
        {
            return 0; 
        }

        // do stupid counting stuff
        int count = 0;
        while ( large >= small)
        {
            int rsl = 0;
            int tmp = large >> 1; // the leftend will fill with 0
            while ( tmp >= small )
            {
                rsl += 1;
                tmp = tmp >> 1;
            }
            count += (1<<rsl);
            tmp = small << rsl;
            large = large - tmp;
        }

        if ( negtiveLarge == -1)
        {
            count = -count;
        }

        if ( negtiveSmall == -1)
        {
            count = -count;
        }

        return count;
    }

    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return insaneDivide(dividend, divisor);
    }
};