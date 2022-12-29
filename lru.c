#include <stdio.h>
int findLRU(int *, int);
int main() {

    int no_of_frames, n, frames[10], a[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
    printf("Enter number of a: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    for (i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }
    for (i = 0; i < n; ++i) {
        flag1 = flag2 = 0;
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == a[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    faults++;
                    frames[j] = a[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0) {
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = a[i];
            time[pos] = counter;
        }
        printf("\n");
        for (j = 0; j < no_of_frames; ++j)
            printf("%d\t", frames[j]);
    }
    printf("\n");
    printf("Total Page Faults = %d\n", faults);

    return 0;
}
int findLRU(int *time, int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}