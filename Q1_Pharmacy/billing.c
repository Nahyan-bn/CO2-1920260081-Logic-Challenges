#include <stdio.h>

int main(void) {
    /* Predict and demonstrate original bug vs. correct implementation */
    double price = 200.0;
    int qty = 4;
    int senior = 1; /* 1 if senior citizen, 0 otherwise */

    /* 
     * Buggy original expression:
     * In C, integer division 15 / 100 evaluates to 0, completely wiping out the discount!
     * Same for 5 / 100 which evaluates to 0.
     * Furthermore, 'count = count++ + 1;' causes Undefined Behavior (UB)
     * because the scalar 'count' is modified twice without a sequence point.
     */

    /* Corrected, readable implementation using intermediate variables */
    double gross = price * qty;
    double discount = senior ? (gross * 0.15) : 0.0;
    double taxable = gross - discount;
    double gst = taxable * 0.05;
    double total = taxable + gst;

    double net = (total > 1000.0) ? (total - 50.0) : total;

    printf("=== Jan Aushadhi Pharmacy Billing ===\n");
    printf("Gross: Rs %.2f | Discount: Rs %.2f | GST: Rs %.2f\n", gross, discount, gst);
    printf("Total: Rs %.2f | Net Payable: Rs %.2f\n", total, net);

    return 0;
}