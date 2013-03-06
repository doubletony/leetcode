class Solution {
public:

    // do in another way
    
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 2 )
        {
            return 0;
        }
        int size = prices.size();
        vector<int> maxTable;
        maxTable.resize( size );
        maxTable[0] = 0;

        for (int i = 1; i < size; i++)
        {
            int curb = maxTable[i-1] ;
            for (int j = 0; j < i; j++)
            {
                if ( (prices[i] - prices[j] + maxTable[j] ) > curb )
                {
                    curb = prices[i] - prices[j] + maxTable[j];
                }
            }
            maxTable[i] = curb;

        }
        int max = 0;
        return maxTable[size -1];
    }
};