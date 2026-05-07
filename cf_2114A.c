#include<stdio.h>
#include<math.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        char s[5];
        scanf("%s", s);
        int y=0;
        for(int i=0; i<4; i++)
        {
            int dig = s[i] - '0';
            y = y*10+dig;
        }
        if((int)sqrt(y) * (int)sqrt(y) == y)
        {
            printf("%d %d\n", 1, (int)sqrt(y)-1);
        }
        else printf("-1\n");
    }
}

