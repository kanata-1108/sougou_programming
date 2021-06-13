#include <stdio.h>

int main(void){
    FILE *fp;
    FILE *after_fp;
    int i, j, k, l;
    char str[17][100];
    float seiseki[15][17];
    
    fp = fopen("kadai-6.csv", "r");
    after_fp = fopen("after_kadai-6.csv", "w");

    if(fp == NULL && after_fp == NULL){
        printf("failed\n");
        return 1;
    }

    fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9], str[10], str[11]);
    fprintf(after_fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9], str[10], str[11]);

    for(i = 1; i < 16; i++){
        fscanf(fp, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", 
        &seiseki[i][0], &seiseki[i][1], &seiseki[i][2], &seiseki[i][3], &seiseki[i][4], &seiseki[i][5], &seiseki[i][6], &seiseki[i][7], &seiseki[i][8], &seiseki[i][9], &seiseki[i][10], &seiseki[i][11]);
        fprintf(after_fp, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
        seiseki[i][0], seiseki[i][1], seiseki[i][2], seiseki[i][3], seiseki[i][4], seiseki[i][5], seiseki[i][6], seiseki[i][7], seiseki[i][8], seiseki[i][9], seiseki[i][10], seiseki[i][11]);
    }

    return 0;
}