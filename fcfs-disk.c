#include <stdio.h>
#include <stdlib.h>
int main() {

    printf("Enter the size of Array of disk: ");
    int size;
    int totalmove = 0;
    int arr[100];
    scanf("%d", &size);
    printf("Enter the Track number: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int head;
    printf("Enter the initial Head: ");
    scanf("%d", &head);
    printf("SEEK SEQUENCE IS:\n");
    for (int i = 0; i < size; i++) {
        totalmove = totalmove + abs(arr[i] - head);
        head = arr[i];
        printf("%d\n", head);
    }
    printf("Total Head Movement=%d\n ", totalmove);
    return 0;
}