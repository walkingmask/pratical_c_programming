
/*---
 * - 13-1.c
 * 2015//()
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習13-1
 * ポインタを使って配列の各要素を0に設定するプログラム
---*/

#include <stdio.h>

int main(){
	int i;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	for(i=0; i<10; i++) printf("%d ", arr[i]);
	printf("\n");

	/* 初期化 */
	for(i=0; i<10; i++) *(arr+i) = 0;

	for(i=0; i<10; i++) printf("%d ", arr[i]);
	printf("\n");

	return(0);
}

/*---
出力結果
% ./13-1 
1 2 3 4 5 6 7 8 9 10 
0 0 0 0 0 0 0 0 0 0 
---*/