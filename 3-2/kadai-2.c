#include <stdio.h>

int main(void){
    FILE *fp;
    char str[4][10];
    int data[10][4];
    int i, num, japanese, math, english;
    int j, t, k, l, n = 3;

    fp = fopen("kadai-2.csv", "r");

    if(fp == NULL){
        printf("failed\n");
        return 1;
    }

    printf("before sort\n");
    fscanf(fp, "%[^,],%[^,],%[^,],%s", str[0], str[1], str[2], str[3]);
    printf("%s %s %s %s\n", str[0], str[1], str[2],str[3]);

    for(i = 0; i < 3;i++){
        fscanf(fp, "%d,%d,%d,%d", &data[i][0], &data[i][1], &data[i][2], &data[i][3]);
        printf("%d %d %d %d\n", data[i][0], data[i][1], data[i][2], data[i][3]);
    }
    fclose(fp);

    for(l = 0; l < n - 1; l++){
        for(j = n - 1; j > l; j--){
            if(data[j-1][1] < data[j][1]){
                for(k = 0; k < 4; k++){
                    t = data[j][k];
                    data[j][k] = data[j-1][k];
                    data[j-1][k] = t;
                }
            }
        }
   }

   printf("\n");
   printf("after sort\n");
   printf("%s %s %s %s\n", str[0], str[1], str[2],str[3]);
   for(i = 0; i < 3;i++){
       printf("%d %d %d %d\n", data[i][0], data[i][1], data[i][2], data[i][3]);
    }

    return 0;
}

