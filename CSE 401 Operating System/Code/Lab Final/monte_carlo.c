#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>

int count_circle=0;
int count_square=0;
void *runner(void *param);


int main(int argc,char *argv[])
{
    int n=atoi(argv[1]),i;
   // printf("%d\n",n);
    pthread_t tid[n];
    pthread_attr_t attr;
    
    pthread_attr_init(&attr);
    
    for(i=0;i<n;i++)
    	pthread_create(&tid[i],&attr,runner,argv[1]);
    
    for(i=0;i<n;i++)
    	pthread_join(tid[i],NULL);
    	
    	
  //  printf("%d %d\n",count_circle,count_square);
 
    printf("%lf\n",4.0*(count_circle/(1.0*(count_circle+count_square))));

}
float gen_random()
{
	return (float)(rand())/RAND_MAX*2-1;
}
void *runner(void *param)
{
	int l=-1,u=1;
	srand(time(0));
	
	for(int i=0;i<100;i++)
	{
	    float x=gen_random();
	    float y=gen_random();
	    
	 //   printf("%lf %lf\n",x,y);
	    if(x*x+y*y<=1) count_circle++;
	    else count_square++;
	}

}