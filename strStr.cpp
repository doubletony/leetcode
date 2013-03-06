class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if ( haystack == NULL)
        {
            return NULL;
        }
        
        if ( needle == NULL)
        {
            return NULL;
        }

        // let assume it's well defined
        int lenH = strlen(haystack);
        int lenN = strlen(needle);

        if (lenN == 0)
        {
            return haystack;
        }
        char * pos = NULL;
        for (int i = 0; i <= (lenH - lenN); i++)
        {
            if ( haystack[i] == needle[0] )
            {
                //
                bool foundIt = true;
                for (int j = 0; j < lenN; j++)
                {
                    if ( haystack[i+j] != needle[j] )
                    {
                        foundIt = false;
                        break;
                    }
                }

                if (foundIt)
                {
                    pos = &(haystack[i]);
                    break;
                }
            }
        }

        return pos;
    }
};