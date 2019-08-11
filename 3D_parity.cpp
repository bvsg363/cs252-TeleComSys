#include<iostream>
#include <string>
#include <cmath>
using namespace std;

//sum of elements of an array
int arr_sum(int *A, int n){
	int c = 0;
	for (int i = 0; i < n; ++i)
	{
		c += A[i];
	}
	return c;
}

void fun(int *A, int n){
	if (A[n] == 1)
	{
		A[n] = 0;
	}
	else
		A[n] = 1;
}

int ceil_div(int a,int b){

	if (a%b != 0)
	{
		return floor(a/b)+1;
	}
	else
		return floor(a/b);
}

int main(){
	int n,k,pc1,pc2,pc3;
	string payload;
	cin>>payload;
	n = payload.length();
	k = ceil_div(n,4);
	int par1[k];
	int par2[4];
	int par3[k+3];
	for (int i = 0; i < k; ++i)
	{
		par1[i] = 0;
	}

	for (int i = 0; i < 4; ++i)
	{
		par2[i] = 0;
	}

	for (int i = 0; i < k+3; ++i)
	{
		par3[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{	
		if (payload[i] == '1')
		{
			int p = ceil_div(i+1,4);
			int q = i % 4;
			int r = p+q-1;
			fun(par1,p-1);
			fun(par2,q);
			fun(par3,r);
		}
	}

	string red;

	for (int i = 0; i < k; ++i)
	{
		red += to_string(par1[i]);
	}
	for (int i = 0; i < 4; ++i)
	{
		red += to_string(par2[i]);
	}
	for (int i = 0; i < 3+k; ++i)
	{
		red += to_string(par3[i]);
	}

	pc1 = arr_sum(par1,k)%2;
	pc2 = arr_sum(par2,4)%2;
	pc3 = arr_sum(par3,k+3)%2;

	red += to_string(pc1)+to_string(pc2)+to_string(pc3);
	cout<<red<<endl;

}