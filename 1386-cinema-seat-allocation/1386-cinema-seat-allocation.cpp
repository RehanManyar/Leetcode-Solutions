class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, int> mp;

        for (auto &x : reservedSeats) {
            int row = x[0];
            int seat = x[1];

            if (seat >= 2 && seat <= 9) {
                mp[row] |= (1 << seat);
            }
        }

        int ans = (n - mp.size()) * 2;

        for (auto &[row, mask] : mp) {

            // 2 3 4 5
            int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);

            // 4 5 6 7
            int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);

            // 6 7 8 9
            int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

            bool L = (mask & left) == 0;
            bool M = (mask & middle) == 0;
            bool R = (mask & right) == 0;

            if (L && R)
                ans += 2;
            else if (L || M || R)
                ans += 1;
        }

        return ans;
    }
};