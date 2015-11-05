
/*---
 * - 10-4.c
 * 2015/1/20(TUE)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習10-4
 * 2つの整数の値を交換するSWAPマクロ
---*/

#include <stdio.h>

#define SWAP(a, b) {int temp; temp = a; a = b; b = temp;}

int main(){
	int a = 123;
	int b = 321;

	printf("a = %d, b = %d\n", a, b);

	SWAP(a, b)

	printf("a = %d, b = %d\n", a, b);

	return(0);
}

/*---
出力結果
% ./10-4
a = 123, b = 321
a = 321, b = 123
---*/
