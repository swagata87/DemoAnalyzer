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

int CompareYears1() {

  std::cout << "Get the root files " << std::endl;
  //Out_ptGT80_redefhists_2018

  TFile *file_2018 = new TFile("./highstat_redefhists_2018_30_70.root");
  TFile *file_2021 = new TFile("./highstat_redefhists_2021.root");
  TFile *file_2023 = new TFile("./highstat_redefhists_2023_30_70.root");
  TFile *file_2024 = new TFile("./highstat_redefhists_2024_30_70.root");

  //--Plotting Styles//
  /*
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetPadBottomMargin(0.12);  
  gStyle->SetPadTopMargin(0.05);   
  gStyle->SetTitleXSize(0.05);
  gStyle->SetTitleXOffset(1.05);
  gStyle->SetTitleYSize(0.05);
  gStyle->SetTitleYOffset(1.05);
  gStyle->SetOptStat();
  */
  //////// Output File /////////
  TFile* outputFile = new TFile("compare_years_default_sieie.root","RECREATE");
  outputFile->cd();

  //barrel
  TH1D* h1_my_SigmaIetaIeta_signal_barrel_2024 = (TH1D*)file_2024->Get("h1_my_SigmaIetaIeta_signal_barrel");
  h1_my_SigmaIetaIeta_signal_barrel_2024->Rebin(1);
  //h1_my_SigmaIetaIeta_signal_barrel_2024->SetMarkerStyle(kFullCircle);
  h1_my_SigmaIetaIeta_signal_barrel_2024->SetLineColor(kBlue);
  h1_my_SigmaIetaIeta_signal_barrel_2024->SetLineWidth(3);
  h1_my_SigmaIetaIeta_signal_barrel_2024->Scale(1/h1_my_SigmaIetaIeta_signal_barrel_2024->GetEntries());
  h1_my_SigmaIetaIeta_signal_barrel_2024->GetXaxis()->SetTitle("Sieie");
  h1_my_SigmaIetaIeta_signal_barrel_2024->SetTitle("");
  h1_my_SigmaIetaIeta_signal_barrel_2024->SetStats(0);
  h1_my_SigmaIetaIeta_signal_barrel_2024->GetXaxis()->SetRangeUser(0, 0.03);
  //h1_my_SigmaIetaIeta_signal_barrel_2024->GetYaxis()->SetRangeUser(0, 1);

  TH1D* h1_my_SigmaIetaIeta_signal_barrel_2023 = (TH1D*)file_2023->Get("h1_my_SigmaIetaIeta_signal_barrel");
  h1_my_SigmaIetaIeta_signal_barrel_2023->Rebin(1);
  //  h1_my_SigmaIetaIeta_signal_barrel_2023->SetMarkerStyle(kFullCircle);
  h1_my_SigmaIetaIeta_signal_barrel_2023->SetLineColor(kRed);
  h1_my_SigmaIetaIeta_signal_barrel_2023->SetLineWidth(3);
  h1_my_SigmaIetaIeta_signal_barrel_2023->Scale(1/h1_my_SigmaIetaIeta_signal_barrel_2023->GetEntries());

  TH1D* h1_my_SigmaIetaIeta_signal_barrel_2021 = (TH1D*)file_2021->Get("h1_my_SigmaIetaIeta_signal_barrel");
  // h1_my_SigmaIetaIeta_signal_barrel_2021->SetMarkerStyle(kFullCircle);
  h1_my_SigmaIetaIeta_signal_barrel_2021->Rebin(1);
  h1_my_SigmaIetaIeta_signal_barrel_2021->SetLineColor(kGreen+1);
  h1_my_SigmaIetaIeta_signal_barrel_2021->SetLineWidth(3);
  h1_my_SigmaIetaIeta_signal_barrel_2021->Scale(1/h1_my_SigmaIetaIeta_signal_barrel_2021->GetEntries());

  TH1D* h1_my_SigmaIetaIeta_signal_barrel_2018 = (TH1D*)file_2018->Get("h1_my_SigmaIetaIeta_signal_barrel");
  h1_my_SigmaIetaIeta_signal_barrel_2018->Rebin(1);
  //h1_my_SigmaIetaIeta_signal_barrel_2018->SetMarkerStyle(kFullCircle);
  h1_my_SigmaIetaIeta_signal_barrel_2018->SetLineColor(kGray+1);
  h1_my_SigmaIetaIeta_signal_barrel_2018->SetLineWidth(3);
  h1_my_SigmaIetaIeta_signal_barrel_2018->Scale(1/h1_my_SigmaIetaIeta_signal_barrel_2018->GetEntries());


  TCanvas* my_canvas1 = new TCanvas("canvas","canvas",800,600);
  my_canvas1->cd();
  gPad->SetLogy();
  h1_my_SigmaIetaIeta_signal_barrel_2024->Draw("L");
  //  h1_my_SigmaIetaIeta_signal_barrel_2021->Draw("L same");
  h1_my_SigmaIetaIeta_signal_barrel_2023->Draw("L same");
  h1_my_SigmaIetaIeta_signal_barrel_2018->Draw("L same");

  TLegend *leg_example = new TLegend(0.65,0.70,0.98,0.94);
  leg_example->SetHeader("Sieie default, signal(30-70 GeV), barrel","C"); // option "C" allows to center the header
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(h1_my_SigmaIetaIeta_signal_barrel_2018, "2018", "lp");
  // leg_example->AddEntry(h1_my_SigmaIetaIeta_signal_barrel_2021, "2021", "lp");
  leg_example->AddEntry(h1_my_SigmaIetaIeta_signal_barrel_2023, "2023", "lp");
  leg_example->AddEntry(h1_my_SigmaIetaIeta_signal_barrel_2024, "2024", "lp");
  leg_example->Draw("same");
  my_canvas1->SetGrid();

  my_canvas1->Write();
  //  my_canvas1->SaveAs("DefaultSieie_years_barrel.pdf");
  my_canvas1->SaveAs("DefaultSieie_years_barrel_30_70.png");

  /////endcaps

  TH1D* h1_my_SigmaIetaIeta_signal_endcap_2024 = (TH1D*)file_2024->Get("h1_my_SigmaIetaIeta_signal_endcap");
  h1_my_SigmaIetaIeta_signal_endcap_2024->Rebin(4);
  //h1_my_SigmaIetaIeta_signal_endcap_2024->SetMarkerStyle(kFullCircle);
  //h1_my_SigmaIetaIeta_signal_endcap_2024->SetMarkerColor(kBlue);
  h1_my_SigmaIetaIeta_signal_endcap_2024->SetLineColor(kBlue);
  h1_my_SigmaIetaIeta_signal_endcap_2024->SetLineWidth(3);
  h1_my_SigmaIetaIeta_signal_endcap_2024->Scale(1/h1_my_SigmaIetaIeta_signal_endcap_2024->GetEntries());
  h1_my_SigmaIetaIeta_signal_endcap_2024->GetXaxis()->SetTitle("Sieie");
  h1_my_SigmaIetaIeta_signal_endcap_2024->SetTitle("");
  h1_my_SigmaIetaIeta_signal_endcap_2024->SetStats(0);
  h1_my_SigmaIetaIeta_signal_endcap_2024->GetXaxis()->SetRangeUser(0.0, 0.08);
  // h1_my_SigmaIetaIeta_signal_endcap_2024->GetYaxis()->SetRangeUser(0.0, 0.25);

  TH1D* h1_my_SigmaIetaIeta_signal_endcap_2023 = (TH1D*)file_2023->Get("h1_my_SigmaIetaIeta_signal_endcap");
  h1_my_SigmaIetaIeta_signal_endcap_2023->Rebin(4);
  h1_my_SigmaIetaIeta_signal_endcap_2023->SetLineColor(kRed);
  h1_my_SigmaIetaIeta_signal_endcap_2023->SetLineWidth(3);
  h1_my_SigmaIetaIeta_signal_endcap_2023->Scale(1/h1_my_SigmaIetaIeta_signal_endcap_2023->GetEntries());
  // h1_my_SigmaIetaIeta_signal_endcap_2023->SetMarkerStyle(kFullCircle);
  // h1_my_SigmaIetaIeta_signal_endcap_2023->SetMarkerColor(kRed);

  TH1D* h1_my_SigmaIetaIeta_signal_endcap_2021 = (TH1D*)file_2021->Get("h1_my_SigmaIetaIeta_signal_endcap");
  h1_my_SigmaIetaIeta_signal_endcap_2021->Rebin(4);
  h1_my_SigmaIetaIeta_signal_endcap_2021->SetLineColor(kGreen+1);
  h1_my_SigmaIetaIeta_signal_endcap_2021->SetLineWidth(3);
  h1_my_SigmaIetaIeta_signal_endcap_2021->Scale(1/h1_my_SigmaIetaIeta_signal_endcap_2021->GetEntries());
  //h1_my_SigmaIetaIeta_signal_endcap_2021->SetMarkerStyle(kFullCircle);
  //h1_my_SigmaIetaIeta_signal_endcap_2021->SetMarkerColor(kGreen+1);

  TH1D* h1_my_SigmaIetaIeta_signal_endcap_2018 = (TH1D*)file_2018->Get("h1_my_SigmaIetaIeta_signal_endcap");
  h1_my_SigmaIetaIeta_signal_endcap_2018->Rebin(4);
  h1_my_SigmaIetaIeta_signal_endcap_2018->SetLineColor(kGray+1);
  h1_my_SigmaIetaIeta_signal_endcap_2018->SetLineWidth(3);
  h1_my_SigmaIetaIeta_signal_endcap_2018->Scale(1/h1_my_SigmaIetaIeta_signal_endcap_2018->GetEntries());
  //  h1_my_SigmaIetaIeta_signal_endcap_2018->SetMarkerStyle(kFullCircle);
  //h1_my_SigmaIetaIeta_signal_endcap_2018->SetMarkerColor(kGray+1);


  TCanvas* my_canvas2 = new TCanvas("canvas2","canvas2",800,600);
  my_canvas2->cd();
  gPad->SetLogy();
  h1_my_SigmaIetaIeta_signal_endcap_2024->Draw("C");
  //  h1_my_SigmaIetaIeta_signal_endcap_2021->Draw("C same");
  h1_my_SigmaIetaIeta_signal_endcap_2023->Draw("C same");
  h1_my_SigmaIetaIeta_signal_endcap_2018->Draw("C same");

  TLegend *leg_example2 = new TLegend(0.69,0.70,0.98,0.94);
  leg_example2->SetHeader("Sieie default, signal(30-70 GeV), endcap","C"); // option "C" allows to center the header
  leg_example2->SetFillColor(0);
  leg_example2->SetTextFont(42);
  leg_example2->SetBorderSize(0);
  leg_example2->AddEntry(h1_my_SigmaIetaIeta_signal_endcap_2018, "2018", "lp");
  // leg_example2->AddEntry(h1_my_SigmaIetaIeta_signal_endcap_2021, "2021", "lp");
  leg_example2->AddEntry(h1_my_SigmaIetaIeta_signal_endcap_2023, "2023", "lp");
  leg_example2->AddEntry(h1_my_SigmaIetaIeta_signal_endcap_2024, "2024", "lp");
  leg_example2->Draw("same");
  my_canvas2->SetGrid();

  my_canvas2->Write();
  //  my_canvas2->SaveAs("DefaultSieie_years_endcap.pdf");
  my_canvas2->SaveAs("DefaultSieie_years_endcap_30_70.png");


  return 0;

}
