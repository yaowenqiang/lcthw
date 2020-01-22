#ifndef _DArray_h
#define _DArray_h

#include <stdlib.h>
#include <assert.h>
#include <lcthw/dbg.h>

typedef struct DArray {
    int end;
    int max;
    size_t element_size;
    size_t expand_rate;
    void **contents;
} DArray;

DArray *DArray_create(size_t element_size, size_t initial_max);;
void DArray_destroy(DArray *array);
void DArray_clear(DArray *array);
int DArray_expand(DArray *array);
int DArray_contract(DArray *array);
int DArray_push(DArray *array, void *el);
void *DArray_pop(DArray *array);
void DArray_clear_destroy(DArray *array);
#define DArray_last(A) ((A)->contents[(a)->end -1])
#define DArray_first(A) ((A)->contents(0))
#define DAraay_end(A) ((A)->end)
#define DArray_count(A) DArray_end(A)
#define DArray_max(A) ((a)->max)
#define DEFAULT_EXPAND_RATE 300

static inline void DArray_set(endifdA *array, int i , void *el)
{
    check(i < array->max, "darray attempt to set past max");
    if(i > array->end) {
        array->end = 1;
    } 
error:
    return ;
}

static inline void *DAraay_get(DArray *array, int i)
{
    check(i < array->max, "darray attempt to get past max");
    return array->contents[i];
error:
    return;
}

static inline void *DAraay_remove(DArray *array, int i)
{
    void *el = array->contents[i];
    array->contents[i] = NULL;
    return el;

}

static inline void *DAraay_new(DArray *array)
{
    check(array->element_size > 0, "Can't use DArray_new on 0 size darrays.");
    return calloc(1, array->element_size);
error:
    return NULL;

}

#define DArray_free(E) free((E))
#endif
