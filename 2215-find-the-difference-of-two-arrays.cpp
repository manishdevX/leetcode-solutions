// LINK - https://leetcode.com/problems/find-the-difference-of-two-arrays/description/

// m = size of nums1, n = size of nums2

// Solution 1, TC = O(m^2*n^2), SC = O(1)
class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> answer(2);
        for (auto &&num : nums1)
        {
            if (find(answer[0].begin(), answer[0].end(), num) ==
                    answer[0].end() &&
                find(nums2.begin(), nums2.end(), num) == nums2.end())
            {
                answer[0].push_back(num);
            }
        }
        for (auto &&num : nums2)
        {
            if (find(answer[1].begin(), answer[1].end(), num) ==
                    answer[1].end() &&
                find(nums1.begin(), nums1.end(), num) == nums1.end())
            {
                answer[1].push_back(num);
            }
        }
        return answer;
    }
};

// Solution 2, TC = O(n+m), SC = O(m+n)
class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> answer(2);
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
            if (s2.find(num) == s2.end())
            {
                answer[0].push_back(num);
                s2.insert(num);
            }
        }
        for (auto &&num : nums2)
        {
            if (s1.find(num) == s1.end())
            {
                answer[1].push_back(num);
                s1.insert(num);
            }
        }
        return answer;
    }
};

// Solution 3, TC = O(m^2*n^2), SC = O(m+n)
class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> answer(2);
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
            if (s2.find(num) == s2.end() &&
                find(answer[0].begin(), answer[0].end(), num) ==
                    answer[0].end())
            {
                answer[0].push_back(num);
            }
        }
        for (auto &&num : nums2)
        {
            if (s1.find(num) == s1.end() &&
                find(answer[1].begin(), answer[1].end(), num) ==
                    answer[1].end())
            {
                answer[1].push_back(num);
            }
        }
        return answer;
    }
};
