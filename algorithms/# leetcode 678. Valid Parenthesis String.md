# leetcode 678. Valid Parenthesis String
[leetcode 678](https://leetcode.com/problems/valid-parenthesis-string/)

## 题目描述
字符'*'可当作是'('或')'或空字符，判断一个括号字符串是否匹配

## 思路
cmax,cmin记录当前左括号的取值范围为[cmin,cmax],'\*'当作'('，则cmax+=1，'\*'当作')'，则匹配一个左括号cmin-=1，若当作空字符，则无事发生。

若cmax<0,说明前面所有的'\*'都当作'('也不够匹配当前')'，匹配失败
若cmin<0，说明如果前面所有的'\*'都当作)，则(已经不够用，失配了，所以必须将|cmin|数量的'\*'当作是空字符。`cmin=max(0,cmin)`

最后检查cmin是否等于0，来判断是否能括号匹配。

## code
~~~cpp
class Solution {
public:
    bool checkValidString(string s) {
        int cmin=0,cmax=0;
        for(char c : s)
        {
            if(c=='(')
            {
                cmin++;
                cmax++;
            }
            else if(c==')')
            {
                cmin--;
                cmax--;
            }
            else if(c=='*')
            {
                cmax++;
                cmin--;
            }
            if(cmax<0)
                return false;
            cmin=max(0,cmin);
        }
        return cmin==0;
    }
};
~~~