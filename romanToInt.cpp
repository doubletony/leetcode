class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a[200];
        for (int i = 0; i < s.length(); i++)
        {
            switch( s[i])
            {
                case 'I': a[i] = 1;break;
                case 'V': a[i] = 5;break;
                case 'X': a[i] = 10;break;
                case 'L': a[i] = 50;break;
                case 'C': a[i] = 100;break;
                case 'D': a[i] = 500;break;
                case 'M': a[i] = 1000;break;
            }
        }

        int rstl = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if ( a[i] < a[i+1] )
            {
                rstl -= a[i];
            }
            else
            {
                rstl += a[i];
            }
        }

        rstl += a[s.length() - 1];
        return rstl;
    }
};