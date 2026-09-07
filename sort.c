#include <stdlib.h>
#include <stdio.h>

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

    int value;
    size_t count = 0;
    int result;

    /* Count the integers in the file. */
    while ((result = fscanf(file, "%d", &value)) == 1) {
        count++;
    }

    if (result != EOF || ferror(file)) {
        fprintf(stderr, "Could not read a file of integers.\n");
        fclose(file);
        return 1;
    }

    if (count == 0) {
        printf("\n");
        fclose(file);
        return 0;
    }

    int *numbers = malloc(count * sizeof(int));

    if (numbers == NULL) {
        fprintf(stderr, "Could not allocate memory.\n");
        fclose(file);
        return 1;
    }
    rewind(file);

    for (size_t i = 0; i < count; i++) {
        if (fscanf(file, "%d", &numbers[i]) != 1) {
            fprintf(stderr, "Could not read an integer.\n");
            free(numbers);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    for (size_t i = 1; i < count; i++) {
        int key = numbers[i];
        size_t j = i;

        while (j > 0 && numbers[j - 1] > key) {
            numbers[j] = numbers[j - 1];
            j--;
        }

        numbers[j] = key;
    }
    for (size_t i = 0; i < count; i++) {
        if (i > 0) {
            printf(" ");
        }

        printf("%d", numbers[i]);
    }

    printf("\n");

    free(numbers);

    return 0;
}
