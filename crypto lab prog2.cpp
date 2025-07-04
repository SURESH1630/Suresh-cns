#include <stdio.h>
#include <string.h>

int main() {
    char plaintext[100], ch;
    char ciphertext[100];
    int i;
    char substitution[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    printf("Enter the message: ");
    gets(plaintext);
    for (i = 0; plaintext[i] != '\0'; i++) {
        ch = plaintext[i];
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = substitution[ch - 'A'];
        }
        else if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = substitution[ch - 'a'] + ('a' - 'A'); 
        }
        else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0';
    printf("Encrypted message: %s\n", ciphertext);
    return 0;
}

