#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Could not open file");
        return 1;
    }

    int numbers[10];

    for (int i = 0; i < 10; i++) {
        if (fscanf(file, "%d", &numbers[i]) != 1) {
            fprintf(stderr, "File must contain ten integers.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    long long sum = 0;

    for (int i = 0; i < 10; i++) {
        sum += numbers[i];
    }

    printf("%lld\n", sum);

    return 0;
}
