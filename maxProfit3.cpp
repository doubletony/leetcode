class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        vector<int> maxBefore(n, 0);
        vector<int> maxAfter(n, 0);
        
        if ( n < 2)
        {
            return 0;
        }
        int maxpossible = 0;
        int curMin = prices[0];

        for (int i = 0; i < n; i++)
        {
            if ( prices[i] < curMin)
            {
                curMin = prices[i];
            }

            if ( (prices[i] - curMin) > maxpossible)
            {
                maxpossible = prices[i] - curMin;
            }

            maxBefore[i] = maxpossible;
        }

        maxpossible = 0;
        int curMax = prices[n-1];

        for (int i = n-1; i >= 0 ; i--)
        {
            if ( prices[i] > curMax)
            {
                curMax  = prices[i];
            }
            if ( (curMax - prices[i]) > maxpossible)
            {
                maxpossible = curMax - prices[i];
            }

            maxAfter[i] = maxpossible;
        }

        int retmax = 0;
        for (int i = 0; i < n; i++)
        {
            retmax = max ( retmax, maxBefore[i] + maxAfter[i] );
        }
        return retmax;
    }
};