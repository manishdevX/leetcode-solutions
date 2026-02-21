// LINK - https://leetcode.com/problems/prime-in-diagonal

// n = size of nums and nums[i], k = max element in nums

// Solution 1, TC = O(n*sqrt(k)), SC = O(1)
class Solution
{
public:
    bool diagonalPrimeHelper(int num)
    {
        if (num < 2)
        {
            return false;
        }
        for (int div = 2; div * div <= num; div++)
        {
            if (num % div == 0)
            {
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>> &nums)
    {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            bool d1 = diagonalPrimeHelper(nums[i][i]);
            bool d2 = diagonalPrimeHelper(nums[i][n - i - 1]);
            if (d1)
            {
                ans = max(ans, nums[i][i]);
            }
            if (d2)
            {
                ans = max(ans, nums[i][n - i - 1]);
            }
        }
        return ans;
    }
};

// Solution 2, TC = O(n^2+kloglogk), SC = O(k)
class Solution
{
public:
    void diagonalPrimeHelper(vector<bool> &isPrime)
    {
        int n = isPrime.size() - 1;
        for (int i = 2; i * i <= n; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }

    int diagonalPrime(vector<vector<int>> &nums)
    {
        int ans = 0, n = nums.size(), maxi = 0;
        for (auto &&vec : nums)
        {
            maxi = max(maxi, *max_element(vec.begin(), vec.end()));
        }
        vector<bool> isPrime(maxi + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        diagonalPrimeHelper(isPrime);

        for (int i = 0; i < n; i++)
        {
            if (isPrime[nums[i][i]])
            {
                ans = max(ans, nums[i][i]);
            }
            if (isPrime[nums[i][n - i - 1]])
            {
                ans = max(ans, nums[i][n - i - 1]);
            }
        }
        return ans;
    }
};