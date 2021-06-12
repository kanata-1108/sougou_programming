#include <stdio.h>

int main(void){
    FILE *fp;
    char str[4][10];
    int data[10][4];
    int i, num, japanese, math, english;

    fp = fopen("kadai-1csv.csv", "r");

    if(fp == NULL){
        printf("failed\n");
        return 1;
    }

    fscanf(fp, "%[^,],%[^,],%[^,],%s", str[0], str[1], str[2], str[3]);
    printf("%s %s %s %s\n", str[0], str[1], str[2],str[3]);

    for(i = 0; i < 3;i++){
        fscanf(fp, "%d,%d,%d,%d", &data[i][0], &data[i][1], &data[i][2], &data[i][3]);
        printf("%d %d %d %d\n", data[i][0], data[i][1], data[i][2], data[i][3]);
    }
    fclose(fp);

    return 0;
}

