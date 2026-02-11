// LINK - https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/

// n = size of nums, m = avg value of i

// solution 1, TC = O(n*logm), SC = O(1)
class Solution
{
public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (isValidIndex(i, k))
            {
                sum += nums[i];
            }
        }
        return sum;
    }

    bool isValidIndex(int index, int k)
    {
        int count = 0;
        while (index)
        {
            if (index % 2)
            {
                count++;
            }
            index /= 2;
        }

        return count == k;
    }
};

// solution 2, TC = O(n*logm), SC = O(1)
class Solution
{
public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (isValidIndex(i, k))
            {
                sum += nums[i];
            }
        }
        return sum;
    }

    bool isValidIndex(int index, int k)
    {
        int count = 0;
        while (index)
        {
            count += index & 1;
            index >>= 1;
        }

        return count == k;
    }
};