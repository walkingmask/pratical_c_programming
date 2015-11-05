/*---
 * - 5-5.c
 * 2014/12/23(THU)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング p73 5.16 実習5-5
 * 時間と分を入力するとその合計時間を分で表す (ex. 1h30m -> 90m)
---*/

#include <stdio.h>

int main(){
	int h, m;	// hour, minutes
	char buf[6];
	printf("時間を入力してください(例 09:45) => ");
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "%d:%d", &h, &m);
	printf("%d:%dの合計時間は%d分です\n", h, m, (60*h+m));
	return(0);
}

/*---
出力結果
% ./5-5
時間を入力してください(例 09:45) => 4:44
4:44の合計時間は284分です
---*/
