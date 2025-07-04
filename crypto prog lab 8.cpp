#include <stdio.h>
#include <string.h>
int main() {
    long p, q, n, phi, e, d;
    char msg[100];
    long m[100], en[100], temp[100];
    int i, j, len;
    printf("Enter two distinct primes: ");
    scanf("%d %d", &p, &q);
    n = p * q;
    phi = (p - 1) * (q - 1);
    for (e = 3; e < phi; e++) {
        long a = e, b = phi;
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        if (a == 1) break;
    }
    d = 1;
    while ((d * e) % phi != 1) {
        d++;
        if (d > phi) {
            printf("Modular inverse not found.\n");
            return 1;
        }
    }
    printf("Public key (e, n): (%d, %d)\n", e, n);
    printf("Private key (d, n): (%d, %d)\n", d, n);
    printf("Enter lowercase message: ");
    scanf("%s", msg);
    len = strlen(msg);
    for (i = 0; i < len; i++) {
        m[i] = msg[i] - 'a' + 1;
    }
    for (i = 0; i < len; i++) {
        long base = m[i], exp = e, res = 1;
        base = base % n;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % n;
            base = (base * base) % n;
            exp = exp / 2;
        }
        temp[i] = res;
        en[i] = res + 'a' - 1;
    }
    printf("Encrypted: ");
    for (i = 0; i < len; i++)
        printf("%c", (char)en[i]);
    printf("\nDecrypted: ");
    for (i = 0; i < len; i++) {
        long base = temp[i], exp = d, res = 1;
        base = base % n;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % n;
            base = (base * base) % n;
            exp = exp / 2;
        }
        printf("%c", (char)(res + 'a' - 1));
    }
    printf("\n");
    return 0;
}

