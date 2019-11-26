#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void Funcion(double s, double D, int Nx, int Nt,string name);
	
const int D = 1;
const int s = 1;
const int Nx = 30;
const int Nt = 15;
const double dx = 2.0/Nx;
const double dt = 2E-3;

int main(void)
{
	Funcion(s,D,Nx,Nt,"datos.dat");
	return 0;
}

void Funcion(double s, double D, int Nx, int Nt, string name)
{
	double M[Nx][Nt];
    for(int i = 0; i < Nt; i++)
    {
        for(int j = 0; j < Nx; j++)
        {
			if(i == 0 | j == 0 | j == Nx)
            {
				M[i][j] = 0;
			}
		}
	}
	
	for(int i = 0; i < Nt; i++)
    {
		for(int j = 1; j < Nx; j++)
        {
			M[i+1][j] = M[i][j] + ((D*dt)/(pow(dx,2)))*(M[i][j+1] - 2*M[i][j] + M[i][j-1]) + dt*s;
		}
	}
	
	ofstream outfile;
    outfile.open(name);
	
	for(int i = 0; i <= Nt; i++)
	{
		for(int j = 0; j <= Nx; j++)
		{
			outfile << M[i][j] << "\t";
		}
		outfile << endl;
	}		
	outfile.close();
}