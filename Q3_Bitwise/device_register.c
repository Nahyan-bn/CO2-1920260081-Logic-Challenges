#include <stdio.h>

enum { LIGHT = 0, FAN = 1, AC = 2, HEATER = 3, PUMP = 4 };

/* Set bit to 1 */
unsigned char switch_on(unsigned char reg, int dev) {
    return reg | (1 << dev);
}

/* Clear bit to 0 */
unsigned char switch_off(unsigned char reg, int dev) {
    return reg & ~(1 << dev);
}

/* Toggle bit */
unsigned char toggle(unsigned char reg, int dev) {
    return reg ^ (1 << dev);
}

/* Test if bit is 1 */
int is_on(unsigned char reg, int dev) {
    return (reg >> dev) & 1;
}

/* Print register in 8-bit binary */
void show(unsigned char reg) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (reg >> i) & 1);
    }
    printf("\n");
}

int main(void) {
    unsigned char reg = 0;

    reg = switch_on(reg, LIGHT);
    reg = switch_on(reg, AC);
    show(reg);                    /* Expected: 00000101 */

    reg = toggle(reg, FAN);
    reg = switch_off(reg, LIGHT);
    show(reg);                    /* Expected: 00000110 */

    printf("AC is %s, PUMP is %s\n",
           is_on(reg, AC) ? "ON" : "OFF",
           is_on(reg, PUMP) ? "ON" : "OFF");

    return 0;
}