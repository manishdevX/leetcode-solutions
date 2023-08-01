// TC = O(n), SC = O(n)

class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        string st = "";
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == ' ')
            {
                count++;
            }
            if (count == k)
            {
                break;
            }
            st += s[i];
        }
        return st;
    }
};