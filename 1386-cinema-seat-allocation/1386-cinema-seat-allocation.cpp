class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        ranges::sort(reservedSeats);

        int ans = 2 * n;
        int m = reservedSeats.size();

        // Bitmasks for the three possible groups
        constexpr int LEFT   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        constexpr int MIDDLE = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        constexpr int RIGHT  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (int i = 0; i < m; ) {

            int row = reservedSeats[i][0];
            int mask = 0;

            // Build reservation mask for this row
            while (i < m && reservedSeats[i][0] == row) {
                mask |= 1 << reservedSeats[i][1];
                ++i;
            }

            // This row was initially counted as 2 families.
            ans -= 2;

            bool left  = (mask & LEFT) == 0;
            bool middle = (mask & MIDDLE) == 0;
            bool right = (mask & RIGHT) == 0;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};