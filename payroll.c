#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr,
                "Usage: %s last_name first_name minutes hourly_rate\n",
                argv[0]);
        return 1;
    }

    int minutes = atoi(argv[3]);
    double hourly_rate = atof(argv[4]);

    double total_payment = (minutes / 60.0) * hourly_rate;

    printf("%s %s: %.2f\n", argv[2], argv[1], total_payment);

    return 0;
}
