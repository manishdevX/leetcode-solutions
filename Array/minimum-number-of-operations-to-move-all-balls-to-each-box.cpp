// LINK - https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/

// n = length of boxes

// Solution 1 TC = O(n^2), SC = O(n)
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (boxes[j] == '1')
                {
                    ans[i] += abs(i - j);
                }
            }
        }
        return ans;
    }
};

// TC = O(n), SC = O(n)
// Solution 2
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> p(n);
        vector<pair<int, int>> s(n);

        boxes[0] == '1' ? p[0] = {1, 0} : p[0] = {0, 0};
        boxes[n - 1] == '1' ? s[n - 1] = {1, n - 1} : s[n - 1] = {0, 0};

        for (int i = 1; i < n; i++)
        {
            if (boxes[i] == '1')
            {
                p[i] = {p[i - 1].first + 1, p[i - 1].second + i};
            }
            else
            {
                p[i] = p[i - 1];
            }
            int r = n - i - 1;
            if (boxes[r] == '1')
            {
                s[r] = {s[r + 1].first + 1, s[r + 1].second + r};
            }
            else
            {
                s[r] = s[r + 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            ans[i] = abs(p[i].second - p[i].first * i) +
                     abs(s[i].second - s[i].first * i);
        }
        return ans;
    }
};

// TC = O(n), SC = O(n)
// Solution 3
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> ans(n, 0);
        int freq = 0, balls = 0;

        for (int i = 0; i < n; i++)
        {
            ans[i] += freq;
            balls += boxes[i] - '0';
            freq += balls;
        }
        freq = 0, balls = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] += freq;
            balls += boxes[i] - '0';
            freq += balls;
        }
        return ans;
    }
};