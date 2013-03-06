class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( n < 0)
        {
            x = 1.0/x;
            n = -n;
        }

        if ( n == 0 )
        {
            return 1;
        }

        if ( n == 1)
        {
            return x;
        }

        if ( n == 1)
        {
            return x;
        }

        if ( (n % 2) == 0 )
        {
            double tmp = pow(x, n / 2);
            return tmp*tmp;
        }
        else
        {
            double tmp = pow(x, n / 2);
            return tmp*tmp*x;
        }
    }
};