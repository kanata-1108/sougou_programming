#include <stdio.h>

int main(void){
    FILE *fp;
    char *c1 = "番号";
    char *c2 = "国語";
    char *c3 = "数学";
    char *c4 = "英語";
    int n1 = 1;
    int n2 = 10;
    int n3 = 12;
    int n4 = 14;
    int i;

    fp = fopen("kadai-3.csv", "w");

    if(fp == NULL){
        printf("failed\n");
        return 1;
    }
    
    fprintf(fp, "%s,%s,%s,%s\n", c1, c2, c3, c4);

    for(i = 0; i < 5; i++){
        fprintf(fp, "%d,%d,%d,%d\n", n1 + i, n2 + 2 * i, n3 + 2 * i, n4 + 2 * i);
    }
    fclose(fp);

    return 0;
}

