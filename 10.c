#include<stdio.h>

int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;
    
    // Input the number of tracks to be traversed
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);
    
    // Input the position of the head
    printf("Enter the position of the head: ");
    scanf("%d", &h);
    
    // Initialize the array with 0 for first two positions (head position and zero track)
    t[0] = 0;
    t[1] = h;
    
    // Input the tracks
    printf("Enter the tracks: ");
    for (i = 2; i < n + 2; i++) {
        scanf("%d", &t[i]);
    }
    
    // Sorting the tracks (including head and zero) in ascending order
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
    
    // Finding the index of the head in the sorted array
    for (i = 0; i < n + 2; i++) {
        if (t[i] == h) {
            j = i;
            k = i;
            p = 0;
        }
    }
    
    // Traverse to the left side from the head
    while (t[j] != 0) {
        atr[p] = t[j];
        j--;
        p++;
    }
    atr[p] = t[j]; // Adding the 0th track to the sequence
    
    // Traverse to the right side from the head
    for (p = k + 1; p < n + 2; p++, k++) {
        atr[p] = t[k + 1];
    }
    
    // Printing the seek sequence and calculating the total head movements
    printf("Seek sequence is: ");
    for (j = 0; j < n + 1; j++) {
        if (atr[j] > atr[j + 1]) {
            d[j] = atr[j] - atr[j + 1];
        } else {
            d[j] = atr[j + 1] - atr[j];
        }
        sum += d[j];
        printf("%d ", atr[j]);
    }
    
    // Output total head movements
    printf("\nTotal head movements: %d", sum);
    
    return 0;
}
