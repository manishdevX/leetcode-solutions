// LINK - https://leetcode.com/problems/greatest-common-divisor-of-strings

// n1 = length of str1, n2 = length of str2

// Solution 1 TC = O(min(n1,n2)), SC = O(s1+s2)
class Solution
{
public:
    string gcdHelper(string str1, string str2, string asf)
    {
        int n1 = str1.length(), n2 = str2.length();
        while (asf.length())
        {
            int m = asf.length(), d1 = n1 / m, d2 = n2 / m, r1 = n1 % m,
                r2 = n2 % m;
            if (r1 == 0 && r2 == 0)
            {
                string s1 = "", s2 = "";
                while (d1)
                {
                    s1 += asf;
                    d1--;
                }
                while (d2)
                {
                    s2 += asf;
                    d2--;
                }
                if (s1 == str1 && s2 == str2)
                {
                    return asf;
                }
            }
            asf = asf.substr(0, m - 1);
        }
        return asf;
    }

    string gcdOfStrings(string str1, string str2)
    {
        string asf = str1.length() < str2.length() ? str1 : str2;
        return gcdHelper(str1, str2, asf);
    }
};

// Solution 2 TC = O(log(m*n)), SC = O(1)

class Solution
{
public:
    int getGCD(int a, int b)
    {
        if (a % b == 0)
        {
            return b;
        }
        return getGCD(b, a % b);
    }
    string gcdOfStrings(string str1, string str2)
    {
        int m = str1.length(), n = str2.length();
        if (str1 + str2 != str2 + str1)
        {
            return "";
        }
        int gcd = getGCD(m, n);
        return str1.substr(0, gcd);
    }
};