#include <stdio.h>
#include <stdlib.h>
#define QUANTUM 0.1
struct process{
    int AT;
    int BT;
    double CT;
    double TAT;
    double WT;
    double RemainingTime;
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

void DeleteJob(struct process **processes, int *n, struct process *processToDelete){
    int i;
    for(i = 0; i < *n; i++){
        if(processes[i] == processToDelete)
            break;
    }
    for(i = i + 1; i < *n; i++)
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
        processes[i].RemainingTime = BT;
    }

    SortProcessesByAT(processes, n);

    int NumOfProcessInQueue = 0;
    struct process **processQueue = malloc(sizeof(struct process) * n);

    double ATAT = 0, AWT = 0, time = 0;
    int processesDone = 0;

    for(int i = 0, processToExecute = 0; processesDone != n; ){
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

        struct process *currentProcess =  processQueue[processToExecute];

        if(currentProcess->RemainingTime <= QUANTUM) {
            currentProcess->CT = time + QUANTUM;
            currentProcess->TAT = currentProcess->CT - currentProcess->AT;
            currentProcess->WT = currentProcess->TAT - currentProcess->BT;

            ATAT = (ATAT * processesDone + currentProcess->TAT) * 1. / (processesDone + 1);
            AWT = (AWT * processesDone + currentProcess->WT) * 1. / (processesDone + 1);

            DeleteJob(processQueue, &NumOfProcessInQueue, currentProcess);
            if(NumOfProcessInQueue != 0)
                processToExecute = processToExecute % NumOfProcessInQueue;

            processesDone++;
        }
        else
            processToExecute = (processToExecute + 1) % NumOfProcessInQueue;

        currentProcess->RemainingTime -= QUANTUM;
        time += QUANTUM;
    }

    for(int i = 0; i < n; i++)
        printf("Process with AT %d and BT %d has following metrics:\nCompletion time = %f\nTurn around time = %f\nWaiting time = %f\n", processes[i].AT, processes[i].BT, processes[i].CT, processes[i].TAT, processes[i].WT);

    printf("Average turn around time is %f\nAverage waiting time is %f\n", ATAT, AWT);
    return 0;
}