
/*---
 * - 14-2.c
 * 2015/2/13(FRI)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習14-2
 * ファイルをコピーするプログラム(タブは4つのスペースに展開する)
 * 初歩的なファイル入出力関数を用いた版 省バッファ mac用
---*/

#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 512

void copy_file(char *fname1, char *fname2, char *buf);

int main(){
	char in_fname[]  = "sample.txt";		// コピー元のファイル名
	char out_fname[] = "out_sample.txt";	// コピー先のファイル名
	char buf[BUF_SIZE];						// ファイルのコピーの一時保存場所

	copy_file(in_fname, out_fname, buf);

	return(0);
}

void copy_file(char *fname1, char *fname2, char *buf){
	FILE *in_fp, *out_fp;
	int i=0;

	if((in_fp = fopen(fname1, "r")) == NULL){
		fprintf(stderr, "Error: Unable to input file '%s'\n", fname1);
		exit(8);
	}
	if((out_fp = fopen(fname2, "w")) == NULL){
		fprintf(stderr, "Error: Unable to input file '%s'\n", fname2);
		exit(8);
	}

	while(fgets(buf, sizeof(buf), in_fp) != NULL){
		for(i=0; buf[i] != '\n'; i++){
			if(buf[i] == '\t')
				fprintf(out_fp, "    ");
			else
				fputc(buf[i], out_fp);
		}
	}

	fclose(in_fp);
	fclose(out_fp);
}