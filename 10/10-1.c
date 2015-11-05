
/*---
 * - 10-1.c
 * 2015/1/20(TUE)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習10-1
 * パラメータが10で割り切れるなら真をそうでないなら偽を返すマクロ
---*/

#include <stdio.h>

#define IS_MULTIPLE10(num) ( (num % 10 == 0)? 1 : 0 )

int main(){
	int a = 11;
	int b = 30;
	char answer;

	answer = IS_MULTIPLE10(a)? 'y' : 'n';
	printf("is %d multiple of 10? : %c\n", a, answer);

	answer = IS_MULTIPLE10(b)? 'y' : 'n';
	printf("is %d multiple of 10? : %c\n", b, answer);

	return(0);
}

/*---
出力結果
% ./10-1 
is 11 multiple of 10? : n
is 30 multiple of 10? : y
---*/
