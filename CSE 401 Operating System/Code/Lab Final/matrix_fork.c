#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
    int colA,colB,rowA,rowB;
    printf("Enter A matrix base (row, col):");
    scanf("%d %d",&rowA,&colA);
    printf("Enter B matrix base (row, col):");
    scanf("%d %d",&rowB,&colB);

    if(colA==rowB)
    {
        int A[rowA][colA],B[rowB][colB],mul[rowA][colB];
        int i, j,k;
        for( i=0; i<rowA; i++)
        {
            for( j=0; j<colB; j++)
                mul[i][j]=0;
        }

        printf("Enter matrix A\n");
        for(i=0; i<rowA; i++)
        {
            for(j=0; j<colA; j++)
                scanf("%d",&A[i][j]);
        }
        printf("Enter matrix B\n");
        for(i=0; i<rowB; i++)
        {
            for(j=0; j<colB; j++)
                scanf("%d",&B[i][j]);
        }

        for (int i = 0; i < rowA; i++)
        {
            int  pid = fork();

            if (pid==0)
            {
                for (int j = 0; j < colB; j++)
                {
                    mul[i][j] = 0;
                    for (int k = 0; k < colA; k++)
                    {
                        mul[i][j] += A[i][k] * B[k][j];
                    }
                    printf("%d ",mul[i][j]);
                }


                for(i=0; i<rowA*rowA; i++)
                    wait(NULL);
                printf("\n");

                  exit(0);
            }
        }
        printf("A X B :\n");
        for(i=0; i<rowA; i++)
        {
            for(j=0; j<colB; j++)
            {
                printf("%d ",mul[i][j]);
            }
            printf("\n");
        }
    }
}