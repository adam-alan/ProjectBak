#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}


static void heapify(ElementType A[],int i,int N){
    int left = 0,right = 0,m = 0;
    while(1){
        left = 2*i;
        right = 2*i + 1;
        m = i;
        if (left < N && A[left] > A[m]){
            m = left;
        }

        if (right < N && A[right] > A[m]){
            m =right;
        }

        if (m != i){
            ElementType tmp = A[i];
            A[i] = A[m];
            A[m] = tmp;
            i = m;
        } else {
            break;
        }

    }
}

void build_heap(ElementType A[],int N){
    for (int i = (N-1) >> 1;i >= 0;--i){
        heapify(A,i,N);
    }
}

void heap_sort(ElementType A[],int N){
    build_heap(A,N);
    while (N > 1){
        --N;
        ElementType tmp = A[0];
        A[0] = A[N];
        A[N] = tmp;
        heapify(A,0,N);
    }
}


ElementType Median(ElementType A[], int N){
    
    heap_sort(A,N);
    /*
    for (int i = 0;i < N;i++){
        printf("%f ",A[i]);
    }*/
/*
    if (N % 2 == 0){
        return ( ( A[N/2] + A[N/2-1] ) / 2 );
    } else {
        return A[N/2];
    }
*/
    return A[N/2];
}