#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double x0 = 0.5;
	double xn,x;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	
	double f_arr[Nend-Nskip];
	ofstream out("logmap_graph.dat");

	for(double r=0; r <= 4; r += 0.001){
	   x=x0;
	   for(int i=1; i <= Nskip; i++){
		   xn = x*r - x*x*r;
	   }
	   x = xn;
	   for(int i=Nskip+1; i <= Nend; i++){
	   		   xn = x*r - x*x*r;
	   		   // cout << r << "\t" << x << endl; // vorherige Ausgabe
			   f_arr[i-Nskip-1] = xn; // Werteuebergabe
   	   }
	}
	
	// Dateiausgabe
	for(double r=0; r <= 4; r += 0.001){
	  for(int i=1; i <= Nend; i++){
	    out << r << "\t" << f_arr[i-1] << endl;
	  }
	}


	out.close();
	return 0;
}
