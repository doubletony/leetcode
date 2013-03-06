class Solution {
public:
    int minOne(int i, int j)
    {
        if (i < j)
            return i;
        else
            return j;

    }


    int maxAreaBruteForce(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int size = height.size();
        int currentMax = 0;
        for (int i =0; i < size ;i++)
        {
            for (int j = i; j < size; j++)
            {
                int tmp = (j -i) * minOne( height[i], height[j] );
                if (tmp > currentMax)
                {
                    currentMax = tmp;
                }
            }
        }
        return currentMax;
    }

    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( height.size() < 2 )
        {
            return 0;
        }

        if ( height.size() == 2)
        {
            return minOne(height[0], height[1]);
        }
        
        int start = 0;
        int end = height.size() - 1;
        int maxW = 0;
        int aH = minOne(height[start], height[end]);
        maxW = aH * (end - start);
        bool stop = false;
        while ( !stop )
        {
            stop = true;
            if ( height[start] > height[end])
            {
                // shrink end, search the nearest higher than end
                int nextEnd = end - 1;
                while ( nextEnd > start )
                {
                    if ( height[nextEnd] > height[end])
                    {
                        stop = false;
                        end = nextEnd;
                        break;
                    }
                    nextEnd--;
                }
            }
            else
            {
                // actually, we don't need to worry about equal case
                // increase start
                int newStart = start + 1;
                while ( end > newStart )
                {
                    if ( height[newStart] > height[start])
                    {
                        stop = false;
                        start = newStart;
                        break;
                    }
                    newStart++;
                }
            }

            if ( !stop )
            {
                // check the new area
                int aH = minOne(height[start], height[end]);
                int nw = aH * (end - start); // new water size
                if (  nw > maxW )
                {
                    maxW = nw;
                }
            }
        }

        return maxW;
    }

};