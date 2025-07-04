#include <stdio.h>

int main() {
    char message[100];
    int i, key;

    printf("Enter a message: ");
    gets(message);

    printf("Enter key (1-25): ");
    scanf("%d", &key);
    for (i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + key) % 26) + 'A';
            message[i] = ch;
        }
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + key) % 26) + 'a';
            message[i] = ch;
        }
    }

    printf("Encrypted message: %s\n", message);

    return 0;
}

