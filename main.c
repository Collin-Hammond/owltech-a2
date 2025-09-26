#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// Forward declarations from convert.c
void oct_to_bin(const char *oct, char *out);
void oct_to_hex(const char *oct, char *out);
void hex_to_bin(const char *hex, char *out);
void to_sign_magnitude(int32_t n, char *out);
void to_ones_complement(int32_t n, char *out);
void to_twos_complement(int32_t n, char *out);

void run_test(const char *func, const char *input, const char *expected) {
    char actual[300];

    if (strcmp(func, "oct_to_bin") == 0) {
        oct_to_bin(input, actual);
    } else if (strcmp(func, "oct_to_hex") == 0) {
        oct_to_hex(input, actual);
    } else if (strcmp(func, "hex_to_bin") == 0) {
        hex_to_bin(input, actual);
    } else if (strcmp(func, "to_sign_magnitude") == 0) {
        int32_t n = atoi(input);
        to_sign_magnitude(n, actual);
    } else if (strcmp(func, "to_ones_complement") == 0) {
        int32_t n = atoi(input);
        to_ones_complement(n, actual);
    } else if (strcmp(func, "to_twos_complement") == 0) {
        int32_t n = atoi(input);
        to_twos_complement(n, actual);
    } else {
        printf("Unknown function: %s\n", func);
        return;
    }

    printf("%s(%s) -> Expected: %s, Got: %s [%s]\n",
           func, input, expected, actual,
           strcmp(expected, actual) == 0 ? "PASS" : "FAIL");
}

int main() {
    FILE *f = fopen("a2_test.txt", "r");
    if (!f) {
        perror("a2_test.txt not found");
        return 1;
    }

    char line[400];
    int total = 0, passed = 0;

    while (fgets(line, sizeof(line), f)) {
        // skip comments and blank lines
        if (line[0] == '#' || line[0] == '\n') continue;

        char func[50], input[100], expected[300];
        if (sscanf(line, "%s %s %s", func, input, expected) == 3) {
            total++;
            char actual[300];
            if (strcmp(func, "oct_to_bin") == 0) {
                oct_to_bin(input, actual);
            } else if (strcmp(func, "oct_to_hex") == 0) {
                oct_to_hex(input, actual);
            } else if (strcmp(func, "hex_to_bin") == 0) {
                hex_to_bin(input, actual);
            } else if (strcmp(func, "to_sign_magnitude") == 0) {
                int32_t n = atoi(input);
                to_sign_magnitude(n, actual);
            } else if (strcmp(func, "to_ones_complement") == 0) {
                int32_t n = atoi(input);
                to_ones_complement(n, actual);
            } else if (strcmp(func, "to_twos_complement") == 0) {
                int32_t n = atoi(input);
                to_twos_complement(n, actual);
            } else {
                continue;
            }

            int ok = strcmp(expected, actual) == 0;
            printf("%s(%s) -> Expected: %s, Got: %s [%s]\n",
                   func, input, expected, actual, ok ? "PASS" : "FAIL");
            if (ok) passed++;
        }
    }

    fclose(f);

    printf("\nSummary: %d/%d tests passed\n", passed, total);
    return 0;
}
