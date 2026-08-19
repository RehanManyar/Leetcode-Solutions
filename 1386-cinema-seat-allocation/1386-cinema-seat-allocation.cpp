class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // Store reserved seats for only the rows that have reservations.
        unordered_map<int, int> rows;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            // Only seats 2 to 9 can affect a family block.
            if (col >= 2 && col <= 9) {
                rows[row] |= (1 << col);
            }
        }

        // Every completely empty row can accommodate 2 groups.
        int answer = (n - rows.size()) * 2;

        for (auto &[row, mask] : rows) {

            // Seats 2,3,4,5
            bool left = (mask & (1 << 2)) == 0 &&
                        (mask & (1 << 3)) == 0 &&
                        (mask & (1 << 4)) == 0 &&
                        (mask & (1 << 5)) == 0;

            // Seats 4,5,6,7
            bool middle = (mask & (1 << 4)) == 0 &&
                          (mask & (1 << 5)) == 0 &&
                          (mask & (1 << 6)) == 0 &&
                          (mask & (1 << 7)) == 0;

            // Seats 6,7,8,9
            bool right = (mask & (1 << 6)) == 0 &&
                         (mask & (1 << 7)) == 0 &&
                         (mask & (1 << 8)) == 0 &&
                         (mask & (1 << 9)) == 0;

            if (left && right) {
                // Two non-overlapping groups.
                answer += 2;
            }
            else if (left || middle || right) {
                // At least one group can be placed.
                answer += 1;
            }
        }

        return answer;
    }
};