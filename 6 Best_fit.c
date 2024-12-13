#include<stdio.h>
#define max 25

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, lowest = 10000;
    static int bf[max], ff[max];  // bf keeps track of whether the block is allocated or not

    printf("\n\tMemory Management Scheme - Best Fit");
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

    // Best Fit Allocation
    for(i = 1; i <= nf; i++) {
        lowest = 10000;  // Reset the lowest to a large number for each file allocation
        for(j = 1; j <= nb; j++) {
            if(bf[j] != 1) {  // If block is not allocated
                temp = b[j] - f[i];  // Calculate remaining space after file allocation
                if(temp >= 0 && temp < lowest) {  // Check if the block can fit and has the least remaining space
                    ff[i] = j;  // Assign file i to block j
                    lowest = temp;  // Update the lowest fragmentation
                }
            }
        }
        
        if(lowest != 10000) {  // If a suitable block was found
            frag[i] = lowest;  // Store the fragmentation
            bf[ff[i]] = 1;  // Mark the block as allocated
        } else {
            frag[i] = -1;  // If no block can accommodate the file, set fragmentation as -1
            ff[i] = -1;    // Indicate that no block was allocated
        }
        lowest = 10000;  // Reset the lowest for the next file
    }

    // Output the allocation results
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for(i = 1; i <= nf; i++) {
        if(ff[i] != -1) {  // If the file was allocated
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated", i, f[i]);  // If the file was not allocated
        }
    }
}
