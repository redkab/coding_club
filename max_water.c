#include<stdio.h>
int min(int a, int b)
{
    if(a>b) return b;
    else return a;
}
int max_water(int height[], int size)
{
    int start, end, length, h, area, max_area=0;
    for(start = 0; start <size-1; start++)
    {
        for(end=start+1; end<size; end++)
        {
            length = end - start;
            h = min(height[start], height[end]);
            area = length * h;
            if(area>max_area)
            {
                max_area = area;
            }
        }
    }
    return max_area;
}

int main()
{
    int height[] = {1,1};
    printf("%d\n", max_water(height, 2));
            }
