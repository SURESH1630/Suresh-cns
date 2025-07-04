#include <stdio.h>
#include <string.h>
int main() {
    char input[100], key[100];
    printf("Enter a word to encrypt: ");
    scanf("%s", input);
    printf("Enter a key: ");
    scanf("%s", key);
    int IP[8] = {2, 6, 3, 1, 4, 8, 5, 7};
    int FP[8] = {4, 1, 3, 5, 7, 2, 8, 6};
    int len = strlen(input);
    int key_len = strlen(key);
    printf("Encrypted output: ");
    for (int c = 0; c < len; c++) {
        int plain_bin[8] = {0};
        int key_bin[8] = {0};
        int permuted[8], xored[8], final[8];
        unsigned char ch = input[c];
        for (int i = 7; i >= 0; i--) {
            plain_bin[i] = ch % 2;
            ch /= 2;
        }
        ch = key[c % key_len];
        for (int i = 7; i >= 0; i--) {
            key_bin[i] = ch % 2;
            ch /= 2;
        }
        for (int i = 0; i < 8; i++) {
            permuted[i] = plain_bin[IP[i] - 1];
        }
        for (int i = 0; i < 8; i++) {
            xored[i] = permuted[i] ^ key_bin[i];
        }
        for (int i = 0; i < 8; i++) {
            final[i] = xored[FP[i] - 1];
        }
        unsigned char result = 0;
        for (int i = 0; i < 8; i++) {
            result = (result << 1) | final[i];
        }
        printf("%c", result);
    }
    printf("\n");
    return 0;
}

