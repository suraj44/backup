#include <stdio.h>
 

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n",n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
void TOH(int n, char from, char aux, char to)
{
    if(n==1)
    {
        printf("move disk 1 from rod %c to rod %c\n", from, to);
    }
    printf("fjasjfndjkfn\n");
    TOH(n-1, from, to, aux);
    printf("move disk %d from rod %c to rod %c\n",n,from,to);
    TOH(n-1, to, aux, from);
}
 
main()
{
    int n = 4; 
    TOH(n,'A','B','C'); 
    
}

