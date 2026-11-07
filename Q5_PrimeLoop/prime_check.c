#include <stdio.h>

void check_prime(long long n) {
    int divisions = 0;
    int is_prime = 1;

    if (n < 2) {
        is_prime = 0;
    } else {
        /* Optimized loop without calling sqrt(): condition is i * i <= n */
        for (long long i = 2; i * i <= n; i++) {
            divisions++;
            if (n % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }

    if (is_prime) {
        printf("%lld prime divisions = %d\n", n, divisions);
    } else {
        printf("%lld not prime divisions = %d\n", n, divisions);
    }
}

int main(void) {
    check_prime(97);
    check_prime(100);
    check_prime(7919);
    check_prime(1000003);
    return 0;
}