/*---
 * - 5-4.c
 * 2014/12/23(THU)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング p73 5.16 実習5-4
 * マイル数をキロメートル数に変換する (1mile = 0.6213Kmとする)
---*/

#include <stdio.h>

int main(){
	const double mile1 = 0.6213;
	double mile, kmeter;
	mile = kmeter = 0;
	printf("マイル数を入力してください => ");scanf("%lf", &mile);
	kmeter = mile / mile1;
	printf("%fマイルは%fキロメートルです\n", mile, kmeter);
	return(0);
}

/*---
出力結果
% ./5-4
マイル数を入力してください => 8
8.000000マイルは12.876227キロメートルです
---*/
