#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int Hash_Code(string s,int m,int n)
{
	int valu=0;
	for(int i=0;i<=n;i++)
	{
		valu+=((int(s[i]))*pow(3,i));
	}
	return valu;
}

bool Is_same(string Main,int s,int e,string Sub,int l)
{
	int x,y;
	for(x=s,y=0;x<=e && y<l;x++,y++)
	{
		if(Main[x]!=Sub[y])
			return 0;
	}
	return 1;
}

int Rabin_Karp(string Main,string Sub,int l1,int l2)
{
	int MHvalu=Hash_Code(Main,0,l2-1);
	int SHvalu=Hash_Code(Sub,0,l2-1);
	for(int i=1;i<=l1-l2+1;i++)
	{
		if((MHvalu==SHvalu) && Is_same(Main,i-1,i+l2-2,Sub,l2))
			return i-1;
		//MHvalu=(MHvalu-((int)Main[i-1]))/3;
		MHvalu=(MHvalu-Main[i-1])/3;
		//MHvalu+=(((int)Main[i+l2-1])*pow(3,l2-1));
		MHvalu=MHvalu+((Main[i+l2-1])*pow(3,l2-1));
	}
	return -1;

}

int main()
{
	cout<<Rabin_Karp("aaafgsdd","sdd",8,3)<<endl;
}