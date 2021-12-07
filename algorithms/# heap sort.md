# heap sort
[参考链接](https://www.geeksforgeeks.org/heap-sort/)

满二叉树性质：
`parent=(i-1)/2,son_left=i*2+1,son_right=i*2+2`

## 建堆
首先对数组建立大顶堆：父节点一定大于子节点
对每一个非叶节点递归进行比较(堆化)

### 最后一个非叶节点
结论:最后一个叶节点的父节点

证明：假设最后一个叶节点a的父节点b不是最后一个非叶节点。
那么存在一个下标更大的非叶节点c,其孩子d的下标将大于a的下标，与a是最后一个叶节点矛盾

假设数组长度为n，最后一个节点下标为n-1,其父节点为(n-1-1)/2=n/2-1

## 排序
迭代n步，每一步将堆顶元素与堆末尾交换。
将堆的长度减少1，并对下标0进行堆化

## code
~~~cpp
class Solution {
public:
    void max_heapify(vector<int>& arr,int st,int ed)
    {
        int dad=st;
        int son=st*2+1;
        while(son<ed)
        {
            if(son+1<ed&&arr[son+1]>arr[son])
                ++son;
            if(arr[dad]>=arr[son])
                return;
            swap(arr[dad],arr[son]);
            dad=son;
            son=dad*2+1;
        }
    }
    void heap_sort(vector<int>& arr)
    {
        int n=arr.size();
        for(int i=n/2-1;i>=0;--i)
            max_heapify(arr,i,n);
        for(int i=n-1;i>0;--i)
        {
            swap(arr[0],arr[i]);
            max_heapify(arr,0,i);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heap_sort(nums);
        return nums;
    }
};
~~~