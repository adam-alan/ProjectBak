#include <iostream>

#include <algorithm>
using namespace std;





void heap_sort(int array[],int lenth,bool (*compare)(int,int));
void build_heap(int array[],int length,bool (*compare)(int,int));
static void heapify(int array[],int i,int length,bool (*compare)(int,int));

template<typename Type>
bool my_less(Type key1,Type key2){
    return key1 < key2;
}

template<typename Type>
bool my_greater(Type key1,Type key2){
    return key1 > key2;
}



int main ()
{
    int array[10] = {16,4,10,14,7,9,3,2,8,1};
    heap_sort(array, 10, my_less);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}

static void heapify(int array[],int i,int length,bool (*p)(int,int)){
    int left = 0,right = 0,m = 0;
    while(1){
        left = 2*i + 1;
        right = 2*i + 2;
        m = i;
        if (left < length && p(array[left],array[m])){
            m = left;
        }

        if (right < length && p(array[right],array[m])){
            m = right;
        }

        if (m != i){
            swap(array[i],array[m]);
            i = m;
        } else {
            break;
        }

    }
}

void build_heap(int array[],int length,bool (*p)(int,int)){
    for (int i = (length-1) >> 1;i >= 0;--i){
        heapify(array,i,length,p);  
    }
}

void heap_sort(int array[],int length,bool (*p)(int,int)){
    build_heap(array,length,p);
    while (length > 1){
        --length;
        swap(array[0],array[length]);
        heapify(array,0,length,p);
    }
}
