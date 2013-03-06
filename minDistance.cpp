/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
class Solution {
public:

    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if ( word1.length() == 0)
        {
            return word2.length();
        }

        if (word2.length() == 0)
        {
            return word1.length();
        }

        vector< vector<int> >  table;
        table.resize( word1.length() + 1);

        for (int i = 0; i <= word1.length(); i++)
        {
            table[i].resize(word2.length() + 1);
        }

        // fill the table with initial state

        for (int i = 0; i <= word1.length(); i++)
        {
            table[i][0] = i;
        }

        for (int i = 0; i <= word2.length(); i++)
        {
            table[0][i] = i;
        }


        for (int i = 1; i <= word1.length(); i++)
        {
            for (int j = 1; j <= word2.length(); j++)
            {
                int curMin = table[i][j-1] + 1;

                if ( ( table[i-1][j] + 1 )  < curMin)
                {
                    curMin = table[i-1][j] + 1;
                }

                int diagCost = 1;
                if (  word1[i-1] == word2[j-1])
                {
                    diagCost = 0;
                }

                if ( ( table[i-1][j-1] + diagCost )  < curMin)
                {
                    curMin = table[i-1][j-1] + diagCost;
                }

                table[i][j] = curMin;
            }
        }
        return table[ word1.length() ][word2.length() ];
    }
};