#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_OF_PAGE_FRAMES 100

struct Frame{
    unsigned int R;
    unsigned int VirtualPage;
    int present;
    unsigned int age;
};
int Find_Minimal_R(struct Frame TLB[]){
    for(int i = 0; i < NUM_OF_PAGE_FRAMES; i++){
        if(TLB[i].present == 0)
            return i;
    }
    int mini = 0;
    for(int i = 0; i < NUM_OF_PAGE_FRAMES; i++){
        if(TLB[i].age < TLB[mini].age)
            mini = i;
    }
    return mini;
};
int find_by_VirtualPage(struct Frame TLB[], int VirtualPageIndex){
    for(int i = 0; i < NUM_OF_PAGE_FRAMES; i++){
        if(TLB[i].present == 1) {
            if (VirtualPageIndex == TLB[i].VirtualPage)
                return i;
        }
    }
    return -1;
}
int main(){
    FILE *input = fopen("input.txt", "r");

    struct Frame TLB[NUM_OF_PAGE_FRAMES];
    for(int i = 0; i < NUM_OF_PAGE_FRAMES; i++){
        TLB[i].present = 0;
    }

    int VirtualPageIndex, hit = 0, miss = 0;
    //let tick be equal to the time needed for scanning one Virtual Page index
    while(fscanf(input, "%d", &VirtualPageIndex) != EOF){
        if(find_by_VirtualPage(TLB, VirtualPageIndex) == -1){
            int PageToReplace = Find_Minimal_R(TLB);
            TLB[PageToReplace].VirtualPage = VirtualPageIndex;
            TLB[PageToReplace].present = 1;
            TLB[PageToReplace].R = 1;
            miss++;
        }
        else{
            int PageReferenced = find_by_VirtualPage(TLB, VirtualPageIndex);
            TLB[PageReferenced].R = 1;
            hit++;
        }

        //updating ages
        //when the tick starts R bits should be equal to zero
        for(int i = 0; i < NUM_OF_PAGE_FRAMES; i++){
            //right shift
            TLB[i].age /= 2;
            //number below is 2^31, it is the leftmost bit
            TLB[i].age += 2147483648 * TLB[i].R;
            TLB[i].R = 0;
        }
    }
    printf("%lf", hit * 1. / miss);
    return 0;
}