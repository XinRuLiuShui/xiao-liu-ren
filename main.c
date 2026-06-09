#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include "xiao_liu_ren.h"


int main() {
    time_t result = time(NULL);
    struct tm tm = *localtime(&result);
    printf("%s\n",predicate(tm));
}
