#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [&](auto a, auto b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
            });
            priority_queue<int, vector<int>, greater<int>> q;
            q.push(intervals[0][1]);
            for (int i = 1; i < intervals.size(); ++i)
            {
                if (intervals[i][0] >= q.top())
                    q.pop();
                q.push(intervals[i][1]);
            }
            return q.size();
    }
};

int main()
{
    
}