// It's a brute-force solution, and it takes O(n^3 log(n) )

class Solution {
public:

    int quickSearch(vector<int> &num, int value, int start)
    {
        // assumuption: num is sorted in non-descending order 
        int size = num.size();
        int small = start;
        int large = size - 1;
        int mid = (small+ large) / 2;
        while( small < large)
        {
            if( num[mid] > value )
                large = mid - 1;
            else if( num[mid] < value)
                small = mid + 1;
            else
                return mid; // got you

            mid = (small + large) / 2;
        }
        if( (num[mid] == value) && (small == mid) )
            return mid;
        return -1; // we can not find it.

    }

    bool isEqual(vector<int> &a, vector<int> &b)
    {
        if ( (a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2])  )
        {
            return true;
        }   
        return false;
    }

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        if (num.size() < 4) return result;

        if ( num.size() == 4 )
        {
            if ( (num[0] + num[1] + num[2] + num[3]) == target)
            {
                vector<int>  tuple;
                tuple.push_back(num[0]);
                tuple.push_back(num[1]);
                tuple.push_back(num[2]);
                tuple.push_back(num[3]);
                result.push_back(tuple);
            }
            return result;
        }

        for( unsigned int i = 0; i < num.size(); i++)
        {
            for( unsigned int j = i+1; j < num.size(); j++)
            {
                for( unsigned int k = j+1; k < num.size(); k++)
                {
                    int id = quickSearch(num, target -num[i] - num[j] - num[k], k+1);
                    if( id != -1 )
                    {
                        vector<int>  tuple;
                        tuple.push_back(num[i]);
                        tuple.push_back(num[j]);
                        tuple.push_back(num[k]);
                        tuple.push_back(num[id]);
                        bool insertFlag = true;
                        for(unsigned int l = 0; l < result.size(); l++)
                        {
                            if ( isEqual(result[l], tuple)  )
                            {
                                insertFlag = false;
                                break;
                            }
                        }
                        if(insertFlag)
                            result.push_back(tuple);

                    }
                }
            }
        }
        return result;
    }
};