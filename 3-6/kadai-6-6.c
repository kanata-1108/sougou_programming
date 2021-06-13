#include <stdio.h>

FILE *fp;
FILE *after_fp;
char str[17][100];
int seiseki[15][17];
int soten_value[15];
int kiroku_value[15];
int kiroku_kanzan_value[15];
float kiroku_kanzan = 700.0 / 49.0;
int sougou_value[15];
int average_value;
int gouhi_value[15];
char *soten = "素点";
char *kiroku = "記録点";
char *num = "受験番号";
char *kanzan_kiroku = "換算記録点";
char *sougou = "総合点";
char *average = "平均点";
char *gouhi = "合否";

int func(void){
    int i, j, k, l, m, n, t = 0, u;

    for(i = 0; i < 15; i++){
        fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", 
        &seiseki[i][0], &seiseki[i][1], &seiseki[i][2], &seiseki[i][3], &seiseki[i][4], &seiseki[i][5], &seiseki[i][6], &seiseki[i][7], &seiseki[i][8], &seiseki[i][9], &seiseki[i][10], &seiseki[i][11]);
        for(k = 0; k < 3; k++){
            soten_value[i] += seiseki[i][k];
        }
        for(l = 0; l < 9; l++){
            kiroku_value[i] += seiseki[i][l + 3];
        }
        for(m = 3; m < 12; m++){
            if(m == 5 || m == 6){
                kiroku_kanzan_value[i] += seiseki[i][m] * 1.4;
            }else{
                kiroku_kanzan_value[i] += seiseki[i][m];
            }
        }
        kiroku_kanzan_value[i] = kiroku_kanzan_value[i] * kiroku_kanzan;
        sougou_value[i] = kiroku_kanzan_value[i] + soten_value[i];

        if(i == 14){
            for(j = 0; j < 15; j++){
                t += sougou_value[j];
                printf("%d\n", t);
            }
            average_value = t / 15;
            for(n = 0; n < 15; n++){
                if(sougou_value[n] >= average_value){
                    gouhi_value[n] = 1;
                }else{
                    gouhi_value[n] = 0;
                }
            }
        }
    }   
}
int main(void){
    int i;

    fp = fopen("kadai-6.csv", "r");
    after_fp = fopen("after_kadai-6.csv", "w");

    if(fp == NULL && after_fp == NULL){
        printf("failed\n");
        return 1;
    }

    fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9], str[10], str[11]);
    fprintf(after_fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", num, str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9], str[10], str[11], soten, kiroku, kanzan_kiroku, sougou, gouhi);

    func();

    for(i = 0; i < 15; i++){
        fprintf(after_fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
        i + 1, seiseki[i][0], seiseki[i][1], seiseki[i][2], seiseki[i][3], seiseki[i][4], seiseki[i][5], seiseki[i][6], seiseki[i][7], seiseki[i][8], seiseki[i][9], seiseki[i][10], seiseki[i][11], soten_value[i], kiroku_value[i], kiroku_kanzan_value[i], sougou_value[i], gouhi_value[i]);
    }

    fclose(fp);

    return 0;

}