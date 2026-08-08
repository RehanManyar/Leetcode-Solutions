class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (x == 0) return 0.0;
        if (x == 1) return 1.0;

        // Convert int to long long first
        long long binary = n;

        // Handle negative POWER
        if (binary < 0) {
            x = 1 / x;
            binary = -binary;
        }

        while (binary > 0) {

            // If power is odd
            if (binary % 2 == 1) {
                ans *= x;
            }

            // Square the base
            x *= x;

            // Divide power by 2
            binary /= 2;
        }

        return ans;
    }
};