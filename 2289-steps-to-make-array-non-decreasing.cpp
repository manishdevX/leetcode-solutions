// LINK - https://leetcode.com/problems/steps-to-make-array-non-decreasing/

// n = size of nums

// solution 1 - TLE, TC = O(n^2), SC = O(1)
class Solution
{
public:
    int totalSteps(vector<int> &nums)
    {
        int steps = 0;

        while (true)
        {
            int i = nums.size() - 1;
            bool removed = false;
            while (i > 0)
            {
                if (nums[i - 1] > nums[i])
                {
                    nums.erase(nums.begin() + i);
                    removed = true;
                }
                i--;
            }
            if (!removed)
            {
                break;
            }

            steps++;
        }
        return steps;
    }
};
