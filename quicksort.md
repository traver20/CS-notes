# quicksort
随机选取一个轴点，将数组分为比pivot小和比pivot大的部分，对两部分递归进行排序  
快速排序算法是不稳定的排序算法  
比如 5,5,3 在第一种填坑法中，两个5将会调换顺序

    vector<int>& quicksort(vector<int>& arr, int lo, int hi)//左闭右开区间
        {
            if(lo+1>=hi)
                return arr;
            int mid=partition(arr, lo, hi);
            quicksort(arr,lo,mid);
            quicksort(arr,mid+1,hi);
            return arr;
        }

## 填坑法
左右方向扫描，依次填坑

    int partition(vector<int>& arr, int lo, int hi)
        {
            int randIdx=rand()%(hi-lo)+lo;
            swap(arr[randIdx],arr[lo]);
            int pivot=arr[lo];
            int left=lo,right=hi-1;
            while(left<right)
            {
                while(left<right&&arr[right]>=pivot)
                    --right;
                if(left<right)
                    arr[left]=arr[right];
                while(left<right&&arr[left]<pivot)
                    ++left;
                if(left<right)
                    arr[right]=arr[left];
            }
            arr[left]=pivot;
            return left;
        }

## 从左到右扫描法
将比pivot小的元素依次放入数组的左边

    int partition(vector<int>& arr, int lo, int hi)
        {
            int randIdx=rand()%(hi-lo)+lo;
            swap(arr[randIdx],arr[hi-1]);
            int pivot=arr[hi-1];
            int smallPos=lo;
            int i=lo;
            for(;i<hi-1;++i)
            {
                if(arr[i]<pivot)
                    swap(arr[i],arr[smallPos++]);
            }
            swap(arr[smallPos],arr[hi-1]);
            return smallPos;
        }
