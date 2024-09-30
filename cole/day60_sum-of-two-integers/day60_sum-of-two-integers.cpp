class Solution {
public:
    int getSum(int a, int b) {
        int carry;
        do {
            carry = a & b;
            b = a ^ b;
            a = carry << 1;
        } while (carry != 0);
        return b;
    }
};