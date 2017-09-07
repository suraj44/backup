#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int len(char*);
void rev(char*);
int strtoint(char*);
char * inttostr(int);
char* dectoother(int);
int othertodec(char*, int);
char hexa(char);
int main()
{
   int x,y;
   int n;
   /*printf("Enter base x and base y\n");
   scanf("%d %d", &x,&y);
   n = rand() % x;
   printf("(%d)%d is equal to (%d)%d\n", n,x,,y);
   */
   printf("%s", inttostr(73));

}

char hexa(char c)
{
   if ( c=='A' || c=='a')
      return '0';
   else if ( c=='B' || c=='b')
      return '1';
   else if ( c=='C' || c=='c')
      return '2';
   else if ( c=='D' || c=='d')
      return '3';
   else if ( c=='E' || c=='e')
      return '4';
   else if ( c=='F' || c=='f')
      return '5';
   else return '6';
}
int len(char* a)
{
   int i=0;
   while(a[i] != '\0')
      i++;
   return i;
}
void rev(char* a)
{
   int l = len(a)-1;
   int i =0;
   int tmp;
   while(i<l)
   {

      tmp = a[i];
      a[i] = a[l];
      a[l] = tmp;
      i++;
      l--;
   }
}



int strtoint(char* a)
{
   int i =0,p=0,ans=0,tmp=0;
   int l = len(a);
   rev(a);
   for(i=0; i<l;i++)
   {
      tmp = a[i] - 48 ;
      ans += tmp * pow(10,p);
      p++;

   }
   return ans;
}

char * inttostr(int n)
{
   int i=0,c, rem, tmp;
   char a[10];
   while(n>0)
   {
      tmp = n % 10;
      tmp+=48;
      a[i]  = tmp;
      i++;
      n/=10;

   }
   a[i] = '\0';
   rev(a);
   return a;

}
char* dectoother(int num)
{
   int base=2;
   int i =0,rem,tmp,p =0 ,r=0;
   char ans[15];
   while(num>0)
   {
      //rem = num %10;
      tmp = num %base;
      if(tmp > 9)
         tmp+=39;
      tmp +=48;
      //printf("%c\n", tmp);
      ans[i] = tmp;
      i++;

      num/=base;

   }
   //ans[i] = '\0';
   r = 4-(i)%4;
   while(r>0 && r<4)
   {
      ans[i] = '0';
      r--;
      i++;
   }
   ans[i] = '\0';
   rev(ans);
   return ans;

}

int othertodec(char * a, int base)
{
   int l = len(a);
   rev(a);
   
   a[l] = '\0';
   int ans=0,tmp =0;
   int i =0;
   int p = 0;

   while(a[i] != '\0')
   {
      if (hexa(a[i])-48<6)
         tmp = hexa(a[i]) - 48 +10;
      else
         tmp = a[i] - 48;
      if (tmp>=base)
      {
         printf("invalid input\n");
         exit(0);
      }

      ans+= tmp * pow(base,p);
      p++;
      i++;
   }
   return ans;

}


