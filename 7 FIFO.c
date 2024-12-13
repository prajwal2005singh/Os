#include<stdio.h>

void main() {
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;
    
    // Taking inputs
    printf("\nEnter the length of reference string: ");
    scanf("%d", &n);
    
    printf("\nEnter the reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }
    
    printf("\nEnter the number of frames: ");
    scanf("%d", &f);
    
    // Initialize frames with -1 to represent empty frames
    for(i = 0; i < f; i++) {
        m[i] = -1;
    }
    
    printf("\nThe Page Replacement Process is as follows:\n");
    
    // Loop through each page in the reference string
    for(i = 0; i < n; i++) {
        // Check if the page is already in memory (no page fault)
        for(k = 0; k < f; k++) {
            if(m[k] == rs[i]) {
                break;  // Page found in memory, no page fault
            }
        }

        // If the page was not found in memory, page fault occurs
        if(k == f) {
            m[count++] = rs[i];  // Insert the page into memory
            pf++;  // Increment page fault counter
        }

        // Print the current state of memory frames
        for(j = 0; j < f; j++) {
            printf("\t%d", m[j]);
        }

        // If there was a page fault, print the page fault number
        if(k == f) {
            printf("\tPF No. %d", pf);
        }
        
        printf("\n");

        // If all frames are filled, use circular behavior
        if(count == f) {
            count = 0;
        }
    }

    // Output the total number of page faults
    printf("\nThe number of Page Faults using FIFO are: %d", pf);
}
