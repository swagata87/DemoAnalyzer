#include <iostream>
#include <algorithm>
#include "TLatex.h"
#include <iomanip>
#include <vector>
#include "TPad.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TSystem.h"
#include "TImage.h"
#include "TKey.h"
#include "TH1.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TObjArray.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TPostScript.h"
#include <TPaveStats.h>
#include "TLegend.h"
#include <TProfile.h>
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "THStack.h"

int CompareProf_EB_per_rechit() {

  std::cout << "Get the root files " << std::endl;
  TFile *file_2018 = new TFile("./Out_redefhists_2018.root");
  TFile *file_2023 = new TFile("./Out_redefhists_2023.root");
  TFile *file_2024 = new TFile("./Out_redefhists_2024.root");

  std::cout << "Get profile hist 1" << std::endl;
  TProfile* prof_my_sieie_signal_barrel_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_my_sieie_signal_barrel_vs_pt");
  prof_my_sieie_signal_barrel_vs_pt_2024->SetMarkerColor(kBlue);
  prof_my_sieie_signal_barrel_vs_pt_2024->SetLineColor(kBlue);
  prof_my_sieie_signal_barrel_vs_pt_2024->SetLineWidth(3);
  prof_my_sieie_signal_barrel_vs_pt_2024->GetXaxis()->SetTitle("Reconstructed p_{T} of electron");
  prof_my_sieie_signal_barrel_vs_pt_2024->GetYaxis()->SetTitle("Sigma_ieta_ieta");
  prof_my_sieie_signal_barrel_vs_pt_2024->SetTitle("");
  prof_my_sieie_signal_barrel_vs_pt_2024->SetStats(0);
  prof_my_sieie_signal_barrel_vs_pt_2024->GetYaxis()->SetRangeUser(0.007,0.020);


  std::cout << "Get profile hist 2" << std::endl;
  TProfile* prof_my_sieie_per_rechit_signal_barrel_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_per_rechit_signal_barrel_vs_pt");
  prof_my_sieie_per_rechit_signal_barrel_vs_pt_2024->SetMarkerColor(kRed);
  prof_my_sieie_per_rechit_signal_barrel_vs_pt_2024->SetLineColor(kRed);
  prof_my_sieie_per_rechit_signal_barrel_vs_pt_2024->SetLineWidth(3);

  std::cout << "Get profile hist 3" << std::endl;
  TProfile* prof_my_sieie_per_rechit_m1p05_signal_barrel_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_per_rechit_m1p05_signal_barrel_vs_pt;1");
  prof_my_sieie_per_rechit_m1p05_signal_barrel_vs_pt_2024->SetMarkerColor(kMagenta);
  prof_my_sieie_per_rechit_m1p05_signal_barrel_vs_pt_2024->SetLineColor(kMagenta);
  prof_my_sieie_per_rechit_m1p05_signal_barrel_vs_pt_2024->SetLineWidth(3);

  TProfile* prof_my_sieie_per_rechit_m1p1_signal_barrel_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_per_rechit_m1p1_signal_barrel_vs_pt;1");
  prof_my_sieie_per_rechit_m1p1_signal_barrel_vs_pt_2024->SetMarkerColor(kGreen+1);
  prof_my_sieie_per_rechit_m1p1_signal_barrel_vs_pt_2024->SetLineColor(kGreen+1);
  prof_my_sieie_per_rechit_m1p1_signal_barrel_vs_pt_2024->SetLineWidth(3);

  TProfile* prof_my_sieie_per_rechit_m1p15_signal_barrel_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_per_rechit_m1p15_signal_barrel_vs_pt;1");
  prof_my_sieie_per_rechit_m1p15_signal_barrel_vs_pt_2024->SetMarkerColor(kGray+1);
  prof_my_sieie_per_rechit_m1p15_signal_barrel_vs_pt_2024->SetLineColor(kGray+1);
  prof_my_sieie_per_rechit_m1p15_signal_barrel_vs_pt_2024->SetLineWidth(3);

  TProfile* prof_my_sieie_per_rechit_m1p2_signal_barrel_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_per_rechit_m1p2_signal_barrel_vs_pt;1");
  prof_my_sieie_per_rechit_m1p2_signal_barrel_vs_pt_2024->SetMarkerColor(kCyan);
  prof_my_sieie_per_rechit_m1p2_signal_barrel_vs_pt_2024->SetLineColor(kCyan);
  prof_my_sieie_per_rechit_m1p2_signal_barrel_vs_pt_2024->SetLineWidth(3);

  TProfile* prof_my_sieie_per_rechit_m1p25_signal_barrel_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_per_rechit_m1p25_signal_barrel_vs_pt;1");
  prof_my_sieie_per_rechit_m1p25_signal_barrel_vs_pt_2024->SetMarkerColor(kBlack);
  prof_my_sieie_per_rechit_m1p25_signal_barrel_vs_pt_2024->SetLineColor(kBlack);
  prof_my_sieie_per_rechit_m1p25_signal_barrel_vs_pt_2024->SetLineWidth(3);


  //--Plotting Styles//
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetPadBottomMargin(0.12);  
  gStyle->SetPadTopMargin(0.05);   
  gStyle->SetTitleXSize(0.05);
  gStyle->SetTitleXOffset(1.05);
  gStyle->SetTitleYSize(0.05);
  gStyle->SetTitleYOffset(1.05);
  gStyle->SetOptStat();

  //////// Output File /////////
  TFile* outputFile = new TFile("compare_sieie_EB_per_rechit.root","RECREATE");
  outputFile->cd();

  TCanvas* my_canvas1 = new TCanvas("canvas","canvas",800,600);
  my_canvas1->cd();
  gPad->SetLogy();
  prof_my_sieie_signal_barrel_vs_pt_2024->Draw();
  prof_my_sieie_per_rechit_signal_barrel_vs_pt_2024->Draw("same");
  prof_my_sieie_per_rechit_m1p05_signal_barrel_vs_pt_2024->Draw("same");
  prof_my_sieie_per_rechit_m1p1_signal_barrel_vs_pt_2024->Draw("same");
  prof_my_sieie_per_rechit_m1p15_signal_barrel_vs_pt_2024->Draw("same");
  prof_my_sieie_per_rechit_m1p2_signal_barrel_vs_pt_2024->Draw("same");
  prof_my_sieie_per_rechit_m1p25_signal_barrel_vs_pt_2024->Draw("same");
  
  TLegend *leg_example = new TLegend(0.65,0.70,0.94,0.94);
  leg_example->SetHeader("Sieie, real e, barrel","C"); // option "C" allows to center the header
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(prof_my_sieie_signal_barrel_vs_pt_2024, "default", "lp");
  leg_example->AddEntry(prof_my_sieie_per_rechit_signal_barrel_vs_pt_2024, "per recHit", "lp");
  leg_example->AddEntry(prof_my_sieie_per_rechit_m1p05_signal_barrel_vs_pt_2024, "per recHit * 1.05", "lp");
  leg_example->AddEntry(prof_my_sieie_per_rechit_m1p1_signal_barrel_vs_pt_2024, "per recHit * 1.1", "lp");
  leg_example->AddEntry(prof_my_sieie_per_rechit_m1p15_signal_barrel_vs_pt_2024, "per recHit * 1.15", "lp");
  leg_example->AddEntry(prof_my_sieie_per_rechit_m1p2_signal_barrel_vs_pt_2024, "per recHit * 1.2", "lp");
  leg_example->AddEntry(prof_my_sieie_per_rechit_m1p25_signal_barrel_vs_pt_2024, "per recHit * 1.25", "lp");

  leg_example->Draw("same");
  my_canvas1->SetGrid();

  my_canvas1->Write();
  my_canvas1->SaveAs("compareSieie_EB_per_rechit.pdf");
  my_canvas1->SaveAs("compareSieie_EB_per_rechit.png");

  return 0;

}
