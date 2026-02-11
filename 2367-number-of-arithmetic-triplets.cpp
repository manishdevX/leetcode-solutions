// LINK - https://leetcode.com/problems/number-of-arithmetic-triplets/

// n = size of nums

// solution 1, TC = O(n^2), SC = O(1)
class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int count = 0, n = nums.size();
        for (int i = 1; i < n - 1; i++)
        {
            int left = 0, right = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] - nums[j] == diff)
                {
                    left++;
                    break;
                }
            }
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] - nums[i] == diff)
                {
                    right++;
                    break;
                }
            }
            if (left == right && left == 1)
            {
                count++;
            }
        }
        return count;
    }
};

// Solution 2, TC = O(n), SC = O(1)
class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int count = 0, n = nums.size();
        vector<int> arr(201, 0);

        for (auto &&num : nums)
        {
            arr[num]++;
        }

        for (auto &&num : nums)
        {
            if (num - diff >= 0 && num + diff <= 200 && arr[num - diff] && arr[num + diff])
            {
                count++;
            }
        }

        return count;
    }
};
