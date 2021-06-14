#include <stdio.h>

int main(void){
    FILE *fp;
    FILE *after_fp;
    int i, j, k, l, m;
    char str[17][100];
    int seiseki[15][17];
    char *soten = "素点";
    char *kiroku = "記録点";
    char *num = "受験番号";
    char *kanzan_kiroku = "換算記録点";
    int soten_value;
    int kiroku_value;
    int kiroku_kanzan_value;
    float kiroku_kanzan = 700.0 / 49.0;
    char *sougou = "総合点";
    int sougou_value;

    fp = fopen("kadai-6.csv", "r");
    after_fp = fopen("after_kadai-6.csv", "w");

    if(fp == NULL && after_fp == NULL){
        printf("failed\n");
        return 1;
    }

    fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9], str[10], str[11]);
    fprintf(after_fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", num, str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9], str[10], str[11], soten, kiroku, kanzan_kiroku, sougou);

    for(i = 1; i < 16; i++){
        fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", 
        &seiseki[i][0], &seiseki[i][1], &seiseki[i][2], &seiseki[i][3], &seiseki[i][4], &seiseki[i][5], &seiseki[i][6], &seiseki[i][7], &seiseki[i][8], &seiseki[i][9], &seiseki[i][10], &seiseki[i][11]);
        for(k = 0; k < 3; k++){
            soten_value += seiseki[i][k];
        }
        for(l = 0; l < 9; l++){
            kiroku_value += seiseki[i][l + 3];
        }
        for(m = 3; m < 12; m++){
            if(m == 5 || m == 6){
                kiroku_kanzan_value += seiseki[i][m] * 1.4;
            }else{
                kiroku_kanzan_value += seiseki[i][m];
            }
        }
        kiroku_kanzan_value = kiroku_kanzan_value * kiroku_kanzan;
        sougou_value += kiroku_kanzan_value + soten_value;

        fprintf(after_fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
        i, seiseki[i][0], seiseki[i][1], seiseki[i][2], seiseki[i][3], seiseki[i][4], seiseki[i][5], seiseki[i][6], seiseki[i][7], seiseki[i][8], seiseki[i][9], seiseki[i][10], seiseki[i][11], soten_value, kiroku_value, kiroku_kanzan_value, sougou_value);

        soten_value = 0;
        kiroku_value = 0;
        kiroku_kanzan_value = 0;
        sougou_value = 0;
    }

    return 0;
}