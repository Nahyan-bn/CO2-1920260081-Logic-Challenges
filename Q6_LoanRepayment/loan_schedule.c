#include <stdio.h>

int main(void) {
    /* Self-Help Group Micro-Loan */
    double balance = 10000.0;
    double rate = 0.02;          /* 2% per month */
    double repayment = 2000.0;   /* Rs 2,000 fixed repayment */
    double total_interest = 0.0;
    int month = 0;
    const int MAX_MONTHS = 360;  /* 30-year safety limit to prevent infinite loops */

    printf("Month | Interest | Principal Paid | Remaining Balance\n");
    printf("----------------------------------------------------\n");

    /* 
     * Using 'balance > 0.001' instead of 'balance != 0'
     * to avoid infinite loop caused by floating-point representation errors.
     */
    while (balance > 0.001) {
        month++;
        if (month > MAX_MONTHS) {
            printf("\n[ALERT] Loan failed to amortize within %d months.\n", MAX_MONTHS);
            break;
        }

        double interest = balance * rate;
        total_interest += interest;

        if (repayment <= interest) {
            printf("\n[ERROR] Repayment (Rs %.2f) is less than monthly interest (Rs %.2f). Loan will never terminate!\n",
                   repayment, interest);
            break;
        }

        /* Final month adjustment: balance + interest may be less than fixed payment */
        double actual_payment = repayment;
        if (balance + interest < repayment) {
            actual_payment = balance + interest;
            balance = 0.0;
        } else {
            balance = (balance + interest) - repayment;
        }

        printf("%5d | %8.2f | %14.2f | %17.2f\n",
               month, interest, actual_payment - interest, balance);
    }

    printf("\nTotal Months: %d | Total Interest Paid: Rs %.2f\n", month, total_interest);
    return 0;
}