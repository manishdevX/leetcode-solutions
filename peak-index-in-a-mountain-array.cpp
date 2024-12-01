// LINK - https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

// n = size of arr

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> leftarr(n), rightarr(n);
        leftarr[0] = 0;
        rightarr[n - 1] = n - 1;
        for (int i = 1; i < n; i++)
        {
            int r = n - i - 1;
            leftarr[i] = arr[i] > arr[leftarr[i - 1]] ? i : leftarr[i - 1];
            rightarr[r] = arr[r] > arr[rightarr[r + 1]] ? r : rightarr[r + 1];
        }

        for (int i = 0; i < n; i++)
        {
            if (leftarr[i] == rightarr[i])
            {
                return i;
            }
        }
        return -1;
    }
};

// Solution 2 TC = O(logn), SC = O(1)
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size(), l = 0, r = n - 1;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if ((m == 0 || arr[m] > arr[m - 1]) &&
                (m == n - 1 || arr[m] < arr[m + 1]))
            {
                l = m + 1;
            }
            else if ((m == 0 || arr[m] < arr[m - 1]) &&
                     (m == n - 1 || arr[m] > arr[m + 1]))
            {
                r = m - 1;
            }
            else
            {
                return m;
            }
        }
        return -1;
    }
};

// Solution 3 TC = O(logn), SC = O(1)
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size(), l = 0, r = n - 1;
        while (l < r)
        {
            int m = (l + r) >> 1;
            if (arr[m] < arr[m + 1])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};
