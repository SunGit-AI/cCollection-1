#ifndef IDVALUELIST_H
#define IDVALUELIST_H

#endif // IDVALUELIST_H
typedef struct id_value_list *IDValueList;

#define MIN_ID (0)
#define MAX_ID (999999999)
/* overhead parameter that determines both space and search costs */
/* must be strictly greater than 1 */
#define OVERHEAD (1.1)
#define NULL_ID (-1)
#define INVALID_VALUE (-1)

/* build an IDValueList out of an unsorted array of n good ids */
/* returns 0 on allocation failure */
IDValueList IDValueListCreate(int n, int unsorted_id_list[], int unsorted_value_list[]);

/* destroy an IDValueList */
void IDValueListDestroy(IDValueList list);

/* check an id against the list */
/* returns nonzero if id is in the list */
int IDValueListContains(IDValueList list, int id);

int IDValueList_getValue(IDValueList list, int id);

int IDValueList_getIndex(IDValueList list, int id);

