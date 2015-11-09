#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double xn, xo = 0.5; // neues xn und altes xo
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	double maxr = 4.0; double rstep = 0.01; // Wertebereich+Schritte zu r
	
	double f_arr[(Nend-Nskip)*((int)(maxr/rstep))]; // Ausgabewerte f(x)
	ofstream out("logmap_graph.dat"); // Ausgabedatei
	// cout << "Arraylaenge: " << (sizeof(f_arr)/sizeof(*f_arr)) << endl; // debug

	for(double r = 0.0; r < maxr; r+=rstep){
	  int thisstep = (int)(r/rstep);
	  for(int i = 0; i < Nend; i++){
	    xn = xo*r - xo*xo*r;
	    xo = xn;
	    if(i > Nskip){
	      // cout << r << "\t" << xn << endl; // alte Ausgabe
	      // cout << "Schreibe xn " << i+(thisstep*(Nend-Nskip)) << endl; // debug
	      
	      f_arr[i+(thisstep*(Nend-Nskip-1))] = xn; // Werteuebergabe
	    }
	  }
	  //cout << "Erster Wert bei " << (1+thisstep)*(Nend-Nskip) << " :: " << f_arr[(1+thisstep)*(Nend-Nskip)] << endl; // debug
	  xo = 0.5;
	}
	
	// Dateiausgabe
	for(double r=0; r <= maxr; r += rstep){
	  int thisstep = (int)(r/rstep);
	  for(int i=0; i < Nend; i++){
	    if(i > Nskip){
	      out << r << "\t" << f_arr[i+(thisstep*(Nend-Nskip))] << endl;
	    }
	  }
	}
	
	cout << "Datei geschrieben." << endl;

	out.close();
	return 0;
}
