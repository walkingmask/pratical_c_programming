
/*---
 * - 12-2.c
 * 2015/02/10(TUE)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習12-2
 * 時刻と日付を格納する構造体と，２つの時刻の違いを分単位で表す関数
---*/

#include <stdio.h>
#include <stdlib.h>

struct time{
	int year;
	int month;
	int day;
	char week[4];
	int hour;
	int minute;
	int second;
};

int def_time(int hour1, int hour2, int minute1, int minute2);

int main(){
	time logs[3] = {
		{2015, 1, 1, "THU", 13, 45, 31},
		{2015, 1, 2, "FRI", 14, 21, 2},
		{2015, 1, 3, "SAT", 11, 58, 9},
	};

	printf("-logs-\n");
	for(int i=0; i<3; i++)
		printf("%02d:%04d/%02d/%02d/(%3s) %02d:%02d:%02d\n", i+1, logs[i].year, logs[i].month, logs[i].day, logs[i].week,
			logs[i].hour, logs[i].minute, logs[i].second);

	printf("-function-\n");
	printf("log01.time - log02.time = %d minutes\n", def_time(logs[0].hour, logs[1].hour, logs[0].minute, logs[1].minute));
	return(0);
}

int def_time(int hour1, int hour2, int minute1, int minute2){
	int times;
	times = (abs(hour1) - abs(hour2))*60;
	times += abs(minute1) - abs(minute2);
	return(abs(times));
}

/*---
出力結果
-logs-
01:2015/01/01/(THU) 13:45:31
02:2015/01/02/(FRI) 14:21:02
03:2015/01/03/(SAT) 11:58:09
-function-
log01.time - log02.time = 36 minutes
---*/
