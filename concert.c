nclude<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node *pre, *next;
};

int insert(struct node **h, int key)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (!n) return 0;
    n->val = key;
    n->pre = n->next = NULL;

    if (!(*h))
    {
        *h = n;
        return 1;
    }

    struct node *p = *h;
    while (p && p->val < key)
        p = p->next;

    if (!p)
    {
        struct node *tail = *h;
        while (tail->next)
            tail = tail->next;
        tail->next = n;
        n->pre = tail;
    }
    else if (!p->pre)
    {
        n->next = p;
        p->pre = n;
        *h = n;
    }
    else
    {
        n->next = p;
        n->pre = p->pre;
        p->pre->next = n;
        p->pre = n;
    }
    return 1;
}

struct node *search(struct node *h, int key)
{
    struct node *p = h;
    while (p && p->val <= key)
    {
        if (p->val == key)
            return p;
        p = p->next;
    }
    return NULL;
}

int delete(struct node **h, int key)
{
    struct node *d = search(*h, key);
    if (!d)
        return 0;

    if (d->pre)
        d->pre->next = d->next;
    else
        *h = d->next;

    if (d->next)
        d->next->pre = d->pre;

    free(d);
    return 1;
}

struct node * getPrice(struct node *h, int max)
{
    struct node *p = h;
    while(p && p->val <=max)
    {
        p = p->next;
    }
    return p->pre;
}


int main()
{
    int m,n;
    scanf("%d %d", &n, &m);
    struct node *t = NULL:
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d", &x);
        insert(&t, x);
    }
    int *h = (int *)malloc(m*sizeof(int));
    for(int i=0; i<m; i++)
    {
        scanf("%d", h+i);
    }
    for(int i=0; i<m; i++)
    {
        struct node *p = getMax(t, h[i]);


    

