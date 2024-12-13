#include<stdio.h>

int main() {
    int i, j, k, min, rs[25], m[10], count[10], flag[25], n, f, pf = 0, next = 1;
    
    // Input: Length of reference string
    printf("Enter the length of reference string -- ");
    scanf("%d", &n);
    
    // Input: Reference string
    printf("Enter the reference string -- ");
    for(i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
        flag[i] = 0;  // Initialize all flags to 0
    }
    
    // Input: Number of frames
    printf("Enter the number of frames -- ");
    scanf("%d", &f);
    
    // Initialize memory slots and counts
    for(i = 0; i < f; i++) {
        m[i] = -1;  // Initially, all memory slots are empty
        count[i] = 0;  // No pages have been accessed
    }

    printf("\nThe Page Replacement process is -- \n");

    // Process each page in the reference string
    for(i = 0; i < n; i++) {
        // Check if page is already in memory
        for(j = 0; j < f; j++) {
            if(m[j] == rs[i]) {
                flag[i] = 1;  // Page is already in memory, no page fault
                count[j] = next;  // Update the last accessed time for the page
                next++;
                break;  // No need to check further, page is found
            }
        }

        // If page is not found in memory (page fault)
        if(flag[i] == 0) {
            // Check if there is space in memory
            if(i < f) {
                m[i] = rs[i];  // Add page to memory
                count[i] = next;  // Update the access time for the page
                next++;
            } else {
                // Find the least recently used (LRU) page
                min = 0;
                for(j = 1; j < f; j++) {
                    if(count[min] > count[j]) {
                        min = j;  // Find the page with the smallest access time
                    }
                }

                // Replace the least recently used page
                m[min] = rs[i];
                count[min] = next;
                next++;
            }
            pf++;  // Increment page fault counter
        }

        // Print the current state of memory
        for(j = 0; j < f; j++) {
            printf("%d\t", m[j]);
        }
        
        // If a page fault occurred, print the page fault number
        if(flag[i] == 0) {
            printf("PF No. -- %d", pf);
        }
        
        printf("\n");
    }

    // Output the total number of page faults
    printf("\nThe number of page faults using LRU are %d", pf);

    return 0;
}
