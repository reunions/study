#include <stdio.h>
#include <stdlib.h>

int main()
{
  int k;
  int n=0;
  int i=0;
  int sum=0;
  int old_sum=0;
  scanf("%d",&k);
  int a[k+1];
  for(i=0;i<k;i++)
  {
    scanf("%d",&a[i]);
  }
   a[k]=0;
  for(i=0;i<k;i++)
  {
  	if(a[i]<0)
  	{
  		n++;	
	}
  }
  if(n==k)
  {
  	printf("0\n");
  	return 0;
  }
  else
  {
	for(i=0;i<k;i++)
  	{
  		sum=sum+a[i];
  	if(sum<0)
  	{
  		sum=0;
		continue;	
	}
	else
	{
		if(sum>old_sum)
  	{
  		old_sum=sum;	
	}
		if(sum<=old_sum)
	{
		old_sum=old_sum;
	}
  	}
    }
  }
  	printf("%d",old_sum);
  	return 0;
  }
  	
  	
  	
