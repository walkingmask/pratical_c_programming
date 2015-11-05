
/*---
 * - 14-1.c
 * 2015/2/13(FRI)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習14-1
 * ファイルを読み込み，その行数を数えるプログラム
---*/

#include <stdio.h>
#include <stdlib.h>

/* ファイル名 */
const char fname[] = "sample.txt";

int main(){
	char c;			// ファイルの文字を１つずつ格納する
	int count = 0;	// 改行文字の数
	FILE *in_fp;

	if((in_fp = fopen(fname, "r")) == NULL){
		fprintf(stderr, "Error: Unable to input file '%s'\n", fname);
		exit(8);
	}

	while((c = fgetc(in_fp)) != EOF)	// EOFが出るまでループ
		count += (c == '\n')? 1 : 0;	// 改行文字があればカウント

	fclose(in_fp);

	printf("ファイル '%s' の行数は %d です\n", fname, count+1);

	return(0);
}

/*---
出力結果
% ./14-1
ファイル 'sample.txt' の行数は 5 です
---*/
