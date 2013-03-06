class Solution {
public:
    int largestRectangleArea_brute_force(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxArea  = 0;
        for (int i = 0; i < height.size(); i++)
        {
            int left,right;
            // left search
            left = right = i;
            while (left >= 0)
            {
                if (height[left] >= height[i])
                {
                    left--;
                }
                else
                {
                    break;
                }
            }

            while (right < height.size())
            {
                if (height[right] >= height[i])
                {
                    right++;
                }
                else
                {
                    break;
                }
            }
            int area = height[i] * (right - left - 1);
            if (area > maxArea)
            {
                maxArea = area;
            }
        }
        return maxArea;
    }

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
};

