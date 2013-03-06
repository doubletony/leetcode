class Solution {
public:

    // the right way
    
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
            maxTable[i] = prices[i] - prices[i-1];

        }

        int max = 0;
        for (int i = 0; i < size; i++)
        {
            if (maxTable[i] > 0)
                max += maxTable[i];
        }
        return max;
    }
};