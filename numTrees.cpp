class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> catalan(n+1, 0);
        catalan[0] = 1;
        catalan[1] = 1;
        catalan[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            for (int k = 0; k < i; k++)
            {
                catalan[i] += ( catalan[k] * catalan[i-1-k]);
            }
        }
        return catalan[n];
    }
};