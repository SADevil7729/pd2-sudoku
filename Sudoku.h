#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
class Sudoku
{
public:
Sudoku()
{
	sol=0;
}
void readIn(void)
{
int i,j;

for(i=1;i<=9;i++)
{
	for(j=1;j<=9;j++)
	{
		scanf("%d",&arr[i][j]);
	}
}
}
bool check3_1(int a[][10],int b,int c)
{
int i;
for(i=1;i<=9;i++)
{
	if(a[b][i]==c)
	{
		return false;
	}
}
return true;
}
bool check3_2(int a[][10],int b,int c)
{
int i;
for(i=1;i<=9;i++)
{
	if(a[i][b]==c)
	{
		return false;
	}
}
return true;
}
bool check4(int a,int b,int c,int d[][10])
{
int i,j;
for(i=1;i<=3;i++)
{
	for(j=1;j<=3;j++)
	{
		if(d[i+(a-1)/3*3][j+(b-1)/3*3]==c)
		{
			return false;
		}
	}
}
return true;
}
int check5(int a[][10])
{
int i,j,k,l,m,temp2;
int temp[10][10][10]={0};
for(i=1;i<=9;i++)
{
	for(j=1;j<=9;j++)
	{
		if(a[i][j]!=0)
		{
			for(k=1;k<=9;k++)
			{
				temp[i][k][ a[i][j] ]=1;
			}
			for(k=1;k<=9;k++)
			{
				temp[k][j][ a[i][j] ]=1;
			}
			for(k=1;k<=3;k++)
			{
				for(l=1;l<=3;l++)
				{
					temp[k+(i-1)/3*3][l+(j-1)/3*3][ a[i][j] ]=1;
				}
			}
		}
	}
}

for(i=0;i<=2;i++)
{
	for(j=0;j<=2;j++)
	{
		for(m=1;m<=9;m++)
		{
			temp2=0;
			for(k=1;k<=3;k++)
			{
				for(l=1;l<=3;l++)
				{
					if(temp[k+i*3][l+j*3][m]==0&&a[k+i*3][l+j*3]==0)
					{
						temp2++;
						if(temp2>=2)
						{
							goto step1;
						}
						n1=k+i*3;
						n2=l+j*3;
						n3=m;
					}
				}
			}
			step1:
			if(temp2==1)
			{
				return 1;
			}
			
		}
	}
}

for(i=1;i<=9;i++)
{
	for(j=1;j<=9;j++)
	{
		temp2=0;
		for(k=1;k<=9;k++)
		{
			if(temp[i][j][k]==0&&a[i][j]==0)
			{
				temp2++;
				if(temp2>=2)
				{
					break;
				}
				n1=i;
				n2=j;
				n3=k;
			}
		}
		if(temp2==1)
		{
			return 1;
		}
	}
}


for(i=1;i<=9;i++)
{
	for(j=1;j<=9;j++)
	{
		temp2=0;
		for(k=1;k<=9;k++)
		{
			if(temp[i][k][j]==0&&a[i][k]==0)
			{
				temp2++;
				if(temp2>=2)
				{
					break;
				}
				n1=i;
				n2=k;
				n3=j;
			}
		}
		if(temp2==1)
		{
			return 1;
		}
	}
}

for(i=1;i<=9;i++)
{
	for(j=1;j<=9;j++)
	{
		temp2=0;
		for(k=1;k<=9;k++)
		{
			if(temp[k][i][j]==0&&a[k][i]==0)
			{
				temp2++;
				if(temp2>=2)
				{
					break;
				}
				n1=k;
				n2=i;
				n3=j;
			}
		}
		if(temp2==1)
		{
			return 1;
		}
	}
}

return 0;
}
bool check6(int a[][10])
{
int i,j,k,l;
for(i=1;i<=9;i++)
{
	for(j=1;j<=9;j++)
	{
		if(a[i][j]!=0)
		{
			for(k=1;k<=9;k++)
			{
				if(k!=j&&a[i][k]==a[i][j])
				{
					return false;
				}
				if(k!=i&&a[k][j]==a[i][j])
				{
					return false;
				}
			}
			for(k=1;k<=3;k++)
			{
				for(l=1;l<=3;l++)
				{
					if(k+(i-1)/3*3!=i&&l+(j-1)/3*3!=j&&a[k+(i-1)/3*3][l+(j-1)/3*3]==a[i][j])
					{
						return false;
					}
				}
			}
		}
	}
}
return true;
}
void solve(void)
{
int i,j,temp;
sol=0;
temp=0;
for(i=1;i<=9;i++)
{
	for(j=1;j<=9;j++)
	{
		if(arr[i][j]==0)
		{
			temp++;
		}
	}
}
if(check6(arr)==false)
{
	sol=0;
}
else if(temp>=65)
{
	sol=2;
}
else
{
	solve2(arr,temp);
}

if(sol<=2)
{
	printf("%d",sol);
}
else
{
	printf("2");
}
if(sol==1)
{
	printf("\n");
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			printf("%d ",solu[i][j]);
		}
		printf("\n");
	}
}
}
void solve2(int a[][10],int num_0)
{
if(sol>=2)
{
return ;
}
int i,j,x=0,y=0;
if(num_0>=1)
{
	if(check5(a)==1)
	{
		i=n1;
		j=n2;
		a[n1][n2]=n3;
		solve2(a,num_0-1);
		a[i][j]=0;
	}
	else
	{
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
			{
				if(a[i][j]==0)
				{
					x=i;
					y=j;
					goto step2;
				}
			}
		}
		step2:
		for(i=1;i<=9;i++)
		{
			if(check3_1(a,x,i)==false)
			{
				continue;
			}
			if(check3_2(a,y,i)==false)
			{
				continue;
			}
			if(check4(x,y,i,a)==false)
			{
				continue;
			}
			a[x][y]=i;
			solve2(a,num_0-1);
			a[x][y]=0;
		}
	}
}
else
{
	sol++;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			solu[i][j]=a[i][j];
		}
	}
}

}

