// TC = O(n), SC = O(1)

class Solution
{
public:
    int differenceOfSum(vector<int> &nums)
    {
        int element_sum = 0, digit_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int d = nums[i];
            element_sum += nums[i];
            while (d)
            {
                digit_sum += d % 10;
                d /= 10;
            }
        }
        return abs(digit_sum - element_sum);
    }
};