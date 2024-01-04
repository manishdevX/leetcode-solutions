// LINK - https://leetcode.com/problems/find-common-elements-between-two-arrays/

// Solution 1 TC = O(size of nums1 * size of nums2), SC = O(1)
class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans(2, 0);
        for (auto &&num : nums1)
        {
            if (find(nums2.begin(), nums2.end(), num) != nums2.end())
            {
                ans[0] += 1;
            }
        }

        for (auto &&num : nums2)
        {
            if (find(nums1.begin(), nums1.end(), num) != nums1.end())
            {
                ans[1] += 1;
            }
        }
        return ans;
    }
};

// Solution 2 TC = O(max(size of nums1,size of nums2)), SC = O(size of nums1+size of nums2)
class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans(2, 0);
        unordered_set<int> s1;
        unordered_set<int> s2;

        for (auto &&num : nums1)
        {
            s1.insert(num);
        }
        for (auto &&num : nums2)
        {
            s2.insert(num);
        }

        for (auto &&num : nums1)
        {
            if (s2.find(num) != s2.end())
            {
                ans[0] += 1;
            }
        }
        for (auto &&num : nums2)
        {
            if (s1.find(num) != s1.end())
            {
                ans[1] += 1;
            }
        }
        return ans;
    }
};

// Solution 3 TC = O(max(size of nums1,size of nums2)), SC = O(1)
class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans(2, 0);
        vector<bool> v1(101, false);
        vector<bool> v2(101, false);

        for (auto &&num : nums1)
        {
            v1[num] = true;
        }
        for (auto &&num : nums2)
        {
            v2[num] = true;
        }

        for (auto &&num : nums1)
        {
            if (v2[num])
            {
                ans[0] += 1;
            }
        }
        for (auto &&num : nums2)
        {
            if (v1[num])
            {
                ans[1] += 1;
            }
        }
        return ans;
    }
};