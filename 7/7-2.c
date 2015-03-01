/*---
 * - 7-2.c
 * 2015/01/12(MON)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング p204 7.15 実習7-2
 * 任意の2つの日付の間の日数を計算するプログラム
 
 * 基本的な考え方
1.日付が遡る
	　→日付を入れ替える
2.同じ年
	2.1同じ月
		2.1.1同じ日
			→0日
		2.1.2異なる日
			→日付2の日-日付1の日
	2.2異なる月
		2.2.1ひと月のみ異なる
			→日付1の月の残り日数+日付2の月の経過日数※
		2.2.2ひと月以上異なる
			→上記に加えて間の月の日数※
3.異なる年
	3.1一年のみ異なる
		→日付1の月の残り日数+年の残り月数+日付2の月の残り日数+年の経過月数※
	3.2一年以上異なる
		→上記に加えて間の年数※
※閏年の加味
---*/

#include <stdio.h>

void replace_date(char *cdate1, char *cdate2);
int is_LeapYear(int year);

int main(){
	int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};	// 各月の日数(閏年ではない場合の)
	int i,sumday=0;												// sumday 合計日数
	int year1,year2,month1,month2,day1,day2;					// 日付1と2を格納する
	char buf1[10],buf2[10];										// 入力受付用

	// プログラムの説明と入力の問い合わせ
	printf("特定の2つの日付の間の日数を計算します\n");
	printf("2つの日付を8桁の数字で入力してください(入力例 19900511)\n");
	printf("日付1 => ");fgets(buf1, sizeof(buf1), stdin);
	printf("日付2 => ");fgets(buf2, sizeof(buf2), stdin);

	// 日付が遡る場合の処理
	replace_date(buf1, buf2);

	sscanf(buf1, "%04d%02d%02d", &year1, &month1, &day1);
	sscanf(buf2, "%04d%02d%02d", &year2, &month2, &day2);

	// 年が同じ場合
	if(year1 == year2){
		// 閏年だった場合は2月の日数を29にする
		months[2] = is_LeapYear(year1) ? 29 : 28;
		// 月が同じ場合
		if(month1 == month2){
			// 日が同じ場合
			if(day1 == day2)
				sumday = 0;
			// 日が異なる場合
			else
				sumday = day2 - day1;
		}
		// 月が異なる場合
		else{
			// ひと月以上異なる場合
			if(month2-month1 > 1)
				for(i=month1+1; i<month2; i++) sumday += months[i];
			// ひと月のみ異なる場合
			sumday = months[month1] - day1 + day2;
		}
	}
	// 年が異なる場合
	else{
		// 一年以上異なる場合
		if(year2-year1 > 1)
			for(i=year1+1; i<year2; i++)
				sumday += is_LeapYear(i)? 366 : 365;
		// 一年のみ異なる場合
		months[2] = is_LeapYear(year1) ? 29 : 28;
		sumday += months[month1] - day1;
		for(i=month1+1; i<=12; i++) sumday += months[i];
		months[2] = is_LeapYear(year1) ? 29 : 28;
		for(i=1; i<month2; i++) sumday += months[i];
		sumday += day2;
	}

	printf("日数は%d日です\n", sumday);

	return(0);
}

/* 日付が遡る場合に日付1と2をそれぞれを入れ替える */
void replace_date(char *cdate1, char *cdate2){
	int idate1, idate2, i;
	char temp;
	// 文字列の日付を整数に変える
	sscanf(cdate1, "%d", &idate1);
	sscanf(cdate2, "%d", &idate2);
	// 日付2が日付1より若ければ入れ替える
	if(idate1>idate2){
		for(i=0; i<8; i++){
			temp = cdate1[i];
			cdate1[i] = cdate2[i];
			cdate2[i] = temp;
		}
	}
}

/* 与えられた西暦が閏年であれば真を，そうでなければ偽を返す */
int is_LeapYear(int year){
	// 4で割り切れる年は閏年
	if(year % 4 == 0){
		// 100で割り切れるが，400で割り切れない年は閏年ではない
		if((year % 100 == 0) && (year % 400 != 0))
			return(0);
		else
			return(1);
	}
	// それ以外は閏年ではない
	return(0);
}

/*---
出力結果
% ./test
特定の2つの日付の間の日数を計算します
2つの日付を8桁の数字で入力してください(入力例 19900511)
日付1 => 19901127
日付2 => 20150112
日数は8812日です
% ./test
特定の2つの日付の間の日数を計算します
2つの日付を8桁の数字で入力してください(入力例 19900511)
日付1 => 19900101
日付2 => 22000101
日数は76701日です
---*/
