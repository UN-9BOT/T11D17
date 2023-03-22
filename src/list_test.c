#include "list.h"

#include <stdio.h>

void initTest();
void addTest();
void findDoorTest();
void removeDoorTest();

int main(void) {
    initTest();
    addTest();
    findDoorTest();
    removeDoorTest();
}

void initTest() {
    Door *test = malloc(sizeof(List));
    test->id = 0;
    test->status = 3;
    List *header = init(test);
    int resId = header->door->id;
    int resStatus = header->door->status;
    printf("-> 1 Test. \n\t->Init. id = %i, status = %i\n", resId, resStatus);
    if (resId == test->id && resStatus == test->status) {
        printf("\t\tSUCCESS\n----\n");
    } else {
        printf("\t\tFAIL\n----\n");
    }
    destroy(header);
}

void addTest() {
    Door *test = malloc(sizeof(List));  // 1st el
    test->id = 0;
    test->status = 3;
    Door *test2 = malloc(sizeof(List));  // 2st el
    test2->id = 1;
    test2->status = 2;
    List *header = init(test);  // init 1st el header
    List *last_elem = add_door(header, test2);

    int resId2 = last_elem->door->id;
    int resStatus2 = last_elem->door->status;
    printf("-> 2 Test.\n\t->Add. id = %i, status = %i\n", resId2, resStatus2);
    if (resId2 == test2->id && resStatus2 == test2->status) {
        printf("\t\tSUCCESS\n----\n");
    } else {
        printf("\t\tFAIL\n----\n");
    }
    destroy(header);
}

void findDoorTest() {
    Door *doors[5];
    List *lists[5];
    List *result[5];
    int flag = 0;
    for (int i = 0; i < 5; i++) {  // malloc for doors
        doors[i] = malloc(sizeof(List));
        doors[i]->id = i;
        doors[i]->status = i;
    }
    lists[0] = init(doors[0]);     // init el header
    for (int i = 1; i < 5; i++) {  // add all doors without header
        lists[i] = add_door(lists[i - 1], doors[i]);
    }
    for (int i = 0; i < 5; i++) {  // all find result
        result[i] = find_door(i, lists[0]);
    }
    for (int i = 0; i < 5; i++) {  // check results
        if (result[i] != lists[i]) {
            flag = 1;
        }
    }
    printf("-> 3 Test.\n\t->Find.\n");
    if (flag == 0) {
        printf("\t\tSUCCESS\n----\n");
    } else {
        printf("\t\tFAIL\n----\n");
    }

    destroy(lists[0]);
}

void removeDoorTest() {
    Door *doors[5];
    List *lists[5];
    int flag = 0;
    for (int i = 0; i < 5; i++) {  // malloc for doors
        doors[i] = malloc(sizeof(List));
        doors[i]->id = i;
        doors[i]->status = i;
    }
    lists[0] = init(doors[0]);     // init el header
    for (int i = 1; i < 5; i++) {  // add all doors without header
        lists[i] = add_door(lists[i - 1], doors[i]);
    }
    for (int i = 2; i < 4; i++) {
        remove_door(lists[i], lists[0]);
    }
    if (lists[1]->next != lists[4]) {
        flag = 1;
    }
    printf("-> 4 Test.\n\t->Remove.\n");
    if (flag == 0) {
        printf("\t\tSUCCESS\n----\n");
    } else {
        printf("\t\tFAIL\n----\n");
    }

    destroy(lists[0]);
}
