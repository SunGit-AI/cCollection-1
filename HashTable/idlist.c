#include <stdlib.h>
#include <assert.h>
#include "idlist.h"

/* overhead parameter that determines both space and search costs */
/* must be strictly greater than 1 */
#define OVERHEAD (1.1)
#define NULL_ID (-1)


struct id_list {
    int size;
    int ids[1];         /* we'll actually malloc more space than this */
};

IDList IDListCreate(int n, int unsorted_id_list[])
{
    IDList list;
    int size;
    int i;
    int probe;

    size = (int) (n * OVERHEAD + 1);
    list = malloc(sizeof(*list) + sizeof(int) * (size-1));
    if(list == 0) return 0;
    /* else */
    list->size = size;

    /* clear the hash table */
    for(i = 0; i < size; i++) {
        list->ids[i] = NULL_ID;
    }

    /* load it up */
    for(i = 0; i < n; i++) {

        assert(unsorted_id_list[i] >= MIN_ID);
        assert(unsorted_id_list[i] <= MAX_ID);

        /* hashing with open addressing by division */
        /* this MUST be the same pattern as in IDListContains */
        for(probe = unsorted_id_list[i] % list->size;
            list->ids[probe] != NULL_ID;
            probe = (probe + 1) % list->size);

        assert(list->ids[probe] == NULL_ID);

        list->ids[probe] = unsorted_id_list[i];
    }

    return list;
}

void IDListDestroy(IDList list)
{
    free(list);
}

int IDListContains(IDList list, int id)
{
    int probe;

    /* this MUST be the same pattern as in IDListCreate */
    for(probe = id % list->size;
        list->ids[probe] != NULL_ID;
        probe = (probe + 1) % list->size) {
        if(list->ids[probe] == id) {
            return 1;
        }
    }

    return 0;
}
