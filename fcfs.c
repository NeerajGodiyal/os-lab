#include <stdio.h>
void sort(int a[][2], int n);
int main() {
    printf("Ayam Dobhal | Section C | University Roll Number 2016685\n");
    int n;
    printf("Enter the no. of process: ");
    scanf("%d", &n);
    int arr[n][2];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival and burst time for the %dth process: ", i + 1);
        scanf("%d%d", &arr[i][0], &arr[i][1]);
    }
    sort(arr, n);
    int wait[n], tat[n], averageWait = 0, averageTAT = 0;
    wait[0] = 0;
    for (int i = 1; i < n; i++) {
        wait[i] = wait[i - 1] + arr[i - 1][1];
        averageWait += wait[i];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = wait[i] + arr[i][1];
        averageTAT += tat[i];
    }
    double a = averageTAT / (1.0 * n), b = averageWait / (1.0 * n);
    printf("Process no.\t Arrival time \t Burst Time\t Waiting Time \t Turn around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d \t\t %d \t\t%d\n", i + 1, arr[i][0], arr[i][1], wait[i], tat[i]);
    }
    printf("The average wait time is: %lf and the average turn around time is: %lf\n", b, a);
    return 0;
}
void sort(int a[][2], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][0] > a[j][0]) {
                int t = a[i][0];
                int k = a[i][1];
                a[i][0] = a[j][0];
                a[i][1] = a[j][1];
                a[j][0] = t;
                a[j][1] = k;
            }
        }
    }
}