
/*---
 * - 15-2_3.c
 * 2015/2/13(FRI)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習15-2
 * n*nの正方行列同士の乗算を行う関数とテストプログラム
 * 最適化コマンドラインオプションを使用 -O3
---*/

#define N 4

#include <stdio.h>
#include <string.h>
#include <time.h>

void multiple_matrix(int m1[N][N], int m2[N][N], int m3[N][N], int n);

int main(){
	// 計算前の行列
	int m1[N][N] ={{1 ,2 ,3, 4},
                   {4, 5, 6, 7},
                   {7, 8, 9, 10},
                   {10, 11, 12, 13}};
	int m2[N][N] ={{1 ,2 ,3, 4},
                   {4, 5, 6, 7},
                   {7, 8, 9, 10},
                   {10, 11, 12, 13}};
    // 計算後の行列
	int m3[N][N];
	memset(m3, 0, sizeof(m3));

	clock_t start, end;
	start = clock();

	multiple_matrix(m1, m2, m3, N);

	end = clock();
	printf("time : %lu µs\n", end - start);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%4d ", m3[i][j]);
		}
		printf("\n");
	}

	return(0);
}

void multiple_matrix(int m1[N][N], int m2[N][N], int m3[N][N], int n){
	int i, j, k;
	register int temp;
	for(k=0; k<n; k++){
		for(j=0; j<n; j++){
			temp = m2[k][j];
			for(i=0; i<n; i++)
				m3[i][j] += (m1[i][k] * temp);
		}
	}
}

/*---
出力結果
% ./15-2_4
time : 2 µs
  70   80   90  100 
 136  158  180  202 
 202  236  270  304 
 268  314  360  406 
---*/
