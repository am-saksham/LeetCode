class Solution {
public:

    int sumOfDigits(int num) {
        int sum = 0;
        while(num > 0) {
            int d = num % 10;
            sum += (int)pow(d, 2);
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;

        while(n != 1) {
            if(seen.count(n)) return false;
            seen.insert(n);
            n = sumOfDigits(n);
        }
        return true;
    }
};