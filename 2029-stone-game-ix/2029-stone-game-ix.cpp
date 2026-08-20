class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};

        for (int x : stones) {
            cnt[x % 3]++;
        }
        // If there are no remainder-1 or remainder-2 stones,
        // Alice cannot avoid eventually taking a multiple of 3.
        if (cnt[1] == 0 && cnt[2] == 0)
            return false;

        // When there are remainder-0 stones, they effectively
        // change whose turn it is without changing the remainder.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // cnt[0] is odd
        return abs(cnt[1] - cnt[2]) > 2;
    }
};