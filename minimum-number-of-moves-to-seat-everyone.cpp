// LINK - https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

// TC = O(nlogn), SC = O(1)
// Solution
class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        int total_moves = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        for (int i = 0; i < seats.size(); i++)
        {
            total_moves += abs(seats[i] - students[i]);
        }
        return total_moves;
    }
};
