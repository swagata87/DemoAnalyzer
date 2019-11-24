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

int CompareSigBkg_default() {

  std::cout << "Get the root files " << std::endl;
  //Out_ptGT80_redefhists_2018

  //  TFile *file_2018 = new TFile("./Out_redefhists_2018.root");
  // TFile *file_2021 = new TFile("./Out_redefhists_2021.root");
  // TFile *file_2023 = new TFile("./Out_redefhists_2023.root");
  TFile *file_2024 = new TFile("./Out_redefhists_2024.root");

  //--Plotting Styles//
  //  gStyle->SetPadLeftMargin(0.15);
  //  gStyle->SetPadRightMargin(0.05);
  //  gStyle->SetPadBottomMargin(0.12);  
  // gStyle->SetPadTopMargin(0.05);   
  // gStyle->SetTitleXSize(0.05);
  // gStyle->SetTitleXOffset(1.05);
  // gStyle->SetTitleYSize(0.05);
  // gStyle->SetTitleYOffset(1.05);
   gStyle->SetOptStat();

  //////// Output File /////////
  TFile* outputFile = new TFile("compare_sig_bkg_default_sieie.root","RECREATE");
  outputFile->cd();

  //barrel
  TH1D* h1_my_SigmaIetaIeta_signal_barrel_2024 = (TH1D*)file_2024->Get("h1_my_SigmaIetaIeta_signal_barrel");
  h1_my_SigmaIetaIeta_signal_barrel_2024->Rebin(2);
  h1_my_SigmaIetaIeta_signal_barrel_2024->SetLineColor(kBlue);
  h1_my_SigmaIetaIeta_signal_barrel_2024->SetLineWidth(3);
  h1_my_SigmaIetaIeta_signal_barrel_2024->Scale(1/h1_my_SigmaIetaIeta_signal_barrel_2024->GetEntries());
  h1_my_SigmaIetaIeta_signal_barrel_2024->GetXaxis()->SetTitle("Sieie");
  h1_my_SigmaIetaIeta_signal_barrel_2024->SetTitle("");
  h1_my_SigmaIetaIeta_signal_barrel_2024->SetStats(0);
  h1_my_SigmaIetaIeta_signal_barrel_2024->GetXaxis()->SetRangeUser(0, 0.035);

  TH1D* h1_my_SigmaIetaIeta_bkg_barrel_2024 = (TH1D*)file_2024->Get("h1_my_SigmaIetaIeta_bkg_barrel");
  h1_my_SigmaIetaIeta_bkg_barrel_2024->Rebin(2);
  h1_my_SigmaIetaIeta_bkg_barrel_2024->SetLineColor(kRed);
  h1_my_SigmaIetaIeta_bkg_barrel_2024->SetLineWidth(3);
  h1_my_SigmaIetaIeta_bkg_barrel_2024->Scale(1/h1_my_SigmaIetaIeta_bkg_barrel_2024->GetEntries());

  TCanvas* my_canvas1 = new TCanvas("canvas","canvas",800,600);
  my_canvas1->cd();
  gPad->SetLogy();
  h1_my_SigmaIetaIeta_signal_barrel_2024->Draw();
  h1_my_SigmaIetaIeta_bkg_barrel_2024->Draw("same");

  TLegend *leg_example = new TLegend(0.65,0.70,0.94,0.94);
  leg_example->SetHeader("SIEIE default, barrel","C"); // option "C" allows to center the header
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(h1_my_SigmaIetaIeta_signal_barrel_2024, "signal", "lp");
  leg_example->AddEntry(h1_my_SigmaIetaIeta_bkg_barrel_2024, "bkg", "lp");
  leg_example->Draw("same");
  my_canvas1->SetGrid();

  my_canvas1->Write();
  my_canvas1->SaveAs("Sieie_default_sig_vs_bkg_barrel.png");

  /////endcaps
  TH1D* h1_my_SigmaIetaIeta_signal_endcap_2024 = (TH1D*)file_2024->Get("h1_my_SigmaIetaIeta_signal_endcap");
  h1_my_SigmaIetaIeta_signal_endcap_2024->Rebin(4);
  h1_my_SigmaIetaIeta_signal_endcap_2024->SetLineColor(kBlue);
  h1_my_SigmaIetaIeta_signal_endcap_2024->SetLineWidth(3);
  h1_my_SigmaIetaIeta_signal_endcap_2024->Scale(1/h1_my_SigmaIetaIeta_signal_endcap_2024->GetEntries());
  h1_my_SigmaIetaIeta_signal_endcap_2024->GetXaxis()->SetTitle("Sieie");
  h1_my_SigmaIetaIeta_signal_endcap_2024->SetTitle("");
  h1_my_SigmaIetaIeta_signal_endcap_2024->SetStats(0);
  h1_my_SigmaIetaIeta_signal_endcap_2024->GetXaxis()->SetRangeUser(0, 0.1);

  TH1D* h1_my_SigmaIetaIeta_bkg_endcap_2024 = (TH1D*)file_2024->Get("h1_my_SigmaIetaIeta_bkg_endcap");
  h1_my_SigmaIetaIeta_bkg_endcap_2024->Rebin(4);
  h1_my_SigmaIetaIeta_bkg_endcap_2024->SetLineColor(kRed);
  h1_my_SigmaIetaIeta_bkg_endcap_2024->SetLineWidth(3);
  h1_my_SigmaIetaIeta_bkg_endcap_2024->Scale(1/h1_my_SigmaIetaIeta_bkg_endcap_2024->GetEntries());

  TCanvas* my_canvas2 = new TCanvas("canvas2","canvas2",800,600);
  my_canvas2->cd();
  gPad->SetLogy();
  h1_my_SigmaIetaIeta_signal_endcap_2024->Draw();
  h1_my_SigmaIetaIeta_bkg_endcap_2024->Draw("same");

  TLegend *leg_example2 = new TLegend(0.65,0.70,0.94,0.94);
  leg_example2->SetHeader("SIEIE default, endcap","C"); // option "C" allows to center the header
  leg_example2->SetFillColor(0);
  leg_example2->SetTextFont(42);
  leg_example2->SetBorderSize(0);
  leg_example2->AddEntry(h1_my_SigmaIetaIeta_signal_endcap_2024, "signal", "lp");
  leg_example2->AddEntry(h1_my_SigmaIetaIeta_bkg_endcap_2024, "bkg", "lp");
  leg_example2->Draw("same");
  my_canvas2->SetGrid();

  my_canvas2->Write();
  my_canvas2->SaveAs("Sieie_default_sig_vs_bkg_endcap.png");


  return 0;

}
