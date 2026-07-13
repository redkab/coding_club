#include<stdio.h>

int main()
{
    float time=0;
    int piles[] = {};
    int k;
    int h;
    int size = sizeof(piles)/sizeof(piles[0]);
    for(k=1; ;k++)
    {
    for(i=0; i<size; i++)
    {
        if(piles[i] < k)
        {
            time++;
        }
        else 
        {
            time += piles[i]/k;
        }
    }
    
    

