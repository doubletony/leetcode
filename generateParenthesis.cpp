


class Solution {
public:

    void nextCombination(vector<int> &p, int n)
    {
        // generate the next parenthesis, given the current status.
        // 1 for '(', and 0 for ')'

        // count how many '(' from the end
        if ( p[0] == 0 )
        {
            return ; // impossilbe case
        }

        int count_end = 0;
        int i;
        for ( i = 2*n -1; i >= 0; i--)
        {
            if ( p[i] == 1)
            {
                count_end++;
                p[i] = 0;
            }
            else
            {
                break;
            }
        }

        for ( ; i >= 0; i--)
        {
            if ( p[i] == 1)
            {
               count_end++;
               p[i] = 0;
               break;
            }
        }

        if ( i < 0)
        {
            return ;
        }

        for (int j = 0; j < count_end; j++)
        {
            p[i+j+1] = 1;
        }

    }

    bool isValid(vector<int> &p, int n)
    {
        if ( p[0] == 0)
        {
            return false;
        }

        if ( p[2*n-1] == 1 )
        {
            return false;
        }

        int count = 0;
        for (int i = 0; i < 2*n; i++)
        {
            if ( p[i] == 1)
                count++;
            else
                count--;   
            if (count < 0)
            {
                return false;
            }
        }
        return true;
    }

    string convertToString(vector<int> &p, int n)
    {
        string s;
        s.resize( 2*n);
        for (int i = 0; i < 2*n; i++)
        {
            if (p[i] == 1)
            {
                s[i] = '(';
            }
            else
            {
                s[i] = ')';
            }
        }
        return s;
    }

    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> rslt;

        if (n == 0)
        {
            return rslt;
        }

        vector<int> p(n*2 , 0);

        for (int i =0; i < n; i++)
        {
            p[i] = 1;
        }

        while ( p[0] == 1 )
        {
            // still have possible to be valid;
            if ( isValid(p, n) )
            {
                rslt.push_back(  convertToString(p,n));
            }

            nextCombination(p,n);
        }
        
        return rslt;
    }
};    