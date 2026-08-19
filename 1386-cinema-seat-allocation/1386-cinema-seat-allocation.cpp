class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        ranges::sort(reservedSeats);

        int families = 2 * n;
        int m = reservedSeats.size();

        for (int i = 0; i < m; ) {

            int row = reservedSeats[i][0];

            // This row was initially counted as 2 families.
            families -= 2;

            array<bool, 11> reserved{};

            // Mark reserved seats of this row.
            while (i < m && reservedSeats[i][0] == row) {
                reserved[reservedSeats[i][1]] = true;
                i++;
            }

            bool left =
                !reserved[2] &&
                !reserved[3] &&
                !reserved[4] &&
                !reserved[5];

            bool middle =
                !reserved[4] &&
                !reserved[5] &&
                !reserved[6] &&
                !reserved[7];

            bool right =
                !reserved[6] &&
                !reserved[7] &&
                !reserved[8] &&
                !reserved[9];

            if (left && right) {
                families += 2;
            }
            else if (left || middle || right) {
                families += 1;
            }
        }

        return families;
    }
};