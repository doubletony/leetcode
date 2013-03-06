class Solution {
public:


    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 2 )
        {
            return 0;
        }
        int size = prices.size();
        vector< vector<int> > maxTable;
        maxTable.resize( size);
        for (int i = 0; i < size; i++)
        {
            maxTable[i].resize( size, 0 );

        }
        // initialized 
        for (int i = 0; i < size - 1; i++)
        {
            if ( (prices[i+1] - prices[i]) > 0 )
            {
                maxTable[i][i+1] = prices[i+1] - prices[i];
            }
        }

        for (int gap = 2; gap < size; gap++ )
        {
            // day window
            for ( int starDay = 0; starDay < size; starDay++ )
            {
                if ( (starDay + gap) >= size)
                {
                    // the startDay no need to check
                    continue;;
                }

                int best = -1;
                for (int k = 1; k < gap; k++)
                {
                    int tmp = maxTable[starDay][starDay+k] + maxTable[starDay+k][starDay+gap];
                    if ( tmp > best )
                    {
                        best = tmp;
                    }
                }
                maxTable[starDay][starDay+gap] = best;
            }
        }
        return maxTable[0][size - 1];
    }
};