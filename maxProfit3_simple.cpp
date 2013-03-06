class Solution {
public:

    int maxProfit1(vector<int> &prices, int start, int end) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = end - start + 1;
        if ( size < 2 ) 
        {
            // [bug here]. forgot to check length
            return 0;
        }

        vector<int> futrueMax;
        futrueMax.resize( size );
        int curmax = -2012; // we should assume that there is no negative value

        // sweep from the end

        for ( int i = end; i >= start; i-- ) 
            // for ( unsigned int i = prices.size() - 1; i >= 0; i-- ) 
            // [bug here], unsigned will never less than 0
        {
            if ( prices[i] > curmax)
            {
                curmax = prices[i];
            }
            futrueMax[i - start] = curmax;
        }

        // sweep from the head
        int curmin = curmax + 1; // we should loose.
        int curMaxprot = 0;

        for ( int i = start; i < end; i++ )
        {
            if ( prices[i] < curmin)
            {
                curmin = prices[i];
            }

            int curprof = futrueMax[i-start] - curmin;
            if ( curprof > curMaxprot )
            {
                curMaxprot = curprof;
            }
        }
        return curMaxprot;
    }

    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 2)
        {
            return 0;
        }
        int max = 0;
        int n = prices.size();
        return 0;
    }
};