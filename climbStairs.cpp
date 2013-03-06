class Solution {
public:

    int climbStairsNaive(int n)
    {
        if ( n == 1)
        {
            return 1;
        }
        
        if ( n == 2)
        {
            return 2;
        }

        return climbStairsNaive(n-1) + climbStairsNaive(n-2);
    }

    int climbStairsDPRec(int n, vector<int> &table)
    {
        if ( n == 1)
        {
            table[1] = 1;
            return 1;
        }

        if ( n == 2)
        {
            table[2] = 1;
            return 2;
        }

        int oneStep , twoStep;
        if (table[n-1] != -1)
        {
            oneStep = table[n-1];
        }
        else
        {
            oneStep = climbStairsNaive(n-1);
        }

        if (table[n-2] != -1)
        {
            twoStep = table[n-2];
        }
        else
        {
            twoStep = climbStairsNaive(n-2);
        }
        table[n] = oneStep+twoStep;
        return oneStep+twoStep;
    }

    int climbStairsDP(int n)
    {
        if ( n == 1)
        {
            return 1;
        }

        if ( n == 2)
        {
            return 2;
        }
        vector<int>  table;
        table.resize(n+1, 0);
        table[0] = 0;
        table[1] = 1;
        table[2] = 2;
        for (int i = 3; i <=n; i++)
        {
            table[i] = table[i-1] + table[i-2];
        }
        return table[n];
    }
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return climbStairsDP(n);
    }
};
