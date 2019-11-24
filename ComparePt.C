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

int ComparePt() {

  std::cout << "Get the root files " << std::endl;
  //Out_ptGT80_redefhists_2018

  TFile *file_ttbar = new TFile("./Out_ttbar_pt.root");
  TFile *file_dy = new TFile("./Out_dy_pt.root");
  TFile *file_qcd = new TFile("./Out_qcd_pt.root");

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
  TFile* outputFile = new TFile("comparePT.root","RECREATE");
  outputFile->cd();

  //ttbar
  TH1D* h1_pt_signal_ttbar = (TH1D*)file_ttbar->Get("pt_signal");
  //  h1_pt_signal_ttbar->Rebin(2);
  h1_pt_signal_ttbar->SetLineColor(kBlue);
  h1_pt_signal_ttbar->SetLineWidth(3);
  // h1_pt_signal_ttbar->Scale(1/h1_pt_signal_ttbar->GetEntries());
  //  h1_pt_signal_ttbar->GetXaxis()->SetRangeUser(0, 0.03);

  //dy
  TH1D* h1_pt_signal_dy = (TH1D*)file_dy->Get("pt_signal");
  //  h1_pt_signal_ttbar->Rebin(2);
  h1_pt_signal_dy->SetLineColor(kRed);
  h1_pt_signal_dy->SetLineWidth(3);
  h1_pt_signal_dy->GetXaxis()->SetTitle("ele pT");
  h1_pt_signal_dy->SetTitle("");
  h1_pt_signal_dy->SetStats(0);
  h1_pt_signal_dy->GetXaxis()->SetRangeUser(0, 150);


  TH1D* h1_pt_signal_qcd = (TH1D*)file_qcd->Get("pt_signal");
  //  h1_pt_signal_ttbar->Rebin(2);
  h1_pt_signal_qcd->SetLineColor(kGreen+1);
  h1_pt_signal_qcd->SetLineWidth(3);


  TCanvas* my_canvas1 = new TCanvas("canvas","canvas",800,600);
  my_canvas1->cd();
  gPad->SetLogy();
  h1_pt_signal_dy->Draw();
  h1_pt_signal_ttbar->Draw("same");
  h1_pt_signal_qcd->Draw("same");

  TLegend *leg_example = new TLegend(0.65,0.70,0.94,0.94);
  leg_example->SetHeader("Electron pT","C"); // option "C" allows to center the header
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(h1_pt_signal_ttbar, "ttbar", "lp");
  leg_example->AddEntry(h1_pt_signal_dy, "dy", "lp");
  leg_example->AddEntry(h1_pt_signal_qcd, "QCD", "lp");
  leg_example->Draw("same");
  my_canvas1->SetGrid();

  my_canvas1->Write();
  my_canvas1->SaveAs("elePt_differentProcs.png");



  return 0;

}
