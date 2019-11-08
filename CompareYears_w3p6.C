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

int CompareYears_w3p6() {

  std::cout << "Get the root files " << std::endl;
  TFile *file_2018 = new TFile("./Out_redefhists_2018.root");
  TFile *file_2021 = new TFile("./Out_redefhists_2021.root");
  TFile *file_2023 = new TFile("./Out_redefhists_2023.root");
  TFile *file_2024 = new TFile("./Out_redefhists_2024.root");

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
  TFile* outputFile = new TFile("compare_years_sieie_w3p6.root","RECREATE");
  outputFile->cd();

  //barrel
  TH1D* h1_my_SigmaIetaIeta_w3p6_signal_barrel_2024 = (TH1D*)file_2024->Get("h1_my_SigmaIetaIeta_w3p6_signal_barrel");
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2024->Rebin(2);
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2024->SetLineColor(kBlue);
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2024->SetLineWidth(3);
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2024->Scale(1/h1_my_SigmaIetaIeta_w3p6_signal_barrel_2024->GetEntries());
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2024->GetXaxis()->SetTitle("Sieie");
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2024->SetTitle("");
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2024->SetStats(0);
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2024->GetXaxis()->SetRangeUser(0, 0.03);

  TH1D* h1_my_SigmaIetaIeta_w3p6_signal_barrel_2023 = (TH1D*)file_2023->Get("h1_my_SigmaIetaIeta_w3p6_signal_barrel");
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2023->Rebin(2);
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2023->SetLineColor(kRed);
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2023->SetLineWidth(3);
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2023->Scale(1/h1_my_SigmaIetaIeta_w3p6_signal_barrel_2023->GetEntries());

  TH1D* h1_my_SigmaIetaIeta_w3p6_signal_barrel_2021 = (TH1D*)file_2021->Get("h1_my_SigmaIetaIeta_w3p6_signal_barrel");
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2021->Rebin(2);
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2021->SetLineColor(kGreen+1);
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2021->SetLineWidth(3);
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2021->Scale(1/h1_my_SigmaIetaIeta_w3p6_signal_barrel_2021->GetEntries());

  TH1D* h1_my_SigmaIetaIeta_w3p6_signal_barrel_2018 = (TH1D*)file_2018->Get("h1_my_SigmaIetaIeta_w3p6_signal_barrel");
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2018->Rebin(2);
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2018->SetLineColor(kGray+1);
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2018->SetLineWidth(3);
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2018->Scale(1/h1_my_SigmaIetaIeta_w3p6_signal_barrel_2018->GetEntries());


  TCanvas* my_canvas1 = new TCanvas("canvas","canvas",800,600);
  my_canvas1->cd();
  gPad->SetLogy();
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2024->Draw();
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2021->Draw("same");
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2023->Draw("same");
  h1_my_SigmaIetaIeta_w3p6_signal_barrel_2018->Draw("same");

  TLegend *leg_example = new TLegend(0.65,0.70,0.94,0.94);
  leg_example->SetHeader("Sieie w=3.6, real e, barrel","C"); // option "C" allows to center the header
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(h1_my_SigmaIetaIeta_w3p6_signal_barrel_2018, "2018", "lp");
  leg_example->AddEntry(h1_my_SigmaIetaIeta_w3p6_signal_barrel_2021, "2021", "lp");
  leg_example->AddEntry(h1_my_SigmaIetaIeta_w3p6_signal_barrel_2023, "2023", "lp");
  leg_example->AddEntry(h1_my_SigmaIetaIeta_w3p6_signal_barrel_2024, "2024", "lp");
  leg_example->Draw("same");
  my_canvas1->SetGrid();

  my_canvas1->Write();
  my_canvas1->SaveAs("DefaultSieie_years_barrel_w3p6.pdf");
  my_canvas1->SaveAs("DefaultSieie_years_barrel_w3p6.png");

  /////endcaps

  TH1D* h1_my_SigmaIetaIeta_w3p6_signal_endcap_2024 = (TH1D*)file_2024->Get("h1_my_SigmaIetaIeta_w3p6_signal_endcap");
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2024->Rebin(4);
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2024->SetLineColor(kBlue);
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2024->SetLineWidth(3);
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2024->Scale(1/h1_my_SigmaIetaIeta_w3p6_signal_endcap_2024->GetEntries());
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2024->GetXaxis()->SetTitle("Sieie");
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2024->SetTitle("");
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2024->SetStats(0);
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2024->GetXaxis()->SetRangeUser(0, 0.08);

  TH1D* h1_my_SigmaIetaIeta_w3p6_signal_endcap_2023 = (TH1D*)file_2023->Get("h1_my_SigmaIetaIeta_w3p6_signal_endcap");
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2023->Rebin(4);
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2023->SetLineColor(kRed);
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2023->SetLineWidth(3);
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2023->Scale(1/h1_my_SigmaIetaIeta_w3p6_signal_endcap_2023->GetEntries());

  TH1D* h1_my_SigmaIetaIeta_w3p6_signal_endcap_2021 = (TH1D*)file_2021->Get("h1_my_SigmaIetaIeta_w3p6_signal_endcap");
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2021->Rebin(4);
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2021->SetLineColor(kGreen+1);
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2021->SetLineWidth(3);
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2021->Scale(1/h1_my_SigmaIetaIeta_w3p6_signal_endcap_2021->GetEntries());

  TH1D* h1_my_SigmaIetaIeta_w3p6_signal_endcap_2018 = (TH1D*)file_2018->Get("h1_my_SigmaIetaIeta_w3p6_signal_endcap");
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2018->Rebin(4);
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2018->SetLineColor(kGray+1);
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2018->SetLineWidth(3);
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2018->Scale(1/h1_my_SigmaIetaIeta_w3p6_signal_endcap_2018->GetEntries());


  TCanvas* my_canvas2 = new TCanvas("canvas2","canvas2",800,600);
  my_canvas2->cd();
  gPad->SetLogy();
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2024->Draw();
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2021->Draw("same");
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2023->Draw("same");
  h1_my_SigmaIetaIeta_w3p6_signal_endcap_2018->Draw("same");

  TLegend *leg_example2 = new TLegend(0.65,0.70,0.94,0.94);
  leg_example2->SetHeader("Sieie w=3.6, real e, endcap","C"); // option "C" allows to center the header
  leg_example2->SetFillColor(0);
  leg_example2->SetTextFont(42);
  leg_example2->SetBorderSize(0);
  leg_example2->AddEntry(h1_my_SigmaIetaIeta_w3p6_signal_endcap_2018, "2018", "lp");
  leg_example2->AddEntry(h1_my_SigmaIetaIeta_w3p6_signal_endcap_2021, "2021", "lp");
  leg_example2->AddEntry(h1_my_SigmaIetaIeta_w3p6_signal_endcap_2023, "2023", "lp");
  leg_example2->AddEntry(h1_my_SigmaIetaIeta_w3p6_signal_endcap_2024, "2024", "lp");
  leg_example2->Draw("same");
  my_canvas2->SetGrid();

  my_canvas2->Write();
  my_canvas2->SaveAs("DefaultSieie_years_endcap_w3p6.pdf");
  my_canvas2->SaveAs("DefaultSieie_years_endcap_w3p6.png");


  return 0;

}
