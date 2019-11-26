#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// variable globales
const int D = 1;
const int S = 1;
const int Nx = 30;
const int Nt = 10;
const double Tf = 1.0;
double Ti = 0.0;
const int Xi = -1;
const int Xf = 1;
const double dx = 2.0/Nx;
const double dt = 2.21E-3; //Este valor debe ser menor a (2*dx*dx)/(4*D) y este valor es de 2,22E-3.
;


int main(void)
{
	double **G = new double *[Nt+1];
    for(int i = 0; i <= Nt; i++)
    {
            G[i] = new double[Nx+1];
    }
	
    for(int i = 0; i <= Nt; i++)
    {
        for(int j = 0; j <= Nx; j++)
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
			G[i+1][j] = G[i][j] + ((D * dt)/(pow(dx,2))) * (G[i][j+1] - 2 * G[i][j] + G[i][j-1]) + dt * S;
		}
	}
	
	ofstream outfile;
    outfile.open("Datos.dat");
	
	for(int i = 0; i <= Nt; i++){
		for(int j = 0; j <= Nx; j++){
			outfile << G[i][j] << "\t";
		}
		outfile << endl;
	}		
	outfile.close();		
	return 0;
}