#include <stdio.h>
int main() {

    int n;
    printf("Enter the no. of process: ");
    scanf("%d", &n);
    int arr[n][3], burst[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival, burst time and priority number for the process %d: ", i + 1);
        scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
        burst[i] = arr[i][1];
    }
    int wait[n], tat[n], prev[n];
    int t = 0, averageTAT = 0, averageWait = 0;
    for (int i = 0; i < n; i++) {
        wait[i] = 0;
        prev[i] = arr[i][0];
    }
    while (1) {
        int ind = 0, mini = 100000;
        for (int i = 0; i < n; i++) {
            if (t >= arr[i][0] && mini > arr[i][2] && arr[i][1] > 0) {
                mini = arr[i][2];
                ind = i;
            }
        }
        if (mini == 100000)
            break;
        arr[ind][1] -= 1;
        wait[ind] += t - prev[ind];
        t++;
        prev[ind] = t;
    }
    for (int i = 0; i < n; i++) {
        tat[i] = wait[i] + burst[i];
        averageTAT += tat[i];
        averageWait += wait[i];
    }
    double a = averageTAT / (1.0 * n), b = averageWait / (1.0 * n);
    printf("Process no.\t Arrival time \t Burst Time\t Priority_no \t Waiting Time \t   Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t\t %d\t\t\t %d \t\t\t %d \t\t\t%d\t\t\t%d\n", i + 1, arr[i][0], burst[i], arr[i][2], wait[i], tat[i]);
    }
    printf("The average wait time is: %lf and the average turn around time is: %lf\n", b, a);
    return 0;
}