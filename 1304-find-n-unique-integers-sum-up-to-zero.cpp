// LINK - https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

// Solution 1, TC = O(n), SC = O(1)
class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> ans(n);
        int i = 0, j = n - 1;
        while (i < j)
        {
            ans[i] = j * -1;
            ans[j] = j;
            i++;
            j--;
        }
        if (i == j)
        {
            ans[i] = 0;
        }
        return ans;
    }
};

// Solution 2, TC = O(n), SC = O(1)
class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> ans(n);
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans[i] = i + 1;
            sum += ans[i];
        }
        ans[n - 1] = -sum;
        return ans;
    }
};
