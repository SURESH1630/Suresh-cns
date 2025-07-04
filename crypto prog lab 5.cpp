#include <stdio.h>
#include <string.h>
int main() {
    char message[100], key[100], fullKey[100], result[100];
    int i, j, msgLen, keyLen, choice;
    printf("Enter message (uppercase, no spaces): ");
    gets(message);
    printf("Enter key (uppercase): ");
    gets(key);
    msgLen = strlen(message);
    keyLen = strlen(key);
    for (i = 0; i < msgLen; i++) {
        fullKey[i] = key[i % keyLen];
    }
    fullKey[msgLen] = '\0';
    printf("Choose:\n1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        for (i = 0; i < msgLen; i++) {
            result[i] = ((message[i] - 'A') + (fullKey[i] - 'A')) % 26 + 'A';
        }
        result[msgLen] = '\0';
        printf("Encrypted Message: %s\n", result);
    } else if (choice == 2) {
        for (i = 0; i < msgLen; i++) {
            result[i] = ((message[i] - 'A') - (fullKey[i] - 'A') + 26) % 26 + 'A';
        }
        result[msgLen] = '\0';
        printf("Decrypted Message: %s\n", result);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}

