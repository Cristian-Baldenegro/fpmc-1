#include <iostream>
#include <math.h>
#include "herwig.h"
#include "EFT_AAttbarProcess.h"

using namespace std;

namespace eft_aattbar{
// Computes the squared matrix element
	double sqme(double* _p1,double* _p2,double* _p3,double* _p4,double* _xi1,double* _xi2,double* _xi3,double* _xi4,double* _xi5,double* _xi6){
		
		// EFT couplings
		double xi1 = *_xi1;
		double xi2 = *_xi2;
		double xi3 = *_xi3;
		double xi4 = *_xi4;
		double xi5 = *_xi5;
		double xi6 = *_xi6;
		double couplings[6] = {xi1,xi2,xi3,xi4,xi5,xi6};
		
		// Convert momenta to MG desired format
		// HW: (px,py,pz,E,M)
		// MG: (E,px,py,pz)
		double p1[4] = {_p1[3],_p1[0],_p1[1],_p1[2]};
		double p2[4] = {_p2[3],_p2[0],_p2[1],_p2[2]};
		double p3[4] = {_p3[3],_p3[0],_p3[1],_p3[2]};
		double p4[4] = {_p4[3],_p4[0],_p4[1],_p4[2]};
		vector<double*> p = {p1,p2,p3,p4}
		
		// Create a process object
		EFT_AAttbarProcess process;

        // Read param_card and set parameters
		process.initProc("../MG_standalone_eft_ttbar/Cards/param_card.dat");

		// Set momenta for this event
		process.setMomenta(p);

		// Evaluate matrix element
		process.sigmaKin();

		const double* matrix_elements = process.getMatrixElements();

		// cout << "Momenta:" << endl;
		// for(int i=0;i < process.nexternal; i++)
		// 	cout << setw(4) << i+1 
		// << setiosflags(ios::scientific) << setw(14) << p[i][0]
		// << setiosflags(ios::scientific) << setw(14) << p[i][1]
		// << setiosflags(ios::scientific) << setw(14) << p[i][2]
		// << setiosflags(ios::scientific) << setw(14) << p[i][3] << endl;
		// cout << " -----------------------------------------------------------------------------" << endl;

		// Display matrix elements
		for(int i=0; i<process.nprocesses;i++)
			cout << " Matrix element = " 
		//	 << setiosflags(ios::fixed) << setprecision(17)
		<< matrix_elements[i]
		<< " GeV^" << -(2*process.nexternal-8) << endl;

		cout << " -----------------------------------------------------------------------------" << endl;

		return matrix_elements[0];

	}
}