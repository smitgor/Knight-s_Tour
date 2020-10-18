#include<stdio.h>

int n,x,y,s,M[1000000],G[1000][1000];
int ans[10][10],counter=0;


void jump(int d)
{
	if(M[s]==0)
	{
		x = x - 1*d;
		y = y + 2*d;
	}
	else if(M[s]==1)
	{
		x = x - 2*d;
		y = y + 1*d;
	}
	else if(M[s]==2)
	{
		x = x - 2*d;
		y = y - 1*d;
	}
	else if(M[s]==3)
	{
		x = x - 1*d;
		y = y - 2*d;
	}
	else if(M[s]==4)
	{
		x = x + 1*d;
		y = y - 2*d;
	}
	else if(M[s]==5)
	{
		x = x + 2*d;
		y = y - 1*d;
	}
	else if(M[s]==6)
	{
		x = x + 2*d;
		y = y + 1*d;
	}
	else if(M[s]==7)
	{
		x = x + 1*d;
		y = y + 2*d;
	}
}


int main()
{
	int x1,y1,c,d,min=8,dist,min_dist,gd,gm;
	
	printf("enter size of board : ");
	scanf("%d",&n);
	
	//initialise
	for(x=0;x<n;x++)
		for(y=0;y<n;y++)
			G[x][y] = -1;
			
	//initial position

	
	x=0; y=0;
    int i,j;
    for(i=0;i<n*n;i++)
    {
        M[s]=0;
    }
	//Knight's tour
	for(s=0;s<n*n;s++)
	{
        if(x>=0 && x<n && y>=0 && y<n && G[x][y]==-1)
        {
            G[x][y]=s;
        }
        else
        {
            s=s-1;
            jump(-1);
            while(M[s]==7)
            {
                G[x][y]=-1;
                M[s]=0;
                s=s-1;
                jump(-1);
            }
            M[s]+=1;
        }
        jump(1);
	}
	
	if(s==n*n)
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