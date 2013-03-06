class Solution {
public:

    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> rest;
        if (rowIndex < 0)
        {
            return rest;
        }

        if (rowIndex == 0)
        {
            rest.push_back(1);
            return rest;
        }

        if (rowIndex == 1)
        {
            rest.push_back(1);
            rest.push_back(1);
            return rest;
        }
        
        unsigned int currUp, currBot;
        unsigned int currEl;
        currUp = rowIndex;
        currBot = 1;
        currEl = rowIndex;
        int k = rowIndex - 2;
        rest.push_back(1);
        rest.push_back(currEl);

        while( k >=0 )
        {
            currUp--;
            currBot++;
            currEl = (currEl*currUp)/currBot;
            rest.push_back(currEl);
            k--;
        }
        return rest;
    }
};