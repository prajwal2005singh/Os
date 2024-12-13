#include<stdio.h>
#define max 25

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    static int bf[max], ff[max];  // bf keeps track of whether the block is allocated or not

    printf("\n\tMemory Management Scheme - First Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    // Input for the block sizes
    printf("\nEnter the size of the blocks:\n");
    for(i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    // Input for the file sizes
    printf("\nEnter the size of the files:\n");
    for(i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    // First Fit Allocation
    for(i = 1; i <= nf; i++) {
        for(j = 1; j <= nb; j++) {
            if(bf[j] != 1) {  // Check if block is not allocated
                temp = b[j] - f[i];  // Calculate remaining space after allocation
                if(temp >= 0) {  // If block can accommodate the file
                    ff[i] = j;  // Allocate file i to block j
                    bf[j] = 1;  // Mark the block as allocated
                    frag[i] = temp;  // Store the fragmentation (remaining space)
                    break;  // Move to the next file
                }
            }
        }
        if(bf[ff[i]] != 1) {  // If no block was allocated for this file
            frag[i] = -1;  // Indicate that the file was not allocated
            ff[i] = -1;    // Indicate no block assignment
        }
    }

    // Output the allocation results
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for(i = 1; i <= nf; i++) {
        if(ff[i] != -1) {  // If the file was allocated
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
        } else {  // If the file was not allocated
            printf("\n%d\t\t%d\t\tNot Allocated", i, f[i]);
        }
    }
}
