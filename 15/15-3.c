
/*---
 * - 15-3.c
 * 2015/1/22(THU)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習15-3
 * 配列の要素の統計を算出するプログラム
 * 配列の要素はrandを使用
 * 非最適化状態と最適化オプション-O3を使った場合の実行時間を比較
---*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_MAX 1024*100

int main(){
	int i;
	int arr[ARR_MAX];
	register int sum = 0;

	srand((unsigned)time(NULL));
	for(i=0; i<ARR_MAX; i++) arr[i] = rand()%100;

	clock_t start, end;
	start = clock();

	for(i=0; i<ARR_MAX; i++) sum += arr[i];

	end = clock();
	printf("time : %lu µs\n", end-start);

	return(0);
}

/*---
実行結果
非最適化オプション		280 ~ 350 µs
最適化オプション-O3	1 ~ 3     µs
---*/
