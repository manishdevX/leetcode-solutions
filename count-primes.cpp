// LINK - https://leetcode.com/problems/count-primes

// Solution 1 TC = O(nlogn), SC = O(n) TLE
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> isPrime(n, true);
        for (int i = 2; i < n; i++)
        {
            for (int j = 2; i * j < n; j++)
            {
                isPrime[i * j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            isPrime[i] ? count++ : count;
        }
        return count;
    }
};

// Solution 2 TC = O(nlogn), SC = O(n) TLE
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> isPrime(n, true);
        for (int i = 2; i < n; i++)
        {
            for (int j = i * 2; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            isPrime[i] ? count++ : count;
        }
        return count;
    }
};

// Solution 3 TC = O(nlogn), SC = O(n)
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> isPrime(n, true);
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * 2; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            isPrime[i] ? count++ : count;
        }
        return count;
    }
};

// Solution 4 TC = O(nloglogn), SC = O(1)
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> isPrime(n, true);
        for (int i = 2; i * i <= n; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * 2; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            isPrime[i] ? count++ : count;
        }
        return count;
    }
};