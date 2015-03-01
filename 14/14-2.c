
/*---
 * - 14-2.c
 * 2015/2/13(FRI)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習14-2
 * ファイルをコピーするプログラム(タブは4つのスペースに展開する)
 * 初歩的なファイル入出力関数を用いた版 全バッファ mac用
---*/

#include <stdio.h>
#include <stdlib.h>

int get_filesize(char *fname);
void reader(char *fname, char *buf);
void writer(char *fname, char *buf);


int main(){
	char in_fname[]  = "sample.txt";		// コピー元のファイル名
	char out_fname[] = "out_sample.txt";	// コピー先のファイル名

	int in_fsize = get_filesize(in_fname); 		// コピー元のファイルのサイズ
	char buf[in_fsize];							// ファイルのコピーの一時保存場所
	reader(in_fname, buf);						// コピー元のファイルをbufにコピー
	writer(out_fname, buf);						// コピー先のファイルにbufをコピー

	return(0);
}

int get_filesize(char *fname){
	FILE *fp;
	int fsize;

	if((fp = fopen(fname, "rb")) == NULL){
		fprintf(stderr, "Error: Unable to input file '%s'\n", fname);
		exit(8);
	}
	/* ファイルサイズを取得 */
	fseek(fp, 0L, SEEK_END); 	// fpの位置をファイルの最後へ移動する
	fsize = ftell(fp);			// fpの現在の位置の値を取得

	fclose(fp);

	return(fsize);
}

void reader(char *fname, char *buf){
	FILE *fp;
	int i=0;

	if((fp = fopen(fname, "r")) == NULL){
		fprintf(stderr, "Error: Unable to input file '%s'\n", fname);
		exit(8);
	}

	while((buf[i] = fgetc(fp)) != EOF) i++;

	fclose(fp);
}

void writer(char *fname, char *buf){
	FILE *fp;
	int i;

	if((fp = fopen(fname, "w")) == NULL){
		fprintf(stderr, "Error: Unable to input file '%s'\n", fname);
		exit(8);
	}

	for(i=0; buf[i] != EOF; i++){
		if(buf[i] == '\t')			// タブ文字が出てきたらス半角ペース４つに置き換える
			fprintf(fp, "    ");
		else
			putc(buf[i], fp);
	}

	fclose(fp);
}
