#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void ft(int Nx,int s,string name);
	
const int D = 1;
const int S = 1;
const int Nx = 30;
const double dx = 2.0/Nx;
const int Nt = (2*D)/(dx*dx);

int main()
{
	ft(Nx, S, "datos.dat");
	return 0;
}

void ft(int Nx, int s,string name)
{
	double N[Nt][Nx];
	for(int i = 0; i < Nt; i++)
    {
        for(int j = 0; j <=Nx; j++)
        {
			if(i == 0 | j == 0 | j == Nx)
            {
				N[j][i] = 0;
			}
		}
	}
	
	for(int i = 0; i<Nt;i++)
	{
		for(int j = 0; j<Nx; j++)
		{
			N[j][i+1]= (N[j+1][i] + N[j-1][i])/2 + s/Nt;
		}	
	}
	
	ofstream outfile;
    outfile.open(name);
	
	for(int i = 0; i < Nt; i++)
	{
		for(int j = 0; j < Nx; j++)
		{
			outfile << N[j][i] << "\t";
		}
		outfile << endl;
	}		
	outfile.close();
}

//void ft2(double I,int nx)
//{
    //double P[Nt][nx];
	
    //for(int j=0; j<=Nx; j++)
	//{    
        //P[j][0] = 0;
    //}
    
    //for(int i=1; i<=Nt; i++)
	//{
        //for(int j=0; j<Nx; j++)
		//{
            //P[j][i] = abs(I[j][i]-I[j-1][i]);
        //}
    //}
//}
