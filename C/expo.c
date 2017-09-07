#include <stdio.h>
#include <math.h>
#include <time.h>
main()
{
	double ans;
	int n,e;
	printf("Enter the base number\n");
	scanf("%d", &n);
	printf("Enter the exponent to raise the number to\n");
	scanf("%d", &e);
	clock_t start,end;
	start = clock();
	ans = pow(2,log(n)/log(2)*e);
	end = clock();
	printf("The answer is %f\n", ans);
	printf("It took %f s to compute\n", (double)(end-start)/CLOCKS_PER_SEC );
	start = clock();
	ans = pow(3,log(n)/log(3)*e);
	end = clock();
	printf("The answer is %f\n", ans);
	printf("It took %f s to compute\n", (double)(end-start)/CLOCKS_PER_SEC );
	

}
