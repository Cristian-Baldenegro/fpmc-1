#include "../MG_standalone_eft_ttbar/SubProcesses/P1_Sigma_AAttbar_UFO_aa_ttx/EFT_AAttbarProcess.h"
#include "herwig.h"
#include <iostream>
#include <math.h>

using namespace std;

namespace eft_aattbar {
// Computes the squared matrix element
double sqme(double *_p0_1, double *_px_1, double *_py_1, double *_pz_1,
            double *_p0_2, double *_px_2, double *_py_2, double *_pz_2,
            double *_p0_3, double *_px_3, double *_py_3, double *_pz_3,
            double *_p0_4, double *_px_4, double *_py_4, double *_pz_4,
            double *_xi1, double *_xi2, double *_xi3, double *_xi4,
            double *_xi5, double *_xi6) {

  // EFT couplings
  double xi1 = *_xi1;
  double xi2 = *_xi2;
  double xi3 = *_xi3;
  double xi4 = *_xi4;
  double xi5 = *_xi5;
  double xi6 = *_xi6;
  double couplings[6] = {xi1, xi2, xi3, xi4, xi5, xi6};

  // Convert momenta to MG desired format
  // MG: (E,px,py,pz)
  double p1[4] = {*_p0_1,*_px_1,*_py_1,*_pz_1};
  double p2[4] = {*_p0_2,*_px_2,*_py_2,*_pz_2};
  double p3[4] = {*_p0_3,*_px_3,*_py_3,*_pz_3};
  double p4[4] = {*_p0_4,*_px_4,*_py_4,*_pz_4};
  vector<double *> p = {p1, p2, p3, p4};

  // Create a process object
  EFT_AAttbarProcess process;

  // Read param_card and set parameters
  process.initProc("../MG_standalone_eft_ttbar/Cards/param_card.dat",
                   couplings);

  // Set momenta for this event
  process.setMomenta(p);

  // Evaluate matrix element
  process.sigmaKin();

  const double *matrix_elements = process.getMatrixElements();

  // cout << "Momenta:" << endl;
  // for(int i=0;i < process.nexternal; i++)
  // 	cout << setw(4) << i+1
  // << setiosflags(ios::scientific) << setw(14) << p[i][0]
  // << setiosflags(ios::scientific) << setw(14) << p[i][1]
  // << setiosflags(ios::scientific) << setw(14) << p[i][2]
  // << setiosflags(ios::scientific) << setw(14) << p[i][3] << endl;
  // cout << "
  // -----------------------------------------------------------------------------"
  // << endl;

  // Display matrix elements
  for (int i = 0; i < process.nprocesses; i++)
    cout << " Matrix element = "
         //	 << setiosflags(ios::fixed) << setprecision(17)
         << matrix_elements[i] << " GeV^" << -(2 * process.nexternal - 8)
         << endl;

  cout << " -------------------------------------------------------------------"
          "----------"
       << endl;

  return matrix_elements[0];
}
} // namespace eft_aattbar