#define pileup_cxx
#include "pileup.h"
#include <TH2.h>
#include <TH1.h>
#include <TH1D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include "TROOT.h"
#include <TProfile.h>


void pileup::Loop()
{
//   In a ROOT session, you can do:
//      root> .L pileup.C
//      root> pileup t
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

  TFile* outputFile = new TFile("Out_redefhists_2024_pileup.root","RECREATE");

  //  Float_t ptbins[] = { 0,5,10,15,20,25,30,35,40,45,50,70,90,200 };
  // Int_t  binnum = sizeof(ptbins)/sizeof(Float_t) - 1; // or just the number
  //  TProfile* prof_my_eleSigmaIetaIeta_signal_barrel_vs_pt = new TProfile("prof_my_sieie_signal_barrel_vs_pt","my_sieie_signal_barrel_vs_pt", binnum, ptbins,0,0.15);

  //  TProfile* prof_cmssw_eleSigmaIetaIeta_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_signal_barrel_vs_PU","cmssw_sieie_signal_barrel_vs_PU", 120,0,120,0,0.15);
  //  TH2F* h2D_cmssw_eleSigmaIetaIeta_signal_barrel_vs_PU = new TH2F("h2D_cmssw_sieie_signal_barrel_vs_PU","h2D_cmssw_sieie_signal_barrel_vs_PU", 10,55,75,150,0,0.15);

  //barrel
  TH1F* cmssw_eleSigmaIetaIeta_signal_barrel_PU_55_60 = new TH1F("cmssw_sieie_signal_barrel_vs_PU_1","cmssw_sieie_signal_barrel_vs_PU_1", 100,0,0.5);
  TH1F* cmssw_eleSigmaIetaIeta_signal_barrel_PU_60_65 = new TH1F("cmssw_sieie_signal_barrel_vs_PU_2","cmssw_sieie_signal_barrel_vs_PU_2", 100,0,0.5);
  TH1F* cmssw_eleSigmaIetaIeta_signal_barrel_PU_65_70 = new TH1F("cmssw_sieie_signal_barrel_vs_PU_3","cmssw_sieie_signal_barrel_vs_PU_3", 100,0,0.5);
  TH1F* cmssw_eleSigmaIetaIeta_signal_barrel_PU_70_75 = new TH1F("cmssw_sieie_signal_barrel_vs_PU_4","cmssw_sieie_signal_barrel_vs_PU_4", 100,0,0.5);

  //my_eleSigmaIetaIeta_w4p1_
  TH1F* my_eleSigmaIetaIeta_w4p1_signal_barrel_PU_55_60 = new TH1F("my_sieie_w4p1_signal_barrel_vs_PU_1","my_sieie_w4p1_signal_barrel_vs_PU_1", 100,0,0.5);
  TH1F* my_eleSigmaIetaIeta_w4p1_signal_barrel_PU_60_65 = new TH1F("my_sieie_w4p1_signal_barrel_vs_PU_2","my_sieie_w4p1_signal_barrel_vs_PU_2", 100,0,0.5);
  TH1F* my_eleSigmaIetaIeta_w4p1_signal_barrel_PU_65_70 = new TH1F("my_sieie_w4p1_signal_barrel_vs_PU_3","my_sieie_w4p1_signal_barrel_vs_PU_3", 100,0,0.5);
  TH1F* my_eleSigmaIetaIeta_w4p1_signal_barrel_PU_70_75 = new TH1F("my_sieie_w4p1_signal_barrel_vs_PU_4","my_sieie_w4p1_signal_barrel_vs_PU_4", 100,0,0.5);

  //my_eleSigmaIetaIeta_per_rechit_m1p25_
  TH1F* my_eleSigmaIetaIeta_per_rechit_m1p25_signal_barrel_PU_55_60 = new TH1F("my_sieie_per_rechit_m1p25_signal_barrel_vs_PU_1","my_sieie_per_rechit_m1p25_signal_barrel_vs_PU_1", 100,0,0.5);
  TH1F* my_eleSigmaIetaIeta_per_rechit_m1p25_signal_barrel_PU_60_65 = new TH1F("my_sieie_per_rechit_m1p25_signal_barrel_vs_PU_2","my_sieie_per_rechit_m1p25_signal_barrel_vs_PU_2", 100,0,0.5);
  TH1F* my_eleSigmaIetaIeta_per_rechit_m1p25_signal_barrel_PU_65_70 = new TH1F("my_sieie_per_rechit_m1p25_signal_barrel_vs_PU_3","my_sieie_per_rechit_m1p25_signal_barrel_vs_PU_3", 100,0,0.5);
  TH1F* my_eleSigmaIetaIeta_per_rechit_m1p25_signal_barrel_PU_70_75 = new TH1F("my_sieie_per_rechit_m1p25_signal_barrel_vs_PU_4","my_sieie_per_rechit_m1p25_signal_barrel_vs_PU_4", 100,0,0.5);

  //endcap
  TH1F* cmssw_eleSigmaIetaIeta_signal_endcap_PU_55_60 = new TH1F("cmssw_sieie_signal_endcap_vs_PU_1","cmssw_sieie_signal_endcap_vs_PU_1", 100,0,0.5);
  TH1F* cmssw_eleSigmaIetaIeta_signal_endcap_PU_60_65 = new TH1F("cmssw_sieie_signal_endcap_vs_PU_2","cmssw_sieie_signal_endcap_vs_PU_2", 100,0,0.5);
  TH1F* cmssw_eleSigmaIetaIeta_signal_endcap_PU_65_70 = new TH1F("cmssw_sieie_signal_endcap_vs_PU_3","cmssw_sieie_signal_endcap_vs_PU_3", 100,0,0.5);
  TH1F* cmssw_eleSigmaIetaIeta_signal_endcap_PU_70_75 = new TH1F("cmssw_sieie_signal_endcap_vs_PU_4","cmssw_sieie_signal_endcap_vs_PU_4", 100,0,0.5);

  //my_eleSigmaIetaIeta_w3p2_
  TH1F* my_eleSigmaIetaIeta_w3p2_signal_endcap_PU_55_60 = new TH1F("my_sieie_w3p2_signal_endcap_vs_PU_1","my_sieie_w3p2_signal_endcap_vs_PU_1", 100,0,0.5);
  TH1F* my_eleSigmaIetaIeta_w3p2_signal_endcap_PU_60_65 = new TH1F("my_sieie_w3p2_signal_endcap_vs_PU_2","my_sieie_w3p2_signal_endcap_vs_PU_2", 100,0,0.5);
  TH1F* my_eleSigmaIetaIeta_w3p2_signal_endcap_PU_65_70 = new TH1F("my_sieie_w3p2_signal_endcap_vs_PU_3","my_sieie_w3p2_signal_endcap_vs_PU_3", 100,0,0.5);
  TH1F* my_eleSigmaIetaIeta_w3p2_signal_endcap_PU_70_75 = new TH1F("my_sieie_w3p2_signal_endcap_vs_PU_4","my_sieie_w3p2_signal_endcap_vs_PU_4", 100,0,0.5);

  TH1F* my_eleSigmaIetaIeta_per_rechit_m1p25_signal_endcap_PU_55_60 = new TH1F("my_sieie_per_rechit_m1p25_signal_endcap_vs_PU_1","my_sieie_per_rechit_m1p25_signal_endcap_vs_PU_1", 100,0,0.5);
  TH1F* my_eleSigmaIetaIeta_per_rechit_m1p25_signal_endcap_PU_60_65 = new TH1F("my_sieie_per_rechit_m1p25_signal_endcap_vs_PU_2","my_sieie_per_rechit_m1p25_signal_endcap_vs_PU_2", 100,0,0.5);
  TH1F* my_eleSigmaIetaIeta_per_rechit_m1p25_signal_endcap_PU_65_70 = new TH1F("my_sieie_per_rechit_m1p25_signal_endcap_vs_PU_3","my_sieie_per_rechit_m1p25_signal_endcap_vs_PU_3", 100,0,0.5);
  TH1F* my_eleSigmaIetaIeta_per_rechit_m1p25_signal_endcap_PU_70_75 = new TH1F("my_sieie_per_rechit_m1p25_signal_endcap_vs_PU_4","my_sieie_per_rechit_m1p25_signal_endcap_vs_PU_4", 100,0,0.5);

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      for(int iele=0; iele < elePt_->size(); iele++) {

	// signal | barrel
	if (ele_genmatched_->at(iele)==1 && fabs(eleScEta_->at(iele))<1.44  && (elePt_->at(iele)>0) ) {
	  //	  h2D_cmssw_eleSigmaIetaIeta_signal_barrel_vs_PU->Fill(puTrue_->at(iele),cmssw_eleSigmaIetaIeta_->at(iele) );
	  if ( (puTrue_->at(0)>=55) && (puTrue_->at(0)<60) ) cmssw_eleSigmaIetaIeta_signal_barrel_PU_55_60->Fill(cmssw_eleSigmaIetaIeta_->at(iele));
	  if ( (puTrue_->at(0)>=60) && (puTrue_->at(0)<65) ) cmssw_eleSigmaIetaIeta_signal_barrel_PU_60_65->Fill(cmssw_eleSigmaIetaIeta_->at(iele));
	  if ( (puTrue_->at(0)>=65) && (puTrue_->at(0)<70) ) cmssw_eleSigmaIetaIeta_signal_barrel_PU_65_70->Fill(cmssw_eleSigmaIetaIeta_->at(iele));
	  if ( (puTrue_->at(0)>=70) && (puTrue_->at(0)<75) ) cmssw_eleSigmaIetaIeta_signal_barrel_PU_70_75->Fill(cmssw_eleSigmaIetaIeta_->at(iele));

	  //
	  if ( (puTrue_->at(0)>=55) && (puTrue_->at(0)<60) ) my_eleSigmaIetaIeta_w4p1_signal_barrel_PU_55_60->Fill(my_eleSigmaIetaIeta_w4p1_->at(iele));
	  if ( (puTrue_->at(0)>=60) && (puTrue_->at(0)<65) ) my_eleSigmaIetaIeta_w4p1_signal_barrel_PU_60_65->Fill(my_eleSigmaIetaIeta_w4p1_->at(iele));
	  if ( (puTrue_->at(0)>=65) && (puTrue_->at(0)<70) ) my_eleSigmaIetaIeta_w4p1_signal_barrel_PU_65_70->Fill(my_eleSigmaIetaIeta_w4p1_->at(iele));
	  if ( (puTrue_->at(0)>=70) && (puTrue_->at(0)<75) ) my_eleSigmaIetaIeta_w4p1_signal_barrel_PU_70_75->Fill(my_eleSigmaIetaIeta_w4p1_->at(iele));

	  if ( (puTrue_->at(0)>=55) && (puTrue_->at(0)<60) ) my_eleSigmaIetaIeta_per_rechit_m1p25_signal_barrel_PU_55_60->Fill(my_eleSigmaIetaIeta_per_rechit_m1p25_->at(iele));
	  if ( (puTrue_->at(0)>=60) && (puTrue_->at(0)<65) ) my_eleSigmaIetaIeta_per_rechit_m1p25_signal_barrel_PU_60_65->Fill(my_eleSigmaIetaIeta_per_rechit_m1p25_->at(iele));
	  if ( (puTrue_->at(0)>=65) && (puTrue_->at(0)<70) ) my_eleSigmaIetaIeta_per_rechit_m1p25_signal_barrel_PU_65_70->Fill(my_eleSigmaIetaIeta_per_rechit_m1p25_->at(iele));
	  if ( (puTrue_->at(0)>=70) && (puTrue_->at(0)<75) ) my_eleSigmaIetaIeta_per_rechit_m1p25_signal_barrel_PU_70_75->Fill(my_eleSigmaIetaIeta_per_rechit_m1p25_->at(iele));

	}

	// signal | endcap
	if (ele_genmatched_->at(iele)==1 && fabs(eleScEta_->at(iele))>1.56  && (elePt_->at(iele)>0) ) {
	  //	  h2D_cmssw_eleSigmaIetaIeta_signal_endcap_vs_PU->Fill(puTrue_->at(iele),cmssw_eleSigmaIetaIeta_->at(iele) );
	  if ( (puTrue_->at(0)>=55) && (puTrue_->at(0)<60) ) cmssw_eleSigmaIetaIeta_signal_endcap_PU_55_60->Fill(cmssw_eleSigmaIetaIeta_->at(iele));
	  if ( (puTrue_->at(0)>=60) && (puTrue_->at(0)<65) ) cmssw_eleSigmaIetaIeta_signal_endcap_PU_60_65->Fill(cmssw_eleSigmaIetaIeta_->at(iele));
	  if ( (puTrue_->at(0)>=65) && (puTrue_->at(0)<70) ) cmssw_eleSigmaIetaIeta_signal_endcap_PU_65_70->Fill(cmssw_eleSigmaIetaIeta_->at(iele));
	  if ( (puTrue_->at(0)>=70) && (puTrue_->at(0)<75) ) cmssw_eleSigmaIetaIeta_signal_endcap_PU_70_75->Fill(cmssw_eleSigmaIetaIeta_->at(iele));

	  //
	  if ( (puTrue_->at(0)>=55) && (puTrue_->at(0)<60) ) my_eleSigmaIetaIeta_w3p2_signal_endcap_PU_55_60->Fill(my_eleSigmaIetaIeta_w3p2_->at(iele));
	  if ( (puTrue_->at(0)>=60) && (puTrue_->at(0)<65) ) my_eleSigmaIetaIeta_w3p2_signal_endcap_PU_60_65->Fill(my_eleSigmaIetaIeta_w3p2_->at(iele));
	  if ( (puTrue_->at(0)>=65) && (puTrue_->at(0)<70) ) my_eleSigmaIetaIeta_w3p2_signal_endcap_PU_65_70->Fill(my_eleSigmaIetaIeta_w3p2_->at(iele));
	  if ( (puTrue_->at(0)>=70) && (puTrue_->at(0)<75) ) my_eleSigmaIetaIeta_w3p2_signal_endcap_PU_70_75->Fill(my_eleSigmaIetaIeta_w3p2_->at(iele));

	  if ( (puTrue_->at(0)>=55) && (puTrue_->at(0)<60) ) my_eleSigmaIetaIeta_per_rechit_m1p25_signal_endcap_PU_55_60->Fill(my_eleSigmaIetaIeta_per_rechit_m1p25_->at(iele));
	  if ( (puTrue_->at(0)>=60) && (puTrue_->at(0)<65) ) my_eleSigmaIetaIeta_per_rechit_m1p25_signal_endcap_PU_60_65->Fill(my_eleSigmaIetaIeta_per_rechit_m1p25_->at(iele));
	  if ( (puTrue_->at(0)>=65) && (puTrue_->at(0)<70) ) my_eleSigmaIetaIeta_per_rechit_m1p25_signal_endcap_PU_65_70->Fill(my_eleSigmaIetaIeta_per_rechit_m1p25_->at(iele));
	  if ( (puTrue_->at(0)>=70) && (puTrue_->at(0)<75) ) my_eleSigmaIetaIeta_per_rechit_m1p25_signal_endcap_PU_70_75->Fill(my_eleSigmaIetaIeta_per_rechit_m1p25_->at(iele));

	}
      }
   }

   cmssw_eleSigmaIetaIeta_signal_barrel_PU_55_60->Write();
   cmssw_eleSigmaIetaIeta_signal_barrel_PU_60_65->Write();
   cmssw_eleSigmaIetaIeta_signal_barrel_PU_65_70->Write();
   cmssw_eleSigmaIetaIeta_signal_barrel_PU_70_75->Write();

   my_eleSigmaIetaIeta_w4p1_signal_barrel_PU_55_60->Write();
   my_eleSigmaIetaIeta_w4p1_signal_barrel_PU_60_65->Write();
   my_eleSigmaIetaIeta_w4p1_signal_barrel_PU_65_70->Write();
   my_eleSigmaIetaIeta_w4p1_signal_barrel_PU_70_75->Write();

   my_eleSigmaIetaIeta_per_rechit_m1p25_signal_barrel_PU_55_60->Write();
   my_eleSigmaIetaIeta_per_rechit_m1p25_signal_barrel_PU_60_65->Write();
   my_eleSigmaIetaIeta_per_rechit_m1p25_signal_barrel_PU_65_70->Write();
   my_eleSigmaIetaIeta_per_rechit_m1p25_signal_barrel_PU_70_75->Write();

   cmssw_eleSigmaIetaIeta_signal_endcap_PU_55_60->Write();
   cmssw_eleSigmaIetaIeta_signal_endcap_PU_60_65->Write();
   cmssw_eleSigmaIetaIeta_signal_endcap_PU_65_70->Write();
   cmssw_eleSigmaIetaIeta_signal_endcap_PU_70_75->Write();

   my_eleSigmaIetaIeta_w3p2_signal_endcap_PU_55_60->Write();
   my_eleSigmaIetaIeta_w3p2_signal_endcap_PU_60_65->Write();
   my_eleSigmaIetaIeta_w3p2_signal_endcap_PU_65_70->Write();
   my_eleSigmaIetaIeta_w3p2_signal_endcap_PU_70_75->Write();

   my_eleSigmaIetaIeta_per_rechit_m1p25_signal_endcap_PU_55_60->Write();
   my_eleSigmaIetaIeta_per_rechit_m1p25_signal_endcap_PU_60_65->Write();
   my_eleSigmaIetaIeta_per_rechit_m1p25_signal_endcap_PU_65_70->Write();
   my_eleSigmaIetaIeta_per_rechit_m1p25_signal_endcap_PU_70_75->Write();

 
}
