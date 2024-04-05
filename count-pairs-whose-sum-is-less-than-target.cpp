// LINK - https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/

// TC = O(n^2), SC = O(1)
// Solution 1
class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] < target)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

// TC = O(nlogn), SC = O(1)
// Solution 2
class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        int left = 0, count = 0, right = nums.size() - 1;
        sort(nums.begin(), nums.end());

        while (left < right)
        {
            if (nums[left] + nums[right] < target)
            {
                count += right - left;
                left++;
            }
            else
            {
                right--;
            }
        }

        return count;
    }
};
