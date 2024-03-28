// TC = O(logn), MC = O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;

        while(l <= r) {
            long long m = l + (r-l) / 2;
            if(m * m == num) {
                return true;
            }
            else if (m * m > num) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return false;
    }
};

// https://leetcode.com/problems/valid-perfect-square/solutions/622060/unique-solution-easy-to-understand-c/
// TC = O(sqrt(n)), MC = O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        // every perfect square is a sum of odd numbers starting from 1
        // 1 + 3 = 4
        // 1 + 3 + 5 = 9
        // 1 + 3 + 5 + 7 = 16
        // 1 + 3 + 5 + 7 + 9 = 25
        // `num` er jnno sqrt(num) prjnto loop cholbe. tai TC = O(sqrt(n))
        // eta check korar jnno amra `num` theke `i` minus kore dkhbo je num=0 hoy kina, hoile true
        // but, minus krte krte negative hoile false return korbo

        for(int i = 1; num > 0; i += 2) {
            num = num - i;
            if (num == 0) return true;
        }
        return false;
    }
};

// TC = O(sqrt(n)), MC = O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i;
        for(i = 1; i * i < num; i++);
        return i * i == num; // condition true hoile i++ hbe, tai (i * i < num) kora hoise
    }
};