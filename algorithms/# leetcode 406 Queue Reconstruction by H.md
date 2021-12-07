# leetcode 406 Queue Reconstruction by Height
给定一个数组，每个元素都是一个二元组  
1. 身高
2. 在队伍前面比他高的人数

根据这一输入，重建符合要求的排列

## 思路
首先可以想到，最高的人，无论在队伍里的哪个位置，他的第二项都为0  
而队伍中第二高的人，只需看他是在最高的人前面还是后面，就可以决定第二项是0还是1  
据此，算法如下：  
1. 首先按从高到低排序
2. 从高到低处理
3. 可以想到，每当处理一个元素时，排在自己后面的都是比自己矮的，不会影响第二项的值
4. 而排在前面的会影响自己第二项的值，根据第二项的值插入指定位置即可

有一点要注意的是，当高度相同时，要按第二项由小到大的顺序排列  
这是因为最终的队伍里应该是第二项小的排前面，会影响第二项更大的元素的第二项值  
而在处理每一个元素时是假定排在前面的元素会影响当前元素第二项值  
所以要先处理第二项更小的元素  

## code
~~~cpp
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int>& lhs,vector<int>& rhs)
             {
                 if(lhs[0]==rhs[0])
                     return lhs[1]<rhs[1];
                 return lhs[0]>rhs[0];
             });
        vector<vector<int>> ans;
        for(auto person : people)
            ans.insert(ans.begin()+person[1],person);
        return ans;
    }
};
~~~