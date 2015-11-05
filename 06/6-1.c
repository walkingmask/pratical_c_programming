
/*---
 * - 6-1.c
 * 2014/12/23(THU)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング p84 6.10 実習6-1
 * 2点間の距離の2乗を計算し，2乗した値から元の距離を算出する
---*/

#include <stdio.h>
#include <math.h>

int main(){
	int a, b, p;	// 2点a,b，2乗した値power
	double d;		// 2乗した値の平方根=2点間の距離distance
	char buf[64];

	printf("2つの値を入力してください(例 200,7891) => ");
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "%d,%d", &a, &b);

	p = (a-b)*(a-b);
	printf("%dと%dの距離の2乗は%dです\n", a, b, p);

	d = sqrt(p);
	printf("%dと%dの距離は%.2fです\n", a, b, d);
	return(0);
}

/*---
出力結果
% ./6-1
2つの値を入力してください(例 200,7891) => 22,67
22と67の距離の2乗は2025です
22と67の距離は45.00です
---*/
