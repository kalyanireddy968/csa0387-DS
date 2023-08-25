#include <stdio.h>

int reverse(int x) {
    int reversed = 0;
    
    while (x != 0) {
        // Check for overflow
        if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10) {
            return 0;
        }
        
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    
    return reversed;
}

int main() {
    int num = 32;
    int reversed = reverse(num);
    
    printf("Original number: %d\n", num);
    printf("Reversed number: %d\n", reversed);
    
    return 0;
}
