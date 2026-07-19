class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long digit = 0;
        long long result = 0;

        while (temp > 0) {
            digit = temp % 10;
            result = result * 10 + digit;
            temp /= 10;
        }

        return result == x;
    }
};