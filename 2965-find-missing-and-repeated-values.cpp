// LINK - https://leetcode.com/problems/find-missing-and-repeated-values

// n = size of grid and size of grid[i]

// Solution 1, TC = O(n^4), SC = O(1)
class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        vector<int> ans(2, 0);
        int num = 1;
        while (num <= grid.size() * grid.size())
        {
            int c = 0;
            for (auto &&row : grid)
            {
                c += count(row.begin(), row.end(), num);
            }
            if (c == 2)
            {
                ans[0] = num;
            }
            if (c == 0)
            {
                ans[1] = num;
            }
            if (ans[0] > 0 && ans[1] > 0)
            {
                return ans;
            }
            num++;
        }
        return ans;
    }
};

// Solution 2, TC = O(n^2), SC = O(n^2)
class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        unordered_map<int, int> mp;
        vector<int> ans(2, 0);

        for (auto &&vec : grid)
        {
            for (auto &&num : vec)
            {
                mp[num]++;
            }
        }

        for (int i = 1; i <= grid.size() * grid.size(); i++)
        {
            if (mp[i] == 2)
            {
                ans[0] = i;
            }
            if (mp[i] == 0)
            {
                ans[1] = i;
            }
            if (ans[0] > 0 && ans[1] > 0)
            {
                return ans;
            }
        }
        return ans;
    }
};

// Solution 3, TC = O(n^2), SC = O(n^2)
class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        unordered_set<int> s;
        vector<int> ans(2, 0);
        int n = grid.size() * grid.size();
        int sum = ((1 + n) * n) / 2;

        for (auto &&vec : grid)
        {
            for (auto &&num : vec)
            {
                if (s.find(num) != s.end())
                {
                    ans[0] = num;
                }
                else
                {
                    s.insert(num);
                    sum -= num;
                }
            }
        }
        ans[1] = sum;
        return ans;
    }
};