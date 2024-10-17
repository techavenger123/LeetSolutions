#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int maximumSwap(int num) {
        std::string strNum = std::to_string(num);
        int n = strNum.length();
        std::vector<int> last(10, -1);
        
        // Record the last occurrence of each digit
        for (int i = 0; i < n; ++i) {
            last[strNum[i] - '0'] = i;
        }
        
        // Try to find a digit to swap
        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > strNum[i] - '0'; --d) {
                if (last[d] > i) {
                    // Swap the digits
                    std::swap(strNum[i], strNum[last[d]]);
                    return std::stoi(strNum);  // Convert back to integer and return
                }
            }
        }
        
        return num;  // If no swap is made, return the original number
    }
};
