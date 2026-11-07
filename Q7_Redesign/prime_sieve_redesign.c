#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 1000000

/* Redesign: Precompute primes up to 1,000,000 using Sieve of Eratosthenes */
bool is_prime_sieve[LIMIT + 1];

void generate_sieve(void) {
    for (int i = 0; i <= LIMIT; i++) is_prime_sieve[i] = true;
    is_prime_sieve[0] = is_prime_sieve[1] = false;

    for (int p = 2; p * p <= LIMIT; p++) {
        if (is_prime_sieve[p]) {
            for (int i = p * p; i <= LIMIT; i += p) {
                is_prime_sieve[i] = false;
            }
        }
    }
}

int main(void) {
    generate_sieve();

    long test_tickets[] = {97, 100, 7919, 999983};
    int n = sizeof(test_tickets) / sizeof(test_tickets[0]);

    printf("=== Day-4 Redesign: O(1) Sieve Query Verification ===\n");
    for (int i = 0; i < n; i++) {
        long ticket = test_tickets[i];
        printf("Ticket %ld: %s (Time: O(1))\n",
               ticket, is_prime_sieve[ticket] ? "WINNER (PRIME)" : "NO PRIZE");
    }
    return 0;
}