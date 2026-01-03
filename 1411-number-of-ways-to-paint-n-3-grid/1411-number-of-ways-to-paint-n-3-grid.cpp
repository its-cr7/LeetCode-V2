class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        long long type1 = 6;  
        long long type2 = 6;  
        for (int i = 2; i <= n; i++) {
            long long newType1 = (type1 * 3 % MOD + type2 * 2 % MOD) % MOD;
            long long newType2 = (type1 * 2 % MOD + type2 * 2 % MOD) % MOD;
            type1 = newType1;
            type2 = newType2;
        }
        return (type1 + type2) % MOD;
    }
};