
/*---
 * - 13-2.c
 * 2015//()
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習13-2
 * 文字列１つを引数にとり，その文字列中のスペース文字でない最初の文字へのポインタを返す関数とテストプログラム
---*/

#include <stdio.h>

char *isNoSpace(char *str);

int main(){
	char str[32] = "          oppai";
	printf("The character's address which first comes out in string is '%p'\n", isNoSpace(str));
	printf("and, that is '%c'\n", *(isNoSpace(str)));
	return(0);
}

char *isNoSpace(char *str){
	while(*str == ' '){
		str++;
	}
	return(str);
}

/*---
出力結果
% ./13-2            
The character's address which first comes out in string is '0x7fff5da87b2a'
and, that is 'o'
---*/
