#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}

int factorial(int num){
    if (num == 1 || num == 0){
        return 1;
    }
    return num*factorial(num-1);
}

int FactorialSum(List L){
    if (L == NULL){
        return 0;
    }
    PtrToNode head = L;
    int sum = 0;
    while (head != NULL){
        sum += factorial(head->Data);
        head = head->Next;
    }
    return sum;
}
