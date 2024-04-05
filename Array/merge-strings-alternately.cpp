// LINK - https://leetcode.com/problems/merge-strings-alternately/description/

// n1 = length of word1, n2 = length of word2

// Solution 1 TC = O(max(n1,n2)), SC = O(n1+n2)
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string st = "";
        int i = 0, j = 0, n1 = word1.length(), n2 = word2.length();
        while (i < n1 && j < n2)
        {
            if (st.size() % 2 == 0)
            {
                st += word1[i++];
            }
            else
            {
                st += word2[j++];
            }
        }

        while (i < n1)
        {
            st += word1[i++];
        }
        while (j < n2)
        {
            st += word2[j++];
        }
        return st;
    }
};

// Solution 2 TC = O(max(n1,n2)), SC = O(n1+n2)
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string st;
        int i = 0, j = 0, n1 = word1.length(), n2 = word2.length();

        while (i < n1 || j < n2)
        {
            if (i < n1)
            {
                st.push_back(word1[i++]);
            }
            if (j < n2)
            {
                st.push_back(word2[j++]);
            }
        }
        return st;
    }
};