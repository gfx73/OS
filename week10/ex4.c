#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>

#define MAX_NUM_OF_FILES 1000
int main(){
	FILE *fp = fopen("ex4.txt", "w");
	DIR *tmp = opendir("tmp");
	struct dirent *dp;
	struct dirent *inode[MAX_NUM_OF_FILES];
	int n = 0;
	while((dp = readdir(tmp)) != NULL){
		inode[n] = dp;
		n++;
	}
	for(int i = 0; i < n; i++){
		int m = 0;
		int indeces[MAX_NUM_OF_FILES];
		for(int j = 0; j < n; j++){
			if(inode[i]->d_ino == inode[j]->d_ino){
				if(j <= i && m != 0){
					m = 0;
					break;
				}
				indeces[m] = j;
				m++;
			}
		}
		if(m > 1){
			fprintf(fp, "%lu\n", inode[i]->d_ino);
			for(int k = 0; k < m; k++)
				fprintf(fp, "%s ", inode[indeces[k]]->d_name);
			fprintf(fp, "\n");
		}
	}
	return 0;
}
