#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char key[100], matrix[5][5], message[100], cleanMsg[200], finalMsg[200];
    int seen[26] = {0};
    int i, j, k = 0, len = 0;

    printf("Enter key: ");
    gets(key);

    // Build key matrix
    for (i = 0; i < strlen(key); i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';
        if (ch >= 'A' && ch <= 'Z' && !seen[ch - 'A']) {
            seen[ch - 'A'] = 1;
            cleanMsg[k++] = ch;
        }
    }

    for (i = 0; i < 26; i++) {
        if ((i + 'A') == 'J') continue;
        if (!seen[i]) {
            cleanMsg[k++] = i + 'A';
        }
    }

    // Fill 5x5 matrix
    k = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            matrix[i][j] = cleanMsg[k++];
        }
    }

    // Input message
    printf("Enter message (no spaces): ");
    gets(message);

    // Clean message (remove spaces, convert to uppercase, replace J)
    k = 0;
    for (i = 0; i < strlen(message); i++) {
        char ch = toupper(message[i]);
        if (ch == 'J') ch = 'I';
        if (ch >= 'A' && ch <= 'Z') {
            cleanMsg[k++] = ch;
        }
    }
    cleanMsg[k] = '\0';

    // Insert X between same letters
    len = 0;
    for (i = 0; i < k; i++) {
        finalMsg[len++] = cleanMsg[i];
        if (i + 1 < k && cleanMsg[i] == cleanMsg[i + 1]) {
            finalMsg[len++] = 'X';
        }
    }
    if (len % 2 != 0) {
        finalMsg[len++] = 'X';
    }
    finalMsg[len] = '\0';

    // Encrypt message
    printf("\nEncrypted Message: ");
    for (i = 0; i < len; i += 2) {
        char ch1 = finalMsg[i];
        char ch2 = finalMsg[i + 1];
        int r1, c1, r2, c2;

        // Find positions
        for (r1 = 0; r1 < 5; r1++) {
            for (c1 = 0; c1 < 5; c1++) {
                if (matrix[r1][c1] == ch1)
                    goto found1;
            }
        }
        found1:

        for (r2 = 0; r2 < 5; r2++) {
            for (c2 = 0; c2 < 5; c2++) {
                if (matrix[r2][c2] == ch2)
                    goto found2;
            }
        }
        found2:

        // Apply Playfair rules
        if (r1 == r2) {
            printf("%c%c", matrix[r1][(c1 + 1) % 5], matrix[r2][(c2 + 1) % 5]);
        } else if (c1 == c2) {
            printf("%c%c", matrix[(r1 + 1) % 5][c1], matrix[(r2 + 1) % 5][c2]);
        } else {
            printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
        }
    }

    printf("\n");
    return 0;
}

