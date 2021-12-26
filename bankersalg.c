#include<stdio.h>
#include<stdlib.h>
//safety algorithm
int safety(int alloc[][10], int need[][10], int W[1][10], int n, int m, int seq[])
{
    int i, j, k, q = 0, f1 = 0, f2 = 0, Finish[10], work[1][10];
    
    for (i = 0; i < n; i++)
    	Finish[i] = 0;
    for (i = 0; i < m; i++)
    	work[0][i] = W[0][i];

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (Finish[i] == 0)
            {
                f2 = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[0][j])
                    f2 = 1;
                }
                if (f2 == 0 && Finish[i] == 0)
                {
                    for (j = 0; j < m; j++)
                    work[0][j] = work[0][j] + alloc[i][j];
                    Finish[i] = 1;
                    f1++;
                    seq[q++] = i;
                }
            }
        }
        if (f1 == n)
        return 1;
    }
    return 0;
}
void main()
{
	int max[10][10], alloc[10][10], need[10][10], work[1][10], seq[10], i, j, n, m, s;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	printf("Enter the number of resources : ");
	scanf("%d",&m);
	printf("Enter the maximum matrix :\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&max[i][j]);
			
	printf("Enter the allocation matrix :\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&alloc[i][j]);
	
	printf("Enter the available matrix :\n");
	for(j=0;j<m;j++)
		scanf("%d",&work[0][j]);		
	//calculating the need matrix
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			need[i][j] = max[i][j]-alloc[i][j];
			
	printf("The need matrix is :\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<m;j++)
		{
			printf("%d\t",need[i][j]);
		}
	}
	
	//checking safety
    s = safety(alloc, need, work, n, m, seq);
    //printing safety sequence
    if(s!=0)
    {
        printf("\n\n");
        printf("\n The Safety Sequence is : \n");
        printf("<");
        for (i = 0; i < n; i++)
        printf(" P%d ", seq[i]);
        printf(">\n");
    }
    else
        printf("\n The System is in Deadlock\n");
			
}	
