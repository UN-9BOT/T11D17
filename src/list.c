#include "list.h"

int main(void) {
    Door *test = malloc (sizeof(List));
    test->id = 0;
    test->status = 0;
    List* pList = init(test);
    /* tNode = add_door( */
    /* add_door( */
}


List* init(Door* door) {
    List *tNode = malloc (sizeof(List));
    tNode->door = door;
    tNode->next = NULL;
    return (tNode);
}

List* add_door(List* elem, Door* door) {
    List* target = malloc (sizeof(List));
    target->door = door;
    target->next = elem -> next;
    elem->next = target;
    return (elem);
}

List* find_door(int door_id, List* root) {
    List* current = root;
    while (current->next != NULL) {
        if (current->door->id == door_id) {
            break;
        }
        current = current->next;
    }
    return (current);
}


List* remove_door(List* elem, List* root) {
    List* current = root;
    List* trash = NULL;
    List* previous = NULL;
    while (current != elem) {
        previous = current;
        current = current->next;
    }

    if (previous) {
        trash = previous->next;
        previous->next=current->next;
    } else {


    free(trash->door);
    free(trash);
    return (root);
}
            

/* void destroy(List* root) { */
/*     List* current = root->next; */
/*     while (current != NULL) { */
/*         free(current->door); */
/*         free(current); */
/*         current = current->next; */
/*     } */
/* } */