void giveQuestion(void)
{
printf("0 0 0 0 0 0 0 0 0\
\n0 0 0 8 4 0 0 0 0\
\n0 0 1 0 0 0 2 0 0\
\n0 0 0 0 1 0 0 9 0\
\n7 0 0 0 0 2 0 0 0\
\n5 6 0 0 0 0 0 8 0\
\n0 0 0 0 0 0 0 0 0\
\n8 4 0 0 0 0 1 0 0\
\n3 0 0 6 0 0 5 0 0\n");
}

void transform()
{
srand(time(NULL));
int i,j;
for(i=1;i<=rand()%3+1;i++)
{
changeNum(rand()%9+1,rand()%9+1);
changeRow(rand()%3,rand()%3);
changeCol(rand()%3,rand()%3);
rotate(rand()%4);
flip(rand()%2);
}
for(i=1;i<=9;i++)
{
	for(j=1;j<=9;j++)
	{
		printf("%d ",arr[i][j]);
	}
	printf("\n");
}
}
void changeNum(int a,int b)
{
int i,j;
for(i=1;i<=9;i++)
{
	for(j=1;j<=9;j++)
	{
		if(arr[i][j]==a)
		{
			arr[i][j]=b;
		}
		else if(arr[i][j]==b)
		{
			arr[i][j]=a;
		}
	}
}
}

void changeRow(int a,int b)
{
int i,j,temp;
for(i=1;i<=3;i++)
{
	for(j=1;j<=9;j++)
	{
		temp=arr[i+a*3][j];
		arr[i+a*3][j]=arr[i+b*3][j];
		arr[i+b*3][j]=temp;
	}
}
}

void changeCol(int a,int b)
{
int i,j,temp;
for(i=1;i<=9;i++)
{
	for(j=1;j<=3;j++)
	{
		temp=arr[i][j+a*3];
		arr[i][j+a*3]=arr[i][j+b*3];
		arr[i][j+b*3]=temp;
	}
}
}
void rotate(int n)
{
int temp[10][10],i,j;
while(n--)
{
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			temp[i][j]=arr[i][j];
		}
	}
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			arr[i][j]=temp[10-j][i];
		}
	}
}
}
void flip(int n)
{
int i,j,temp;
if(n)
{
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=9;j++)
		{
			temp=arr[i][j];
			arr[i][j]=arr[10-i][j];
			arr[10-i][j]=temp;
		}
	}
}
else
{
	for(j=1;j<=4;j++)
	{
		for(i=1;i<=9;i++)
		{
			temp=arr[i][j];
			arr[i][j]=arr[i][10-j];
			arr[i][10-j]=temp;
		}
	}

}

}
int arr[10][10];
int sol;
int solu[10][10];
int n1,n2,n3;
};
