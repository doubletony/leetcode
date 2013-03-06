class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        unsigned int rsl = 0;
        int neg = 1;
        while ( str[i] != '\0' && str[i] == ' ' )
        {
            i++;
        }

        if ( str[i] == '-')
        {
            neg = -1;
            i++;
        }

        if ( str[i] == '+')
        {
            i++;
        }

        while ( str[i] != '\0' && str[i] >= '0' && str[i] <= '9'  )
        {
            rsl = rsl*10 + str[i] - '0';
            i++;
        }
        return neg * rsl;
    }
};