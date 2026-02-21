// LINK - https://leetcode.com/problems/median-of-two-sorted-arrays

// m = size of nums1, n = size of nums2

// Solution 1, TC = O(m+n), SC = O(m+n)
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

// Solution 2, TC = O(m+n), SC = O(m+n)
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size(), i = 0, j = 0, s = (m + n) / 2;
        vector<int> vec;
        for (int k = 0; k <= s; k++)
        {
            if (i < m && j < n)
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
            else if (i < m)
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
        if ((m + n) % 2)
        {
            return (double)(vec[s]);
        }
        return (double)(vec[s - 1] + vec[s]) / 2;
    }
};

// Solution 3, TC = O(m+n), SC = O(1)
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size(), i = 0, j = 0, s = (m + n) / 2,
            n1, n2;
        for (int k = 0; k <= s; k++)
        {
            n2 = n1;
            if (i < m && j < n)
            {
                nums1[i] < nums2[j] ? n1 = nums1[i++] : n1 = nums2[j++];
            }
            else if (i < m)
            {
                n1 = nums1[i++];
            }
            else
            {
                n1 = nums2[j++];
            }
        }

        if ((m + n) % 2)
        {
            return (double)(n1);
        }
        return (double)(n1 + n2) / 2;
    }
};

// Solution 4, TC = O(log(min(m,n))), SC = O(1)
class Solution
{
private:
    double median(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size(), s = m + n,
            left_half = (s + 1) / 2;
        int lo = 0, hi = m;
        while (lo <= hi)
        {
            int mid1 = lo + (hi - lo) / 2;
            int mid2 = left_half - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < m)
            {
                r1 = nums1[mid1];
            }
            if (mid2 < n)
            {
                r2 = nums2[mid2];
            }
            if (mid1 - 1 >= 0)
            {
                l1 = nums1[mid1 - 1];
            }
            if (mid2 - 1 >= 0)
            {
                l2 = nums2[mid2 - 1];
            }

            if (l1 > r2)
            {
                hi = mid1 - 1;
            }
            else if (l2 > r1)
            {
                lo = mid1 + 1;
            }
            else
            {
                if (s % 2)
                {
                    return max(l1, l2);
                }
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
        }
        return 0;
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m <= n)
        {
            return median(nums1, nums2);
        }
        return median(nums2, nums1);
    }
};