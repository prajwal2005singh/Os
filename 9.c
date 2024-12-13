#include<stdio.h>
#include<stdlib.h>

int main() {
    int f[50], p, i, st, len, j, c, k, a, fn = 0;

    // Initialize all blocks as free (0 means free)
    for (i = 0; i < 50; i++) f[i] = 0;

    // Begin file allocation loop
    x:
    fn = fn + 1;  // Increment file number

    // Get starting block and length from user
    printf("Enter index starting block and length: ");
    scanf("%d%d", &st, &len);
    k = len;

    // Check if starting block is available (free)
    if (f[st] == 0) {
        // Try to allocate blocks
        for (j = st; j < (st + k); j++) {
            if (f[j] == 0) {  // Block is free
                f[j] = fn;
                printf("%d -------------->%d\n", j, f[j]);
            } else {  // Block is already allocated
                printf("%d Block is already allocated \n", j);
                k++;  // Increment length to try to allocate more blocks
            }
        }
    } else {
        // Starting block is already allocated
        printf("%d starting block is already allocated \n", st);
    }

    // Ask user if they want to allocate more files
    printf("Do you want to enter more file(Yes - 1/No - 0): ");
    scanf("%d", &c);
    if (c == 1) {
        goto x;  // Go back to file allocation loop
    } else {
        exit(0);  // Exit the program
    }

    return 0;
}
