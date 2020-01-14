#undef NODEBUG
#include "dbg.h"
#include <stdio.h>
#include <assert.h>

void copy(char to[], char from[])
{
    int i = 0;
     while((to[i] = from[i]) != '\n') {
        ++i;
     }
}

int safecopy(int from_len, char *from, int to_len , char *to)
{
    assert(from != NULL && to != NULL && "from and to can't be NULL");

    int i = 0;
    int max = from_len > to_len - 1? to_len -1:from_len;

    if(from_len <= 0 || to_len <=0) return -1;

    for(i = 0; i < max; i ++) {
        to[i] = from[i];
    }

    to[to_len - 1] = '\0';
    return i;
}


int main(int argc, char *argv[])
{
    char from[] = "0123456789";
    int from_len = sizeof(from);

    char to[] = "0123456";
    int to_len = sizeof(to);

    debug("Copying '%s':%d to '%s':%d", from, from_len, to, to_len);

    int rc = safecopy(from_len, from, to_len, to);
    check(rc > 0, "Failed to safecopy.");
    check(to[to_len - 1] == '\0', "String not terminateed.");

    debug("Result is: '%s':%d", to, to_len);

    rc = safecopy(from_len*-1, from, to_len, to);
    check(rc == -1, "safecopy should fail #1.");
    check(to[to_len - 1] == '\0', "String not terminateed.");

    rc = safecopy(from_len, from, 0, to);
    check(rc > 0, "safecopy should faile #2.");
    check(to[to_len - 1] == '\0', "String not terminateed.");
    return 0;
error:
    return -1;



}
