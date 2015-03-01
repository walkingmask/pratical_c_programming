/*---
 * - 4-4.c
 * 2014/12/23(THU)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング p52 4.13 実習4-4
 * 大きな(縦幅7，横幅5)HELLOを出力する
---*/

#include <stdio.h>

int main(){
	printf(
		"H   H  EEEEE  L      L      OOOOO\n"
		"H   H  E      L      L      O   O\n"
		"H   H  E      L      L      O   O\n"
		"HHHHH  EEEEE  L      L      O   O\n"
		"H   H  E      L      L      O   O\n"
		"H   H  E      L      L      O   O\n"
		"H   H  EEEEE  LLLLL  LLLLL  OOOOO\n"
	);
	return(0);
}

/*---
出力結果
% ./4-4
H   H  EEEEE  L      L      OOOOO
H   H  E      L      L      O   O
H   H  E      L      L      O   O
HHHHH  EEEEE  L      L      O   O
H   H  E      L      L      O   O
H   H  E      L      L      O   O
H   H  EEEEE  LLLLL  LLLLL  OOOOO
---*/
