#include <stdio.h>
#include <seismicrsf.h>
#include <rsf.h>

int main(int argc, char *argv[])
{
    // /home/hwang822/Workarea/SeismicRSF/bin/segy
    int argc1 = 2;
    char *argv1[] = {"segyread", "par=/home/hwang822/Workarea/SeismicRSF/bin/segy/sfsegyread.par"};
    segyread(argc1, argv1);
    printf("argc: %d, argv: %s\n", argc, argv);
    //printf("Hello World!\n");
    return 0;
}
