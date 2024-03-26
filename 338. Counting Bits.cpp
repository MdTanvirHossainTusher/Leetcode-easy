class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ones(n+1);
        for(int i = 0; i <= n; i++) {
            ones[i] = __builtin_popcount(i);
        }
        return ones;
    }
};

class Solution {
public:
    vector<int> countBits(int n) { // O(n*logn)
        vector<int> ones(n+1);
        for(int i = 0; i <= n; i++) {
            int cnt = 0, x = i;
            while(x) {
                if (x % 2 != 0) cnt++;
                x /= 2;
            }
            ones[i] = cnt;
        }
        return ones;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ones(n+1);
        for(int i = 0; i <= n; i++) {
            int cnt = 0, x = i;
            while(x) {
                if (x % 2 != 0) cnt++;
                x >>= 1;
            }
            ones[i] = cnt;
        }
        return ones;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ones(n+1);
        for(int i = 0; i <= n; i++) {
            int cnt = 0, x = i;
            while(x) {// jkhn x=0 hbe thmbo
                cnt++; // joto bar nicher operation kora jbe jotota 1 ase `x` e
                x = x & (x-1); 
            }
            ones[i] = cnt;
        }
        return ones;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        /**
        0 = 0000 -> 0 (base case)
        1 = 0001 -> 1 = 1 + dp[n-1]
        2 = 0010 -> 1 = 1 + dp[n-2]
        3 = 0011 -> 1 = 1 + dp[n-2]
        4 = 0100 -> 01(00 = 0) = 1 + dp[n-4]
        5 = 0101 -> 01(01 = 1) = 1 + dp[n-4]
        6 = 0110 -> 01(10 = 2) = 1 + dp[n-4]
        7 = 0111 -> 01(11 = 3) = 1 + dp[n-4]
        8 = 1000 -> 1(000 = 0) = 1 + dp[n-8]

        https://youtu.be/RyBM56RIWrM?si=bZ0EhETEP-OchjVT
        */

        vector<int> dp(n+1);
        dp[0] = 0;
        int prvPowerOfTwoNum;
        for(int i = 1; i <= n; i++) { // TC = MC : O(n)
            if((i & (i-1)) == 0) { // check whether `n` is a power of 2 
                prvPowerOfTwoNum = i;
            }
            dp[i] = 1 + dp[i-prvPowerOfTwoNum];
        }
        return dp;
    }
};

// TC = MC : O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        /**
        0 = 0000 -> 0 (base case)
        1 = 0001 -> 1 = 1 + dp[n-1]
        2 = 0010 -> 1 = 1 + dp[n-2]
        3 = 0011 -> 1 = 1 + dp[n-2]
        4 = 0100 -> 01(00 = 0) = 1 + dp[n-4]
        5 = 0101 -> 01(01 = 1) = 1 + dp[n-4]
        6 = 0110 -> 01(10 = 2) = 1 + dp[n-4]
        7 = 0111 -> 01(11 = 3) = 1 + dp[n-4]
        8 = 1000 -> 1(000 = 0) = 1 + dp[n-8]
        */
        vector<int> dp(n+1);
        dp[0] = 0;
        int offset = 1;
        for(int i = 1; i <= n; i++) {
            if(offset * 2 == i) { // check whether `i` is a power of 2 
                offset = i;
            }
            dp[i] = 1 + dp[i-offset];
        }
        return dp;
    }
};


