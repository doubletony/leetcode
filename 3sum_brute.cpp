// It's a brute-force solution, and it takes O(n^2 log(n) )

class Solution {
public:

    int quickSearch(vector<int> &num, int value, int start)
    {
        // assumuption: num is sorted in non-descending order 
        int size = num.size();
        int small = start;
        int large = size - 1;
        int mid = (small+ large) / 2;
        while( small <= large)
        {
            mid = (small + large) / 2;
            if( num[mid] > value )
                large = mid - 1;
            else if( num[mid] < value)
                small = mid + 1;
            else
                return mid; // got you
                
        }
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
    
    vector<vector<int> > threeSumBF(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        for( unsigned int i = 0; i < num.size(); i++)
        {
            for( unsigned int j = i+1; j < num.size(); j++)
            {
                int id = quickSearch(num, -num[i] - num[j], j+1);
                if( id != -1 )
                {
                    vector<int>  tuple;
                    tuple.push_back(num[i]);
                    tuple.push_back(num[j]);
                    tuple.push_back(num[id]);
                    bool insertFlag = true;
                    for(unsigned int k = 0; k < result.size(); k++)
                    {
                        if ( isEqual(result[k], tuple)  )
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
        return result;
    }

    vector<vector<int> > twoSum(vector<int> &num, int start, int end) 
    {
        
    }

    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        for( unsigned int i = 0; i < num.size(); i++)
        {
            for( unsigned int j = i+1; j < num.size(); j++)
            {
                int id = quickSearch(num, -num[i] - num[j], j+1);
                if( id != -1 )
                {
                    vector<int>  tuple;
                    tuple.push_back(num[i]);
                    tuple.push_back(num[j]);
                    tuple.push_back(num[id]);
                    bool insertFlag = true;
                    for(unsigned int k = 0; k < result.size(); k++)
                    {
                        if ( isEqual(result[k], tuple)  )
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
        return result;
    }
};