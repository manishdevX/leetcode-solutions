// TC = O(n^2), SC = O(n)

// solution 1
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < i + 1; j++)
            {
                sum += nums[j];
            }
            result.push_back(sum);
        }
        return result;
    }
};

// TC = O(n), SC = O(n)

// solution 2
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> result;
        result.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            result.push_back(result[i - 1] + nums[i]);
        }
        return result;
    }
};