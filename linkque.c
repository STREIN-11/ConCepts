#include <stdio.h>
#include <stdlib.h>
struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void print(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enque(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
        printf("Queue is Full");
    else
        n->data = val;
    n->next = NULL;
    if (f == NULL)
        f = r = n;
    else
        r->next = n;
        r = n;
    printf("Enqueue Element is : %d\n", val);
}
int deque()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
        printf("Queue is Empty\n");
    else
        f = f->next;
        val = ptr->data;
        free(ptr);
    printf("Dequeue Element is : %d\n", val);
}

int main()
{
    int q;
    int n, m, remove;
    printf("Enter Size : ");
    scanf("%d", &n);
    printf("Enter Enqueue Element : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        enque(m);
    }
    printf("Do you want to Dqueue (1/n) : ");
    scanf("%d",&q);
    if (q == 1){
        printf("How many Element want to remove : ");
        scanf("%d", &remove);
        for (int i = 0; i < remove; i++)
        {
            deque();
        }
        print(f);
    }
    else{
        print(f);
    }

}
