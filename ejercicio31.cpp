#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void ft(int Nx,int s,string name);
	
const int D = 1;
const int S = 1;
const int Nx = 100;
const double dx = 2.0/Nx;
const int Nt = (2*D)/(dx*dx);
int iteracion = 0;
double error = 1;

int main()
{
	ft(Nx, S, "datos.dat");
	return 0;
}

void ft(int Nx, int s,string name)
{
    ofstream outfile;
    outfile.open(name);
	double N[Nx+1];
    double A[Nx+1];
	for(int i = 0; i <=Nx; i++)
    {
        A[i]=0.0;
	}
    
    while(error>1E-5)
    {
        iteracion +=1;
        for(int i = 1; i<=Nx;i++)
        {
			N[i]= (1/2)*(A[i+1] + A[i-1]) + s;	
            outfile << iteracion <<"\t"<< N[i]<< "\t"<<endl;
            error -=0.000001;
        }
    }
        outfile.close();
}