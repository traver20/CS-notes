#include<iostream>
#include<string>

using namespace std;
int dp[1004][1004][2];
class Solution {
public:
    string lp(string& s, int i, int j)
    {
        if (i > j)
            return "";
        if (dp[i][j][0] != 0 || dp[i][j][1] != 0)
            return s.substr(dp[i][j][0], dp[i][j][1] - dp[i][j][0] + 1);
        int len = j - i + 1;
        if (len == 1)
        {
            dp[i][j][0] = dp[i][j][1] = i;
            return s.substr(i, 1);
        }
        if (len == 2) {
            if (s[i] == s[j])
            {
                dp[i][j][0] = i;
                dp[i][j][1] = j;
                return s;
            }
            dp[i][j][0] = dp[i][j][1] = i;
            return s.substr(i, 1);
        }
        string mid = lp(s, i + 1, j - 1);;
        if (s[i] == s[j] && dp[i + 1][j - 1][0] == i + 1 && dp[i + 1][j - 1][1] == j - 1)
        {
            dp[i][j][0] = i;
            dp[i][j][1] = j;
            return s[i] + mid + s[j];
        }
        string l = lp(s, i, j - 1);
        string r = lp(s, i + 1, j);
        int ln = l.size(), rn = r.size(), mn = mid.size();
        if (ln > rn)
        {
            if (mn > ln)
            {
                dp[i][j][0] = dp[i + 1][j - 1][0];
                dp[i][j][1] = dp[i + 1][j - 1][1];
                return mid;
            }
            dp[i][j][0] = dp[i][j - 1][0];
            dp[i][j][1] = dp[i][j - 1][1];
            return l;
        }
        if (mn > rn)
        {
            dp[i][j][0] = dp[i + 1][j - 1][0];
            dp[i][j][1] = dp[i + 1][j - 1][1];
            return mid;
        }
        dp[i][j][0] = dp[i + 1][j][0];
        dp[i][j][1] = dp[i + 1][j][1];
        return r;
    }
    string longestPalindrome(string s) {
        for (int i = 0; i < 1004; ++i)
            for (int j = 0; j < 1004; ++j)
                dp[i][j][0] = dp[i][j][1] = 0;
        int len = s.size();
        return lp(s, 0, len - 1);
    }
};

int main()
{
    Solution mysolve;
    string res = mysolve.longestPalindrome(string("cbbd"));
    cout << res << endl;
}