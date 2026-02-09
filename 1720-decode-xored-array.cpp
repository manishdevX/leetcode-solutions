// LINK - https://leetcode.com/problems/decode-xored-array/

// n = size of encoded

// solution 1, TC = O(n), SC = O(1)
class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> ans;
        ans.push_back(first);

        for (int i = 0; i < encoded.size(); i++)
        {
            ans.push_back(ans[i] ^ encoded[i]);
        }
        return ans;
    }
};