// LINK - https://leetcode.com/problems/find-pivot-index/description/

// n = size of nums

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ps(n, 0), ss(n, 0);
        for (int i = 1; i < n; i++)
        {
            ps[i] = ps[i - 1] + nums[i - 1];
            ss[n - i - 1] = ss[n - i] + nums[n - i];
        }
        for (int i = 0; i < n; i++)
        {
            if (ps[i] == ss[i])
            {
                return i;
            }
        }
        return -1;
    }
};

// Solution 2 TC = O(n), SC = O(1)

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int i = 0, n = nums.size(), lsum = 0, rsum = 0;
        for (auto &&num : nums)
        {
            rsum += num;
        }
        while (i < n)
        {
            if (lsum == rsum - nums[i])
            {
                return i;
            }
            else
            {
                lsum += nums[i];
                rsum -= nums[i++];
            }
        }
        return -1;
    }
};