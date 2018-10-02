#include <stdio.h>
#include <idlist.h>
#include <idvaluelist.h>

void test_f_001_idList(void)
{
    int iAry_Ids[] = {1000, 2, 3, 4, 7, 50};
    IDList m_idList1 = IDListCreate(6, iAry_Ids);

    if(IDListContains(m_idList1, 1006))
    {
        printf("found id!\n");
    }
    else
    {
        printf("not found!\n");
    }
    IDListDestroy(m_idList1);
}

void test_f_002_idvalueList(void)
{
    int iAry_Ids[] = {1000, 2, 8, 4, 15, 50};
    int iAry_values[] = {100, 20, 33, 44, 75, 507};
    IDValueList m_List1 = IDValueListCreate(6, iAry_Ids, iAry_values);
    for (int i =0; i<6; i++)
    {
        int index = IDValueList_getIndex(m_List1, iAry_Ids[i]);
        printf("index of %d is %d \n", iAry_Ids[i], index);
    }

    if(m_List1==0)
    {
        printf("creation failed!\n");
    }
    if(IDValueListContains(m_List1, 1006))
    {
        printf("found id!\n");
    }
    else
    {
        printf("not found!\n");
    }
    int value = IDValueList_getValue(m_List1, 15);
    if(value!=INVALID_VALUE)
    {

        printf("found value: %d \n", value);
    }
    IDValueListDestroy(m_List1);
}
int main()
{
    //test_f_001_idList();
    test_f_002_idvalueList();
    return 0;
}
