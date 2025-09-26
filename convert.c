#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//convert uint32_t to 32-bit binary string
void to_32bit_binary(uint32_t value, char *out) {
    for (int i = 31; i >= 0; i--) {
        out[31 - i] = ((value >> i) & 1) ? '1' : '0';
    }
    out[32] = '\0';
}

//PART 1: Direct Mapping

void oct_to_bin(const char *oct, char *out) {
    int pos = 0;
    while (*oct) {
        int digit = *oct - '0';
        out[pos++] = (digit & 4) ? '1' : '0';
        out[pos++] = (digit & 2) ? '1' : '0';
        out[pos++] = (digit & 1) ? '1' : '0';
        oct++;
    }
    out[pos] = '\0';
}

void oct_to_hex(const char *oct, char *out) {
    char bin[256];
    oct_to_bin(oct, bin);

    //pad binary to multiple of 4
    int len = strlen(bin);
    int pad = (4 - (len % 4)) % 4;
    char padded[260];
    for (int i = 0; i < pad; i++) padded[i] = '0';
    strcpy(padded + pad, bin);

    //convert 4 bits -> hex
    int pos = 0;
    for (int i = 0; i < strlen(padded); i += 4) {
        int val = (padded[i] - '0') * 8 +
                  (padded[i+1] - '0') * 4 +
                  (padded[i+2] - '0') * 2 +
                  (padded[i+3] - '0');
        out[pos++] = (val < 10) ? ('0' + val) : ('A' + val - 10);
    }
    out[pos] = '\0';

    //trim leading zeros, but keep at least one digit 
    int start = 0;
    while (out[start] == '0' && out[start + 1] != '\0') {
        start++;
    }
    if (start > 0) {
        memmove(out, out + start, strlen(out + start) + 1);
    }
}


void hex_to_bin(const char *hex, char *out) {
    int pos = 0;
    while (*hex) {
        char c = *hex;
        int val;
        if (c >= '0' && c <= '9') val = c - '0';
        else if (c >= 'A' && c <= 'F') val = 10 + (c - 'A');
        else if (c >= 'a' && c <= 'f') val = 10 + (c - 'a');
        else { hex++; continue; }
        out[pos++] = (val & 8) ? '1' : '0';
        out[pos++] = (val & 4) ? '1' : '0';
        out[pos++] = (val & 2) ? '1' : '0';
        out[pos++] = (val & 1) ? '1' : '0';
        hex++;
    }
    out[pos] = '\0';
}

//PART 2: Signed Representations

void to_sign_magnitude(int32_t n, char *out) {
    if (n >= 0) {
        to_32bit_binary((uint32_t)n, out);
    } else {
        uint32_t mag = (uint32_t)(-n);
        to_32bit_binary(mag, out);
        out[0] = '1'; // set sign bit
    }
}

void to_ones_complement(int32_t n, char *out) {
    if (n >= 0) {
        to_32bit_binary((uint32_t)n, out);
    } else {
        uint32_t mag = (uint32_t)(-n);
        to_32bit_binary(mag, out);
        // flip bits
        for (int i = 0; i < 32; i++) {
            out[i] = (out[i] == '0') ? '1' : '0';
        }
    }
}

void to_twos_complement(int32_t n, char *out) {
    to_32bit_binary((uint32_t)n, out);
}