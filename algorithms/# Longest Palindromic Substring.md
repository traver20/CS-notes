# Longest Palindromic Substring
[leetcode 5](https://leetcode.com/problems/longest-palindromic-substring/)

## 问题描述
> In computer science, the longest palindromic substring or longest symmetric factor problem is the problem of finding a maximum-length contiguous substring of a given string that is also a palindrome.

找到最长的连续的回文子串

## DP
`dp[i][j]==1`表示子串(i,j)为回文
dp[i][j]=1 需要满足两个条件
1. `s[i]==s[j]`
2. `j-i<3||dp[i+1][j-1]`

~~~cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n];
        int st=0,len=1;
        for(int i=0;i<n;++i)
            for(int j=i;j<n;++j)
                dp[i][j]=0;
        for(int i=n-1;i>=0;--i)
            for(int j=i;j<n;++j)
            {
                dp[i][j]=s[i]==s[j]&&(j-i<3||dp[i+1][j-1]);
                if(dp[i][j]&&j-i+1>len)
                {
                    st=i;
                    len=j-i+1;
                }
            }
        return s.substr(st,len);
    }
};
~~~

## extend
从每一个字符，试图以单个字符或两个字符开始进行扩展

~~~cpp
class Solution {
public:
    int lo,len;
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<2)
            return s;
        for(int i=0;i<n-1;++i)
        {
            extend(s,i,i);
            extend(s,i,i+1);
        }
        return s.substr(lo,len);
    }
    void extend(string& s,int j,int k)
    {
        while(j>=0&&k<s.size()&&s[j]==s[k])
        {
            --j;
            ++k;
        }
        if(k-j-1>len)
        {
            len=k-j-1;
            lo=j+1;
        }
    }
};
~~~