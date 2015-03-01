
/*---
 * - 9-3.c
 * 2015/1/20(TUE)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習9-3
 * 配列arrayに特定の数値numberがいくつあるか数える再帰関数とテストプログラム
---*/

#include <stdio.h>

int count(int number, int *array, int length);

int main(){
	int array[16] = {1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4};	// 数値を格納した配列
	int number = 4;										// サーチする数値

	printf("配列に含まれる %d の数は %d です\n", number, count(number, array, 16));

	return(0);
}

/* 再帰関数 */
int count(int number, int *array, int length){
	if(length == -1) return(0);	// 終了条件

	if(array[length] == number)
		return(1 + count(number, array, length-1));
	else
		return(count(number, array, length-1));
}

/*---
出力結果
% ./9-3
配列に含まれる 4 の数は 2 です
% ./9-3
配列に含まれる 2 の数は 1 です
---*/
