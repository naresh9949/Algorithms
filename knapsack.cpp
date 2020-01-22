#include<iostream>
using namespace std;

int KnapSack(int weights[],int prices[],int n,int weight)
{
	//weight++;
	int matrix[n][weight],i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<weight;j++)
		{
			if(j==0)
			{
				matrix[i][j]=0;
				continue;
			}

			if(j<weights[i] && i==0)
				matrix[i][j]=0;
			else if(j<weights[i] && i!=0)
				matrix[i][j]=matrix[i-1][j];
			else if(j>=weights[i] && i!=0)
				matrix[i][j]=max(matrix[i-1][j],prices[i]+matrix[i-1][j-weights[i]]);
			else
				matrix[i][j]=prices[i];
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<weight;j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	return matrix[n-1][weight-1];
}
int main()
{
	int weights[]={2,4,6,8,7};
	int prices[]={3,6,4,9,11};
	int weight=6;
	cout<<KnapSack(weights,prices,3,weight+1)<<endl;
}