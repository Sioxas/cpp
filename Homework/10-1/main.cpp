//泰勒公式 
#include <stdio.h>
#include <math.h>

int jc(int n)
{
    int result = 1;
    if(n==0) return result;
 
    else
    {
        while(n)
        {
            result *= n;
            n--;
        }
        return result;
    }
}



int main(int argc, char** argv) {
	double x;
	scanf("%lf",&x);
	int n=10;
	double result=1.0;
	int sign=-1;
	for(int i=1;i<n;i++){
		result=result+sign*pow(x,2*i)/jc(2*i);
		sign=(sign==-1)?1:-1;
	}
	printf("%lf",result);
	return 0;
}
