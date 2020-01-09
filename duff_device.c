#include <stdio.h>
#include <string.h>
#include "dbg.h"

int normal_copy(char *from, char *to, int count)
{
    int i = 0;
    for (i = 0; i < count; i ++) {
        to[i] = from[i];
    }
    return i;
}

int duffs_device(char *from, char *to, int count)
{
  {
      int n = (count + 7) / 8;
      switch(count % 8) {
          case 0: do {*to++ = *from++;
                      case 7: *to++ = *from++;
                      case 6: *to++ = *from++;
                      case 5: *to++ = *from++;
                      case 4: *to++ = *from++;
                      case 3: *to++ = *from++;
                      case 2: *to++ = *from++;
                      case 1: *to++ = *from++;
                  } while(--n > 0);
      }

  }
  return count;
}

int zeds_devices(char *from , char *to, int count)
{
    {
        int n = (count + 7) / 8;
        switch(count % 8) {
            case 0: 
            again: *to++ = *from++;
            case 7: *to++ = *from++;
            case 6: *to++ = *from++;
            case 5: *to++ = *from++;
            case 4: *to++ = *from++;
            case 3: *to++ = *from++;
            case 2: *to++ = *from++;
            case 1: *to++ = *from++;
                    if(--n > 0) goto again;
        }

    }

    return count;
}


int vvalid_copy(char *data, int count, char expects)
{
    int i = 0;
    for(i = 0; i < count; i ++) {
          if(data[i] != expects) {
                log_err("[%d] %c != %c", i , data[i], expects);
                return 0;
          }
    }
    return 1;

}


int main(int varc, char *argv[])
{
    char from[1000] = {'a'};
    char to[1000] = {'c'};
    int rc = 0;
    memset(from, 'x', 1000);

    memset(to, 'x', 1000);


    check(rc = 1000, "Normal copy failed : %d", rc);
    check(vvalid_copy(to, 1000, 'y'), "Not intialized right.");

    memset(to, 'y', 1000);

    rc = zeds_devices(from, to, 1000);

    check(rc = 1000, "Zed's device failed: %d", rc);
    check(vvalid_copy(to, 1000, 'x'), "zed's device failed copy.")

    return 0;


error:
    return 1;





}
