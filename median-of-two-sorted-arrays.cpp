// LINK - https://leetcode.com/problems/median-of-two-sorted-arrays

// m = size of nums1, n = size of nums2

// Solution 1 TC = O(m+n), SC = O(m+n)
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size(), i = 0, j = 0, s = m + n;
        vector<int> vec;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                vec.push_back(nums1[i]);
                i++;
            }
            else
            {
                vec.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m)
        {
            vec.push_back(nums1[i]);
            i++;
        }
        while (j < n)
        {
            vec.push_back(nums2[j]);
            j++;
        }
        if (s % 2 == 0)
        {
            return (double)(vec[(s - 2) / 2] + vec[s / 2]) / 2;
        }
        return (double)vec[(s - 1) / 2];
    }
};