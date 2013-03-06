class Solution {
public:

    unsigned int reverseInt(unsigned int x, unsigned int &shifts)
    {
        if ( x < 10)
        {
            return x;
        }
        unsigned a = x % 10;
        unsigned tmp = reverseInt( x/10, shifts );
        shifts *= 10;
        return a*shifts+tmp;
    }

    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        unsigned int shift = 1;
        if (x < 0)
        {
            int v = reverseInt( -x, shift );

            return -v;
        }
        else
        {
            int v = reverseInt( x, shift );
            return v;
        }
    }
};