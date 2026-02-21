// LINK - https://leetcode.com/problems/longest-alternating-subarray

// n = size of nums

// Solution 1, TC = O(n^3), SC = O(n)
class Solution
{
public:
    int alternatingSubarray(vector<int> &nums)
    {
        vector<int> subarr;
        int count = -1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = 1; i + j < nums.size(); j++)
            {
                for (int k = 0; k <= j; k++)
                {
                    subarr.push_back(nums[i + k]);
                }
                int val = 1, ind = 1;
                for (ind = 1; ind < subarr.size(); ind++)
                {
                    if (subarr[ind] - subarr[ind - 1] != val)
                    {
                        break;
                    }
                    val *= -1;
                }
                if (ind == subarr.size())
                {
                    count = max(count, ind);
                }
                subarr.clear();
            }
        }
        return count;
    }
};

// Solution 2, TC = O(n^2), SC = O(1)
class Solution
{
public:
    int alternatingSubarray(vector<int> &nums)
    {
        int count = -1, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int scount = 1, val = 1, k = n - i;
            if (count >= k)
            {
                return count;
            }

            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] - nums[j - 1] != val)
                {
                    break;
                }
                scount++;
                val *= -1;
            }
            if (scount > 1)
            {
                count = max(count, scount);
            }
        }
        return count;
    }
};

// Solution 3, TC = O(n), SC = O(n)
class Solution
{
public:
    int alternatingSubarray(vector<int> &nums)
    {
        int count = 1, n = nums.size();
        vector<int> inc(n, 1);
        vector<int> dec(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == 1)
            {
                inc[i] = dec[i - 1] + 1;
            }
            else if (nums[i] - nums[i - 1] == -1)
            {
                dec[i] = (inc[i - 1] > 1 ? inc[i - 1] + 1 : 1);
            }
            count = max(count, max(inc[i], dec[i]));
        }
        return (count > 1 ? count : -1);
    }
};