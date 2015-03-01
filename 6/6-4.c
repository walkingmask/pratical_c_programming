
/*---
 * - 6-4.c
 * 2014/12/23(THU)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング p84 6.10 実習6-4
 * 指定された総額(1ドル以下)について，その内訳となる硬貨の数を計算する
---*/

#include <stdio.h>
#include <math.h>

int main(){
	int cents, coins;	// 総額cents，硬貨計算用coins
	int q, d, n, p;		// qurters, dimes, nickels, pennies
	q = d = n = p = 0;

	printf("総額を入力してください(1ドル以下) => ");
	scanf("%d", &cents);

	coins = cents;

	q = coins / 25; coins = coins % 25;
	d = coins / 10; coins = coins % 10;
	n = coins / 5 ; coins = coins % 5 ;
	p = coins;

	printf("%dセントに含まれる硬貨は以下の通りです\n", cents);
	printf("%d qurters\n%d dimes\n%d nickels\n%d pennies\n", q, d, n, p);

	return(0);
}

/*---
出力結果
% ./6-4
総額を入力してください(1ドル以下) => 68
68セントに含まれる硬貨は以下の通りです
2 qurters
1 dimes
1 nickels
3 pennies
---*/
