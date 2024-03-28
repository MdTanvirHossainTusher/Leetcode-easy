class Solution
{
public:
    bool isPowerOfFour(int n)
    { // O(log4(n))
        if (n <= 0)
            return false;
        while (n % 4 == 0)
        {
            n /= 4;
        }
        return n == 1;
    }
};

class Solution
{
public:
    bool isPowerOfFour(int n)
    { // O(log4(n))
        if (n < 1)
            return false;
        if (n == 1)
            return true;
        return n % 4 == 0 && isPowerOfFour(n / 4);
    }
};

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        // n ke sqrt koira jei value pabo dekhbo je seta 2 er power kina
        double x = sqrt(double(n));
        if (ceil(x) != floor(x) || n <= 0)
            return false;
        int xx = x;
        return (xx & (xx - 1)) == 0; // `xx` jodi 2 er power hoy taile `n` 4 er power hbe
    }
};

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        // just `n` 2 er power kina check krle hbe na. eg: n=2, n=8 era 2 er power but 4 er power na
        // er jnno n=8=2^3 er power/exponent odd naki even check krte hbe.
        // jodi `n` 2 er power hoy and `n` er exponent `odd` hoy taile `n` 4 er power na. eg: n = 8 = 2^3
        // jodi `n` 2 er power hoy and `n` er exponent `even` hoy taile `n` 4 er power. eg: n = 16 = 2^4
        // exponent/power koto ta check korte pari (n%3) kore. jodi power=even hoy tar mane `n` 4 er power. r kono `n` jodi 4 er power hoy, taile er reminder=1 hbe. eg: n = 16 => 16%3==1
        // r jodi power=odd hoy taile reminder 1 er besi hbe. eg: n=8 => 8%3=2

        return (n > 0 && (n & (n - 1)) == 0 && (n % 3 == 1)); // n % 3 == 1 hoile true, else false
    }
};