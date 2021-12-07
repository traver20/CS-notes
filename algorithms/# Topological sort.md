# Topological sort
[leetcode 210](https://leetcode.com/problems/course-schedule-ii/)

## 问题描述
首先判断有向图里有无环，有环则没有拓扑排序
官方定义：
>a topological sort or topological ordering of a directed graph is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering.

即若有一条u指向v的有向边，则序列里u必须在v前面

## BFS
不断寻找入度为0的点，加入到序列中，接着减少其指向节点的入度

~~~cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> degrees(n,0);
        vector<vector<int>> g(n);
        vector<int> ans;
        for(auto edge : prerequisites)
        {
            int prev=edge[1];
            int next=edge[0];
            g[prev].push_back(next);
            ++degrees[next];
        }
        for(int i=0;i<n;++i)
        {
            int j;
            for(j=0;j<n;++j)
                if(!degrees[j])
                    break;
            if(j==n)
                return {};
            ans.push_back(j);
            --degrees[j];
            for(auto next : g[j])
                --degrees[next];
        }
        return ans;
    }
};
~~~

## DFS
跟DFS搜索类似，只不过在开始遍历边之前,设vis[cur]=-1,表示当前节点正在遍历。
若发现相邻节点vis[j]==-1，则说明回到了路径前面的点，产生了环。
在遍历后将当前节点加入到序列中
由于最先完成DFS的一定是出度最小的点，因此将加入的序列反转后即是拓扑排序

~~~cpp
class Solution {
public:
    vector<int> ans;
    vector<int> vis;
    vector<vector<int>> g;
    bool dfs(vector<int>& vis,vector<vector<int>>& g,int cur){
        vis[cur]=-1;
        for(auto nxt : g[cur])
        {
            if(vis[nxt]==-1)
                return false;//form a cycle
            if(!vis[nxt]&&!dfs(vis,g,nxt))
                return false;
        }
        vis[cur]=1;
        ans.push_back(cur);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> vis(n,0);
        vector<vector<int>> g(n);
        for(auto edge : prerequisites)
        {
            int prev=edge[1];
            int next=edge[0];
            g[prev].push_back(next);
        }
        for(int i=0;i<n;++i){
            if(!vis[i]&&!dfs(vis,g,i)){
                return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
~~~