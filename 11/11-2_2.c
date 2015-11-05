
/*---
 * - 11-2_2.c
 * 2015/2/10(TUE)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習11-2
 * 10*10のビットマップを描く
---*/

#include <stdio.h>

#define X_SIZE 10
#define Y_SIZE 10

char graphics[(X_SIZE/8)+1][Y_SIZE];

/* マクロ */
#define SET_BIT(x, y) graphics[(x)/8][y] |= (0x80 >> ((x)%8))

/* 関数 */
void print_graphics(void);

int main(void){
	int loc;

	for(loc=0; loc < X_SIZE; ++loc)
		SET_BIT(loc, loc);

	print_graphics();
	return(0);
}

void print_graphics(void){
	int x, y;
	unsigned char bit;
	for(y=0; y<Y_SIZE; ++y){
		for(x=0; x<(X_SIZE/8)+1; ++x){
			if(x==X_SIZE/8){
				for(bit=0x80; bit>32; bit=(bit>>1)){
					if((graphics[x][y] & bit) != 0)
						printf("園");
					else
						printf("・");
				}
			}
			else{
				for(bit=0x80; bit>0; bit=(bit>>1)){
					if((graphics[x][y] & bit) != 0)
						printf("園");
					else
						printf("・");
				}
			}
		}
		printf("\n");
	}
}

/*---
出力結果
% ./11-2_2
園・・・・・・・・・
・園・・・・・・・・
・・園・・・・・・・
・・・園・・・・・・
・・・・園・・・・・
・・・・・園・・・・
・・・・・・園・・・
・・・・・・・園・・
・・・・・・・・園・
・・・・・・・・・園
---*/
