/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.
*/
Approach - merge then sort then handle the overlapping.
Can be Handle with stack also.
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval a,Interval b)
{
    return a.start<b.start;
}
vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval) {
    A.push_back(newInterval);
    sort(A.begin(),A.end(),comp);
    vector<Interval>res;//can be done with O(1) space by temp variable
    res.push_back(A[0]);
    for(int i=1;i<A.size();i++)
    {
        if(A[i].start<=res[res.size()-1].end)
        res[res.size()-1].end=max(A[i].end,res[res.size()-1].end);
        else
        res.push_back(A[i]);
    }
    return res;
}
