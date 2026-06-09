#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include "LunarSolarConverter.h"

int count_index(int value);
char *predicate(struct tm time);

int main() {
    time_t result = time(NULL);
    /*    if(result != (time_t)(-1))
      printf("当前时间为 %s(纪元后第 %jd 秒)\n", asctime(gmtime(&result)),
             (intmax_t)result);
    */
    struct tm tm = *localtime(&result);
    /*
    printf("month is %d\n", tm.tm_mon + 1);
    printf("day is %d\n", tm.tm_mday);
    printf("hour is %d\n", tm.tm_hour);
    */

    /*
    Solar solar;
    solar.solarYear = tm.tm_year + 1900;
    solar.solarMonth = (int)tm.tm_mon + 1;
    solar.solarDay = tm.tm_mday;

    Lunar lunar = SolarToLunar(solar);

    printf("农历为 %d-%d-%d\n",lunar.lunarYear,lunar.lunarMonth,lunar.lunarDay);

    //0-大安 ...
    char* table[6] = {"大安", "留连", "速喜", "赤口", "小吉", "空亡"};

    int index_0 = 0;//从大安开始

    int index_1 = count_index(index_0 + lunar.lunarMonth);
    printf("index_1 is %d\n", index_1);

    int index_2 = count_index(index_1 + lunar.lunarDay);
    printf("index_2 is %d\n", index_2);

    //1-子 2-丑
    int shi_chen = (tm.tm_hour + 1) / 2 % 12 + 1;//算出第几个时辰
    printf("shi_chen is %d\n", shi_chen);

    int index_3 = count_index(index_2 + shi_chen);
    printf("index_3 is %d\n", index_3);

    printf("%s", table[index_3]);
    */
    printf("%s",predicate(tm));

}

int count_index(int value) {
    return (value - 1) % 6;//年月时均是从1开始的，但是要映射到数组上，所以减1；用6取余是6个吉凶为一轮
}

char *predicate(struct tm time) {
    Solar solar;
    solar.solarYear = time.tm_year + 1900;
    solar.solarMonth = (int)time.tm_mon + 1;
    solar.solarDay = time.tm_mday;

    Lunar lunar = SolarToLunar(solar);

    //0-大安 ...
    char* table[6] = {"大安", "留连", "速喜", "赤口", "小吉", "空亡"};

    int index_0 = 0;//从大安开始

    int index_1 = count_index(index_0 + lunar.lunarMonth);


    int index_2 = count_index(index_1 + lunar.lunarDay);

    //1-子 2-丑
    int shi_chen = (time.tm_hour + 1) / 2 % 12 + 1;//算出第几个时辰

    int index_3 = count_index(index_2 + shi_chen);

    return table[index_3];
}
