#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H
int getMid(int s, int e);
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si);
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si);
void updateValue(int arr[], int *st, int n, int i, int new_val);
int getSum(int *st, int n, int qs, int qe);
int constructSTUtil(int arr[], int ss, int se, int *st, int si);
int *constructST(int arr[], int n);
void deconstructST(int* intPArr_SegmentTree);
#endif // SEGMENTTREE_H
