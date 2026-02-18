// LINK - https://leetcode.com/problems/two-out-of-three

// n1 = size of nums1, n2 = size of nums2, n3 = size of nums3

// Solution 1 TC = O(n1*(n2+n3)+n2*n3), SC = O(min(n1,n2,n3))
class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2,
                              vector<int> &nums3)
    {
        vector<int> ans;
        for (auto &&num : nums1)
        {
            if (find(nums2.begin(), nums2.end(), num) != nums2.end() ||
                find(nums3.begin(), nums3.end(), num) != nums3.end())
            {
                if (find(ans.begin(), ans.end(), num) == ans.end())
                {
                    ans.push_back(num);
                }
            }
        }
        for (auto &&num : nums2)
        {
            if (find(nums3.begin(), nums3.end(), num) != nums3.end())
            {
                if (find(ans.begin(), ans.end(), num) == ans.end())
                {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};

// TC = O(n1+n2+n3), SC = O(n1+n2+n3)
// Solution 2
class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2,
                              vector<int> &nums3)
    {
        vector<int> ans;
        unordered_map<int, bool> m1;
        unordered_map<int, bool> m2;
        unordered_map<int, bool> m3;

        for (auto &&num : nums1)
        {
            m1[num] = true;
        }
        for (auto &&num : nums2)
        {
            m2[num] = true;
        }
        for (auto &&num : nums3)
        {
            m3[num] = true;
        }

        for (auto &&num : nums1)
        {
            if ((m2[num] || m3[num]) &&
                find(ans.begin(), ans.end(), num) == ans.end())
            {
                ans.push_back(num);
            }
        }
        for (auto &&num : nums2)
        {
            if (m3[num] && find(ans.begin(), ans.end(), num) == ans.end())
            {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

// TC = O(n1+n2+n3), SC = O(min(n1,n2,n3))
// Solution 3
class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2,
                              vector<int> &nums3)
    {
        vector<int> ans;
        vector<int> vec(101, 0);

        for (auto &&num : nums1)
        {
            vec[num] = 1;
        }
        for (auto &&num : nums2)
        {
            if (vec[num] < 2)
            {
                vec[num] += 2;
            }
        }
        for (auto &&num : nums3)
        {
            if (vec[num])
            {
                vec[num] += 3;
            }
        }

        for (int i = 1; i < 101; i++)
        {
            if (vec[i] >= 3)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};