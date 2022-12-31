#include<stdio.h>
#include<stdlib.h>
#include<vector>


typedef struct ConvexHull
{
    /* data */
    int first, second;
}ConvexHull;

int compareX(const void* a, const void* b){
    ConvexHull *c1 = (ConvexHull *)a, *c2 = (ConvexHull *)b;
    return (c1->first - c2->first);
}

int main(){
    ConvexHull c[] = {{0, 0}, {1, -4}, {-1, -5}, {-5, -3}, {-3, -1}, {-1, -3}, {-2, -2}, {-1, -1}, {-2, -1}, {-1, 1}};
    int n = sizeof(c)/sizeof(c[0]);

    //Sorting point 
    qsort(c, n, sizeof(ConvexHull), compareX);

    vector<>
}
