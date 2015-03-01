
/*---
 * - 11-1.c
 * 2015/1/22(THU)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習11-1
 * ビットをset，test，clearするマクロとそれをテストするプログラム
---*/

#include <stdio.h>

#define X_SIZE 16
#define Y_SIZE 16

char graphics[X_SIZE/8][Y_SIZE];

/* マクロ */
#define SET_BIT(x, y) graphics[(x)/8][y] |= (0x80 >> ((x)%8))
#define TEST_BIT(x, y) graphics[(x)/8][y] & (0x80 >> ((x)%8))
#define CLEAR_BIT(x, y) graphics[(x)/8][y] &= ~(0x80 >> ((x)%8))

/* 関数 */
void inputxy(int *x, int *y);
void print_graphics(void);

int main(void){
	int loc_x;
	int loc_y;
	int s;

	printf("set:0, test:1, clear:2, print:3, exit:else\n");
	
	while(true){
		printf("-> ");
		scanf("%d", &s);
		switch(s){
			case 0:
				inputxy(&loc_x, &loc_y);
				SET_BIT(loc_x, loc_y);
				break;
			case 1:
				inputxy(&loc_x, &loc_y);
				if(TEST_BIT(loc_x, loc_y)) printf("loc(%d, %d)\n", loc_x, loc_y);
				else printf("no loc(%d, %d)\n", loc_x, loc_y);
				break;
			case 2:
				inputxy(&loc_x, &loc_y);
				CLEAR_BIT(loc_x, loc_y);
				break;
			case 3:
				print_graphics();
				break;
			default:
				printf(" good bye!\n");
				return(0);
		}
	}

	return(0);
}

void inputxy(int *x, int *y){
	printf("input x -> ");scanf("%d", x);
	printf("input y -> ");scanf("%d", y);
}

void print_graphics(void){
	int x, y;
	unsigned int bit;
	for(y=0; y<Y_SIZE; ++y){
		for(x=0; x<X_SIZE/8; ++x){
			for(bit=0x80; bit>0; bit=(bit>>1)){
				if((graphics[x][y] & bit) != 0)
					printf("あ");
				else
					printf("い");
			}
		}
		printf("\n");
	}
}

/*---
出力結果
% /.11-1
-> 0
input x -> 1
input y -> 1
-> 0
input x -> 0
input y -> 0
-> 0
input x -> 2
input y -> 2
-> 0
input x -> 3
input y -> 3
-> 0
input x -> 4
input y -> 4
-> 0
input x -> 5
input y -> 5
-> 3
あいいいいいいいいいいいいいいい
いあいいいいいいいいいいいいいい
いいあいいいいいいいいいいいいい
いいいあいいいいいいいいいいいい
いいいいあいいいいいいいいいいい
いいいいいあいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
-> 1
input x -> 1
input y -> 1
loc(1, 1)
-> 1
input x -> 2
input y -> 1
no loc(2, 1)
-> 2
input x -> 1
input y -> 1
-> 3
あいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいあいいいいいいいいいいいいい
いいいあいいいいいいいいいいいい
いいいいあいいいいいいいいいいい
いいいいいあいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
いいいいいいいいいいいいいいいい
-> 9
 good bye!
---*/
