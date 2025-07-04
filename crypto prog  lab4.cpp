#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    int key[3][3];
    int i, j, k, len;
    printf("Enter 9 numbers for 3x3 key matrix (row-wise):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &key[i][j]);
        }
    }
    getchar(); 
    printf("Enter message (in uppercase, no spaces): ");
    gets(message);
    len = strlen(message);
    while (len % 3 != 0) {
        message[len] = 'X'; 
        len++;
        message[len] = '\0';
    }
    printf("Encrypted Message: ");
    for (i = 0; i < len; i += 3) {
        int p[3], c[3];
        for (j = 0; j < 3; j++) {
            p[j] = message[i + j] - 'A';
        }
        for (j = 0; j < 3; j++) {
            c[j] = 0;
            for (k = 0; k < 3; k++) {
                c[j] += key[j][k] * p[k];
            }
            c[j] = c[j] % 26;
            printf("%c", c[j] + 'A');
        }
    }
    printf("\n");
    return 0;
}

