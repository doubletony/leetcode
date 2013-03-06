/*
Idea:
Assume we have (n,k), and all of them are sorted.
Then, we can obtain (n, k+1) easily by insert new number in the (n,k).

For example, (4,3)
Obtain (4,1) as

[ [1], [2], [3], [4] ] 

Obtain (4,2) as

[ [1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4] ] 

Obtain (4,3) as

[ [1, 2, 3], [1, 2, 4], [1, 3, 4], [2, 3, 4] ] 

*/

class Solution {
public:

    int maxVec(vector<int> &ve)
    {
        int size = ve.size();
        if (size > 0)
        {
            return ve[size-1];
        }
        else
        {
            return -1; // error
        }
    }

    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector< vector<int> > rsl;
        if (k == 0 )
        {
            return rsl;
        }

        queue< vector<int> > q;
        for (int i = 1; i <= n; i++)
        {
            vector<int> vec;
            vec.push_back(i);
            q.push(vec);
        }
        k--;

        while( k > 0 )
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                vector<int> vec = q.front();
                q.pop();
                int maxv = maxVec(vec);
                for ( int j = maxv+1; j <= n; j++ )
                {
                    vector<int> vecneq = vec;
                    vecneq.push_back(j);
                    q.push(vecneq);
                }
            }
            k--;
        }
        // done.
        while( !q.empty())
        {
            rsl.push_back( q.front() );
            q.pop();
        }
        return rsl;
    }
};