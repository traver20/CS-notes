# lintcode 913 greedy
[link](https://www.lintcode.com/problem/919/description)
给定一个会议的时间间隔序列，求出安排这些会议所需要的房间

## 思路
类比现实中的处理方式，碰到一个会议安排一个房间，所以按开始时间排序

每来一个会议，找到最早结束会议的房间，如果不能安排，则新增房间。

## code
~~~cpp
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        if(intervals.empty())
            return 0;
        sort(intervals.begin(),intervals.end(),[&](auto a,auto b){
            if(a.start==b.start)
                return a.end<b.end;
            return a.start<b.start;
        });
        priority_queue<int,vector<int>,greater<int>> q;
        q.push(intervals[0].end);
        for(int i=1;i<intervals.size();++i)
        {
            if(intervals[i].start>=q.top())
                q.pop();
            q.push(intervals[i].end);
        }
        return q.size();
    }
};
~~~