#include "xiao_liu_ren.h"

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
