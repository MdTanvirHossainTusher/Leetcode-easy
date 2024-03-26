# define ll long long

class Solution {
public:
    vector<ll> nums;
    void powers() {
        nums.push_back(1);
        for (int i = 1; i <= 20; i++) {
            // cout<<nums[i-1] * 3 <<endl;
            nums.push_back(nums[i-1] * 3);
        }
    }
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        powers();
        int l = 0, r = nums.size()-1;

        while(l <= r) {
            int m = l + (r-l) / 2;
            if(nums[m] == n) return true;
            else if(nums[m] > n) r = m-1;
            else l = m+1;
        }
        return false;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        // 27%3=0, 27/3=9 -> 9%3=0, 9/3=3 ->3%3=0, 3/3=1 ==> true
        // 21%3=0, 21/3=7 -> 7%3=1 --> break and n!=1 --> false
        // continuously vag krte hbe cz case-2, n == 1 e thmbo cz 3^0 = 1, er pore 3 er r positive power nai
        
        if(n <= 0) return false;
        while(n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

class Solution {
public:
    // 27%3=0, 27/3=9 -> 9%3=0, 9/3=3 ->3%3=0, 3/3=1 ==> true
    // 21%3=0, 21/3=7 -> 7%3=1 --> break and n!=1 --> false
    // continuously vag krte hbe cz case-2, n == 1 e thmbo cz 3^0 = 1, er pore 3 er r positive power nai
    /**
        if(n <= 0) return false;
        while(n % 3 == 0) {// TC = O(log3(n)), MC = O(1)
            n /= 3;
        }
        return n == 1;
    */
    
    // uporer code e recursion diye kora jabe
    bool isPowerOfThree(int n) { // TC = O(log3(n)), MC = O(1)
        if (n < 1) return false;
        if (n == 1) return true;
        return n % 3 == 0 && isPowerOfThree(n / 3);
    }
};

// https://leetcode.com/problems/power-of-three/solutions/77856/1-line-java-solution-without-loop-recursion/
class Solution {
public:
    bool isPowerOfThree(int n) {
        /**
            n = 3^x
        ==> log3(n) = x*log3(3)
        ==> log3(n) = x*1
        ==> x = log3(n) = log10(n)/log10(3)
        
        x = log10(1162261467)/log10(3) = 19
        x = log10(2147483647 / INT_MAX)/log10(3) = 19.5588223603
        x = log10(3486784401)/log10(3) = 20 ==> pass int value
        */

        int maxPower = log(INT_MAX) / log(3);
        int maxValue = pow(3, maxPower);
        return (n > 0 && maxValue % n == 0); // n > 0 cz n <= 0  is false, if n == 0/1 it will not pass the condition
    }
};