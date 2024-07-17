class Solution {
public:
    int addDigits(int num) {
        
        if (num == 0) {
            return 0;
        }
        
        int sum = 0;
        
        
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        
        
        while (sum > 9) {
            int new_sum = 0;
            while (sum > 0) {
                new_sum += sum % 10;
                sum /= 10;
            }
            sum = new_sum;
        }
        
        return sum;
    }
};

