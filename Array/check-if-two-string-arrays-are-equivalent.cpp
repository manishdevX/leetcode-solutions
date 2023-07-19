// TC = O(n*k), SC = O(n*k)

// solution 1
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string st1 = "", st2 = "";
        for (string st : word1)
        {
            st1 += st;
        }
        for (string st : word2)
        {
            st2 += st;
        }
        return st1 == st2;
    }
};

// TC = O(n*k), SC = O(1)

// solution 2
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int s1 = word1.size();
        int s2 = word2.size();
        int sp1 = 0, sp2 = 0, wp1 = 0, wp2 = 0;

        while (wp1 < s1 && wp2 < s2)
        {
            if (word1[wp1][sp1] != word2[wp2][sp2])
            {
                return false;
            }
            sp1++;
            sp2++;
            if (sp1 == word1[wp1].size())
            {
                sp1 = 0;
                wp1++;
            }
            if (sp2 == word2[wp2].size())
            {
                sp2 = 0;
                wp2++;
            }
        }
        return wp1 == s1 && wp2 == s2;
    }
};
