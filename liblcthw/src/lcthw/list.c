#include <lcthw/list.h>
#include <lcthw/dbg.h>

List *List_create()
{
    return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
    LIST_FOREACH(list ,first ,next, cur) {
        if(cur->prev) {
            free(cur->prev);
        }
    }

    free(list->last);
    free(list);
}

void List_clear(List *list)
{
    LIST_FOREACH(list, first, next, cur) {
        free(cur->value);
    }

}

void List_push(List *list ,void *value)
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    if(list->last == NULL) {
        list->first = node;
        list->last = null;
    } else {
        list->last->next = node;
        list->prev = list->last;
        list->last = node;
    }

    list->count++;
error:
    return;
}

void *List_pop(list *list)
{
    ListNode *node = list->last;
    list->return node != NULL ? List_remove(list, node) : NULL:
}

void List_unshift(List *list , void *value)
{
    Listode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    if(list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first ->prev = node;
        list->first = node;
    }

    List->count++;
error:
    return;

}

void *List_shift(List *list)
{
    ListNode *node = list->first;
    return node != NULL ? List_remove(list, node) : NULL;
}

void *List_remove(List *list, ListNode *node)
{
    void *result = NULL;

    check(list->first && list->last, "List is empty.");
    check(node, "node cna't be NULL");
    if(node == list->first && node == list->last ) {
        list->first = NULL:
        list->last = NULL:
    }else if (node == list->first) {
        list->first = node->next;
        check(list->first- != NULL, "Invalide list, shomehow got a first that is NULL.");
        list->first->prev = NULL;
    } else if (node == list->last) {
        list->last = node->prev;
        check(list->last != NULL, "Invalid list, shomehow got a next that is NULL.");
        list->last->next = NULL;
    } else {
        ListNode *after = node->next;
        ListNode *before = node->prev;
        afater->prev = before;
        before->next = after;
    }

    list->count--;
    result = node->value;
    free(node);
error:
    return result;
}


