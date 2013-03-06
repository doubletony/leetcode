class Solution {
public:
    
    bool isEqual( char a, char b)
    {
        if ( a == '\0' ) return false;
        if ( b == '.' ) return true;
        if ( a == b )  return true;
        return false;
    }
    
    bool regMatch(const char *s, const char *p)
    {
        if ( p[0] == '\0' && s[0] == '\0')
        {
            // we reach the end of matching pair
            return true;
        }

        if ( (p[0] == '\0' && s[0] != '\0') )
        {
            // The regex reaches its end,
            // but the string does not.
            return false;
        }
        
        // we have at least one char left in regex
        if ( (!isEqual(s[0], p[0])) && (p[1] != '*') )
            return false;
            
        if ( p[1] == '\0' )
        {
            // potential problem, if s looks like
            return regMatch(s + 1, p + 1);                  
        }
        else
        {
            if ( p[1] == '*' )
            {
                if (regMatch(s, p+2) ) 
                    return true;
                if ( isEqual(s[0], p[0]) ) 
                    return regMatch(s+1, p);
                else 
                    return false;
            }
            else
                return regMatch(s + 1, p + 1);
        }            
    }

    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        return regMatch(s, p);
    }
};