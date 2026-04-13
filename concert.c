#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node *pre, *next;
};

int insert(struct node **h, int key)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->val = key;
    n->pre=0, n->next = 0;
    if(!(*h))
    {
        *h = n;
        return 1;
    }
    struct node *p = *h;
    while(p && p->val<key)
    {
        p = p->next;
    }
        p->pre->next = n;
        n->pre = p->pre;
        n->next = p;
        p->pre = n;
    return 1;
}

struct node *search(struct node *h, int key)
{
    struct node *p = h;
    while(p && p->val<=key)
    {
        if(p->val == key)return p;
    }
    return NULL;
}

int delete(struct node **h, int key)
{
    struct node *d = search(*h, key);
    if(!d)return 0;
    if(!d->pre)
    {
        *h = d->next;
        return 1;
    }
    d->pre->next = d->next;
    d->next->pre = d->pre;
    free(d);
    return 1;
}



int main()
{}
