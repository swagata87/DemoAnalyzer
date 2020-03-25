#define localCovPhiPhi_EE_cxx
#include "localCovPhiPhi_EE.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <algorithm>
#include "TLatex.h"
#include "TROOT.h"
#include <iomanip>
#include "TObjArray.h"
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
void localCovPhiPhi_EE::Loop()
{
//   In a ROOT session, you can do:
//      root> .L localCovPhiPhi_EE.C
//      root> localCovPhiPhi_EE t
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


  TFile* outputFile = new TFile("my_sigma_iphi_iphi_ROC_2024.root","RECREATE");
  outputFile->cd();
  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntriesFast();

  float cuts[38] = {0.001, 0.002, 0.003 ,0.004 ,0.005, 0.006 ,0.007, 0.0075 ,0.008, 0.0085, 0.0087 ,0.0089 ,0.009, 0.0092, 0.0096, 0.0098 ,0.01, 0.011 , 0.012 , 0.013, 0.014, 0.015, 0.016 , 0.017, 0.018, 0.019 ,0.02, 0.025 ,0.03, 0.035, 0.04,0.045 ,0.05, 0.06, 0.07, 0.08, 0.09, 1};

  int len = sizeof(cuts) / sizeof(cuts[0]);
  std::cout << "len of cuts array " << len << std::endl;

  std::vector<float> x_sigEff_sipip_default;
  std::vector<float> y_bkgEff_sipip_default;

  std::vector<float> x_sigEff_sipip_w3p7;
  std::vector<float> y_bkgEff_sipip_w3p7;

  std::vector<float> x_sigEff_sipip_w3p2;
  std::vector<float> y_bkgEff_sipip_w3p2;

  std::vector<float> x_sigEff_sipip_pr;
  std::vector<float> y_bkgEff_sipip_pr;

   Long64_t nbytes = 0, nb = 0;

   for (int i=0; i<len; i++) {

     int nsig_total_endcap=0;
     int nbkg_total_endcap=0;

     int nsig_default_passed_endcap=0;
     int nbkg_default_passed_endcap=0;

     int nsig_w3p7_passed_endcap=0;
     int nbkg_w3p7_passed_endcap=0;

     int nsig_w3p2_passed_endcap=0;
     int nbkg_w3p2_passed_endcap=0;

     int nsig_pr_passed_endcap=0;
     int nbkg_pr_passed_endcap=0;
 
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      for(int iele=0; iele < elePt_->size(); iele++) {

	if (  ((fabs(eleScEta_->at(iele)) ) > 1.56 ) && ( elePt_->at(iele) > 2 ) && ( elePt_->at(iele) < 7  )  ) {

	  //	  if ( (i==0) && ( ele_genmatched_->at(iele)==1 ) ) std::cout << "sipip " << my_eleSigmaIphiIphi_->at(iele) << std::endl;

	  if ( ele_genmatched_->at(iele)==1 ) nsig_total_endcap++;
	  if ( ele_genmatched_->at(iele)==0 ) nbkg_total_endcap++;

	  //// default
	  if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIphiIphi_->at(iele)) >= 0.000) && ((my_eleSigmaIphiIphi_->at(iele)) < cuts[i]) ) nsig_default_passed_endcap++;
	  if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIphiIphi_->at(iele)) >= 0.000) && ((my_eleSigmaIphiIphi_->at(iele)) < cuts[i]) ) nbkg_default_passed_endcap++;

	  //// w3p7
	  if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIphiIphi_w3p7_->at(iele)) >= 0.000) && ((my_eleSigmaIphiIphi_w3p7_->at(iele)) < cuts[i]) ) nsig_w3p7_passed_endcap++;
	  if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIphiIphi_w3p7_->at(iele)) >= 0.000) && ((my_eleSigmaIphiIphi_w3p7_->at(iele)) < cuts[i]) ) nbkg_w3p7_passed_endcap++;

	  //// w3p2
	  if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIphiIphi_w3p2_->at(iele)) >= 0.000) && ((my_eleSigmaIphiIphi_w3p2_->at(iele)) < cuts[i]) ) nsig_w3p2_passed_endcap++;
	  if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIphiIphi_w3p2_->at(iele)) >= 0.000) && ((my_eleSigmaIphiIphi_w3p2_->at(iele)) < cuts[i]) ) nbkg_w3p2_passed_endcap++;

	  //// pr
	  if ( (ele_genmatched_->at(iele)==1) &&  ((my_eleSigmaIphiIphi_per_rechit_->at(iele)) >= 0.000) && ((my_eleSigmaIphiIphi_per_rechit_->at(iele)) < cuts[i]) ) nsig_pr_passed_endcap++;
	  if ( (ele_genmatched_->at(iele)==0) &&  ((my_eleSigmaIphiIphi_per_rechit_->at(iele)) >= 0.000) && ((my_eleSigmaIphiIphi_per_rechit_->at(iele)) < cuts[i]) ) nbkg_pr_passed_endcap++;

	}
      }
   }

   x_sigEff_sipip_default.push_back((double)nsig_default_passed_endcap/(double)nsig_total_endcap);
   y_bkgEff_sipip_default.push_back(1- (double)nbkg_default_passed_endcap/(double)nbkg_total_endcap);

   x_sigEff_sipip_w3p2.push_back((double)nsig_w3p2_passed_endcap/(double)nsig_total_endcap);
   y_bkgEff_sipip_w3p2.push_back(1- (double)nbkg_w3p2_passed_endcap/(double)nbkg_total_endcap);

   x_sigEff_sipip_w3p7.push_back((double)nsig_w3p7_passed_endcap/(double)nsig_total_endcap);
   y_bkgEff_sipip_w3p7.push_back(1- (double)nbkg_w3p7_passed_endcap/(double)nbkg_total_endcap);

   x_sigEff_sipip_pr.push_back((double)nsig_pr_passed_endcap/(double)nsig_total_endcap);
   y_bkgEff_sipip_pr.push_back(1- (double)nbkg_pr_passed_endcap/(double)nbkg_total_endcap);

   std::cout << i << " sipip cut " << cuts[i] << " sig pass / tot : " << nsig_w3p7_passed_endcap << " / " << nsig_total_endcap << std::endl; 

   }


   TCanvas *c1 = new TCanvas("c1_roc","roc", 200,10,600,400);

   TGraph *gr1 = new TGraph (len, &x_sigEff_sipip_default[0], &y_bkgEff_sipip_default[0]);
   gr1->SetTitle("#sigma_{i#phi i#phi} ROC (pT 2-7)");
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

   TGraph *gr2 = new TGraph (len, &x_sigEff_sipip_w3p2[0], &y_bkgEff_sipip_w3p2[0]);
   gr2->SetMarkerColor(3);
   gr2->SetLineColor(3);
   gr2->SetLineWidth(2);
   gr2->SetMarkerStyle(22);
   gr2->Draw("LP:same");
   gr2->Write("w3p2");

   TGraph *gr3 = new TGraph (len, &x_sigEff_sipip_w3p2[0], &y_bkgEff_sipip_w3p2[0]);
   gr3->SetMarkerColor(4);
   gr3->SetLineColor(4);
   gr3->SetLineWidth(2);
   gr3->SetMarkerStyle(23);
   //   gr3->Draw("LP:same");
   gr3->Write("w3p2");

   TGraph *gr4 = new TGraph (len, &x_sigEff_sipip_pr[0], &y_bkgEff_sipip_pr[0]);
   gr4->SetMarkerColor(4);
   gr4->SetLineColor(4);
   gr4->SetLineWidth(2);
   gr4->SetMarkerStyle(23);
   gr4->Draw("LP:same");
   gr4->Write("per_rechit");

   TLegend *leg_example = new TLegend(0.12,0.12,0.42,0.42);
   leg_example->SetHeader("Endcap Sipip (2-7 GeV)","C"); // option "C" allows to center the header                                              
   leg_example->SetFillColor(0);
   leg_example->SetTextFont(42);
   leg_example->SetBorderSize(0);
   leg_example->AddEntry(gr1, "default (w=4.7)","pl");
   leg_example->AddEntry(gr2, "w=3.2","pl");
   //   leg_example->AddEntry(gr3, "w=4.3","pl");
   leg_example->AddEntry(gr4, "per recHit","pl");
   leg_example->Draw("same");

   c1->SetGrid();
   c1->SaveAs("EndcapROC_sipip_2_7.png");

}


