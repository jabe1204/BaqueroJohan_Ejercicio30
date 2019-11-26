#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// variable globales
void Funcion(double s, double D, int Nx, int Nt,string name);
	
const int D = 1;
const int S = 1;
const int Nx = 30;
const int Nt = 10;
const double Tf = 1.0;
double Ti = 0.0;
const int Xi = -1;
const int Xf = 1;
const double dx = 2.0/Nx;
const double dt = 2.21E-3;

int main(void)
{
	Funcion(S,D,Nx,Nt,"datos.dat");
	Funcion(S,D,Nx-1,Nt,"datos1.dat");
	return 0;
}

void Funcion(double s, double D, int Nx, int Nt, string name)
{
	double G[Nx][Nt];
    for(int i = 0; i < Nt; i++)
    {
        for(int j = 0; j < Nx; j++)
        {
			if(i == 0 | j == 0 | j == Nx)
            {
				G[i][j] = 0;
			}
		}
	}
	
	for(int i = 0; i < Nt; i++)
    {
		for(int j = 1; j < Nx; j++)
        {
			G[i+1][j] = G[i][j] + ((D*dt)/(pow(dx,2))) * (G[i][j+1] - 2 * G[i][j] + G[i][j-1]) + dt * S;
		}
	}
	
	ofstream outfile;
    outfile.open(name);
	
	for(int i = 0; i <= Nt; i++)
	{
		for(int j = 0; j <= Nx; j++)
		{
			outfile << G[i][j] << "\t";
		}
		outfile << endl;
	}		
	outfile.close();
}