// LINK - https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/

// n1 = size of items1, n2 = size of items2

// Solution 1 TC = O(n1+n2), SC = O(n1+n2)
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                    vector<vector<int>> &nums2)
    {
        map<int, int> mp;
        vector<vector<int>> ans;
        for (auto &&vec : nums1)
        {
            mp[vec[0]] += vec[1];
        }
        for (auto &&vec : nums2)
        {
            mp[vec[0]] += vec[1];
        }
        for (auto &&it : mp)
        {
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};

// Solution 2 TC = O(n1+n2), SC = O(n1+n2)
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                    vector<vector<int>> &nums2)
    {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i][0] < nums2[j][0])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i][0] == nums2[j][0])
            {
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size())
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size())
        {
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }
};