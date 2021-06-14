#include <stdio.h>

FILE *fp;
FILE *after_fp;
char str[18][100];
int seiseki[15][19];
float kiroku_kanzan = 700.0 / 49.0;
int average_value;
char *soten = "素点";
char *kiroku = "記録点";
char *num = "受験番号";
char *kanzan_kiroku = "換算記録点";
char *sougou = "総合点";
char *average = "平均点";
char *gouhi = "合否";
char *juni = "順位";

int func(void){
    int i, j, k, l, m, n, t = 0;

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
        seiseki[i][18] = i + 1;
    }   
}
int main(void){
    int i, j, l, t, a, b;
    int tmp;

    fp = fopen("kadai-6.csv", "r");
    after_fp = fopen("sort.dat", "w");

    if(fp == NULL && after_fp == NULL){
        printf("failed\n");
        return 1;
    }

    fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9], str[10], str[11]);
    fprintf(after_fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", num, str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9], str[10], str[11], soten, kiroku, kanzan_kiroku, sougou, gouhi, juni);

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
        fprintf(after_fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
        seiseki[i][0], seiseki[i][1], seiseki[i][2], seiseki[i][3], seiseki[i][4], seiseki[i][5], seiseki[i][6], seiseki[i][7], seiseki[i][8], seiseki[i][9], seiseki[i][10], seiseki[i][11], seiseki[i][12], seiseki[i][13], seiseki[i][14], seiseki[i][15], seiseki[i][16], seiseki[i][17], seiseki[i][18]);
    }
    printf("受験番号を入力してください\n");
    scanf("%d", &b);
    printf("国語点数 数学点数 英語点数 国語成績 社会成績 数学成績 理科成績 音楽成績 美術成績 保健体育成績 技術家庭成績 英語成績 素点　記録点　換算記録点　総合点　合否　順位\n");
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",seiseki[b-1][1], seiseki[b-1][2], seiseki[b-1][3], seiseki[b-1][4], seiseki[b-1][5], seiseki[b-1][6], seiseki[b-1][7], seiseki[b-1][8], seiseki[b-1][9], seiseki[b-1][10], seiseki[b-1][11], seiseki[b-1][12], seiseki[b-1][13], seiseki[b-1][14], seiseki[b-1][15], seiseki[b-1][16], seiseki[b-1][17], seiseki[b-1][18]);

    fclose(fp);
    fclose(after_fp);

    return 0;

}