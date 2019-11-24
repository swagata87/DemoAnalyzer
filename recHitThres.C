#define recHitThres_cxx
#include "recHitThres.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include "TROOT.h"
#include <TProfile.h>
#include <TH1.h>
#include <TH1D.h>

void recHitThres::Loop()
{
//   In a ROOT session, you can do:
//      root> .L recHitThres.C
//      root> recHitThres t
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
   if (fChain == 0) return;

   TFile* outputFile = new TFile("crysThres_2018.root","RECREATE");

   TProfile* prof_crys_thres_vs_eta = new TProfile("profile_crys_thres_vs_eta","profile_crys_thres_vs_eta", 60,-3,3,0,100);
   TProfile* prof_crys_thres_vs_phi = new TProfile("profile_crys_thres_vs_phi","profile_crys_thres_vs_phi", 50,-5,5,0,100);

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      for(int icrys=0; icrys < crysEta_->size(); icrys++) {
	//	prof_my_eleSigmaIetaIeta_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_->at(iele) );
	prof_crys_thres_vs_eta->Fill( crysEta_->at(icrys),  crysThr_->at(icrys) );
	prof_crys_thres_vs_phi->Fill( crysPhi_->at(icrys),  crysThr_->at(icrys) );

      }

   }

   prof_crys_thres_vs_eta->Write();
   prof_crys_thres_vs_phi->Write();

}
