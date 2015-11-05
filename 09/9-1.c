
/*---
 * - 9-1.c
 * 2015/1/20(TUE)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習9-1
 * 文字列中の語数を数える関数とテストプログラム
 * ここで言う語数とはスペースで区切られた単語の数のこと(日本語非対応)
---*/

#include <stdio.h>

int how_many_words(char *str, int leng_str);

int main(){
	char str[128];
	int sum_words=0;
	
	printf("文字列中の語数を数えます．適当な文を入力してください\n");

	fgets(str, sizeof(str), stdin);

	sum_words = how_many_words(str, sizeof(str));

	printf("文中に含まれる語数は %d 個です\n", sum_words);

	return(0);
}

/*---
 * 与えられた文字列に含まれる語数を数える関数
 * 引数 str 文字列  leng_str 文字列の要素数
 ---*/
int how_many_words(char *str, int leng_str){
	int sum_words=0, i;

	for(i=0; i<leng_str; i++)
		sum_words += (str[i]==' ')? 1 : 0 ;	// スペースがあるたびに+1

	return(sum_words+1);					// 最後の語を数える為に+1した値を返す
}

/*---
出力結果
% ./9-1
文字列中の語数を数えます．適当な文を入力してください
Cat
文中に含まれる語数は 1 個です
% ./9-1
文字列中の語数を数えます．適当な文を入力してください
She is my cat.
文中に含まれる語数は 4 個です
% ./9-1
文字列中の語数を数えます．適当な文を入力してください
She is very very cute my cat.
文中に含まれる語数は 7 個です
---*/
