#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    //first number is number of processes and second is number of resources
    int n_processes, n_resources;
    fscanf(input,"%d", &n_processes);
    fscanf(input,"%d", &n_resources);

    int *E = malloc(n_resources * sizeof(int)), *A = malloc(n_resources * sizeof(int)),
        **C = (int **)malloc(n_processes * sizeof(int *)), **R = (int **)malloc(n_processes * sizeof(int *)),
        *vis = malloc(n_processes * sizeof(int));

    for(int i = 0; i < n_processes; i++){
        C[i] = (int *)malloc(n_resources * sizeof(int));
        R[i] = (int *)malloc(n_resources * sizeof(int));
    }

    for(int i = 0; i < n_resources; i++)
        fscanf(input,"%d", &E[i]);

    for(int i = 0; i < n_resources; i++)
        fscanf(input,"%d", &A[i]);

    for(int i = 0; i < n_processes; i++){
        vis[i] = 0;
        for(int j = 0; j < n_resources; j++)
            fscanf(input, "%d", &C[i][j]);
    }

    for(int i = 0; i < n_processes; i++){
        for(int j = 0; j < n_resources; j++)
            fscanf(input, "%d", &R[i][j]);
    }

    for(int c = 0; c < n_processes; c++){
        int i = 0;
        for(i = 0; i < n_processes; i++){
            if(vis[i] == 1)
                continue;

            int check = 0;
            for(int j = 0; j < n_resources; j++){
                if(R[i][j] > A[j])
                    check = 1;
            }
            if(check == 0)
                break;
        }

        if (i == n_processes){
            int n_vis = 0;
            for(int k = 0; k < n_processes; k++)
                n_vis += vis[k];
            fprintf(output, "%d processes deadlocked", n_processes - n_vis);
            return 0;
        }

        for(int j = 0; j < n_resources; j++) {
            A[j] += C[i][j];
            if(A[j] > E[j]){
                int n_vis = 0;
                for(int k = 0; k < n_processes; k++)
                    n_vis += vis[k];
                fprintf(output, "%d processes deadlocked", n_processes - n_vis);
                return 0;
            }
        }
        vis[i] = 1;
    }
    fprintf(output, "No deadlocks detected");
    return 0;
}