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

int CompareCrysThres() {

  std::cout << "Get the root files " << std::endl;
  //Out_ptGT80_redefhists_2018

  TFile *file_2018 = new TFile("./crysThres_2018.root");
  TFile *file_2021 = new TFile("./crysThres_2021.root");
  TFile *file_2023 = new TFile("./crysThres_2023.root");
  TFile *file_2024 = new TFile("./crysThres_2024.root");

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
  TFile* outputFile = new TFile("compare_years_recHit_thres.root","RECREATE");
  outputFile->cd();

  TProfile* prof_eta_2024 = (TProfile*)file_2024->Get("profile_crys_thres_vs_eta");
  prof_eta_2024->SetLineColor(kBlue);
  prof_eta_2024->SetLineWidth(3);
  prof_eta_2024->GetXaxis()->SetTitle("#eta");
  prof_eta_2024->SetTitle("");
  prof_eta_2024->SetStats(0);
  prof_eta_2024->GetYaxis()->SetRangeUser(0.05,1.22);

  TProfile* prof_eta_2023 = (TProfile*)file_2023->Get("profile_crys_thres_vs_eta");
  prof_eta_2023->SetLineColor(kRed);
  prof_eta_2023->SetLineWidth(3);

  TProfile* prof_eta_2021 = (TProfile*)file_2021->Get("profile_crys_thres_vs_eta");
  prof_eta_2021->SetLineColor(kRed+3);
  prof_eta_2021->SetLineWidth(3);

  TProfile* prof_eta_2018 = (TProfile*)file_2018->Get("profile_crys_thres_vs_eta");
  prof_eta_2018->SetLineColor(kGreen+1);
  prof_eta_2018->SetLineWidth(3);

  TCanvas* my_canvas1 = new TCanvas("canvas","canvas",800,600);
  my_canvas1->cd();
  ///  gPad->SetLogy();
  prof_eta_2024->Draw();
  prof_eta_2023->Draw("same");
  prof_eta_2021->Draw("same");
  prof_eta_2018->Draw("same");

  TLegend *leg_example = new TLegend(0.35,0.65,0.79,0.94);
  leg_example->SetHeader("pf recHit threshold in ECAL crystal","C"); // option "C" allows to center the header
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(prof_eta_2024, "2024", "lp");
  leg_example->AddEntry(prof_eta_2023, "2023", "lp");
  leg_example->AddEntry(prof_eta_2021, "2021", "lp");
  leg_example->AddEntry(prof_eta_2018, "2018", "lp");
  leg_example->Draw("same");
  my_canvas1->SetGrid();

  my_canvas1->Write();
  my_canvas1->SaveAs("pfrecHitThres_barrel.png");

  /////
  prof_eta_2024->GetYaxis()->SetRangeUser(0,10);

  TCanvas* my_canvas2 = new TCanvas("canvas2","canvas2",800,600);
  my_canvas2->cd();
  ///  gPad->SetLogy();
  prof_eta_2024->Draw();
  prof_eta_2023->Draw("same");
  prof_eta_2021->Draw("same");
  prof_eta_2018->Draw("same");

  //  TLegend *leg_example = new TLegend(0.65,0.70,0.94,0.94);
  // leg_example->SetHeader("pf recHit threshold in ECAL crystal","C"); // option "C" allows to center the header
  // leg_example->SetFillColor(0);
  // leg_example->SetTextFont(42);
  // leg_example->SetBorderSize(0);
  // leg_example->AddEntry(prof_eta_2024, "2024", "lp");
  // leg_example->AddEntry(prof_eta_2023, "2023", "lp");
  // leg_example->AddEntry(prof_eta_2021, "2021", "lp");
  // leg_example->AddEntry(prof_eta_2018, "2018", "lp");
  leg_example->Draw("same");
  my_canvas2->SetGrid();

  my_canvas2->Write();
  my_canvas2->SaveAs("pfrecHitThres_endcap.png");




  return 0;

}
