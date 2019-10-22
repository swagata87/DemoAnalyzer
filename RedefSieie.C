#define RedefSieie_cxx
#include "RedefSieie.h"
#include <TH2.h>
#include <TH1.h>
#include <TH1D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include "TROOT.h"
#include <TProfile.h>


void RedefSieie::Loop()
{
//   In a ROOT session, you can do:
//      root> .L RedefSieie.C
//      root> RedefSieie t
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

  TFile* outputFile = new TFile("Out_redefhists_2018.root","RECREATE");

  //  Float_t ptbins[] = { 0,5,10,15,20,25,30,35,40,45,50,70,90,200 };
  // Int_t  binnum = sizeof(ptbins)/sizeof(Float_t) - 1; // or just the number
  //  TProfile* prof_my_eleSigmaIetaIeta_signal_barrel_vs_pt = new TProfile("prof_my_sieie_signal_barrel_vs_pt","my_sieie_signal_barrel_vs_pt", binnum, ptbins,0,0.15);

  TProfile* prof_cmssw_eleSigmaIetaIeta_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_signal_barrel_vs_pt","cmssw_sieie_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_signal_barrel_vs_pt = new TProfile("prof_my_sieie_signal_barrel_vs_pt","my_sieie_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p6_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p6_signal_barrel_vs_pt","cmssw_sieie_w4p6_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p5_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p5_signal_barrel_vs_pt","cmssw_sieie_w4p5_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p4_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p4_signal_barrel_vs_pt","cmssw_sieie_w4p4_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p3_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p3_signal_barrel_vs_pt","cmssw_sieie_w4p3_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p2_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p2_signal_barrel_vs_pt","cmssw_sieie_w4p2_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p1_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p1_signal_barrel_vs_pt","cmssw_sieie_w4p1_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p0_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p0_signal_barrel_vs_pt","cmssw_sieie_w4p0_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p5_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w3p5_signal_barrel_vs_pt","cmssw_sieie_w3p5_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p0_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w3p0_signal_barrel_vs_pt","cmssw_sieie_w3p0_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p2_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en0p2_signal_barrel_vs_pt","cmssw_sieie_en0p2_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p15_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en0p15_signal_barrel_vs_pt","cmssw_sieie_en0p15_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p5_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en0p5_signal_barrel_vs_pt","cmssw_sieie_en0p5_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en1_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en1_signal_barrel_vs_pt","cmssw_sieie_en1_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p1_0p4_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p1_0p4_signal_barrel_vs_pt","cmssw_sieie_en_0p1_0p4_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p15_0p5_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p15_0p5_signal_barrel_vs_pt","cmssw_sieie_en_0p15_0p5_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p16_0p6_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p16_0p6_signal_barrel_vs_pt","cmssw_sieie_en_0p16_0p6_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p2_1_signal_barrel_vs_pt","cmssw_sieie_en_0p2_1_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1p5_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p2_1p5_signal_barrel_vs_pt","cmssw_sieie_en_0p2_1p5_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_2_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p2_2_signal_barrel_vs_pt","cmssw_sieie_en_0p2_2_signal_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p18_0p8_signal_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p18_0p8_signal_barrel_vs_pt","cmssw_sieie_en_0p18_0p8_signal_barrel_vs_pt", 20,0,100,0,0.15);

  TProfile* prof_cmssw_eleSigmaIetaIeta_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_bkg_barrel_vs_pt","cmssw_sieie_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_bkg_barrel_vs_pt = new TProfile("prof_my_sieie_bkg_barrel_vs_pt","my_sieie_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p6_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p6_bkg_barrel_vs_pt","cmssw_sieie_w4p6_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p5_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p5_bkg_barrel_vs_pt","cmssw_sieie_w4p5_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p4_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p4_bkg_barrel_vs_pt","cmssw_sieie_w4p4_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p3_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p3_bkg_barrel_vs_pt","cmssw_sieie_w4p3_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p2_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p2_bkg_barrel_vs_pt","cmssw_sieie_w4p2_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p1_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p1_bkg_barrel_vs_pt","cmssw_sieie_w4p1_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p0_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w4p0_bkg_barrel_vs_pt","cmssw_sieie_w4p0_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p5_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w3p5_bkg_barrel_vs_pt","cmssw_sieie_w3p5_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p0_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_w3p0_bkg_barrel_vs_pt","cmssw_sieie_w3p0_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p2_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en0p2_bkg_barrel_vs_pt","cmssw_sieie_en0p2_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p15_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en0p15_bkg_barrel_vs_pt","cmssw_sieie_en0p15_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p5_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en0p5_bkg_barrel_vs_pt","cmssw_sieie_en0p5_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en1_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en1_bkg_barrel_vs_pt","cmssw_sieie_en1_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p1_0p4_bkg_barrel_vs_pt","cmssw_sieie_en_0p1_0p4_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p15_0p5_bkg_barrel_vs_pt","cmssw_sieie_en_0p15_0p5_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p16_0p6_bkg_barrel_vs_pt","cmssw_sieie_en_0p16_0p6_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p2_1_bkg_barrel_vs_pt","cmssw_sieie_en_0p2_1_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p2_1p5_bkg_barrel_vs_pt","cmssw_sieie_en_0p2_1p5_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_2_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p2_2_bkg_barrel_vs_pt","cmssw_sieie_en_0p2_2_bkg_barrel_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_barrel_vs_pt = new TProfile("prof_cmssw_sieie_en_0p18_0p8_bkg_barrel_vs_pt","cmssw_sieie_en_0p18_0p8_bkg_barrel_vs_pt", 20,0,100,0,0.15);

  TProfile* prof_cmssw_eleSigmaIetaIeta_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_signal_endcap_vs_pt","cmssw_sieie_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_signal_endcap_vs_pt = new TProfile("prof_my_sieie_signal_endcap_vs_pt","my_sieie_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p6_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p6_signal_endcap_vs_pt","cmssw_sieie_w4p6_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p5_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p5_signal_endcap_vs_pt","cmssw_sieie_w4p5_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p4_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p4_signal_endcap_vs_pt","cmssw_sieie_w4p4_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p3_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p3_signal_endcap_vs_pt","cmssw_sieie_w4p3_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p2_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p2_signal_endcap_vs_pt","cmssw_sieie_w4p2_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p1_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p1_signal_endcap_vs_pt","cmssw_sieie_w4p1_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p0_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p0_signal_endcap_vs_pt","cmssw_sieie_w4p0_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p5_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w3p5_signal_endcap_vs_pt","cmssw_sieie_w3p5_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p0_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w3p0_signal_endcap_vs_pt","cmssw_sieie_w3p0_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p2_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en0p2_signal_endcap_vs_pt","cmssw_sieie_en0p2_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p15_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en0p15_signal_endcap_vs_pt","cmssw_sieie_en0p15_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p5_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en0p5_signal_endcap_vs_pt","cmssw_sieie_en0p5_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en1_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en1_signal_endcap_vs_pt","cmssw_sieie_en1_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p1_0p4_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p1_0p4_signal_endcap_vs_pt","cmssw_sieie_en_0p1_0p4_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p15_0p5_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p15_0p5_signal_endcap_vs_pt","cmssw_sieie_en_0p15_0p5_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p16_0p6_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p16_0p6_signal_endcap_vs_pt","cmssw_sieie_en_0p16_0p6_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p2_1_signal_endcap_vs_pt","cmssw_sieie_en_0p2_1_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1p5_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p2_1p5_signal_endcap_vs_pt","cmssw_sieie_en_0p2_1p5_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_2_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p2_2_signal_endcap_vs_pt","cmssw_sieie_en_0p2_2_signal_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p18_0p8_signal_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p18_0p8_signal_endcap_vs_pt","cmssw_sieie_en_0p18_0p8_signal_endcap_vs_pt", 20,0,100,0,0.15);

  TProfile* prof_cmssw_eleSigmaIetaIeta_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_bkg_endcap_vs_pt","cmssw_sieie_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_bkg_endcap_vs_pt = new TProfile("prof_my_sieie_bkg_endcap_vs_pt","my_sieie_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p6_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p6_bkg_endcap_vs_pt","cmssw_sieie_w4p6_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p5_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p5_bkg_endcap_vs_pt","cmssw_sieie_w4p5_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p4_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p4_bkg_endcap_vs_pt","cmssw_sieie_w4p4_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p3_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p3_bkg_endcap_vs_pt","cmssw_sieie_w4p3_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p2_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p2_bkg_endcap_vs_pt","cmssw_sieie_w4p2_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p1_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p1_bkg_endcap_vs_pt","cmssw_sieie_w4p1_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p0_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w4p0_bkg_endcap_vs_pt","cmssw_sieie_w4p0_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p5_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w3p5_bkg_endcap_vs_pt","cmssw_sieie_w3p5_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p0_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_w3p0_bkg_endcap_vs_pt","cmssw_sieie_w3p0_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p2_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en0p2_bkg_endcap_vs_pt","cmssw_sieie_en0p2_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p15_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en0p15_bkg_endcap_vs_pt","cmssw_sieie_en0p15_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p5_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en0p5_bkg_endcap_vs_pt","cmssw_sieie_en0p5_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en1_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en1_bkg_endcap_vs_pt","cmssw_sieie_en1_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p1_0p4_bkg_endcap_vs_pt","cmssw_sieie_en_0p1_0p4_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p15_0p5_bkg_endcap_vs_pt","cmssw_sieie_en_0p15_0p5_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p16_0p6_bkg_endcap_vs_pt","cmssw_sieie_en_0p16_0p6_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p2_1_bkg_endcap_vs_pt","cmssw_sieie_en_0p2_1_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p2_1p5_bkg_endcap_vs_pt","cmssw_sieie_en_0p2_1p5_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_2_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p2_2_bkg_endcap_vs_pt","cmssw_sieie_en_0p2_2_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_endcap_vs_pt = new TProfile("prof_cmssw_sieie_en_0p18_0p8_bkg_endcap_vs_pt","cmssw_sieie_en_0p18_0p8_bkg_endcap_vs_pt", 20,0,100,0,0.15);
  ///
  ////PU
  TProfile* prof_cmssw_eleSigmaIetaIeta_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_signal_barrel_vs_PU","cmssw_sieie_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_signal_barrel_vs_PU = new TProfile("prof_my_sieie_signal_barrel_vs_PU","my_sieie_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p6_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p6_signal_barrel_vs_PU","cmssw_sieie_w4p6_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p5_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p5_signal_barrel_vs_PU","cmssw_sieie_w4p5_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p4_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p4_signal_barrel_vs_PU","cmssw_sieie_w4p4_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p3_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p3_signal_barrel_vs_PU","cmssw_sieie_w4p3_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p2_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p2_signal_barrel_vs_PU","cmssw_sieie_w4p2_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p1_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p1_signal_barrel_vs_PU","cmssw_sieie_w4p1_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p0_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p0_signal_barrel_vs_PU","cmssw_sieie_w4p0_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p5_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w3p5_signal_barrel_vs_PU","cmssw_sieie_w3p5_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p0_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w3p0_signal_barrel_vs_PU","cmssw_sieie_w3p0_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p2_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en0p2_signal_barrel_vs_PU","cmssw_sieie_en0p2_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p15_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en0p15_signal_barrel_vs_PU","cmssw_sieie_en0p15_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p5_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en0p5_signal_barrel_vs_PU","cmssw_sieie_en0p5_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en1_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en1_signal_barrel_vs_PU","cmssw_sieie_en1_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p1_0p4_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p1_0p4_signal_barrel_vs_PU","cmssw_sieie_en_0p1_0p4_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p15_0p5_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p15_0p5_signal_barrel_vs_PU","cmssw_sieie_en_0p15_0p5_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p16_0p6_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p16_0p6_signal_barrel_vs_PU","cmssw_sieie_en_0p16_0p6_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p2_1_signal_barrel_vs_PU","cmssw_sieie_en_0p2_1_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1p5_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p2_1p5_signal_barrel_vs_PU","cmssw_sieie_en_0p2_1p5_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_2_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p2_2_signal_barrel_vs_PU","cmssw_sieie_en_0p2_2_signal_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p18_0p8_signal_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p18_0p8_signal_barrel_vs_PU","cmssw_sieie_en_0p18_0p8_signal_barrel_vs_PU", 120,0,120,0,0.15);

  TProfile* prof_cmssw_eleSigmaIetaIeta_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_bkg_barrel_vs_PU","cmssw_sieie_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_bkg_barrel_vs_PU = new TProfile("prof_my_sieie_bkg_barrel_vs_PU","my_sieie_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p6_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p6_bkg_barrel_vs_PU","cmssw_sieie_w4p6_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p5_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p5_bkg_barrel_vs_PU","cmssw_sieie_w4p5_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p4_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p4_bkg_barrel_vs_PU","cmssw_sieie_w4p4_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p3_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p3_bkg_barrel_vs_PU","cmssw_sieie_w4p3_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p2_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p2_bkg_barrel_vs_PU","cmssw_sieie_w4p2_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p1_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p1_bkg_barrel_vs_PU","cmssw_sieie_w4p1_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p0_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w4p0_bkg_barrel_vs_PU","cmssw_sieie_w4p0_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p5_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w3p5_bkg_barrel_vs_PU","cmssw_sieie_w3p5_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p0_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_w3p0_bkg_barrel_vs_PU","cmssw_sieie_w3p0_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p2_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en0p2_bkg_barrel_vs_PU","cmssw_sieie_en0p2_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p15_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en0p15_bkg_barrel_vs_PU","cmssw_sieie_en0p15_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p5_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en0p5_bkg_barrel_vs_PU","cmssw_sieie_en0p5_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en1_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en1_bkg_barrel_vs_PU","cmssw_sieie_en1_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p1_0p4_bkg_barrel_vs_PU","cmssw_sieie_en_0p1_0p4_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p15_0p5_bkg_barrel_vs_PU","cmssw_sieie_en_0p15_0p5_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p16_0p6_bkg_barrel_vs_PU","cmssw_sieie_en_0p16_0p6_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p2_1_bkg_barrel_vs_PU","cmssw_sieie_en_0p2_1_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p2_1p5_bkg_barrel_vs_PU","cmssw_sieie_en_0p2_1p5_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_2_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p2_2_bkg_barrel_vs_PU","cmssw_sieie_en_0p2_2_bkg_barrel_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_barrel_vs_PU = new TProfile("prof_cmssw_sieie_en_0p18_0p8_bkg_barrel_vs_PU","cmssw_sieie_en_0p18_0p8_bkg_barrel_vs_PU", 120,0,120,0,0.15);

  TProfile* prof_cmssw_eleSigmaIetaIeta_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_signal_endcap_vs_PU","cmssw_sieie_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_signal_endcap_vs_PU = new TProfile("prof_my_sieie_signal_endcap_vs_PU","my_sieie_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p6_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p6_signal_endcap_vs_PU","cmssw_sieie_w4p6_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p5_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p5_signal_endcap_vs_PU","cmssw_sieie_w4p5_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p4_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p4_signal_endcap_vs_PU","cmssw_sieie_w4p4_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p3_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p3_signal_endcap_vs_PU","cmssw_sieie_w4p3_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p2_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p2_signal_endcap_vs_PU","cmssw_sieie_w4p2_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p1_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p1_signal_endcap_vs_PU","cmssw_sieie_w4p1_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p0_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p0_signal_endcap_vs_PU","cmssw_sieie_w4p0_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p5_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w3p5_signal_endcap_vs_PU","cmssw_sieie_w3p5_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p0_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w3p0_signal_endcap_vs_PU","cmssw_sieie_w3p0_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p2_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en0p2_signal_endcap_vs_PU","cmssw_sieie_en0p2_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p15_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en0p15_signal_endcap_vs_PU","cmssw_sieie_en0p15_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p5_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en0p5_signal_endcap_vs_PU","cmssw_sieie_en0p5_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en1_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en1_signal_endcap_vs_PU","cmssw_sieie_en1_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p1_0p4_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p1_0p4_signal_endcap_vs_PU","cmssw_sieie_en_0p1_0p4_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p15_0p5_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p15_0p5_signal_endcap_vs_PU","cmssw_sieie_en_0p15_0p5_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p16_0p6_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p16_0p6_signal_endcap_vs_PU","cmssw_sieie_en_0p16_0p6_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p2_1_signal_endcap_vs_PU","cmssw_sieie_en_0p2_1_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1p5_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p2_1p5_signal_endcap_vs_PU","cmssw_sieie_en_0p2_1p5_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_2_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p2_2_signal_endcap_vs_PU","cmssw_sieie_en_0p2_2_signal_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p18_0p8_signal_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p18_0p8_signal_endcap_vs_PU","cmssw_sieie_en_0p18_0p8_signal_endcap_vs_PU", 120,0,120,0,0.15);

  TProfile* prof_cmssw_eleSigmaIetaIeta_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_bkg_endcap_vs_PU","cmssw_sieie_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_bkg_endcap_vs_PU = new TProfile("prof_my_sieie_bkg_endcap_vs_PU","my_sieie_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p6_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p6_bkg_endcap_vs_PU","cmssw_sieie_w4p6_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p5_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p5_bkg_endcap_vs_PU","cmssw_sieie_w4p5_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p4_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p4_bkg_endcap_vs_PU","cmssw_sieie_w4p4_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p3_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p3_bkg_endcap_vs_PU","cmssw_sieie_w4p3_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p2_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p2_bkg_endcap_vs_PU","cmssw_sieie_w4p2_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p1_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p1_bkg_endcap_vs_PU","cmssw_sieie_w4p1_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w4p0_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w4p0_bkg_endcap_vs_PU","cmssw_sieie_w4p0_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p5_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w3p5_bkg_endcap_vs_PU","cmssw_sieie_w3p5_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_w3p0_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_w3p0_bkg_endcap_vs_PU","cmssw_sieie_w3p0_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p2_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en0p2_bkg_endcap_vs_PU","cmssw_sieie_en0p2_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p15_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en0p15_bkg_endcap_vs_PU","cmssw_sieie_en0p15_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en0p5_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en0p5_bkg_endcap_vs_PU","cmssw_sieie_en0p5_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en1_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en1_bkg_endcap_vs_PU","cmssw_sieie_en1_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p1_0p4_bkg_endcap_vs_PU","cmssw_sieie_en_0p1_0p4_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p15_0p5_bkg_endcap_vs_PU","cmssw_sieie_en_0p15_0p5_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p16_0p6_bkg_endcap_vs_PU","cmssw_sieie_en_0p16_0p6_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p2_1_bkg_endcap_vs_PU","cmssw_sieie_en_0p2_1_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p2_1p5_bkg_endcap_vs_PU","cmssw_sieie_en_0p2_1p5_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p2_2_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p2_2_bkg_endcap_vs_PU","cmssw_sieie_en_0p2_2_bkg_endcap_vs_PU", 120,0,120,0,0.15);
  TProfile* prof_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_endcap_vs_PU = new TProfile("prof_cmssw_sieie_en_0p18_0p8_bkg_endcap_vs_PU","cmssw_sieie_en_0p18_0p8_bkg_endcap_vs_PU", 120,0,120,0,0.15);

  ///

  TH1D* h1_cmssw_eleSigmaIetaIeta_signal_barrel = new TH1D("h1_cmssw_SigmaIetaIeta_signal_barrel", "cmssw_SigmaIetaIeta_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_signal_barrel", "my_SigmaIetaIeta_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p6_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p6_signal_barrel", "my_SigmaIetaIeta_w4p6_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p5_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p5_signal_barrel", "my_SigmaIetaIeta_w4p5_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p4_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p4_signal_barrel", "my_SigmaIetaIeta_w4p4_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p3_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p3_signal_barrel", "my_SigmaIetaIeta_w4p3_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p2_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p2_signal_barrel", "my_SigmaIetaIeta_w4p2_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p1_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p1_signal_barrel", "my_SigmaIetaIeta_w4p1_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p0_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p0_signal_barrel", "my_SigmaIetaIeta_w4p0_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w3p5_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_w3p5_signal_barrel", "my_SigmaIetaIeta_w3p5_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w3p0_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_w3p0_signal_barrel", "my_SigmaIetaIeta_w3p0_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en0p2_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_en0p2_signal_barrel", "my_SigmaIetaIeta_en0p2_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en0p15_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_en0p15_signal_barrel", "my_SigmaIetaIeta_en0p15_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en0p5_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_en0p5_signal_barrel", "my_SigmaIetaIeta_en0p5_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en1_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_en1_signal_barrel", "my_SigmaIetaIeta_en1_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p1_0p4_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p1_0p4_signal_barrel", "my_SigmaIetaIeta_en_0p1_0p4_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p15_0p5_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p15_0p5_signal_barrel", "my_SigmaIetaIeta_en_0p15_0p5_signal_barrel", 200, 0, 0.1); 
  TH1D* h1_my_eleSigmaIetaIeta_en_0p16_0p6_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p16_0p6_signal_barrel", "my_SigmaIetaIeta_en_0p16_0p6_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p2_1_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p2_1_signal_barrel", "my_SigmaIetaIeta_en_0p2_1_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p2_1p5_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p2_1p5_signal_barrel", "my_SigmaIetaIeta_en_0p2_1p5_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p2_2_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p2_2_signal_barrel", "my_SigmaIetaIeta_en_0p2_2_signal_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p18_0p8_signal_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p18_0p8_signal_barrel", "my_SigmaIetaIeta_en_0p18_0p8_signal_barrel", 200, 0, 0.1);

  TH1D* h1_cmssw_eleSigmaIetaIeta_signal_endcap = new TH1D("h1_cmssw_SigmaIetaIeta_signal_endcap", "cmssw_SigmaIetaIeta_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_signal_endcap", "my_SigmaIetaIeta_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p6_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p6_signal_endcap", "my_SigmaIetaIeta_w4p6_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p5_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p5_signal_endcap", "my_SigmaIetaIeta_w4p5_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p4_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p4_signal_endcap", "my_SigmaIetaIeta_w4p4_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p3_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p3_signal_endcap", "my_SigmaIetaIeta_w4p3_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p2_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p2_signal_endcap", "my_SigmaIetaIeta_w4p2_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p1_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p1_signal_endcap", "my_SigmaIetaIeta_w4p1_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p0_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p0_signal_endcap", "my_SigmaIetaIeta_w4p0_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w3p5_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_w3p5_signal_endcap", "my_SigmaIetaIeta_w3p5_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w3p0_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_w3p0_signal_endcap", "my_SigmaIetaIeta_w3p0_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en0p2_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_en0p2_signal_endcap", "my_SigmaIetaIeta_en0p2_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en0p15_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_en0p15_signal_endcap", "my_SigmaIetaIeta_en0p15_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en0p5_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_en0p5_signal_endcap", "my_SigmaIetaIeta_en0p5_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en1_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_en1_signal_endcap", "my_SigmaIetaIeta_en1_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p1_0p4_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p1_0p4_signal_endcap", "my_SigmaIetaIeta_en_0p1_0p4_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p15_0p5_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p15_0p5_signal_endcap", "my_SigmaIetaIeta_en_0p15_0p5_signal_endcap", 200, 0, 0.1); 
  TH1D* h1_my_eleSigmaIetaIeta_en_0p16_0p6_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p16_0p6_signal_endcap", "my_SigmaIetaIeta_en_0p16_0p6_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p2_1_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p2_1_signal_endcap", "my_SigmaIetaIeta_en_0p2_1_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p2_1p5_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p2_1p5_signal_endcap", "my_SigmaIetaIeta_en_0p2_1p5_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p2_2_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p2_2_signal_endcap", "my_SigmaIetaIeta_en_0p2_2_signal_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p18_0p8_signal_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p18_0p8_signal_endcap", "my_SigmaIetaIeta_en_0p18_0p8_signal_endcap", 200, 0, 0.1);

  //
  TH1D* h1_cmssw_eleSigmaIetaIeta_bkg_barrel = new TH1D("h1_cmssw_SigmaIetaIeta_bkg_barrel", "cmssw_SigmaIetaIeta_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_bkg_barrel", "my_SigmaIetaIeta_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p6_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p6_bkg_barrel", "my_SigmaIetaIeta_w4p6_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p5_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p5_bkg_barrel", "my_SigmaIetaIeta_w4p5_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p4_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p4_bkg_barrel", "my_SigmaIetaIeta_w4p4_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p3_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p3_bkg_barrel", "my_SigmaIetaIeta_w4p3_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p2_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p2_bkg_barrel", "my_SigmaIetaIeta_w4p2_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p1_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p1_bkg_barrel", "my_SigmaIetaIeta_w4p1_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p0_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_w4p0_bkg_barrel", "my_SigmaIetaIeta_w4p0_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w3p5_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_w3p5_bkg_barrel", "my_SigmaIetaIeta_w3p5_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w3p0_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_w3p0_bkg_barrel", "my_SigmaIetaIeta_w3p0_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en0p2_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_en0p2_bkg_barrel", "my_SigmaIetaIeta_en0p2_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en0p15_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_en0p15_bkg_barrel", "my_SigmaIetaIeta_en0p15_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en0p5_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_en0p5_bkg_barrel", "my_SigmaIetaIeta_en0p5_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en1_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_en1_bkg_barrel", "my_SigmaIetaIeta_en1_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p1_0p4_bkg_barrel", "my_SigmaIetaIeta_en_0p1_0p4_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p15_0p5_bkg_barrel", "my_SigmaIetaIeta_en_0p15_0p5_bkg_barrel", 200, 0, 0.1); 
  TH1D* h1_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p16_0p6_bkg_barrel", "my_SigmaIetaIeta_en_0p16_0p6_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p2_1_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p2_1_bkg_barrel", "my_SigmaIetaIeta_en_0p2_1_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p2_1p5_bkg_barrel", "my_SigmaIetaIeta_en_0p2_1p5_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p2_2_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p2_2_bkg_barrel", "my_SigmaIetaIeta_en_0p2_2_bkg_barrel", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_barrel = new TH1D("h1_my_SigmaIetaIeta_en_0p18_0p8_bkg_barrel", "my_SigmaIetaIeta_en_0p18_0p8_bkg_barrel", 200, 0, 0.1);

  TH1D* h1_cmssw_eleSigmaIetaIeta_bkg_endcap = new TH1D("h1_cmssw_SigmaIetaIeta_bkg_endcap", "cmssw_SigmaIetaIeta_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_bkg_endcap", "my_SigmaIetaIeta_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p6_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p6_bkg_endcap", "my_SigmaIetaIeta_w4p6_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p5_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p5_bkg_endcap", "my_SigmaIetaIeta_w4p5_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p4_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p4_bkg_endcap", "my_SigmaIetaIeta_w4p4_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p3_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p3_bkg_endcap", "my_SigmaIetaIeta_w4p3_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p2_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p2_bkg_endcap", "my_SigmaIetaIeta_w4p2_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p1_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p1_bkg_endcap", "my_SigmaIetaIeta_w4p1_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w4p0_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_w4p0_bkg_endcap", "my_SigmaIetaIeta_w4p0_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w3p5_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_w3p5_bkg_endcap", "my_SigmaIetaIeta_w3p5_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_w3p0_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_w3p0_bkg_endcap", "my_SigmaIetaIeta_w3p0_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en0p2_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_en0p2_bkg_endcap", "my_SigmaIetaIeta_en0p2_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en0p15_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_en0p15_bkg_endcap", "my_SigmaIetaIeta_en0p15_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en0p5_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_en0p5_bkg_endcap", "my_SigmaIetaIeta_en0p5_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en1_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_en1_bkg_endcap", "my_SigmaIetaIeta_en1_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p1_0p4_bkg_endcap", "my_SigmaIetaIeta_en_0p1_0p4_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p15_0p5_bkg_endcap", "my_SigmaIetaIeta_en_0p15_0p5_bkg_endcap", 200, 0, 0.1); 
  TH1D* h1_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p16_0p6_bkg_endcap", "my_SigmaIetaIeta_en_0p16_0p6_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p2_1_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p2_1_bkg_endcap", "my_SigmaIetaIeta_en_0p2_1_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p2_1p5_bkg_endcap", "my_SigmaIetaIeta_en_0p2_1p5_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p2_2_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p2_2_bkg_endcap", "my_SigmaIetaIeta_en_0p2_2_bkg_endcap", 200, 0, 0.1);
  TH1D* h1_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_endcap = new TH1D("h1_my_SigmaIetaIeta_en_0p18_0p8_bkg_endcap", "my_SigmaIetaIeta_en_0p18_0p8_bkg_endcap", 200, 0, 0.1);

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      //elePt_
      for(int iele=0; iele < elePt_->size(); iele++) {

	// signal | barrel
	if (ele_genmatched_->at(iele)==1 && fabs(eleScEta_->at(iele))<1.44) {
	  std::cout << "my_eleSigmaIetaIeta_ = " << my_eleSigmaIetaIeta_->at(iele) << std::endl;
	  h1_my_eleSigmaIetaIeta_signal_barrel->Fill(my_eleSigmaIetaIeta_->at(iele));
	  h1_cmssw_eleSigmaIetaIeta_signal_barrel->Fill(cmssw_eleSigmaIetaIeta_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p6_signal_barrel->Fill(my_eleSigmaIetaIeta_w4p6_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p5_signal_barrel->Fill(my_eleSigmaIetaIeta_w4p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p4_signal_barrel->Fill(my_eleSigmaIetaIeta_w4p4_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p3_signal_barrel->Fill(my_eleSigmaIetaIeta_w4p3_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p2_signal_barrel->Fill(my_eleSigmaIetaIeta_w4p2_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p1_signal_barrel->Fill(my_eleSigmaIetaIeta_w4p1_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p0_signal_barrel->Fill(my_eleSigmaIetaIeta_w4p0_->at(iele));
	  h1_my_eleSigmaIetaIeta_w3p5_signal_barrel->Fill(my_eleSigmaIetaIeta_w3p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_w3p0_signal_barrel->Fill(my_eleSigmaIetaIeta_w3p0_->at(iele));
	  h1_my_eleSigmaIetaIeta_en0p2_signal_barrel->Fill(my_eleSigmaIetaIeta_en0p2_->at(iele));
	  h1_my_eleSigmaIetaIeta_en0p15_signal_barrel->Fill(my_eleSigmaIetaIeta_en0p15_->at(iele));
	  h1_my_eleSigmaIetaIeta_en0p5_signal_barrel->Fill(my_eleSigmaIetaIeta_en0p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_en1_signal_barrel->Fill(my_eleSigmaIetaIeta_en1_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p1_0p4_signal_barrel->Fill(my_eleSigmaIetaIeta_en_0p1_0p4_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p15_0p5_signal_barrel->Fill(my_eleSigmaIetaIeta_en_0p15_0p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p16_0p6_signal_barrel->Fill(my_eleSigmaIetaIeta_en_0p16_0p6_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p2_1_signal_barrel->Fill(my_eleSigmaIetaIeta_en_0p2_1_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p2_1p5_signal_barrel->Fill(my_eleSigmaIetaIeta_en_0p2_1p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p2_2_signal_barrel->Fill(my_eleSigmaIetaIeta_en_0p2_2_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p18_0p8_signal_barrel->Fill(my_eleSigmaIetaIeta_en_0p18_0p8_->at(iele));

	  prof_cmssw_eleSigmaIetaIeta_signal_barrel_vs_pt->Fill(elePt_->at(iele),cmssw_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p6_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p5_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p4_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p3_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p3_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p2_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p1_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p0_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p5_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w3p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p0_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w3p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p2_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en0p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p15_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en0p15_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p5_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en1_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p1_0p4_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p1_0p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p15_0p5_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p15_0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p16_0p6_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p16_0p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p2_1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1p5_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p2_1p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_2_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p2_2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p18_0p8_signal_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p18_0p8_->at(iele) );

	  prof_cmssw_eleSigmaIetaIeta_signal_barrel_vs_PU->Fill(puTrue_->at(0),cmssw_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p6_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p5_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p4_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p3_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p3_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p2_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p1_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p0_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p5_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w3p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p0_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w3p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p2_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en0p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p15_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en0p15_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p5_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en1_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p1_0p4_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p1_0p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p15_0p5_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p15_0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p16_0p6_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p16_0p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p2_1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1p5_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p2_1p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_2_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p2_2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p18_0p8_signal_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p18_0p8_->at(iele) );

	}

	// background | barrel
	if (ele_genmatched_->at(iele)==0 && fabs(eleScEta_->at(iele))<1.44) {
	  // std::cout << "\nmy_eleSigmaIetaIeta_ = " << my_eleSigmaIetaIeta_->at(iele) << std::endl;
	  h1_my_eleSigmaIetaIeta_bkg_barrel->Fill(my_eleSigmaIetaIeta_->at(iele));
	  h1_cmssw_eleSigmaIetaIeta_bkg_barrel->Fill(cmssw_eleSigmaIetaIeta_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p6_bkg_barrel->Fill(my_eleSigmaIetaIeta_w4p6_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p5_bkg_barrel->Fill(my_eleSigmaIetaIeta_w4p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p4_bkg_barrel->Fill(my_eleSigmaIetaIeta_w4p4_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p3_bkg_barrel->Fill(my_eleSigmaIetaIeta_w4p3_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p2_bkg_barrel->Fill(my_eleSigmaIetaIeta_w4p2_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p1_bkg_barrel->Fill(my_eleSigmaIetaIeta_w4p1_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p0_bkg_barrel->Fill(my_eleSigmaIetaIeta_w4p0_->at(iele));
	  h1_my_eleSigmaIetaIeta_w3p5_bkg_barrel->Fill(my_eleSigmaIetaIeta_w3p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_w3p0_bkg_barrel->Fill(my_eleSigmaIetaIeta_w3p0_->at(iele));
	  h1_my_eleSigmaIetaIeta_en0p2_bkg_barrel->Fill(my_eleSigmaIetaIeta_en0p2_->at(iele));
	  h1_my_eleSigmaIetaIeta_en0p15_bkg_barrel->Fill(my_eleSigmaIetaIeta_en0p15_->at(iele));
	  h1_my_eleSigmaIetaIeta_en0p5_bkg_barrel->Fill(my_eleSigmaIetaIeta_en0p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_en1_bkg_barrel->Fill(my_eleSigmaIetaIeta_en1_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_barrel->Fill(my_eleSigmaIetaIeta_en_0p1_0p4_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_barrel->Fill(my_eleSigmaIetaIeta_en_0p15_0p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_barrel->Fill(my_eleSigmaIetaIeta_en_0p16_0p6_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p2_1_bkg_barrel->Fill(my_eleSigmaIetaIeta_en_0p2_1_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_barrel->Fill(my_eleSigmaIetaIeta_en_0p2_1p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p2_2_bkg_barrel->Fill(my_eleSigmaIetaIeta_en_0p2_2_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_barrel->Fill(my_eleSigmaIetaIeta_en_0p18_0p8_->at(iele));

	  prof_cmssw_eleSigmaIetaIeta_bkg_barrel_vs_pt->Fill(elePt_->at(iele),cmssw_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p6_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p5_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p4_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p3_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p3_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p2_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p1_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p0_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p5_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w3p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p0_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w3p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p2_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en0p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p15_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en0p15_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p5_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en1_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p1_0p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p15_0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p16_0p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p2_1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p2_1p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_2_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p2_2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_barrel_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p18_0p8_->at(iele) );

	  prof_cmssw_eleSigmaIetaIeta_bkg_barrel_vs_PU->Fill(puTrue_->at(0),cmssw_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p6_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p5_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p4_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p3_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p3_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p2_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p1_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p0_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p5_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w3p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p0_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w3p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p2_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en0p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p15_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en0p15_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p5_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en1_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p1_0p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p15_0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p16_0p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p2_1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p2_1p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_2_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p2_2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_barrel_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p18_0p8_->at(iele) );


	}


	// signal | endcap
	if (ele_genmatched_->at(iele)==1 && fabs(eleScEta_->at(iele))>1.56) {
	  std::cout << "my_eleSigmaIetaIeta_ = " << my_eleSigmaIetaIeta_->at(iele) << std::endl;
	  h1_my_eleSigmaIetaIeta_signal_endcap->Fill(my_eleSigmaIetaIeta_->at(iele));
	  h1_cmssw_eleSigmaIetaIeta_signal_endcap->Fill(cmssw_eleSigmaIetaIeta_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p6_signal_endcap->Fill(my_eleSigmaIetaIeta_w4p6_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p5_signal_endcap->Fill(my_eleSigmaIetaIeta_w4p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p4_signal_endcap->Fill(my_eleSigmaIetaIeta_w4p4_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p3_signal_endcap->Fill(my_eleSigmaIetaIeta_w4p3_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p2_signal_endcap->Fill(my_eleSigmaIetaIeta_w4p2_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p1_signal_endcap->Fill(my_eleSigmaIetaIeta_w4p1_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p0_signal_endcap->Fill(my_eleSigmaIetaIeta_w4p0_->at(iele));
	  h1_my_eleSigmaIetaIeta_w3p5_signal_endcap->Fill(my_eleSigmaIetaIeta_w3p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_w3p0_signal_endcap->Fill(my_eleSigmaIetaIeta_w3p0_->at(iele));
	  h1_my_eleSigmaIetaIeta_en0p2_signal_endcap->Fill(my_eleSigmaIetaIeta_en0p2_->at(iele));
	  h1_my_eleSigmaIetaIeta_en0p15_signal_endcap->Fill(my_eleSigmaIetaIeta_en0p15_->at(iele));
	  h1_my_eleSigmaIetaIeta_en0p5_signal_endcap->Fill(my_eleSigmaIetaIeta_en0p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_en1_signal_endcap->Fill(my_eleSigmaIetaIeta_en1_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p1_0p4_signal_endcap->Fill(my_eleSigmaIetaIeta_en_0p1_0p4_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p15_0p5_signal_endcap->Fill(my_eleSigmaIetaIeta_en_0p15_0p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p16_0p6_signal_endcap->Fill(my_eleSigmaIetaIeta_en_0p16_0p6_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p2_1_signal_endcap->Fill(my_eleSigmaIetaIeta_en_0p2_1_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p2_1p5_signal_endcap->Fill(my_eleSigmaIetaIeta_en_0p2_1p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p2_2_signal_endcap->Fill(my_eleSigmaIetaIeta_en_0p2_2_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p18_0p8_signal_endcap->Fill(my_eleSigmaIetaIeta_en_0p18_0p8_->at(iele));

	  prof_cmssw_eleSigmaIetaIeta_signal_endcap_vs_pt->Fill(elePt_->at(iele),cmssw_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p6_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p5_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p4_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p3_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p3_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p2_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p1_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p0_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p5_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w3p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p0_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w3p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p2_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en0p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p15_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en0p15_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p5_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en1_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p1_0p4_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p1_0p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p15_0p5_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p15_0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p16_0p6_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p16_0p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p2_1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1p5_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p2_1p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_2_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p2_2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p18_0p8_signal_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p18_0p8_->at(iele) );

	  prof_cmssw_eleSigmaIetaIeta_signal_endcap_vs_PU->Fill(puTrue_->at(0),cmssw_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p6_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p5_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p4_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p3_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p3_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p2_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p1_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p0_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p5_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w3p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p0_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w3p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p2_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en0p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p15_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en0p15_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p5_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en1_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p1_0p4_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p1_0p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p15_0p5_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p15_0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p16_0p6_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p16_0p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p2_1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1p5_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p2_1p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_2_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p2_2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p18_0p8_signal_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p18_0p8_->at(iele) );

	}

	// background | endcap
	if (ele_genmatched_->at(iele)==0 && fabs(eleScEta_->at(iele))>1.56) {
	  std::cout << "my_eleSigmaIetaIeta_ = " << my_eleSigmaIetaIeta_->at(iele) << std::endl;
	  h1_my_eleSigmaIetaIeta_bkg_endcap->Fill(my_eleSigmaIetaIeta_->at(iele));
	  h1_cmssw_eleSigmaIetaIeta_bkg_endcap->Fill(cmssw_eleSigmaIetaIeta_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p6_bkg_endcap->Fill(my_eleSigmaIetaIeta_w4p6_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p5_bkg_endcap->Fill(my_eleSigmaIetaIeta_w4p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p4_bkg_endcap->Fill(my_eleSigmaIetaIeta_w4p4_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p3_bkg_endcap->Fill(my_eleSigmaIetaIeta_w4p3_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p2_bkg_endcap->Fill(my_eleSigmaIetaIeta_w4p2_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p1_bkg_endcap->Fill(my_eleSigmaIetaIeta_w4p1_->at(iele));
	  h1_my_eleSigmaIetaIeta_w4p0_bkg_endcap->Fill(my_eleSigmaIetaIeta_w4p0_->at(iele));
	  h1_my_eleSigmaIetaIeta_w3p5_bkg_endcap->Fill(my_eleSigmaIetaIeta_w3p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_w3p0_bkg_endcap->Fill(my_eleSigmaIetaIeta_w3p0_->at(iele));
	  h1_my_eleSigmaIetaIeta_en0p2_bkg_endcap->Fill(my_eleSigmaIetaIeta_en0p2_->at(iele));
	  h1_my_eleSigmaIetaIeta_en0p15_bkg_endcap->Fill(my_eleSigmaIetaIeta_en0p15_->at(iele));
	  h1_my_eleSigmaIetaIeta_en0p5_bkg_endcap->Fill(my_eleSigmaIetaIeta_en0p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_en1_bkg_endcap->Fill(my_eleSigmaIetaIeta_en1_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_endcap->Fill(my_eleSigmaIetaIeta_en_0p1_0p4_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_endcap->Fill(my_eleSigmaIetaIeta_en_0p15_0p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_endcap->Fill(my_eleSigmaIetaIeta_en_0p16_0p6_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p2_1_bkg_endcap->Fill(my_eleSigmaIetaIeta_en_0p2_1_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_endcap->Fill(my_eleSigmaIetaIeta_en_0p2_1p5_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p2_2_bkg_endcap->Fill(my_eleSigmaIetaIeta_en_0p2_2_->at(iele));
	  h1_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_endcap->Fill(my_eleSigmaIetaIeta_en_0p18_0p8_->at(iele));

	  prof_cmssw_eleSigmaIetaIeta_bkg_endcap_vs_pt->Fill(elePt_->at(iele),cmssw_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p6_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p5_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p4_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p3_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p3_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p2_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p1_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p0_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w4p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p5_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w3p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p0_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_w3p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p2_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en0p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p15_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en0p15_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p5_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en1_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p1_0p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p15_0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p16_0p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p2_1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p2_1p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_2_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p2_2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_endcap_vs_pt->Fill(elePt_->at(iele),my_eleSigmaIetaIeta_en_0p18_0p8_->at(iele) );

	  prof_cmssw_eleSigmaIetaIeta_bkg_endcap_vs_PU->Fill(puTrue_->at(0),cmssw_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p6_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p5_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p4_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p3_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p3_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p2_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p1_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w4p0_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w4p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p5_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w3p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_w3p0_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_w3p0_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p2_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en0p2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p15_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en0p15_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en0p5_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en1_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p1_0p4_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p15_0p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p16_0p6_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p2_1_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p2_1p5_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p2_2_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p2_2_->at(iele) );
	  prof_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_endcap_vs_PU->Fill(puTrue_->at(0),my_eleSigmaIetaIeta_en_0p18_0p8_->at(iele) );

	}


      }
   }

   h1_my_eleSigmaIetaIeta_signal_barrel->Write();
   h1_cmssw_eleSigmaIetaIeta_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p6_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p5_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p4_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p3_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p2_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p1_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p0_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_w3p5_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_w3p0_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_en0p2_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_en0p15_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_en0p5_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_en1_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p1_0p4_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p15_0p5_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p16_0p6_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p2_1_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p2_1p5_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p2_2_signal_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p18_0p8_signal_barrel->Write();

   h1_my_eleSigmaIetaIeta_signal_endcap->Write();
   h1_cmssw_eleSigmaIetaIeta_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p6_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p5_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p4_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p3_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p2_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p1_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p0_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_w3p5_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_w3p0_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_en0p2_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_en0p15_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_en0p5_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_en1_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p1_0p4_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p15_0p5_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p16_0p6_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p2_1_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p2_1p5_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p2_2_signal_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p18_0p8_signal_endcap->Write();

   h1_my_eleSigmaIetaIeta_bkg_barrel->Write();
   h1_cmssw_eleSigmaIetaIeta_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p6_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p5_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p4_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p3_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p2_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p1_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_w4p0_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_w3p5_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_w3p0_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_en0p2_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_en0p15_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_en0p5_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_en1_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p2_1_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p2_2_bkg_barrel->Write();
   h1_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_barrel->Write();

   h1_my_eleSigmaIetaIeta_bkg_endcap->Write();
   h1_cmssw_eleSigmaIetaIeta_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p6_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p5_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p4_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p3_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p2_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p1_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_w4p0_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_w3p5_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_w3p0_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_en0p2_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_en0p15_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_en0p5_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_en1_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p2_1_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p2_2_bkg_endcap->Write();
   h1_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_endcap->Write();

   prof_cmssw_eleSigmaIetaIeta_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p6_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p5_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p4_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p3_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p2_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p1_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p0_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w3p5_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w3p0_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en0p2_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en0p15_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en0p5_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en1_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p1_0p4_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p15_0p5_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p16_0p6_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1p5_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_2_signal_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p18_0p8_signal_barrel_vs_pt->Write();
   prof_cmssw_eleSigmaIetaIeta_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p6_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p5_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p4_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p3_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p2_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p1_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p0_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w3p5_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w3p0_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en0p2_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en0p15_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en0p5_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en1_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p1_0p4_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p15_0p5_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p16_0p6_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1p5_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_2_signal_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p18_0p8_signal_endcap_vs_pt->Write();

   prof_cmssw_eleSigmaIetaIeta_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p6_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p5_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p4_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p3_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p2_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p1_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p0_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w3p5_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w3p0_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en0p2_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en0p15_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en0p5_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en1_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_2_bkg_barrel_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_barrel_vs_pt->Write();
   prof_cmssw_eleSigmaIetaIeta_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p6_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p5_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p4_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p3_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p2_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p1_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w4p0_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w3p5_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_w3p0_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en0p2_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en0p15_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en0p5_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en1_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_2_bkg_endcap_vs_pt->Write();
   prof_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_endcap_vs_pt->Write();
   ///

   prof_cmssw_eleSigmaIetaIeta_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p6_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p5_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p4_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p3_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p2_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p1_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p0_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w3p5_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w3p0_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en0p2_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en0p15_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en0p5_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en1_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p1_0p4_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p15_0p5_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p16_0p6_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1p5_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_2_signal_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p18_0p8_signal_barrel_vs_PU->Write();
   prof_cmssw_eleSigmaIetaIeta_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p6_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p5_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p4_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p3_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p2_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p1_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p0_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w3p5_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w3p0_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en0p2_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en0p15_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en0p5_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en1_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p1_0p4_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p15_0p5_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p16_0p6_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1p5_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_2_signal_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p18_0p8_signal_endcap_vs_PU->Write();

   prof_cmssw_eleSigmaIetaIeta_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p6_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p5_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p4_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p3_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p2_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p1_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p0_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w3p5_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w3p0_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en0p2_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en0p15_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en0p5_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en1_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_2_bkg_barrel_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_barrel_vs_PU->Write();
   prof_cmssw_eleSigmaIetaIeta_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p6_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p5_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p4_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p3_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p2_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p1_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w4p0_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w3p5_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_w3p0_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en0p2_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en0p15_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en0p5_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en1_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p1_0p4_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p15_0p5_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p16_0p6_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_1p5_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p2_2_bkg_endcap_vs_PU->Write();
   prof_my_eleSigmaIetaIeta_en_0p18_0p8_bkg_endcap_vs_PU->Write();

}
