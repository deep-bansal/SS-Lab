#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int main(int argc, char const *argv[])
{
    fd_set rf;

    FD_ZERO(&rf);
    FD_SET(0,&rf);


    struct timeval timep;
    timep.tv_sec = 10;
    timep.tv_usec = 0;


    int rval = select(1, &rf, NULL,NULL, &timep);

    if (rval == -1)
        printf("error");
    else if (rval)
        printf("Data is present.\n");
        /* FD_ISSET(0, &rfds) will be true. */
    else
        printf("No data.\n");

    return 0;
}
