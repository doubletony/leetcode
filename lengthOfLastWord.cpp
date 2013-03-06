class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int total = 0;
        while( s[total] != '\0' )
        {
            total++;
        }
        if (total == 0)
        {
            return 0;
        }
        int wordLenght = 0;
        int i = total - 1;
        for ( ; i >= 0; i--)
        {
            if (s[i] == ' ') continue;
            else  break;
        }

        for ( ; i >= 0; i--)
        {
            if (s[i] != ' ') wordLenght++;
            else  break;
        }
        return wordLenght;
    }
};