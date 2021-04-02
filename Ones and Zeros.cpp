class Solution
{
public:
    unordered_map<int, pair<int, int>> mp;
    int dp[610][110][110];
    int solve(int n1, int m, int n, int i, int x, int y)
    {
        if (i >= n1)
            return 0;

        if (dp[i][x][y] != 0)
        {
            return dp[i][x][y];
        }

        int l = mp[i].first + x;
        int r = mp[i].second + y;

        if (l <= m && r <= n)
        {
            int left = 0;
            int right = 0;

            if (dp[i + 1][l][r] != 0)
                left = dp[i + 1][l][r];
            else
                left = solve(n1, m, n, i + 1, l, r);

            if (dp[i + 1][x][y] != 0)
                right = dp[i + 1][x][y];
            else
                right = solve(n1, m, n, i + 1, x, y);

            return dp[i][x][y] = max(1 + left, right);
        }
        else
            return dp[i][x][y] = solve(n1, m, n, i + 1, x, y);
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {

        int n1 = strs.size();

        for (int i = 0; i < n1; i++)
        {
            int cnt1 = 0;
            int cnt0 = 0;

            for (int j = 0; j < strs[i].size(); j++)
            {
                if (strs[i][j] == '1')
                {
                    cnt1++;
                }
                else
                    cnt0++;
            }
            mp[i] = {cnt0, cnt1};
        }
        memset(dp, 0, sizeof dp);
        return solve(n1, m, n, 0, 0, 0);
    }
};