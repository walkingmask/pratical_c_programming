
/*---
 * - .c
 * 2015/1/22(THU)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習
 * memcpyを完全に再現するのは難しそうだなあと思いchar型のみで実装
 * memcpyはint型でもcpy可のよう
 * 8バイト程度のコピーではそんなに差は出なかった
---*/

#include <stdio.h>
#include <string.h>
#include <time.h>

char *memory_copy(char *buf1, char *buf2, int n);

int main(){
	int i;
	char str1[16] = "oppai daisuki";
	char str2[16] = "ochinpo kirai";
	int  arr1[8] = {1,2,3,4,5,6,7,8};
	int  arr2[8] = {8,7,6,5,4,3,2,1};
	clock_t start, end;

	// 自作関数
	start = clock();
	memory_copy(str1, str2 ,8);
	end = clock();
	printf("str1 \"%s\"\n", str1);
	printf("teme: %lu µs\n", end-start);

	// memcpy
	start = clock();
	memcpy(str1, str2, 8);
	end = clock();
	printf("str1 \"%s\"\n", str1);
	printf("teme: %lu µs\n", end-start);

	// memcpyにint型の配列を渡す
	memcpy(arr1, arr2, 4);
	for(i=0; i<8; i++) printf("%d ", arr1[i]);
	printf("\n");

	return(0);
}

char *memory_copy(char *buf1, char *buf2, int n){
	for(int i=0; i<n; i++) buf1[i]  = buf2[i];
	return(buf1);
}

/*---
出力結果
% ./15-5.c
str1 "ochinpo isuki"
teme: 2 µs
str1 "ochinpo isuki"
teme: 0 µs
8 2 3 4 5 6 7 8
---*/
