#include<stdio.h>

int n,x,y,i,M[1000000],G[1000][1000];
int ans[10][10],counter=0;


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
//min degree
int count()
{
	int count=0;
	if((x-1)>=0 && (y+2)<n && G[x-1][y+2]==-1)
		count++;
	if((x-2)>=0 && (y+1)<n && G[x-2][y+1]==-1)
		count++;
	if((x-2)>=0 && (y-1)>=0 && G[x-2][y-1]==-1)
		count++;
	if((x-1)>=0 && (y-2)>=0 && G[x-1][y-2]==-1)
		count++;
	if((x+1)<n && (y-2)>=0 && G[x+1][y-2]==-1)
		count++;
	if((x+2)<n && (y-1)>=0 && G[x+2][y-1]==-1)
		count++;
	if((x+2)<n && (y+1)<n && G[x+2][y+1]==-1)
		count++;
	if((x+1)<n && (y+2)<n && G[x+1][y+2]==-1)
		count++;
	return count;	
}

int main()
{
	int x1,y1,c,d,min=8;
	
	printf("enter size of board : ");
	scanf("%d",&n);
	
	//initialise
	for(x=0;x<n;x++)
		for(y=0;y<n;y++)
			G[x][y] = -1;
			
	//initial position
	printf("enter starting position (0-%d)\n",n-1);
	printf("row : ");
	scanf("%d",&x);
	printf("col : ");
	scanf("%d",&y);
	
	x1=x; y1=y;

	//Knight's tour
	for(i=1;;i++)
	{
		G[x][y]=i;
		min=8;
		d=0;
		for(M[i]=0;M[i]<8;M[i]++)
		{
			jump(1);
			if(x>=0 && x<n && y>=0 && y<n && G[x][y]==-1)
			{
				c=count();
				dist=(x-n/2)*(x-n/2)+(y-n/2)*(y-n/2);
				if(c<min)
				{
					min=count();
					d=M[i];
					min_dist=dist;
				}
			}
			jump(-1);	
		}
		
		if(min==8)
			break;
		
		M[i]=d;
		jump(1);

		x1=x; y1=y;
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
