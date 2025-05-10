#include <stdio.h>
#include <math.h>

int main() {
    int num, rev = 0, on, digit_count = 0, digit, rev1 = 0, left_half, right_half;
    scanf("%d", &num);
    
    // Store the original number
    on = num;

    // Count the number of digits in the number
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        digit_count++;
    }

      temp = num;
    while (temp != 0) {
        digit = temp % 10;
        rev = rev * 10 + digit;
        temp /= 10;
    }
    
    if (rev == on) {
        printf("%d\n", on);
    } else {
        
        if (digit_count % 2 == 0) {
            int half_digits = digit_count / 2;
            int divisor = pow(10, half_digits);
            
            left_half = num / divisor;
            right_half = num % divisor;
          
            temp = left_half;
            while (temp != 0) {
                digit = temp % 10;
                rev1 = rev1 * 10 + digit;
                temp /= 10;
            }
                       int result = left_half * divisor +rev1;
            printf("%d\n", result);
        }
        else
        {
          
        }
    }

    return 0;
}
