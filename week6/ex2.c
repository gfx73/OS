#include <stdio.h>
#include <stdlib.h>

struct process{
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
};

void SortProcessesByAT(struct process *processes, int n) {
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

void SortProcessesByBT(struct process **processes, int n) {
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n - i; j++){
            if(processes[j - 1]->BT > processes[j]->BT){
                struct process *t = processes[j - 1];
                processes[j - 1] = processes[j];
                processes[j] = t;
            }
        }
    }
}

void DeleteTheShortestJob(struct process **processes, int *n){
    for(int i = 1; i < *n; i++)
        processes[i - 1] = processes[i];
    *n = *n - 1;
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

    SortProcessesByAT(processes, n);

    int NumOfProcessInQueue = 0;
    struct process **processQueue = malloc(sizeof(struct process) * n);

    double ATAT = 0, AWT = 0;
    int time = 0, processesDone = 0;

    for(int i = 0; processesDone != n; ){
        if(NumOfProcessInQueue == 0 && time < processes[i].AT) {
            time = processes[i].AT;
            processQueue[NumOfProcessInQueue] = &processes[i];
            NumOfProcessInQueue++;
            i++;
        }

        for(int j = i; j < n && processes[j].AT <= time; j++){
            processQueue[NumOfProcessInQueue] = &processes[i];
            NumOfProcessInQueue++;
            i++;
        }

        SortProcessesByBT(processQueue, NumOfProcessInQueue);

        struct process *currentProcess =  processQueue[0];

        currentProcess->CT = time + currentProcess->BT;
        currentProcess->TAT = currentProcess->CT - currentProcess->AT;
        currentProcess->WT = currentProcess->TAT - currentProcess->BT;

        ATAT = (ATAT * processesDone + currentProcess->TAT) * 1. / (processesDone + 1);
        AWT = (AWT * processesDone + currentProcess->WT) * 1. / (processesDone + 1);

        time = time + currentProcess->BT;

        DeleteTheShortestJob(processQueue, &NumOfProcessInQueue);
        processesDone++;
    }

    for(int i = 0; i < n; i++)
        printf("Process with AT %d and BT %d has following metrics:\nCompletion time = %d\nTurn around time = %d\nWaiting time = %d\n", processes[i].AT, processes[i].BT, processes[i].CT, processes[i].TAT, processes[i].WT);

    printf("Average turn around time is %f\nAverage waiting time is %f\n", ATAT, AWT);
    return 0;
}