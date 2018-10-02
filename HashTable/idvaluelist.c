#include <stdlib.h>
#include <assert.h>
#include <idvaluelist.h>


struct id_value_list {
    int size;
    int *ids;         /* we'll actually malloc more space than this */
    int *values;
};

IDValueList IDValueListCreate(int n, int unsorted_id_list[], int unsorted_value_list[])
{
    IDValueList list;
    int size;
    int i;
    int probe;

    size = (int) (n * OVERHEAD + 1);

    printf("variable  size %d \n", size);

    list = malloc(sizeof(*list));
    if(list == 0) return 0;
    list->ids = malloc(sizeof(int)*size);
    list->values = malloc(sizeof(int)*size);
    printf("malloc list size %d \n", sizeof(list));

    /* else */
    list->size = size;

    /* clear the hash table */
    for(i = 0; i < size; i++) {
        list->ids[i] = NULL_ID;
        list->values[i] = INVALID_VALUE;
    }

    /* load it up */
    for(i = 0; i < n; i++) {

        assert(unsorted_id_list[i] >= MIN_ID);
        assert(unsorted_id_list[i] <= MAX_ID);

        /* hashing with open addressing by division */
        /* this MUST be the same pattern as in IDValueListContains */
        for(probe = unsorted_id_list[i] % list->size;
            list->ids[probe] != NULL_ID;
            probe = (probe + 1) % list->size);

        assert(list->ids[probe] == NULL_ID);

        list->ids[probe] = unsorted_id_list[i];
        list->values[probe] = unsorted_value_list[i];
    }

    return list;
}

void IDValueListDestroy(IDValueList list)
{
    free(list->ids);
    free(list->values);
    free(list);
}

int IDValueListContains(IDValueList list, int id)
{
    int probe;

    /* this MUST be the same pattern as in IDValueListCreate */
    for(probe = id % list->size;
        list->ids[probe] != NULL_ID;
        probe = (probe + 1) % list->size) {
        if(list->ids[probe] == id) {
            return 1;
        }
    }

    return 0;
}

int IDValueList_getIndex(IDValueList list, int id)
{
    int probe;
    for(probe = id % list->size;
        list->ids[probe] != NULL_ID;
        probe = (probe + 1) % list->size) {
        if(list->ids[probe] == id) {
            return probe;
        }
    }

    return INVALID_VALUE;
}

int IDValueList_getValue(IDValueList list, int id)
{
    int index = IDValueList_getIndex(list, id);
    if (index != INVALID_VALUE)
    {
        return list->values[index];
    }
    else
    {
        return INVALID_VALUE;
    }
}


