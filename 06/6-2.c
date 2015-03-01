
/*---
 * - 6-2.c
 * 2014/12/23(THU)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング p84 6.10 実習6-2
 * 数値でしてされた成績を文字で表して出力する
---*/

#include <stdio.h>

int main(){
	int s;	// seiseki

	printf("正解率を数値0〜100で入力してください => ");
	scanf("%d", &s);

	if     (0<=s && s<=60)
		printf("正解率%d%%の成績はFです\n", s);
	else if(61<=s && s<=70)
		printf("正解率%d%%の成績はDです\n", s);
	else if(71<=s && s<=80)
		printf("正解率%d%%の成績はCです\n", s);
	else if(81<=s && s<=90)
		printf("正解率%d%%の成績はBです\n", s);
	else if(91<=s && s<=100)
		printf("正解率%d%%の成績はAです\n", s);
	else
		printf("error! 0〜100の範囲で数値を入力してください！\n");
	return(0);
}

/*---
出力結果
% ./6-2
正解率を数値0〜100で入力してください => 82
正解率82%の成績はBです
---*/
