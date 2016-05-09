//#include <genesis.h>
//#include <string.h>
//
//
//typedef int (*cmpfunc)(void *, void *);
//
//int in_array(void *array[], int size, void *lookfor, cmpfunc cmp)
//{
//    int i;
//
//    for (i = 0; i < size; i++)
//        if (cmp(lookfor, array[i]) == 0)
//            return 1;
//    return 0;
//}
//
//int mainA()
//{
//    char *str[] = {"this is test", "a", "b", "c", "d"};
//
//    if (in_array(str, 5, "c", strcmp))
//        VDP_drawText("yes\n", 1, 1 );
//    else
//        VDP_drawText("no\n", 1, 1 );
//
//    return 0;
//}
//
//
//
//
//
//int contains(int a[], int length, int x)
//{
//    int i;
//    for (i = 0; i < length; i++)
//        if (a[i] == x) return 1;
//
//    return 0;
//}
//
//void mainB()
//{
//    int a[] = { 5, 6, 7 };
//    int length = sizeof(a) / sizeof(a[0]);
//
//    VDP_drawText ( contains(a, length, 5), 1, 1 ); // 1
//    VDP_drawText ( contains(a, length, 4), 1, 1 ); // 0
//}
