
/*---
 * - 11-2.c
 * 2015/2/10(TUE)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習11-2
 * 10*10の正方形ビットマップ上を描く
---*/

#include <stdio.h>

#define X_SIZE 16
#define Y_SIZE 16

char graphics[X_SIZE/8][Y_SIZE];

/* マクロ */
#define SET_BIT(x, y) graphics[(x)/8][y] |= (0x80 >> ((x)%8))

/* 関数 */
void print_graphics(void);

int main(void){
	int loc;
	int i;

	for(i=2; i<12; ++i){
		for(loc=2; loc<12; ++loc){
			SET_BIT(i, loc);
		}
	}
	print_graphics();
	return(0);
}

void print_graphics(void){
	int x, y;
	unsigned int bit;
	for(y=0; y<Y_SIZE; ++y){
		for(x=0; x<X_SIZE/8; ++x){
			for(bit=0x80; bit>0; bit=(bit>>1)){
				if((graphics[x][y] & bit) != 0)
					printf("園");
				else
					printf("・");
			}
		}
		printf("\n");
	}
}

/*---
出力結果
% ./11-2
・・・・・・・・・・・・・・・・
・・・・・・・・・・・・・・・・
・・園園園園園園園園園園・・・・
・・園園園園園園園園園園・・・・
・・園園園園園園園園園園・・・・
・・園園園園園園園園園園・・・・
・・園園園園園園園園園園・・・・
・・園園園園園園園園園園・・・・
・・園園園園園園園園園園・・・・
・・園園園園園園園園園園・・・・
・・園園園園園園園園園園・・・・
・・園園園園園園園園園園・・・・
・・・・・・・・・・・・・・・・
・・・・・・・・・・・・・・・・
・・・・・・・・・・・・・・・・
・・・・・・・・・・・・・・・・
---*/
