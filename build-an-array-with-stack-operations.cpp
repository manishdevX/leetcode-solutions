// LINK - https://leetcode.com/problems/build-an-array-with-stack-operations/description/

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> ans;
        int ind = 0, s = target.size();
        for (int i = 1; i <= n; i++)
        {
            ans.push_back("Push");
            if (i == target[ind])
            {
                ind++;
            }
            else
            {
                ans.push_back("Pop");
            }
            if (ind == s)
            {
                break;
            }
        }
        return ans;
    }
};