#include <stdio.h>

static int server_call_count = 0;

int slow_verify_disability_server(int has_card) {
    server_call_count++; /* Simulating costly remote network call */
    return has_card;
}

int main(void) {
    /* 
     * Short-circuit evaluation:
     * (senior && eligible) || slow_verify_disability_server(disability)
     * If (senior && eligible) is TRUE, the right operand is NEVER evaluated,
     * saving costly server requests.
     * If non-short-circuit bitwise '|' were used, the server function would run every time!
     */
    int passengers[4][3] = {
        {1, 1, 0}, /* Senior & eligible -> Short-circuits, 0 server calls */
        {1, 0, 1}, /* Senior but not eligible -> Calls server */
        {0, 0, 1}, /* Not senior -> Calls server */
        {0, 0, 0}  /* Not senior -> Calls server */
    };

    for (int i = 0; i < 4; i++) {
        int is_senior = passengers[i][0];
        int is_eligible = passengers[i][1];
        int has_disability = passengers[i][2];

        int granted = (is_senior && is_eligible) || slow_verify_disability_server(has_disability);
        printf("Passenger %d: Concession %s | Cumulative Server Calls: %d\n",
               i + 1, granted ? "GRANTED" : "DENIED", server_call_count);
    }
    return 0;
}