class Solution {


public:

    int largestRectangleArea(vector<int> &height) 
    {
        stack<int> s;
        int maxArea = 0;
        int i = 0;
        height.push_back(0);
        while ( i < height.size())
        {
            if (s.empty())
            {
                s.push(i);
                i++;
            }
            else if ( height[ s.top() ] <= height[i] )
            {
                s.push(i);
                i++;
            }
            else
            {
                int t = s.top();
                s.pop();
                int tmparea = 0;
                if ( s.empty())
                {
                    tmparea = height[t] * i;
                }
                else
                {
                    tmparea = height[t] * (i - s.top() - 1);
                }
                if (tmparea > maxArea)
                {
                    maxArea = tmparea;
                }
            }
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT writea int main() function
        if (matrix.size() == 0) return 0;

        vector< vector <int> > counter ( matrix.size(),  vector<int> (matrix[0].size(), 0) );
        for (int col = 0; col < matrix[0].size(); col++)
        {
            if( matrix[0][col] == '1' )
                counter[0][col] = 1;
        }

        for (int row = 1; row < matrix.size(); row++)
        {
            for (int col = 0; col < matrix[0].size(); col++)
            {
                if( matrix[row][col] == '1' )
                    counter[row][col] = counter[row-1][col] + 1;
                else
                    counter[row][col] = 0;
            }
        }
        
        int maxArea = 0;

        for (int row = 0; row < matrix.size(); row++)
        {
            vector <int>  heights;
            for (int j = 0; j < matrix[row].size(); j++)
            {
                heights.push_back( counter[row][j] );
            }

            maxArea = max( maxArea, largestRectangleArea(heights) );
        }

        return maxArea;
    }
};