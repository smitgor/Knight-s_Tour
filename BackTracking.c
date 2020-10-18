#include<stdio.h>

int n,x,y,i,M[10000],G[100][100];

//moving to other square
void jump(int d)
{
	if(M[i]==0)
	{
		x = x - 1*d;
		y = y + 2*d;
	}
	else if(M[i]==1)
	{
		x = x - 2*d;
		y = y + 1*d;
	}
	else if(M[i]==2)
	{
		x = x - 2*d;
		y = y - 1*d;
	}
	else if(M[i]==3)
	{
		x = x - 1*d;
		y = y - 2*d;
	}
	else if(M[i]==4)
	{
		x = x + 1*d;
		y = y - 2*d;
	}
	else if(M[i]==5)
	{
		x = x + 2*d;
		y = y - 1*d;
	}
	else if(M[i]==6)
	{
		x = x + 2*d;
		y = y + 1*d;
	}
	else if(M[i]==7)
	{
		x = x + 1*d;
		y = y + 2*d;
	}
}


int main()
{
	
	printf("enter size of board : ");
	scanf("%d",&n);
	
	//initialise
	for(x=0;x<n;x++)
		for(y=0;y<n;y++)
			G[x][y] = -1;
			
	//initial position
	x=0; y=0;
    for(i=0;i<n*n;i++)
    {
        M[i]=0;
    }


	//Knight's tour
	for(i=0;i<n*n;i++)
	{
        if(x>=0 && x<n && y>=0 && y<n && G[x][y]==-1)
        {
            G[x][y]=i+1;
        }
        else
        {
            //backtracking
            i=i-1;
            jump(-1);
            while(M[i]==7)
            {
                G[x][y]=-1;
                M[i]=0;
                i=i-1;
                jump(-1);
            }
            M[i]+=1;
        }
        jump(1);
	}
	
	if(i==n*n)
		printf("\nsolution found\n");
	else
		printf("\nstuck... Can not find the solution.\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d\t",G[i][j]);
		}
		printf("\n");
	}
	return 0;
}
