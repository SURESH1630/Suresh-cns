#include <stdio.h>
#include <string.h>
int main() {
    int i, j, k, l;
    char a[100], c[100], d[100];
    printf("\n\t\tRAIL FENCE TECHNIQUE (2 rails)");
    printf("\n\nEnter the input string (no spaces): ");
    gets(a);  
	l = strlen(a);
    for (i = 0, j = 0; i < l; i++) {
        if (i % 2 == 0)
            c[j++] = a[i];
    }
    for (i = 0; i < l; i++) {
        if (i % 2 == 1)
            c[j++] = a[i];
    }
    c[j] = '\0';
    printf("\nCipher text after applying rail fence:\n%s", c);
    if (l % 2 == 0)
        k = l / 2;
    else
        k = (l / 2) + 1;
    for (i = 0, j = 0; i < k; i++) {
        d[j] = c[i];
        j += 2;
    }
    for (i = k, j = 1; i < l; i++) {
        d[j] = c[i];
        j += 2;
    }
    d[l] = '\0';
    printf("\nText after decryption:\n%s\n", d);
    return 0;
}

