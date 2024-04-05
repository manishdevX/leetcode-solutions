// LINK - https://leetcode.com/problems/sum-of-all-subset-xor-totals/

// TC = O(2^n), SC = O(1)
// Solution 1
class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int n = pow(2, nums.size()) + 0.5;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            string binary = bitset<12>(i).to_string();
            int val = 0;
            for (int j = 0; j < 12; j++)
            {
                if (binary[j] == '1')
                {
                    val = val ^ nums[11 - j];
                }
            }
            sum += val;
        }
        return sum;
    }
};

// TC = O(2^n), SC = O(2^n)
// Solution 2
class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        return getXOR(nums, 0, 0);
    }

    int getXOR(vector<int> &nums, int index, int val)
    {
        if (index == nums.size())
        {
            return val;
        }

        int included_element = getXOR(nums, index + 1, val ^ nums[index]);
        int excluded_element = getXOR(nums, index + 1, val);
        return included_element + excluded_element;
    }
};