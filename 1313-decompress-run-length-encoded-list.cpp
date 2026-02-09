// LINK - https://leetcode.com/problems/decompress-run-length-encoded-list/

// m = average value of nums[i], n = size of nums

// solution 1, TC = O(m*n), SC = O(m)
class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> ans;
        int i = 1;
        while (i < nums.size())
        {
            vector<int> arr(nums[i - 1], nums[i]);
            ans.insert(ans.end(), arr.begin(), arr.end());
            i += 2;
        }
        return ans;
    }
};

// solution 2, TC = O(m*n), SC = O(1)
class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 1; i < nums.size(); i += 2)
        {
            for (int j = 0; j < nums[i - 1]; j++)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};