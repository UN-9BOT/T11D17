#include "list.h"

List* init(Door* door) {
    List* head = malloc(sizeof(List));
    head->door = door;
    head->next = NULL;
    return (head);
}

List* add_door(List* elem, Door* door) {
    List* target = malloc(sizeof(List));
    target->door = door;
    target->next = elem->next;
    elem->next = target;
    return (elem->next);  // указатель на вставленный элемент
}

List* find_door(int door_id, List* root) {
    List* current = root;
    while (current->next != NULL) {
        if (current->door->id == door_id) {
            break;
        }
        current = current->next;
    }
    return (current);  // if not find return NULL
}

List* remove_door(List* elem, List* root) {
    List* current = root;
    List* previous = NULL;
    while (current != elem) {
        previous = current;
        current = current->next;
    }

    if (previous) {
        previous->next = current->next;
    } else {
        root = current->next;
    }
    if (current != NULL) {
        free(elem->door);
        free(elem);
    }
    return (root);
}

void destroy(List* root) {
    List* current = root;
    while (current != NULL) {
        free(current->door);
        free(current);
        current = current->next;
    }
}
