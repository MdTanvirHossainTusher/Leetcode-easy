// TC = O(logn), MC = O(1)
typedef long long ll;
class Solution {
public:
    int arrangeCoins(int n) {
        /**
        binary search er maddhome 1 to n er moddhe ekta value try kore dkhbo je oita ans howar chance ase kina. eg: n=8 hoile, m=4 => sum = (4*5)/2=10 ja `n` theke besi tai ei `m` er value hbe na. abr try krbo. say, m=3 => sum = (3*4)/2=6 ja `n` thke kom and (n-sum)=(8-6)=2 < 4 ja indicate kore je m=4 or 4th row te just 2ta coin bosbe. jodi (n-sum)=4 ja m=4 or row er soman taile 4th row tao fillup hbe

        */
        ll l = 1, r = n;
        while (l <= r) {
            ll m = l + (r - l) / 2;
            ll sum = (m * (m+1)) / 2;

            if (sum < n && (n-sum) < m) {
                return m;
            }
            else if (sum > n) {
                r = m - 1;
            }
            else if (sum <= n) { // ekhne `=` hbe cause uporer example e m=3 hoile jokhn 4th row tao fillup hbe tkhn ans hbe m=4. tar mane current value theke right e +1 ghor shift korle ans pabo. 
                l = m + 1;
            }
        }
        return r;
    }
};


// TC = O(logn), MC = O(1)
typedef long long ll;
class Solution {
public:
    int arrangeCoins(int n) {
        ll l = 1, r = n;
        // 1 2 3 4 5 6 7 8 9 10 => n=8, m=3
        while (l <= r) {
            ll m = l + (r - l) / 2;
            ll sum = (m * (m+1)) / 2;

            if (sum == n) {
                return m;
            }
            else if (sum > n) {
                r = m - 1;
            }
            else if (sum < n) { 
                l = m + 1;
            }
        }
        return r;
    }
};


// TC = O(sqrt(n)), MC = O(1)
typedef long long ll;
class Solution {
public:
    int arrangeCoins(int n) {
        // n = total coins
        // n=8-1=7, row=2
        // n=7-2=5, row=3
        // n=5-3=2, row=4
        // n=2-4= -2, row=5

        int row = 1;
        while (n > 0) { 
            n = n - row;
            row++;
        }
        return n == 0? row-1 : row-2;
    }
};