#include <stdio.h>
#include <stdlib.h>
int main() {

    printf("Enter the size of Array of disk: ");
    int size;
    int totalmove = 0, count = 0;
    int arr[100];
    scanf("%d", &size);
    printf("Enter the Track number: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    int head;
    printf("Enter the initial Head: ");
    scanf("%d", &head);
    printf("SEEK SEQUENCE IS : ");
    while (count != size) {
        int min = 1000, diff, index;
        for (int i = 0; i < size; i++) {
            diff = abs(arr[i] - head);
            if (min > diff) {
                min = diff;
                index = i;
            }
        }
        totalmove = totalmove + min;
        head = arr[index];
        arr[index] = 1000;
        count++;
        printf("%d\n", head);
    }
    printf("Total head movement is %d\n", totalmove);
    return 0;
}