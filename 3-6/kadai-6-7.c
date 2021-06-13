#include <stdio.h>

FILE *fp;
FILE *after_fp;
char str[18][100];
int seiseki[15][18];
float kiroku_kanzan = 700.0 / 49.0;
int average_value;
char *soten = "素点";
char *kiroku = "記録点";
char *num = "受験番号";
char *kanzan_kiroku = "換算記録点";
char *sougou = "総合点";
char *average = "平均点";
char *gouhi = "合否";

int func(void){
    int i, j, k, l, m, n, t = 0, u, a;

    for(i = 0; i < 15; i++){
        fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", 
        &seiseki[i][1], &seiseki[i][2], &seiseki[i][3], &seiseki[i][4], &seiseki[i][5], &seiseki[i][6], &seiseki[i][7], &seiseki[i][8], &seiseki[i][9], &seiseki[i][10], &seiseki[i][11], &seiseki[i][12]);
        seiseki[i][0] = i + 1;

        for(k = 1; k < 4; k++){
            seiseki[i][13] += seiseki[i][k];
        }
        for(l = 1; l < 10; l++){
            seiseki[i][14] += seiseki[i][l + 3];
        }
        for(m = 4; m < 13; m++){
            if(m == 6 || m == 7){
                seiseki[i][15] += seiseki[i][m] * 1.4;
            }else{
                seiseki[i][15] += seiseki[i][m];
            }
        }
        seiseki[i][15] = seiseki[i][15] * kiroku_kanzan;
        seiseki[i][16] = seiseki[i][15] + seiseki[i][13];


        if(i == 14){
            for(j = 0; j < 16; j++){
                t += seiseki[j][16];
            }
            average_value = t / 15;
            for(n = 0; n < 16; n++){
                if(seiseki[n][16] >= average_value){
                    seiseki[n][17] = 1;
                }else{
                    seiseki[n][17] = 0;
                }
            }
        }
    }   
}
int main(void){
    int i, j, l, k, t, a, b, c, d;
    int tmp;

    fp = fopen("kadai-6.csv", "r");
    after_fp = fopen("sort.dat", "w");

    if(fp == NULL && after_fp == NULL){
        printf("failed\n");
        return 1;
    }

    fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9], str[10], str[11]);
    fprintf(after_fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", num, str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9], str[10], str[11], soten, kiroku, kanzan_kiroku, sougou, gouhi);

    func();

    for(l = 0; l < 15; l++){
        for(j = 15; j > l; j--){
            if(seiseki[j-1][16] < seiseki[j][16]){
                for(a = 0; a < 18; a++){
                    t = seiseki[j][a];
                    seiseki[j][a] = seiseki[j-1][a];
                    seiseki[j-1][a] = t;
                }
            }
        }
   }

    for(i = 0; i < 15; i++){
        fprintf(after_fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
        seiseki[i][0], seiseki[i][1], seiseki[i][2], seiseki[i][3], seiseki[i][4], seiseki[i][5], seiseki[i][6], seiseki[i][7], seiseki[i][8], seiseki[i][9], seiseki[i][10], seiseki[i][11], seiseki[i][12], seiseki[i][13], seiseki[i][14], seiseki[i][15], seiseki[i][16], seiseki[i][17]);
    }

    fclose(fp);

    return 0;

}