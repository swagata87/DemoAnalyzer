#define DrawROC_cxx
#include "DrawROC.h"
#include <algorithm>
#include "TLatex.h"
#include "TROOT.h"
#include <iomanip>
#include "TObjArray.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include "TGraph.h"
#include "TFile.h"
#include "TLegend.h"
#include "TObject.h"
#include "TAttLine.h"
#include "TAttBBox2D.h"
#include "TPoint.h"
#include "TPad.h"
#include "TColor.h"
#include "TStyle.h"
#include "TPostScript.h"
#include "TAttBBox2D.h"
#include "TArrow.h"

void DrawROC::Loop()
{
//   In a ROOT session, you can do:
//      root> .L DrawROC.C
//      root> DrawROC t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

  TFile* outputFile = new TFile("my_sieie_ROC_2018.root","RECREATE");
  outputFile->cd();

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   
   float cuts[40] = {0.002, 0.004, 0.005, 0.006, 0.007, 0.0073, 0.0076, 0.0078, 0.0080, 0.0083, 0.0086 ,0.0088 ,0.009, 0.0095 ,0.010, 0.011, 0.012, 0.013, 0.014, 0.015, 0.016, 0.017, 0.018, 0.019, 0.02, 0.021, 0.022, 0.023, 0.024, 0.025, 0.026 ,0.03, 0.04, 0.05, 0.06, 0.07 ,0.08, 0.09 ,0.1, 10};

   //   float cuts[40] = {0.002, 0.003 ,0.004 ,0.005, 0.006 ,0.007,0.0075 ,0.008, 0.0085, 0.009, 0.0092 ,0.0095 ,0.0100, 0.0101, 0.0102, 0.0103 ,0.0104, 0.0106, 0.0108, 0.0110, 0.0112, 0.0114, 0.0116, 0.0118, 0.0120, 0.0122, 0.0124, 0.0126, 0.015, 0.02, 0.04, 0.05,0.06, 0.07, 0.08 , 0.09, 0.1 ,0.5,0.6,1};

   int len = sizeof(cuts) / sizeof(cuts[0]);
   std::cout << "len of cuts array " << len << std::endl;

   std::vector<float> x_cutName;
   std::vector<float> y_spikeFrac;

   std::vector<float> x_cutName_en;
   std::vector<float> y_spikeFrac_en;

   std::vector<float> x_cutName_rechit;
   std::vector<float> y_spikeFrac_rechit;

   std::vector<float> x_sigEff_sieie_default;
   std::vector<float> y_bkgEff_sieie_default;
   int nsig_default_spike=0;
   
   std::vector<float> x_sigEff_sieie_w4p2;
   std::vector<float> y_bkgEff_sieie_w4p2;
   int nsig_w4p2_spike=0;

   std::vector<float> x_sigEff_sieie_w4p1;
   std::vector<float> y_bkgEff_sieie_w4p1;
   int nsig_w4p1_spike=0;

   std::vector<float> x_sigEff_sieie_w4p3;
   std::vector<float> y_bkgEff_sieie_w4p3;
   int nsig_w4p3_spike=0;
   
   std::vector<float> x_sigEff_sieie_w4p4;
   std::vector<float> y_bkgEff_sieie_w4p4;
   int nsig_w4p4_spike=0;

   std::vector<float> x_sigEff_sieie_per_rechit;
   std::vector<float> y_bkgEff_sieie_per_rechit;
   int nsig_per_rechit_spike=0;

   std::vector<float> x_sigEff_sieie_per_rechit_m1p25;
   std::vector<float> y_bkgEff_sieie_per_rechit_m1p25;
   int nsig_per_rechit_m1p25_spike=0;

   std::vector<float> x_sigEff_sieie_per_rechit_m1p8;
   std::vector<float> y_bkgEff_sieie_per_rechit_m1p8;
   int nsig_per_rechit_m1p8_spike=0;

   std::vector<float> x_sigEff_sieie_per_rechit_m1p5;
   std::vector<float> y_bkgEff_sieie_per_rechit_m1p5;
   int nsig_per_rechit_m1p5_spike=0;

   std::vector<float> x_sigEff_sieie_w4p0;
   std::vector<float> y_bkgEff_sieie_w4p0;
   int nsig_w4p0_spike=0;

   std::vector<float> x_sigEff_sieie_en0p15;
   std::vector<float> y_bkgEff_sieie_en0p15;
   int nsig_en0p15_spike=0;

   std::vector<float> x_sigEff_sieie_en0p15_noRelNoiseCut;
   std::vector<float> y_bkgEff_sieie_en0p15_noRelNoiseCut;
   int nsig_en0p15_noRelNoiseCut_spike=0;

   std::vector<float> x_sigEff_sieie_en0p2;
   std::vector<float> y_bkgEff_sieie_en0p2;
   int nsig_en0p2_spike=0;
   
   Long64_t nbytes = 0, nb = 0;

   for (int i=0; i<len; i++) {

   int nsig_total_barrel=0;
   int nbkg_total_barrel=0;

   int nsig_default_passed_barrel=0;
   int nbkg_default_passed_barrel=0;
   
   int nsig_w4p2_passed_barrel=0;
   int nbkg_w4p2_passed_barrel=0;

   int nsig_w4p1_passed_barrel=0;
   int nbkg_w4p1_passed_barrel=0;

   int nsig_w4p3_passed_barrel=0;
   int nbkg_w4p3_passed_barrel=0;
   
   int nsig_w4p4_passed_barrel=0;
   int nbkg_w4p4_passed_barrel=0;

   int nsig_per_rechit_passed_barrel=0;
   int nbkg_per_rechit_passed_barrel=0;

   int nsig_per_rechit_m1p25_passed_barrel=0;
   int nbkg_per_rechit_m1p25_passed_barrel=0;

   int nsig_per_rechit_m1p8_passed_barrel=0;
   int nbkg_per_rechit_m1p8_passed_barrel=0;

   int nsig_per_rechit_m1p5_passed_barrel=0;
   int nbkg_per_rechit_m1p5_passed_barrel=0;

   int nsig_w4p0_passed_barrel=0;
   int nbkg_w4p0_passed_barrel=0;

   int nsig_en0p15_passed_barrel=0;
   int nbkg_en0p15_passed_barrel=0;

   int nsig_en0p15_noRelNoiseCut_passed_barrel=0;
   int nbkg_en0p15_noRelNoiseCut_passed_barrel=0;

   int nsig_en0p2_passed_barrel=0;
   int nbkg_en0p2_passed_barrel=0;
     
     //     std::cout << "sieie cut : " << cuts[i] << "   " ;
     
     for (Long64_t jentry=0; jentry<nentries;jentry++) {
       Long64_t ientry = LoadTree(jentry);
       if (ientry < 0) break;
       nb = fChain->GetEntry(jentry);   nbytes += nb;
       // if (Cut(ientry) < 0) continue;
       
       for(int iele=0; iele < elePt_->size(); iele++) {
	 
	 if (  ((fabs(eleScEta_->at(iele)) ) < 1.44 ) && ( elePt_->at(iele) > 70 ) && ( elePt_->at(iele) < 150 )  ) {
	   
	   if ( ele_genmatched_->at(iele)==1 ) nsig_total_barrel++;
	   if ( ele_genmatched_->at(iele)==0 ) nbkg_total_barrel++;	  
	  
	   //// default
	   if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_->at(iele)) < cuts[i]) ) nsig_default_passed_barrel++;
	   if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIetaIeta_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_->at(iele)) < cuts[i]) ) nbkg_default_passed_barrel++;
	   if ( (i==1) && (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_->at(iele)) < 0.001)  ) nsig_default_spike++;

	   //// w4p2
	   if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_w4p2_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_w4p2_->at(iele)) < cuts[i]) ) nsig_w4p2_passed_barrel++;
	   if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIetaIeta_w4p2_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_w4p2_->at(iele)) < cuts[i]) ) nbkg_w4p2_passed_barrel++;
	   if ( (i==1) && (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_w4p2_->at(iele)) < 0.001)  ) nsig_w4p2_spike++;

	   //// w4p1
	   if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_w4p1_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_w4p1_->at(iele)) < cuts[i]) ) nsig_w4p1_passed_barrel++;
	   if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIetaIeta_w4p1_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_w4p1_->at(iele)) < cuts[i]) ) nbkg_w4p1_passed_barrel++;
	   if ( (i==1) && (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_w4p1_->at(iele)) < 0.001)  ) nsig_w4p1_spike++;

	   //// w4p3
	   if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_w4p3_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_w4p3_->at(iele)) < cuts[i]) ) nsig_w4p3_passed_barrel++;
	   if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIetaIeta_w4p3_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_w4p3_->at(iele)) < cuts[i]) ) nbkg_w4p3_passed_barrel++;
	   if ( (i==1) && (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_w4p3_->at(iele)) < 0.001)  ) nsig_w4p3_spike++;


	   //// w4p4
	   if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_w4p4_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_w4p4_->at(iele)) < cuts[i]) ) nsig_w4p4_passed_barrel++;
	   if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIetaIeta_w4p4_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_w4p4_->at(iele)) < cuts[i]) ) nbkg_w4p4_passed_barrel++;
	   if ( (i==1) && (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_w4p4_->at(iele)) < 0.001)  ) nsig_w4p4_spike++;

	   //// per_rechit
	   if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_per_rechit_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_per_rechit_->at(iele)) < cuts[i]) ) nsig_per_rechit_passed_barrel++;
	   if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIetaIeta_per_rechit_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_per_rechit_->at(iele)) < cuts[i]) ) nbkg_per_rechit_passed_barrel++;
	   if ( (i==1) && (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_per_rechit_->at(iele)) < 0.001)  ) nsig_per_rechit_spike++;

	   //// per_rechit_m1p25
	   if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_per_rechit_m1p25_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_per_rechit_m1p25_->at(iele)) < cuts[i]) ) nsig_per_rechit_m1p25_passed_barrel++;
	   if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIetaIeta_per_rechit_m1p25_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_per_rechit_m1p25_->at(iele)) < cuts[i]) ) nbkg_per_rechit_m1p25_passed_barrel++;
	   if ( (i==1) && (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_per_rechit_m1p25_->at(iele)) < 0.001)  ) nsig_per_rechit_m1p25_spike++;


	   //// per_rechit_m1p8
	   if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_per_rechit_m1p8_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_per_rechit_m1p8_->at(iele)) < cuts[i]) ) nsig_per_rechit_m1p8_passed_barrel++;
	   if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIetaIeta_per_rechit_m1p8_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_per_rechit_m1p8_->at(iele)) < cuts[i]) ) nbkg_per_rechit_m1p8_passed_barrel++;
	   if ( (i==1) && (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_per_rechit_m1p8_->at(iele)) < 0.001)  ) nsig_per_rechit_m1p8_spike++;

	   //// per_rechit_m1p5
	   if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_per_rechit_m1p5_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_per_rechit_m1p5_->at(iele)) < cuts[i]) ) nsig_per_rechit_m1p5_passed_barrel++;
	   if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIetaIeta_per_rechit_m1p5_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_per_rechit_m1p5_->at(iele)) < cuts[i]) ) nbkg_per_rechit_m1p5_passed_barrel++;
	   if ( (i==1) && (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_per_rechit_m1p5_->at(iele)) < 0.001)  ) nsig_per_rechit_m1p5_spike++;


	   //// w4p0
	   if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_w4p0_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_w4p0_->at(iele)) < cuts[i]) ) nsig_w4p0_passed_barrel++;
	   if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIetaIeta_w4p0_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_w4p0_->at(iele)) < cuts[i]) ) nbkg_w4p0_passed_barrel++;
	   if ( (i==1) && (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_w4p0_->at(iele)) < 0.001)  ) nsig_w4p0_spike++;

	   //// en0p15
	   if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_en0p15_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_en0p15_->at(iele)) < cuts[i]) ) nsig_en0p15_passed_barrel++;
	   if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIetaIeta_en0p15_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_en0p15_->at(iele)) < cuts[i]) ) nbkg_en0p15_passed_barrel++;
	   if ( (i==1) && (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_en0p15_->at(iele)) < 0.001)  ) nsig_en0p15_spike++;

	   //// en0p15_noRelNoiseCut
	   if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_en0p15_noRelNoiseCut_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_en0p15_noRelNoiseCut_->at(iele)) < cuts[i]) ) nsig_en0p15_noRelNoiseCut_passed_barrel++;
	   if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIetaIeta_en0p15_noRelNoiseCut_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_en0p15_noRelNoiseCut_->at(iele)) < cuts[i]) ) nbkg_en0p15_noRelNoiseCut_passed_barrel++;
	   if ( (i==1) && (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_en0p15_noRelNoiseCut_->at(iele)) < 0.001)  ) nsig_en0p15_noRelNoiseCut_spike++;

	   //// en0p2
	   if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_en0p2_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_en0p2_->at(iele)) < cuts[i]) ) nsig_en0p2_passed_barrel++;
	   if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIetaIeta_en0p2_->at(iele)) >= 0.000) && ((my_eleSigmaIetaIeta_en0p2_->at(iele)) < cuts[i]) ) nbkg_en0p2_passed_barrel++;
	   if ( (i==1) && (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIetaIeta_en0p2_->at(iele)) < 0.001)  ) nsig_en0p2_spike++;
	   	   
	 }
       }
       
     }
     
     //std::cout << "nsig_default_total_barrel " << nsig_default_total_barrel << std::endl;
     //std::cout << "nsig_default_passed_barrel " << nsig_default_passed_barrel << std::endl;
     // std::cout << "nbkg_default_total_barrel " << nbkg_default_total_barrel << std::endl;
     //std::cout << "nbkg_default_passed_barrel " << nbkg_default_passed_barrel << std::endl;
     
     //     double sig_eff = (double)nsig_default_passed_barrel/(double)nsig_default_total_barrel;
     // double bkg_eff = (double)nbkg_default_passed_barrel/(double)nbkg_default_total_barrel;

     x_sigEff_sieie_default.push_back((double)nsig_default_passed_barrel/(double)nsig_total_barrel);
     y_bkgEff_sieie_default.push_back(1- (double)nbkg_default_passed_barrel/(double)nbkg_total_barrel);

     x_sigEff_sieie_w4p2.push_back((double)nsig_w4p2_passed_barrel/(double)nsig_total_barrel);
     y_bkgEff_sieie_w4p2.push_back(1- (double)nbkg_w4p2_passed_barrel/(double)nbkg_total_barrel);

     x_sigEff_sieie_w4p1.push_back((double)nsig_w4p1_passed_barrel/(double)nsig_total_barrel);
     y_bkgEff_sieie_w4p1.push_back(1- (double)nbkg_w4p1_passed_barrel/(double)nbkg_total_barrel);

     x_sigEff_sieie_w4p3.push_back((double)nsig_w4p3_passed_barrel/(double)nsig_total_barrel);
     y_bkgEff_sieie_w4p3.push_back(1- (double)nbkg_w4p3_passed_barrel/(double)nbkg_total_barrel);

     x_sigEff_sieie_w4p4.push_back((double)nsig_w4p4_passed_barrel/(double)nsig_total_barrel);
     y_bkgEff_sieie_w4p4.push_back(1- (double)nbkg_w4p4_passed_barrel/(double)nbkg_total_barrel);

     x_sigEff_sieie_per_rechit.push_back((double)nsig_per_rechit_passed_barrel/(double)nsig_total_barrel);
     y_bkgEff_sieie_per_rechit.push_back(1- (double)nbkg_per_rechit_passed_barrel/(double)nbkg_total_barrel);

     x_sigEff_sieie_per_rechit_m1p25.push_back((double)nsig_per_rechit_m1p25_passed_barrel/(double)nsig_total_barrel);
     y_bkgEff_sieie_per_rechit_m1p25.push_back(1- (double)nbkg_per_rechit_m1p25_passed_barrel/(double)nbkg_total_barrel);

     x_sigEff_sieie_per_rechit_m1p8.push_back((double)nsig_per_rechit_m1p8_passed_barrel/(double)nsig_total_barrel);
     y_bkgEff_sieie_per_rechit_m1p8.push_back(1- (double)nbkg_per_rechit_m1p8_passed_barrel/(double)nbkg_total_barrel);

     x_sigEff_sieie_per_rechit_m1p5.push_back((double)nsig_per_rechit_m1p5_passed_barrel/(double)nsig_total_barrel);
     y_bkgEff_sieie_per_rechit_m1p5.push_back(1- (double)nbkg_per_rechit_m1p5_passed_barrel/(double)nbkg_total_barrel);

     x_sigEff_sieie_w4p0.push_back((double)nsig_w4p0_passed_barrel/(double)nsig_total_barrel);
     y_bkgEff_sieie_w4p0.push_back(1- (double)nbkg_w4p0_passed_barrel/(double)nbkg_total_barrel);

     x_sigEff_sieie_en0p15.push_back((double)nsig_en0p15_passed_barrel/(double)nsig_total_barrel);
     y_bkgEff_sieie_en0p15.push_back(1- (double)nbkg_en0p15_passed_barrel/(double)nbkg_total_barrel);

     x_sigEff_sieie_en0p15_noRelNoiseCut.push_back((double)nsig_en0p15_noRelNoiseCut_passed_barrel/(double)nsig_total_barrel);
     y_bkgEff_sieie_en0p15_noRelNoiseCut.push_back(1- (double)nbkg_en0p15_noRelNoiseCut_passed_barrel/(double)nbkg_total_barrel);

     x_sigEff_sieie_en0p2.push_back((double)nsig_en0p2_passed_barrel/(double)nsig_total_barrel);
     y_bkgEff_sieie_en0p2.push_back(1- (double)nbkg_en0p2_passed_barrel/(double)nbkg_total_barrel);

     std::cout << "\n cut " << i << " sieie<" << cuts[i] << " sig eff / bkg rej (default)" << ((double)nsig_default_passed_barrel/(double)nsig_total_barrel) << " / " <<  (1- (double)nbkg_default_passed_barrel/(double)nbkg_total_barrel) << std::endl;

     std::cout << " cut " << i << " sieie<" << cuts[i] << " sig eff / bkg rej (perrecH)" << ((double)nsig_per_rechit_passed_barrel/(double)nsig_total_barrel) << " / " << (1- (double)nbkg_per_rechit_passed_barrel/(double)nbkg_total_barrel) << std::endl;


     if      (i==1)  {
       std::cout << " fraction of spike default " << (double)nsig_default_spike/(double)nsig_total_barrel << std::endl;
       std::cout << " fraction of w4p0 " << (double)nsig_w4p0_spike/(double)nsig_total_barrel << std::endl;
       std::cout << " fraction of w4p2 " << (double)nsig_w4p2_spike/(double)nsig_total_barrel << std::endl;
       std::cout << " fraction of w4p1 " << (double)nsig_w4p1_spike/(double)nsig_total_barrel << std::endl;
       std::cout << " fraction of w4p3 " << (double)nsig_w4p3_spike/(double)nsig_total_barrel << std::endl;
       std::cout << " fraction of w4p4 " << (double)nsig_w4p4_spike/(double)nsig_total_barrel << std::endl;
       std::cout << " fraction of per_rechit " << (double)nsig_per_rechit_spike/(double)nsig_total_barrel << std::endl;
       std::cout << " fraction of per_rechit_m1p25 " << (double)nsig_per_rechit_m1p25_spike/(double)nsig_total_barrel << std::endl;
       std::cout << " fraction of per_rechit_m1p8 " << (double)nsig_per_rechit_m1p8_spike/(double)nsig_total_barrel << std::endl;
       std::cout << " fraction of per_rechit_m1p5 " << (double)nsig_per_rechit_m1p5_spike/(double)nsig_total_barrel << std::endl;

       std::cout << " fraction of en0p15 " << (double)nsig_en0p15_spike/(double)nsig_total_barrel << std::endl;
       std::cout << " fraction of en0p15_noRelNoiseCut " << (double)nsig_en0p15_noRelNoiseCut_spike/(double)nsig_total_barrel << std::endl;
       std::cout << " fraction of en0p2 " << (double)nsig_en0p2_spike/(double)nsig_total_barrel << std::endl;

       x_cutName.push_back(0);
       y_spikeFrac.push_back((double)nsig_default_spike/(double)nsig_total_barrel);

       x_cutName.push_back(1);
       y_spikeFrac.push_back((double)nsig_w4p4_spike/(double)nsig_total_barrel);

       x_cutName.push_back(2);
       y_spikeFrac.push_back((double)nsig_w4p3_spike/(double)nsig_total_barrel);

       x_cutName.push_back(3);
       y_spikeFrac.push_back((double)nsig_w4p2_spike/(double)nsig_total_barrel);

       x_cutName.push_back(4);
       y_spikeFrac.push_back((double)nsig_w4p1_spike/(double)nsig_total_barrel);

       x_cutName.push_back(5);
       y_spikeFrac.push_back((double)nsig_w4p0_spike/(double)nsig_total_barrel);

       ////

       x_cutName_rechit.push_back(0);
       y_spikeFrac_rechit.push_back((double)nsig_default_spike/(double)nsig_total_barrel);

       x_cutName_rechit.push_back(1);
       y_spikeFrac_rechit.push_back((double)nsig_per_rechit_spike/(double)nsig_total_barrel);

       x_cutName_rechit.push_back(2);
       y_spikeFrac_rechit.push_back((double)nsig_per_rechit_m1p25_spike/(double)nsig_total_barrel);

       /////
       x_cutName_en.push_back(0);
       y_spikeFrac_en.push_back((double)nsig_default_spike/(double)nsig_total_barrel);

       x_cutName_en.push_back(1);
       y_spikeFrac_en.push_back((double)nsig_en0p15_spike/(double)nsig_total_barrel);

       x_cutName_en.push_back(2);
       y_spikeFrac_en.push_back((double)nsig_en0p15_noRelNoiseCut_spike/(double)nsig_total_barrel);

       x_cutName_en.push_back(3);
       y_spikeFrac_en.push_back((double)nsig_en0p2_spike/(double)nsig_total_barrel);

     }
    //     std::cout << "sig_eff " << sig_eff << " / bkg_eff " << bkg_eff << std::endl;
   }

   //   gStyle->SetPadLeftMargin(0.15);
   // gStyle->SetPadRightMargin(0.05);
   //  gStyle->SetPadBottomMargin(0.12);  
   // gStyle->SetPadBottomMargin(0.01);  
   // gStyle->SetPadTopMargin(0.01);   
   // gStyle->SetTitleXSize(0.04);
   // gStyle->SetTitleXOffset(1.05);
   // gStyle->SetTitleYSize(0.05);
   // gStyle->SetTitleYOffset(1.05);

   TCanvas *c1 = new TCanvas("c1","eff", 200,10,600,400);

   TGraph *gr1 = new TGraph (len, &x_sigEff_sieie_default[0], &y_bkgEff_sieie_default[0]);
   gr1->SetTitle("#sigma_{i#eta i#eta} ROC");
   gr1->SetMarkerColor(2);
   gr1->SetLineColor(2);
   gr1->SetLineWidth(2);
   gr1->SetMarkerStyle(21);
   gr1->Draw("ALP");
   gr1->GetYaxis()->SetTitle("Background Rejection");
   gr1->GetXaxis()->SetTitle("Signal Efficiency");
   gr1->GetHistogram()->SetMaximum(1.05);   // along                                                                                                        
   gr1->GetHistogram()->SetMinimum(0.0);  //   Y                                                                                                                             
   gr1->GetXaxis()->SetLimits(0.0,1.05);
   gr1->Write("default");

   TGraph *gr2 = new TGraph (len, &x_sigEff_sieie_w4p2[0], &y_bkgEff_sieie_w4p2[0]);
   gr2->SetMarkerColor(3);
   gr2->SetLineColor(3);
   gr2->SetLineWidth(2);
   gr2->SetMarkerStyle(22);
   //gr2->Draw("LP, same");
   gr2->Write("w4p2");

   TGraph *gr6 = new TGraph (len, &x_sigEff_sieie_w4p1[0], &y_bkgEff_sieie_w4p1[0]);
   gr6->SetMarkerColor(3);
   gr6->SetLineColor(3);
   gr6->SetLineWidth(2);
   gr6->SetMarkerStyle(26);
   gr6->Draw("LP, same");
   gr6->Write("w4p1");

   TGraph *gr3 = new TGraph (len, &x_sigEff_sieie_w4p3[0], &y_bkgEff_sieie_w4p3[0]);
   gr3->SetMarkerColor(4);
   gr3->SetLineColor(4);
   gr3->SetLineWidth(2);
   gr3->SetMarkerStyle(23);
   gr3->Draw("LP, same");
   gr3->Write("w4p3");

   TGraph *gr4 = new TGraph (len, &x_sigEff_sieie_w4p4[0], &y_bkgEff_sieie_w4p4[0]);
   gr4->SetMarkerColor(3);
   gr4->SetLineColor(3);
   gr4->SetLineWidth(2);
   gr4->SetMarkerStyle(24);
   //  gr4->Draw("LP, same");
   gr4->Write("w4p4");


   TGraph *gr5 = new TGraph (len, &x_sigEff_sieie_w4p0[0], &y_bkgEff_sieie_w4p0[0]);
   gr5->SetMarkerColor(3);
   gr5->SetLineColor(3);
   gr5->SetLineWidth(2);
   gr5->SetMarkerStyle(25);
   //gr5->Draw("LP, same");
   gr5->Write("w4p0");

   TLegend *leg_example = new TLegend(0.12,0.15,0.4,0.46);
   leg_example->SetHeader("Barrel (pT 70-150 GeV)","C"); // option "C" allows to center the header                                                                                     
   leg_example->SetFillColor(0);
   leg_example->SetTextFont(42);
   leg_example->SetBorderSize(0);
   leg_example->AddEntry(gr1, "default","pl");
   //leg_example->AddEntry(gr_pr, "per rechit","pl");
   //leg_example->AddEntry(gr_pr_m1p25, "per rechit * 1.25","pl");
   // leg_example->AddEntry(gr4, "w=4.4","pl");
   leg_example->AddEntry(gr3, "w=4.3","pl");
   //leg_example->AddEntry(gr2, "w=4.2","pl");
   leg_example->AddEntry(gr6, "w=4.1","pl");
   //leg_example->AddEntry(gr5, "w=4.0","pl");
   leg_example->Draw("same");

   //   TArrow *ar1 = new TArrow(0.0126,0.3,0.0126,1.01);
   // ar1->SetLineColor(kRed);
   // ar1->Draw("same");

   c1->SetGrid();
   c1->SaveAs("BarrelROC_sieie_relative_pt_70_150.png");

   ////
   //swagata // new // per-rechit
   TCanvas *c1_new_pr = new TCanvas("c1_new_pr","eff", 200,10,600,400);

   //   TGraph *gr1 = new TGraph (len, &x_sigEff_sieie_default[0], &y_bkgEff_sieie_default[0]);
   //  gr1->SetTitle("#sigma_{i#eta i#eta} ROC");
   // gr1->SetMarkerColor(2);
   // gr1->SetLineColor(2);
   // gr1->SetLineWidth(2);
   // gr1->SetMarkerStyle(21);
   gr1->Draw("ALP");
   // gr1->GetYaxis()->SetTitle("Background Rejection");
   // gr1->GetXaxis()->SetTitle("Signal Efficiency");
   // gr1->GetHistogram()->SetMaximum(1.05);   // along                                                                                                                
   // gr1->GetHistogram()->SetMinimum(0.0);  //   Y                                                                                                                             
   // gr1->GetXaxis()->SetLimits(0.0,1.05);
   //  gr1->Write("default");

   TGraph *gr_pr = new TGraph (len, &x_sigEff_sieie_per_rechit[0], &y_bkgEff_sieie_per_rechit[0]);
   gr_pr->SetMarkerColor(3);
   gr_pr->SetLineColor(3);
   gr_pr->SetLineWidth(2);
   gr_pr->SetMarkerStyle(24);
   gr_pr->Draw("LP, same");
   gr_pr->Write("per_rechit");

   TGraph *gr_pr_m1p25 = new TGraph (len, &x_sigEff_sieie_per_rechit_m1p25[0], &y_bkgEff_sieie_per_rechit_m1p25[0]);
   gr_pr_m1p25->SetMarkerColor(4);
   gr_pr_m1p25->SetLineColor(4);
   gr_pr_m1p25->SetLineWidth(2);
   gr_pr_m1p25->SetMarkerStyle(28);
   gr_pr_m1p25->Draw("LP, same");
   gr_pr_m1p25->Write("per_rechit_m1p25");


   TGraph *gr_pr_m1p8 = new TGraph (len, &x_sigEff_sieie_per_rechit_m1p8[0], &y_bkgEff_sieie_per_rechit_m1p8[0]);
   gr_pr_m1p8->SetMarkerColor(7);
   gr_pr_m1p8->SetLineColor(7);
   gr_pr_m1p8->SetLineWidth(2);
   gr_pr_m1p8->SetMarkerStyle(29);
   gr_pr_m1p8->Draw("LP, same");
   gr_pr_m1p8->Write("per_rechit_m1p8");

   TGraph *gr_pr_m1p5 = new TGraph (len, &x_sigEff_sieie_per_rechit_m1p5[0], &y_bkgEff_sieie_per_rechit_m1p5[0]);
   gr_pr_m1p5->SetMarkerColor(6);
   gr_pr_m1p5->SetLineColor(6);
   gr_pr_m1p5->SetLineWidth(2);
   gr_pr_m1p5->SetMarkerStyle(24);
   gr_pr_m1p5->Draw("LP, same");
   gr_pr_m1p5->Write("per_rechit_m1p5");

   TLegend *leg_example_new_pr = new TLegend(0.12,0.15,0.4,0.46);
   leg_example_new_pr->SetHeader("Barrel (pT 70-150 GeV)","C"); // option "C" allows to center the header                                                                                     
   leg_example_new_pr->SetFillColor(0);
   leg_example_new_pr->SetTextFont(42);
   leg_example_new_pr->SetBorderSize(0);
   leg_example_new_pr->AddEntry(gr1, "default","pl");
   leg_example_new_pr->AddEntry(gr_pr, "per rechit","pl");
   leg_example_new_pr->AddEntry(gr_pr_m1p25, "per rechit*1.25","pl");
   leg_example_new_pr->AddEntry(gr_pr_m1p8, "per rechit*1.8","pl");
   leg_example_new_pr->AddEntry(gr_pr_m1p5, "per rechit*1.5","pl");
   // leg_example_new_pr->AddEntry(gr4, "w=4.4","pl");
   //   leg_example_new_pr->AddEntry(gr3, "w=4.3","pl");
   //leg_example_new_pr->AddEntry(gr2, "w=4.2","pl");
   //  leg_example_new_pr->AddEntry(gr6, "w=4.1","pl");
   //leg_example_new_pr->AddEntry(gr5, "w=4.0","pl");
   leg_example_new_pr->Draw("same");

   c1_new_pr->SetGrid();
   c1_new_pr->SaveAs("Barrel_whereROCdegrades_sieie_per_rechit_pt_70_150.png");


   ///end new /// swagata

   /////
   TCanvas *c2 = new TCanvas("c2","spikeFrac", 200,10,600,400);

   TGraph *gg1 = new TGraph (x_cutName.size(), &x_cutName[0], &y_spikeFrac[0]);
   gg1->SetTitle("Fraction of events with #sigma_{i#eta i#eta} < 0.001 in signal");
   gg1->SetMarkerColor(2);
   gg1->SetLineColor(2);
   gg1->SetLineWidth(2);
   gg1->SetMarkerStyle(21);
   gg1->Draw("ALP");
   gg1->GetXaxis()->SetTitle("Cut Name");
   gg1->GetYaxis()->SetTitle("Spike fraction");
   gg1->Write("spikeFrac");

   TLegend *leg_example2 = new TLegend(0.2,0.16,0.42,0.5);
   leg_example2->SetHeader("Barrel Sieie","C"); // option "C" allows to center the header                                                            
   leg_example2->AddEntry((TObject*)0, "Bin 0: default", "");
   leg_example2->AddEntry((TObject*)0, "Bin 1: w=4.4", "");
   leg_example2->AddEntry((TObject*)0, "Bin 2: w=4.3", "");
   leg_example2->AddEntry((TObject*)0, "Bin 3: w=4.2", "");
   leg_example2->AddEntry((TObject*)0, "Bin 5: w=4.1", "");
   leg_example2->AddEntry((TObject*)0, "Bin 5: w=4.0", "");

   leg_example2->SetFillColor(0);
   leg_example2->SetTextFont(42);
   leg_example2->SetBorderSize(0);
   //   leg_example->AddEntry(gr1, "default","pl");
   // leg_example->AddEntry(gr4, "w=4.4","pl");
   //  leg_example->AddEntry(gr3, "w=4.3","pl");
   // leg_example->AddEntry(gr2, "w=4.2","pl");
   // leg_example->AddEntry(gr5, "w=4.0","pl");
   leg_example2->Draw("same");


   c2->SetGrid();
   c2->SaveAs("spike_pt_70_150.png");

   ///en
   TCanvas *c3 = new TCanvas("c3","eff_en", 200,10,600,400);

   TGraph *ge1 = new TGraph (len, &x_sigEff_sieie_default[0], &y_bkgEff_sieie_default[0]);
   ge1->SetTitle("#sigma_{i#eta i#eta} ROC");
   ge1->SetMarkerColor(2);
   ge1->SetLineColor(2);
   ge1->SetLineWidth(2);
   ge1->SetMarkerStyle(21);
   ge1->Draw("ALP");
   ge1->GetYaxis()->SetTitle("Background Rejection");
   ge1->GetXaxis()->SetTitle("Signal Efficiency");
   ge1->GetHistogram()->SetMaximum(1.05);   // along                                                                                                                
   ge1->GetHistogram()->SetMinimum(0.0);  //   Y                                                                                                                             
   ge1->GetXaxis()->SetLimits(0.0,1.05);

   TGraph *ge2 = new TGraph (len, &x_sigEff_sieie_en0p15[0], &y_bkgEff_sieie_en0p15[0]);
   ge2->SetMarkerColor(3);
   ge2->SetLineColor(3);
   ge2->SetLineWidth(2);
   ge2->SetMarkerStyle(22);
   ge2->Draw("LP, same");
   ge2->Write("en0p15");

   TGraph *ge4 = new TGraph (len, &x_sigEff_sieie_en0p15_noRelNoiseCut[0], &y_bkgEff_sieie_en0p15_noRelNoiseCut[0]);
   ge4->SetMarkerColor(6);
   ge4->SetLineColor(6);
   ge4->SetLineWidth(2);
   ge4->SetMarkerStyle(24);
   //  ge4->Draw("LP, same");
   ge4->Write("en0p15_noRelNoise");

   TGraph *ge3 = new TGraph (len, &x_sigEff_sieie_en0p2[0], &y_bkgEff_sieie_en0p2[0]);
   ge3->SetMarkerColor(4);
   ge3->SetLineColor(4);
   ge3->SetLineWidth(2);
   ge3->SetMarkerStyle(23);
   ge3->Draw("LP, same");
   ge3->Write("en0p2");

   TLegend *leg_example3 = new TLegend(0.12,0.15,0.4,0.46);
   leg_example3->SetHeader("Barrel Sieie (pT 70-150 GeV)","C"); // option "C" allows to center the header                                                                            
   leg_example3->SetFillColor(0);
   leg_example3->SetTextFont(42);
   leg_example3->SetBorderSize(0);
   leg_example3->AddEntry(ge1, "default","pl");
   leg_example3->AddEntry(ge2, "E>0.15 GeV","pl");
   ///   leg_example3->AddEntry(ge4, "E>0.15 GeV (no rel cut)","pl");
   leg_example3->AddEntry(ge3, "E>0.2 GeV","pl");
   leg_example3->Draw("same");

   //   TArrow *ar1 = new TArrow(0.0126,0.3,0.0126,1.01);
   // ar1->SetLineColor(kRed);
   // ar1->Draw("same");

   c3->SetGrid();
   c3->SaveAs("BarrelROC_sieie_absNoiseCut_pt_70_150.png");

   ///
   TCanvas *c21 = new TCanvas("c21","spikeFrac_absnoisecut", 200,10,600,400);

   TGraph *ggs1 = new TGraph (x_cutName_en.size(), &x_cutName_en[0], &y_spikeFrac_en[0]);
   ggs1->SetTitle("Fraction of events with #sigma_{i#eta i#eta} < 0.001 in signal");
   ggs1->SetMarkerColor(2);
   ggs1->SetLineColor(2);
   ggs1->SetLineWidth(2);
   ggs1->SetMarkerStyle(21);
   ggs1->Draw("ALP");
   ggs1->GetXaxis()->SetTitle("Cut Name");
   ggs1->GetYaxis()->SetTitle("Spike fraction");
   ggs1->Write("spikeFrac_absnoisecut");

   TLegend *leg_example21 = new TLegend(0.2,0.6,0.5,0.9);
   leg_example21->SetHeader("Barrel Sieie (pT 70-150 GeV)","C"); // option "C" allows to center the header                                          
   leg_example21->AddEntry((TObject*)0, "Bin 0: default", "");
   leg_example21->AddEntry((TObject*)0, "Bin 1: E>0.15 GeV", "");
   leg_example21->AddEntry((TObject*)0, "Bin 2: E>0.15 GeV (no abs cut)", "");
   leg_example21->AddEntry((TObject*)0, "Bin 3: E>0.2 GeV", "");
   // leg_example21->AddEntry((TObject*)0, "Bin 2: w=4.3", "");
   // leg_example21->AddEntry((TObject*)0, "Bin 3: w=4.2", "");
   // leg_example21->AddEntry((TObject*)0, "Bin 4: w=4.0", "");

   leg_example21->SetFillColor(0);
   leg_example21->SetTextFont(42);
   leg_example21->SetBorderSize(0);
   leg_example21->Draw("same");


   c21->SetGrid();
   c21->SaveAs("spike_absnoisecut_pt_70_150.png");


   ////

   ///
   TCanvas *c21_rechit = new TCanvas("c21_rechit","spikeFrac_per_rechit_cut", 200,10,600,400);

   TGraph *g_recHit = new TGraph (x_cutName_rechit.size(), &x_cutName_rechit[0], &y_spikeFrac_rechit[0]);
   g_recHit->SetTitle("Fraction of events with #sigma_{i#eta i#eta} < 0.001 in signal");
   g_recHit->SetMarkerColor(2);
   g_recHit->SetLineColor(2);
   g_recHit->SetLineWidth(2);
   g_recHit->SetMarkerStyle(21);
   g_recHit->Draw("ALP");
   g_recHit->GetXaxis()->SetTitle("Cut Name");
   g_recHit->GetYaxis()->SetTitle("fraction");
   g_recHit->Write("spikeFrac_absnoisecut");

   TLegend *leg_rechit = new TLegend(0.2,0.6,0.5,0.9);
   leg_rechit->SetHeader("Barrel Sieie","C"); // option "C" allows to center the header                                                            
   leg_rechit->AddEntry((TObject*)0, "Bin 0: default", "");
   leg_rechit->AddEntry((TObject*)0, "Bin 1: per rechit", "");
   leg_rechit->AddEntry((TObject*)0, "Bin 2: per rechit * 1.25", "");
   //   leg_rechit->AddEntry((TObject*)0, "Bin 2: E>0.15 GeV (no abs cut)", "");
   // leg_rechit->AddEntry((TObject*)0, "Bin 3: E>0.2 GeV", "");
   // leg_rechit->AddEntry((TObject*)0, "Bin 2: w=4.3", "");
   // leg_rechit->AddEntry((TObject*)0, "Bin 3: w=4.2", "");
   // leg_rechit->AddEntry((TObject*)0, "Bin 4: w=4.0", "");

   leg_rechit->SetFillColor(0);
   leg_rechit->SetTextFont(42);
   leg_rechit->SetBorderSize(0);
   leg_rechit->Draw("same");


   c21_rechit->SetGrid();
   c21_rechit->SaveAs("spike_per_rechit_cut_pt_70_150.png");




}


