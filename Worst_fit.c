#include<stdio.h>
#define max 25

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, highest = 0;
    static int bf[max], ff[max];  // bf keeps track of whether block is allocated or not

    printf("\n\tMemory Management Scheme - Worst Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for(i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the files:\n");
    for(i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    // Worst Fit Allocation
    for(i = 1; i <= nf; i++) {
        highest = -1;  // Reset highest before each file allocation
        for(j = 1; j <= nb; j++) {
            if(bf[j] != 1) { // If block is not allocated
                temp = b[j] - f[i]; // Calculate remaining space after allocation
                if(temp >= 0 && highest < temp) { // Check if block is large enough
                    ff[i] = j;  // Allocate the file to the block
                    highest = temp; // Update the largest remaining space
                }
            }
        }
        frag[i] = highest;  // Store the fragmentation of the file
        bf[ff[i]] = 1;  // Mark block as allocated
    }

    // Display the allocation results
    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment\n");
    for(i = 1; i <= nf; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
    }
}
