class Solution 
{
public:
    /*
    The idea is simple: assume the array is sorted, and we have subroutine called 2sumclosest.
    Then, we iterate through the array. The for-loop can be stopped earlier, if the current least
    sum is larger than current closest value to the target.

    We apply the similar idea to write up the 2sumcloest subroutine.
        
    */
    int sumTwoCloest(vector<int> * num, int start, int size, int target)
    {
        int leftnums = size - start;
        if( leftnums < 2 ) return 0; // error
        if( leftnums == 2 ) return (*num)[start] + (*num)[start+1]; // error
        int currBest = 0;
        int signBest = 0;

        currBest = (*num)[start] + (*num)[start+1] - target;
        if (currBest > 0)
        {
            signBest = 1;
        }
        else
        {
            currBest = -currBest;
            signBest = -1;
        }

        for (unsigned int i = start; i < size ; ++i)
        {
            int tail = size - 1;

            if ( ((*num)[i] + (*num)[i+1] - target) >= currBest )
            {
                break;
            } // break for loop, that is the smallest value we can obtain from now on.

            if ( ((*num)[tail] + (*num)[tail - 1] - target ) <= -currBest )
            {
                break;
            } // break for loop also, since that is the largest value we can get.

            // otherwise, we have a chance to beat current best
            for (unsigned int j = i+1; j < size; j++)
            {
                int currVal = ((*num)[i] + (*num)[j] - target);
                if ( ( currVal > -currBest) && (currVal < currBest)  )
                {
                    // we find a better one
                    if ( currVal > 0)
                    {
                        currBest = currVal;
                        signBest = 1;
                    }
                    else
                    {
                        currBest = -currVal;
                        signBest = -1;
                    }
                }
                else
                {
                    if ( currVal > currBest)
                    {
                        break;
                    }
                }
            }

        }
        return target + signBest * currBest;
    }

    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        if ( num.size() < 3) return -1; // error
        int currBest = num[0] + num[1] + num[2];

        for (unsigned int i = 0; i < num.size()-2; ++i)
        {

            if ( (num[i] + num[i+1]+num[i+2] - target) > abs(currBest - target) )
            {
                break;
            } // we can break it, since that's the smallest we can get from now on.

            int twoBest = 0;
            twoBest = sumTwoCloest(&num, i+1, num.size(), target - num[i]);
            if ( abs(num[i] + twoBest - target) < abs(currBest - target))
            {
                currBest = num[i] + twoBest;
            }
        }
        return currBest;
    }
};
