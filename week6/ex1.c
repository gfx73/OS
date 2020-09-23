#include <stdio.h>
#include <stdlib.h>

struct process{
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
};

void SortProcesses(struct process *processes, int n) {
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n - i; j++){
            if(processes[j - 1].AT > processes[j].AT){
                struct process t = processes[j - 1];
                processes[j - 1] = processes[j];
                processes[j] = t;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes\n");
    scanf("%d", &n);

    struct process *processes = malloc(sizeof(struct process) * n);

    printf("Enter arrival time and burst time\n");

    for(int i = 0; i < n; i++){
        int AT, BT;
        scanf("%d %d", &AT, &BT);

        processes[i].AT = AT;
        processes[i].BT = BT;
    }

    SortProcesses(processes, n);

    double ATAT = 0, AWT = 0;
    int time = 0;

    for(int i = 0; i < n; i++){
        if(time < processes[i].AT)
            time = processes[i].AT;

        processes[i].CT = time + processes[i].BT;
        processes[i].TAT = processes[i].CT - processes[i].AT;
        processes[i].WT = processes[i].TAT - processes[i].BT;

        ATAT = (ATAT * i + processes[i].TAT) * 1. / (i + 1);
        AWT = (AWT * i + processes[i].WT) * 1. / (i + 1);

        time = time + processes[i].BT;
    }

    for(int i = 0; i < n; i++)
        printf("Process with AT %d and BT %d has following metrics:\nCompletion time = %d\nTurn around time = %d\nWaiting time = %d\n", processes[i].AT, processes[i].BT, processes[i].CT, processes[i].TAT, processes[i].WT);

    printf("Average turn around time is %f\nAverage waiting time is %f\n", ATAT, AWT);
    return 0;
}