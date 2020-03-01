#include<iostream>
#include<cstring>
using namespace std;

void ComputeLPS(string Sub,int l2,int a[])
{
	int j=0,i;
	a[0]=0;
	for(i=1;i<l2;)
	{
		if(Sub[i]==Sub[j])
		{
			a[i]=j+1;
			j++;
			i++;
			continue;
		}
		if(j!=0)
			j=a[j-1];
		else{
			a[i]=0;
			i++;
		}
	}
}

int KMP_Search(string Main,string Sub,int l1,int l2)
{
	int a[l2],i,j=0;
	ComputeLPS(Sub,l2,a);
	
	for(i=0;i<l1;)
	{
		if(Main[i]==Sub[j])
		{
			i++;
			j++;
		}
		else{
			if(j!=0)
				j=a[j-1];
			else
				i++;
		}
		if(j==l2)
			return i-l2;
	}
	return -1;

}
int main()
{
	string s="aaaaaa";
	string a="aa";
	int l1=s.length();
	int l2=a.length();
	cout<<KMP_Search(s,a,l1,l2)<<endl;
}