
/*---
 * - 12-1.c
 * 2015/02/10(TUE)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習12-1
 * 郵便用宛先リストのデータを格納するための構造体と出力用関数
---*/

#include <stdio.h>

struct mailing{
	char name[60];		// 姓名
	char address1[60];	// 地番
	char address2[60];	// 住居
	char city[40];		// 市
	char state[10];		// 県
	int  zip;			// 郵便番号
};

void print_mailing(struct mailing *temp);

int main(){
	struct mailing okinawa[5] = {
		{"YAMADA TARO"  , "NODAKA"  , "1-1-1", "GINOWAN", "OKINAWA", 9012203},
		{"GINOWAN JIRO" , "UEHARA"  , "1-1-1", "GINOWAN", "OKINAWA", 9012204},
		{"ISHIMINE YOKO", "ISHIMINE", "1-1-1", "NAHA"   , "OKINAWA", 9030804},
		{"NAHA MOMOKO"  , "KUMOJI"  , "1-1-1", "NAHA"   , "OKINAWA", 9000001},
		{"ITOMAN ITOKO" , "SHIOZAKI", "1-1-1", "ITOMAN" , "OKINAWA", 9010364},
	};

	print_mailing(okinawa);

	return(0);
}

void print_mailing(struct mailing *temp){
	for(int i=0; i<5; i++){
		printf("mailing %d\n", i);
		printf("name    :%s\n", temp->name);
		printf("address1:%s\n", temp->address1);
		printf("address2:%s\n", temp->address2);
		printf("city    :%s\n", temp->city);
		printf("state   :%s\n", temp->state);
		printf("zip     :%d\n", temp->zip);
		printf("\n");
		temp++;
	}
}

/*---
出力結果
% ./12-1
mailing 0
name    :YAMADA TARO
address1:NODAKA
address2:1-1-1
city    :GINOWAN
state   :OKINAWA
zip     :9012203

mailing 1
name    :GINOWAN JIRO
address1:UEHARA
address2:1-1-1
city    :GINOWAN
state   :OKINAWA
zip     :9012204

mailing 2
name    :ISHIMINE YOKO
address1:ISHIMINE
address2:1-1-1
city    :NAHA
state   :OKINAWA
zip     :9030804

mailing 3
name    :NAHA MOMOKO
address1:KUMOJI
address2:1-1-1
city    :NAHA
state   :OKINAWA
zip     :9000001

mailing 4
name    :ITOMAN ITOKO
address1:SHIOZAKI
address2:1-1-1
city    :ITOMAN
state   :OKINAWA
zip     :9010364
---*/
