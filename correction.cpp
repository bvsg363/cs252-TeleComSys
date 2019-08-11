#include<iostream>
#include <string>
#include <cmath>
#include<vector>
using namespace std;

//helper function that checks two nums r equal or not if so
//assigns 1 to some num
void help1(int n1, int n2, int &k){
	if (n1 == n2)	
	{
		k = 0;
	}
	else
		k = 1;
}

//sum of elements of an array
int arr_sum(int *A, int n){
	int c = 0;
	for (int i = 0; i < n; ++i)
	{
		c += A[i];
	}
	return c;
}

//fun - used for calculating parity bits
void fun(int *A, int n){
	if (A[n] == 1)
	{
		A[n] = 0;
	}
	else
		A[n] = 1;
}

//fun1 - inverts the current value of a string
string fun1(string S, int n){
	if (S[n] == '1')
	{
		S[n] = '0';
	}
	else
		S[n] = '1';
	return S;
}

//print_vec - printing of a vector
void print_vec(vector<int>v){
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i];
	}
}

//ceil_div - ceil of a/b
int ceil_div(int a,int b){
	if (a%b != 0)
	{
		return floor(a/b)+1;
	}
	else
		return floor(a/b);
}


int main(){
	string cipher,pp1,pp2,pp3;
	int pcn1,pcn2,pcn3,pco1,pco2,pco3;
	//int check;
	
	cin>>cipher>>pp1>>pp2>>pp3>>pcn1>>pcn2>>pcn3;

	int c1,c2,c3,c4,c5,c6;
	int n,k;
	n = cipher.length();
	k = ceil_div(n,4);
	int par1[k];
	int par2[4];
	int par3[k+3];

	vector<int> v1,v2,v3;

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
		if (cipher[i] == '1')
		{
			int p = ceil_div(i+1,4);
			int q = i % 4;
			int r = p+q-1;

			fun(par1,p-1);
			fun(par2,q);
			fun(par3,r);
		}
	}
	for (int i = 0; i < k; ++i)
	{
		if (par1[i] != pp1[i] -'0')
		{
			v1.push_back(i);
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		if (par2[i] != pp2[i] -'0')
		{
			v2.push_back(i);
		}
	}
	for (int i = 0; i < k+3; ++i)
	{
		if (par3[i] != pp3[i] - '0')
		{
			v3.push_back(i);
		}
	}

	pco1 = arr_sum(par1,k)%2;
	pco2 = arr_sum(par2,4)%2;
	pco3 = arr_sum(par3,k+3)%2;

	help1(pco1,pcn1,c4);
	help1(pco2,pcn2,c5);
	help1(pco3,pcn3,c6);

	c1 = v1.size();
	c2 = v2.size();
	c3 = v3.size();

	string checker = to_string(c1)+to_string(c2)+to_string(c3)+to_string(c4)+to_string(c5)+to_string(c6);

	cout<<checker<<endl;

//mssg errors
	if (checker == "000000")
	{
		cout<<"No Error"<<endl;
	}

	else if (checker == "111111")
	{
		cipher = fun1(cipher,4*v1[0]+v2[0]);
		cout<<cipher<<endl;
	}

	else if (checker == "022000")
	{
		cipher = fun1(cipher,4*v3[0]-3*v2[0]);
		cipher = fun1(cipher,4*v3[1]-3*v2[1]);
		cout<<cipher<<endl;
	}
	else if (checker == "202000")
	{
		cipher = fun1(cipher,3*v1[0]+v3[0]);
		cipher = fun1(cipher,3*v1[1]+v3[1]);
		cout<<cipher<<endl;
	}
	else if (checker == "220000" )
	{
		cipher = fun1(cipher,4*v1[1]+v2[0]);
		cipher = fun1(cipher,4*v1[0]+v2[1]);
		cout<<cipher<<endl;
	}
	else if (checker == "222000")
	{
		if (v3[0] == v1[0] + v2[0])
		{
			cipher = fun1(cipher,4*v1[0]+v2[0]);
			cipher = fun1(cipher,4*v1[1]+v2[1]);
		}
		else
		{
			cipher = fun1(cipher,4*v1[1]+v2[0]);
			cipher = fun1(cipher,4*v1[0]+v2[1]);
		}
		cout<<cipher<<endl;
	}
//mssg and parity errors
	else if (checker == "011111")
	{
		cipher = fun1(cipher,4*v3[0]-3*v2[0]);
		cout<<cipher<<endl;
	}
	else if (checker == "101111")
	{
		cipher = fun1(cipher,3*v1[0]+v3[0]);
		cout<<cipher<<endl;
	}
	else if (checker == "110111")
	{
		cipher = fun1(cipher,4*v1[0]+v2[0]);
		cout<<cipher<<endl;
	}

	else if (checker == "211111")
	{
		cipher = fun1(cipher,4*v3[0]-3*v2[0]);
		cout<<cipher<<endl;
	}
	else if (checker == "121111")
	{
		cipher = fun1(cipher,3*v1[0]+v3[0]);
		cout<<cipher<<endl;
	}
	else if (checker == "112111")
	{
		cipher = fun1(cipher,4*v1[0]+v2[0]);
		cout<<cipher<<endl;
	}

//mssg and parity checker errors
	else if (checker == "111011")
	{
		cipher = fun1(cipher,4*v3[0]-3*v2[0]);
		cout<<cipher<<endl; //mssg and 1D parity checker errors
	}
	else if (checker == "111101")
	{
		cipher = fun1(cipher,4*v3[0]-3*v2[0]);
		cout<<cipher<<endl; //mssg and 2D parity checker errors
	}
	else if (checker == "111110")
	{
		cipher = fun1(cipher,4*v3[0]-3*v2[0]);
		cout<<cipher<<endl; //mssg and 3D parity checker errors
	}

//parity errors
	else if (checker == "100000")
	{
		cout<<"1D par Error "<<v1[0]<<endl;
	}
	else if (checker == "010000")
	{
		cout<<"2D par Error "<<v2[0]<<endl;
	}
	else if (checker == "001000")
	{
		cout<<"3D par Error "<<v3[0]<<endl;
	}

	else if (checker == "200000")
	{
		cout<<"1D par 2 Errors "<<v1[0]<<" "<<v1[1]<<endl;
	}
	else if (checker == "020000")
	{
		cout<<"2D par 2 Errors "<<v2[0]<<" "<<v2[1]<<endl;
	}
	else if (checker == "002000")
	{
		cout<<"3D par 2 Errors "<<v3[0]<<" "<<v3[1]<<endl;
	}

	else if (checker == "110000")
	{
		cout<<"1D par Error "<<v1[0]<<" "<<"2D par Error "<<v2[0]<<endl;
	}
	else if (checker == "101000")
	{
		cout<<"1D par Error "<<v1[0]<<" "<<"3D par Error "<<v3[0]<<endl;
	}
	else if (checker == "011000")
	{
		cout<<"2D par Error "<<v2[0]<<" "<<"3D par Error "<<v3[0]<<endl;
	}

//parity checker errors
	else if (checker == "000100")
	{
		cout<<"1D par checker Error"<<endl;
	}
	else if (checker == "000010")
	{
		cout<<"2D par checker Error"<<endl;
	}
	else if (checker == "000001")
	{
		cout<<"3D par checker Error"<<endl;
	}

	else if (checker == "000110")
	{
		cout<<"1D & 2D par checker Errors"<<endl;
	}
	else if (checker == "000101")
	{
		cout<<"1D & 3D par checker Errors"<<endl;
	}
	else if (checker == "000011")
	{
		cout<<"2D & 3D par checker Errors"<<endl;
	}

	else if (checker == "100100")
	{
		cout<<"1D par Error "<<v1[0]<<" 1D par checker Error"<<endl;
	}
	else if (checker == "010010")
	{
		cout<<"2D par Error "<<v2[0]<<" 2D par checker Error"<<endl;
	}
	else if (checker == "001001")
	{
		cout<<"3D par Error "<<v2[0]<<" 3D par checker Error"<<endl;
	}
	
	else if (checker == "100010")
	{
		cout<<"1D par Error "<<v1[0]<<" 2D par checker Error"<<endl;
	}
	else if (checker == "100001")
	{
		cout<<"1D par Error "<<v1[0]<<" 3D par checker Error"<<endl;
	}
	else if (checker == "010100")
	{
		cout<<"2D par Error "<<v2[0]<<" 1D par checker Error"<<endl;
	}
	else if (checker == "010001")
	{
		cout<<"2D par Error "<<v2[0]<<" 3D par checker Error"<<endl;
	}
	else if (checker == "001100")
	{
		cout<<"3D par Error "<<v3[0]<<" 1D par checker Error"<<endl;
	}
	else if (checker == "001010")
	{
		cout<<"3D par Error "<<v3[0]<<" 2D par checker Error"<<endl;
	}


	else
		cout<<"not possible"<<endl;

}
