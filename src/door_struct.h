#ifndef STRU
#define STRU
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct door {
    int id;
    int status;
};
void initialize_doors(struct door* doors);
void sort(struct door* doors);
void closeDoor(struct door* doors);
void prResult(struct door* doors);
#endif
