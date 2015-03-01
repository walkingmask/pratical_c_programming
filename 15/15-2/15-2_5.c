
/*---
 * - 15-2.c
 * 2015/2/13(FRI)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習15-2
 * n*nの正方行列同士の乗算を行う関数とテストプログラム
 * nが500の場合に各最適化を施した時間のみ
---*/

#define N 500

#include <stdio.h>
#include <string.h>
#include <time.h>

void multiple_matrix(int m1[N][N], int m2[N][N], int m3[N][N], int n);

int main(){
	int i, j;
	// 計算前の行列
	int m1[N][N];
	int m2[N][N];
	for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			m1[i][j] = m2[i][j] = 2;
	}
    // 計算後の行列
	int m3[N][N];
	memset(m3, 0, sizeof(m3));

	clock_t start, end;
	start = clock();

	multiple_matrix(m1, m2, m3, N);

	end = clock();
	printf("time : %lu µs\n", end-start);

	 /*for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%4d ", m3[i][j]);
		}
		printf("\n");
	}*/

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
実行結果
未最適化 1876278 µs
内積形式 1459420 µs
外積形式 1711066 µs
-O3     1284466 µs
---*/
