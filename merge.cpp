/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    class Node 
    {
    public:
        int val;
        int idx;
        Node(int v, int id) {val = v; idx = id;};
        bool operator<(const Node& rhs) const { return this->val < rhs.val; };
    };

public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Node> leftVals;
        for (int i = 0; i < intervals.size(); i++)
        {
            leftVals.push_back( Node(intervals[i].start, i)  );
        }

        sort(leftVals.begin(), leftVals.end());
        
        vector<Interval>  result;
        if ( intervals.size() == 0)
        {
            return result;
        }

        int currId = 0;
        int currVal = intervals[ (leftVals[currId].idx)].end;
        int rsltsize = 1;
        result.push_back( Interval(leftVals[currId].val, currVal) );

        for (int i = 1; i < intervals.size(); i++)
        {
            if ( leftVals[i].val <= result[rsltsize - 1].end )
            {
                // merge it
                result[rsltsize - 1].end  = max(result[rsltsize - 1].end , intervals[ (leftVals[i].idx)].end );
            }
            else
            {
                // new one
                result.push_back( Interval(leftVals[i].val, intervals[ (leftVals[i].idx)].end) );
                rsltsize = result.size();
            }
        }

        return result;
    }

};