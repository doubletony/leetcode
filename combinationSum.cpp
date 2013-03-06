/*

I don't like the current implementation. But the idea is as follow:

First, we sort the candidates. 

(We also need pre-process the candidates to make this implementation working.
 1. we need remove the duplicates in the candidate. Otherwise, this code will return duplicates.)

Second, we recursively solve the problem. Given the array of candidates,
we have two possible ways to find a target sum:

- One is to use the current first number in the array, can find the new new target in a shorter array,
since the smaller target value can eliminate some large value in the end of the array.

- The other one is to drop the current first value, and search the target in the rest of array.

The idea is simple, but the code is not written neatly. Some tricks are:

1. quickSearch() is to search the index of the largest value that smaller than the input value.
2. combinationSumRec() is to generate all the results on the go of the searching, which should be
   handled carefully. The variable currenRsize is necessary to use.

*/
class Solution {
public:

    int quickSearch(vector<int> &num, int value, int start, int end)
    {
        // assumption: num is sorted in non-descending order 
        int mid = (start + end ) / 2;

        if ( (start+1) >= end)
        {
            return end;
        }

        if (mid == 0)
        {
            return end;
        }

        if ( mid == end )
        {
            return end;
        }

        if ( (num[mid]  >= value) && (num[mid -1] < value) )
        {
            return mid;
        }
        else if ( (num[mid])  < value) 
        {
            return quickSearch(num, value, mid, end);
        }
        else if ( (num[mid -1] >= value) )
        {
            return quickSearch(num, value, start, mid - 1);
        }
        else
        {
            return mid;
        }


    }

    bool combinationSumRec(vector<int> &candidates, int target, int start, int end, vector<vector<int> > & result )
    {
        if (target == 0)
        {
            vector<int> newTuple;
            result.push_back(newTuple);
            return true; // done
        }

        if ( target < 0)
        {
            return false; // done, but not find exact one
        }

        // not if target > 0, we need something to do
        bool found_one =false;


        // we try to move on to the next location, with the same target
        if ( (start+1) <= end)
        {
            if (combinationSumRec(candidates, target, start+1, end, result) )
            {
                found_one =  true;
            }
        }

        // If we chose to use the starting one
        int newTarget = target - candidates[start];
        int newEnd = quickSearch(candidates, newTarget, start, end);//get the proper end;
        if ( newEnd >= start)
        {
            int currenRsize = result.size();
            if (combinationSumRec(candidates, newTarget, start, newEnd, result) )
            {
                // well, if we found one, we can assume that the last of the result is set up
                for (int i = currenRsize; i < result.size(); i++)
                {
                    result[i].push_back(candidates[start]);
                }
                found_one = true;
            }
        }

        // well, if we reach here, then we found nothing
        return found_one;
    }


    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT wriste int main() function

        vector< vector<int> > result;
        sort(candidates.begin(), candidates.end());

        int end = candidates.size() - 1;
        end = quickSearch(candidates, target, 0, end);
        combinationSumRec(candidates, target, 0, end, result);

        //
        for (int i = 0; i < result.size(); i++)
        {
            reverse(result[i].begin(), result[i].end() );
        }
        
        return result;

    }
};