
/*---
 * - 6-3.c
 * 2014/12/23(THU)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング p84 6.10 実習6-3
 * 6-2プログラムを修正して，正解率の一の位の数に基づいて+，-を付けて出力する
---*/

#include <stdio.h>

int main(){
	int ratio, ope=0;	// 正解率ratio，+,-をつけるか判断するope
	char grade[3];		// 成績
	grade[2] = '\0';

	printf("正解率を数値0〜100で入力してください => ");
	scanf("%d", &ratio);

	if     (0<=ratio && ratio<=60)
		grade[1] = 'F';
	else if(61<=ratio && ratio<=70)
		grade[1] = 'D';
	else if(71<=ratio && ratio<=80)
		grade[1] = 'C';
	else if(81<=ratio && ratio<=90)
		grade[1] = 'B';
	else if(91<=ratio && ratio<=100)
		grade[1] = 'A';
	else{
		printf("error! 0〜100の範囲で数値を入力してください！\n");
		return(0);
	}

	ope = ratio % 10;
	if     (1<=ope && ope <=3)
		grade[0] = '-';
	else if(4<=ope && ope <=7)
		grade[0] = ' ';
	else 
		grade[0] = '+';

	printf("正解率%d%%の成績は%sです\n", ratio, grade);


	return(0);
}

/*---
出力結果
% ./6-3
正解率を数値0〜100で入力してください => 71
正解率71%の成績は-Cです
---*/
