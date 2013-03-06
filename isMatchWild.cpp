class Solution {
public:
    
    bool isEqual( char a, char b)
    {
        if ( a == '\0' ) return false;
        if ( b == '?' ) return true;
        if ( b == '*' ) return true;
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
        if ( !isEqual(s[0], p[0]) && (p[0] != '*') )
            return false;
            
        if ( p[0] == '*')
        {
            if ( regMatch(s, p+1) ) 
                return true;
                
            if ( s[0] != '\0' )
                return regMatch(s+1, p);   
            else
                return false; 
        }
        else
            return regMatch(s+1, p+1);            
    }

    void simplifyReg(const char * p, char * sp)
    {
        int counter = 0;
        int idx = 0;
        char pre = '.';
        while( p[counter] != '\0')
        {
            sp[idx] = p[counter];
            if( (pre != '*') || ( p[counter] != '*') )
            {
                idx++;
            }
            pre = p[counter];
            counter++;   
        }
        sp[idx] = '\0';
    }
    
    bool isMatchRec(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        char psim[256];
        simplifyReg(p, psim);  
        return regMatch(s, psim);
    }
    
    bool wildMatch(const char *s, const char *p)
    {
        
    }
    
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        char psim[256];
        simplifyReg(p, psim);  
        return wildMatch(s, psim);
    }
};