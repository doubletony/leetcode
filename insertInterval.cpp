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
public:

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<Interval> result;
        int i  = 0;
        Interval newOne;
        int idx;
        for (i = 0 ;i < intervals.size(); i++)
        {
            if ( intervals[i].end < newInterval.start)
            {
                result.push_back(intervals[i]);
            }
            else
            {
                break;
            }
        }

        if ( i >= intervals.size())
        {
            result.push_back(newInterval);
            return result;
        }

        result.push_back(newOne);
        idx = result.size() - 1;
        if ( intervals[i].start < newInterval.start )
        {
            result[idx].start = intervals[i].start;
        }
        else
        {
            result[idx].start = newInterval.start;
        }

        for (; i < intervals.size(); i++)
        {
            if (intervals[i].end < newInterval.end)
            {
                continue;
            }
            else
            {
                break;
            }
        }
            
        if ( i >= intervals.size() )
        {
            result[idx].end = newInterval.end;
            return result;
        }
                
        if ( newInterval.end < intervals[i].start)
        {
            result[idx].end = newInterval.end;
        }
        else
        {
            result[idx].end = intervals[i].end;
            i++;
        }


        for (; i < intervals.size(); i++)
        {
            result.push_back(intervals[i]);
        }
        
        return result;
    }
};
