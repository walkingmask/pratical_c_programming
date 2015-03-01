
/*---
 * - 8-7.c
 * 2015/1/20(TUE)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング p121 8.5 実習8-7
 * 0から100までの数値を，例えば85ならば"eighty-five"のように文字列にして出力するプログラム
---*/

#include <stdio.h>

void print_ones(char num);

int main(){
	char input_num[4];	// 入力された数値を文字列として受け取る
	int number;			// 入力された数値

	printf("入力された数値を文字列に変換して返します\n");
	printf("0~100までの範囲で数値を入力してください\n");
	printf("入力 => ");

	fgets(input_num, sizeof(input_num), stdin);
	sscanf(input_num, "%d", &number);

	printf("出力 => ");

	
	if(number < 0 || number > 100){			// 範囲外の数値に対してはエラーを返す
		printf("error! 不正な値です\n");
	}
	else if(number == 0){					// 0の場合 
		printf("zero\n");
	}
	else if(number == 100){					// 100の場合
		printf("one hundred\n");
	}
	else if(20 <= number && number <= 99){	// 20~99の場合
		switch(input_num[0]){
			case '2':
				printf("twenty");
				break;
			case '3':
				printf("thirty");
				break;
			case '4':
				printf("fourty");
				break;
			case '5':
				printf("fifty");
				break;
			case '6':
				printf("sixty");
				break;
			case '7':
				printf("seventy");
				break;
			case '8':
				printf("eighty");
				break;
			case '9':
				printf("ninety");
				break;
		}

		if(input_num[1] != '0'){			// 下一桁が0以外の場合は
			printf("-");					// ハイフンを出力
			print_ones(input_num[1]);		// その後に続く数字を出力
		}
		else printf("\n");					// 0で終わるなら改行

	}
	else if(10 <= number && number <= 19){	// 10~19の場合
		switch(number){
			case 10:
				printf("ten\n");
				break;
			case 11:
				printf("eleven\n");
				break;
			case 12:
				printf("twelve\n");
				break;
			case 13:
				printf("thirteen\n");
				break;
			case 14:
				printf("fourteen\n");
				break;
			case 15:
				printf("fifteen\n");
				break;
			case 16:
				printf("sixteen\n");
				break;
			case 17:
				printf("seventeen\n");
				break;
			case 18:
				printf("eighteen\n");
				break;
			case 19:
				printf("nineteen\n");
				break;
		}
	}
	else
		print_ones(input_num[0]);			// 10未満の場合

	return(0);
}

/* 受け取った文字(数字)によって文字列を出力する関数 */
void print_ones(char num){
	switch(num){
		case '1':
			printf("one\n");
		case '2':
			printf("two\n");
			break;
		case '3':
			printf("three\n");
			break;
		case '4':
			printf("four\n");
			break;
		case '5':
			printf("five\n");
			break;
		case '6':
			printf("six\n");
			break;
		case '7':
			printf("seven\n");
			break;
		case '8':
			printf("eight\n");
			break;
		case '9':
			printf("nine\n");
			break;
	}
}

/*---
出力結果
% ./8-7
入力された数値を文字列に変換して返します
0~100までの範囲で数値を入力してください
入力 => 123
出力 => error! 不正な値です
% ./8-7
入力された数値を文字列に変換して返します
0~100までの範囲で数値を入力してください
入力 => 100
出力 => one hundred
% ./8-7
入力された数値を文字列に変換して返します
0~100までの範囲で数値を入力してください
入力 => 0
出力 => zero
% ./8-7
入力された数値を文字列に変換して返します
0~100までの範囲で数値を入力してください
入力 => 20
出力 => twenty
% ./8-7
入力された数値を文字列に変換して返します
0~100までの範囲で数値を入力してください
入力 => 98
出力 => ninety-eight
% ./8-7
入力された数値を文字列に変換して返します
0~100までの範囲で数値を入力してください
入力 => 13
出力 => thirteen
% ./8-7
入力された数値を文字列に変換して返します
0~100までの範囲で数値を入力してください
入力 => 5
出力 => five
---*/
