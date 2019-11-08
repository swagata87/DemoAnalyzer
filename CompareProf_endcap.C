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

int CompareProf_endcap() {

  std::cout << "Get the root files " << std::endl;
  TFile *file_2018 = new TFile("./Out_redefhists_2018.root");
  TFile *file_2023 = new TFile("./Out_redefhists_2023.root");
  TFile *file_2024 = new TFile("./Out_redefhists_2024.root");

  std::cout << "Get profile hist 1" << std::endl;
  TProfile* prof_my_sieie_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_my_sieie_signal_endcap_vs_pt");
  prof_my_sieie_signal_endcap_vs_pt_2024->SetMarkerColor(kBlue);
  prof_my_sieie_signal_endcap_vs_pt_2024->SetLineColor(kBlue);
  prof_my_sieie_signal_endcap_vs_pt_2024->SetLineWidth(3);
  prof_my_sieie_signal_endcap_vs_pt_2024->GetXaxis()->SetTitle("Reconstructed p_{T} of electron");
  prof_my_sieie_signal_endcap_vs_pt_2024->GetYaxis()->SetTitle("Sigma_ieta_ieta");
  prof_my_sieie_signal_endcap_vs_pt_2024->SetTitle("");
  prof_my_sieie_signal_endcap_vs_pt_2024->SetStats(0);
  prof_my_sieie_signal_endcap_vs_pt_2024->GetYaxis()->SetRangeUser(0.005,0.10);


  std::cout << "Get profile hist 2" << std::endl;
  TProfile* prof_my_sieie_w4p0_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_w4p0_signal_endcap_vs_pt");
  prof_my_sieie_w4p0_signal_endcap_vs_pt_2024->SetMarkerColor(kRed);
  prof_my_sieie_w4p0_signal_endcap_vs_pt_2024->SetLineColor(kRed);
  prof_my_sieie_w4p0_signal_endcap_vs_pt_2024->SetLineWidth(3);

  std::cout << "Get profile hist 3" << std::endl;
  TProfile* prof_my_sieie_w3p5_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_w3p5_signal_endcap_vs_pt;1");
  prof_my_sieie_w3p5_signal_endcap_vs_pt_2024->SetMarkerColor(kMagenta);
  prof_my_sieie_w3p5_signal_endcap_vs_pt_2024->SetLineColor(kMagenta);
  prof_my_sieie_w3p5_signal_endcap_vs_pt_2024->SetLineWidth(3);

  TProfile* prof_my_sieie_w3p7_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_w3p7_signal_endcap_vs_pt;1");
  prof_my_sieie_w3p7_signal_endcap_vs_pt_2024->SetMarkerColor(kGray+1);
  prof_my_sieie_w3p7_signal_endcap_vs_pt_2024->SetLineColor(kGray+1);
  prof_my_sieie_w3p7_signal_endcap_vs_pt_2024->SetLineWidth(3);

  std::cout << "Get profile hist 4" << std::endl;
  TProfile* prof_my_sieie_w3p0_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_w3p0_signal_endcap_vs_pt;1");
  prof_my_sieie_w3p0_signal_endcap_vs_pt_2024->SetMarkerColor(kGreen+1);
  prof_my_sieie_w3p0_signal_endcap_vs_pt_2024->SetLineColor(kGreen+1);
  prof_my_sieie_w3p0_signal_endcap_vs_pt_2024->SetLineWidth(3);
  ///

  //Energy cut , same in endcap and endcap

  std::cout << "Get profile hist en 1" << std::endl;
  TProfile* prof_my_sieie_en0p2_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_en0p2_signal_endcap_vs_pt");
  prof_my_sieie_en0p2_signal_endcap_vs_pt_2024->SetMarkerColor(kGray+1);
  prof_my_sieie_en0p2_signal_endcap_vs_pt_2024->SetLineColor(kGray+1);
  prof_my_sieie_en0p2_signal_endcap_vs_pt_2024->SetLineWidth(3);

  //adjust this one for canvas 2
  std::cout << "Get profile hist en 2" << std::endl;
  TProfile* prof_my_sieie_en0p15_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_en0p15_signal_endcap_vs_pt");
  prof_my_sieie_en0p15_signal_endcap_vs_pt_2024->SetMarkerColor(kRed);
  prof_my_sieie_en0p15_signal_endcap_vs_pt_2024->SetLineColor(kRed);
  prof_my_sieie_en0p15_signal_endcap_vs_pt_2024->SetLineWidth(3);
  prof_my_sieie_en0p15_signal_endcap_vs_pt_2024->GetXaxis()->SetTitle("Reconstructed p_{T} of electron");
  prof_my_sieie_en0p15_signal_endcap_vs_pt_2024->GetYaxis()->SetTitle("Sigma_ieta_ieta");
  prof_my_sieie_en0p15_signal_endcap_vs_pt_2024->SetTitle("");
  prof_my_sieie_en0p15_signal_endcap_vs_pt_2024->SetStats(0);
  prof_my_sieie_en0p15_signal_endcap_vs_pt_2024->GetYaxis()->SetRangeUser(0.002,0.05);

  std::cout << "Get profile hist en 3" << std::endl;
  TProfile* prof_my_sieie_en0p5_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_en0p5_signal_endcap_vs_pt;1");
  prof_my_sieie_en0p5_signal_endcap_vs_pt_2024->SetMarkerColor(kMagenta);
  prof_my_sieie_en0p5_signal_endcap_vs_pt_2024->SetLineColor(kMagenta);
  prof_my_sieie_en0p5_signal_endcap_vs_pt_2024->SetLineWidth(3);

  std::cout << "Get profile hist en 4" << std::endl;
  TProfile* prof_my_sieie_en1_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_en1_signal_endcap_vs_pt;1");
  prof_my_sieie_en1_signal_endcap_vs_pt_2024->SetMarkerColor(kGreen+1);
  prof_my_sieie_en1_signal_endcap_vs_pt_2024->SetLineColor(kGreen+1);
  prof_my_sieie_en1_signal_endcap_vs_pt_2024->SetLineWidth(3);

  ///energy cut different in endcap and endcap

  TProfile* prof_my_sieie_en_0p1_0p4_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_en_0p1_0p4_signal_endcap_vs_pt;1");
  prof_my_sieie_en_0p1_0p4_signal_endcap_vs_pt_2024->SetMarkerColor(kCyan+1);
  prof_my_sieie_en_0p1_0p4_signal_endcap_vs_pt_2024->SetLineColor(kCyan+1);
  prof_my_sieie_en_0p1_0p4_signal_endcap_vs_pt_2024->SetLineWidth(3);

  TProfile* prof_my_sieie_en_0p15_0p5_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_en_0p15_0p5_signal_endcap_vs_pt;1");
  prof_my_sieie_en_0p15_0p5_signal_endcap_vs_pt_2024->SetMarkerColor(kYellow+2);
  prof_my_sieie_en_0p15_0p5_signal_endcap_vs_pt_2024->SetLineColor(kYellow+2);
  prof_my_sieie_en_0p15_0p5_signal_endcap_vs_pt_2024->SetLineWidth(3);

  TProfile* prof_my_sieie_en_0p16_0p6_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_en_0p16_0p6_signal_endcap_vs_pt;1");
  prof_my_sieie_en_0p16_0p6_signal_endcap_vs_pt_2024->SetMarkerColor(kGreen-5);
  prof_my_sieie_en_0p16_0p6_signal_endcap_vs_pt_2024->SetLineColor(kGreen-5);
  prof_my_sieie_en_0p16_0p6_signal_endcap_vs_pt_2024->SetLineWidth(3);

  TProfile* prof_my_sieie_en_0p2_1_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_en_0p2_1_signal_endcap_vs_pt;1");
  prof_my_sieie_en_0p2_1_signal_endcap_vs_pt_2024->SetMarkerColor(kTeal+1);
  prof_my_sieie_en_0p2_1_signal_endcap_vs_pt_2024->SetLineColor(kTeal+1);
  prof_my_sieie_en_0p2_1_signal_endcap_vs_pt_2024->SetLineWidth(3);

  TProfile* prof_my_sieie_en_0p2_1p5_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_en_0p2_1p5_signal_endcap_vs_pt;1");
  prof_my_sieie_en_0p2_1p5_signal_endcap_vs_pt_2024->SetMarkerColor(kViolet+1);
  prof_my_sieie_en_0p2_1p5_signal_endcap_vs_pt_2024->SetLineColor(kViolet+1);
  prof_my_sieie_en_0p2_1p5_signal_endcap_vs_pt_2024->SetLineWidth(3);

  TProfile* prof_my_sieie_en_0p2_2_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_en_0p2_2_signal_endcap_vs_pt;1");
  prof_my_sieie_en_0p2_2_signal_endcap_vs_pt_2024->SetMarkerColor(kRed+2);
  prof_my_sieie_en_0p2_2_signal_endcap_vs_pt_2024->SetLineColor(kRed+2);
  prof_my_sieie_en_0p2_2_signal_endcap_vs_pt_2024->SetLineWidth(3);

  TProfile* prof_my_sieie_en_0p18_0p8_signal_endcap_vs_pt_2024  =  (TProfile*)file_2024->Get("prof_cmssw_sieie_en_0p18_0p8_signal_endcap_vs_pt;1");
  prof_my_sieie_en_0p18_0p8_signal_endcap_vs_pt_2024->SetMarkerColor(kPink+1);
  prof_my_sieie_en_0p18_0p8_signal_endcap_vs_pt_2024->SetLineColor(kPink+1);
  prof_my_sieie_en_0p18_0p8_signal_endcap_vs_pt_2024->SetLineWidth(3);

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
  TFile* outputFile = new TFile("compare_sieie.root","RECREATE");
  outputFile->cd();

  TCanvas* my_canvas1 = new TCanvas("canvas","canvas",800,600);
  my_canvas1->cd();
  gPad->SetLogy();
  prof_my_sieie_signal_endcap_vs_pt_2024->Draw();
  prof_my_sieie_w4p0_signal_endcap_vs_pt_2024->Draw("same");
  prof_my_sieie_w3p5_signal_endcap_vs_pt_2024->Draw("same");
  prof_my_sieie_w3p7_signal_endcap_vs_pt_2024->Draw("same");
  prof_my_sieie_w3p0_signal_endcap_vs_pt_2024->Draw("same");

  TLegend *leg_example = new TLegend(0.65,0.70,0.94,0.94);
  leg_example->SetHeader("Sieie, real e, endcap","C"); // option "C" allows to center the header
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(prof_my_sieie_signal_endcap_vs_pt_2024, "default", "lp");
  leg_example->AddEntry(prof_my_sieie_w4p0_signal_endcap_vs_pt_2024, "4.0", "lp");
  leg_example->AddEntry(prof_my_sieie_w3p5_signal_endcap_vs_pt_2024, "3.5", "lp");
  leg_example->AddEntry(prof_my_sieie_w3p7_signal_endcap_vs_pt_2024, "3.7", "lp");
  leg_example->AddEntry(prof_my_sieie_w3p0_signal_endcap_vs_pt_2024, "3.0", "lp");
  leg_example->Draw("same");
  my_canvas1->SetGrid();

  my_canvas1->Write();
  my_canvas1->SaveAs("compareSieie_endcap.pdf");
  my_canvas1->SaveAs("compareSieie_endcap.png");

  ///same energy cut in EB / EE

  TCanvas* my_canvas2 = new TCanvas("canvas2","canvas2",800,600);
  my_canvas2->cd();
  gPad->SetLogy();
  prof_my_sieie_en0p15_signal_endcap_vs_pt_2024->Draw();
  prof_my_sieie_signal_endcap_vs_pt_2024->Draw("same");
  prof_my_sieie_en0p2_signal_endcap_vs_pt_2024->Draw("same");
  prof_my_sieie_en0p5_signal_endcap_vs_pt_2024->Draw("same");
  prof_my_sieie_en1_signal_endcap_vs_pt_2024->Draw("same");
  prof_my_sieie_en_0p16_0p6_signal_endcap_vs_pt_2024->Draw("same");
  prof_my_sieie_en_0p18_0p8_signal_endcap_vs_pt_2024->Draw("same");
  prof_my_sieie_en_0p1_0p4_signal_endcap_vs_pt_2024->Draw("same");
  prof_my_sieie_en_0p2_2_signal_endcap_vs_pt_2024->Draw("same");
  prof_my_sieie_en_0p2_1p5_signal_endcap_vs_pt_2024->Draw("same");

  TLegend *leg_example2 = new TLegend(0.59,0.15,0.94,0.45);
  leg_example2->SetHeader("Sieie, real e, endcap","C"); // option "C" allows to center the header
  leg_example2->SetFillColor(0);
  leg_example2->SetTextFont(42);
  leg_example2->SetBorderSize(0);
  leg_example2->AddEntry(prof_my_sieie_signal_endcap_vs_pt_2024, "default", "lp");
  leg_example2->AddEntry(prof_my_sieie_en0p15_signal_endcap_vs_pt_2024, "0.15", "lp");
  leg_example2->AddEntry(prof_my_sieie_en0p2_signal_endcap_vs_pt_2024, "0.2", "lp");
  leg_example2->AddEntry(prof_my_sieie_en_0p1_0p4_signal_endcap_vs_pt_2024, "0.1 / 0.4", "lp");
  leg_example2->AddEntry(prof_my_sieie_en0p5_signal_endcap_vs_pt_2024, "0.5", "lp");
  leg_example2->AddEntry(prof_my_sieie_en_0p16_0p6_signal_endcap_vs_pt_2024, "0.16 / 0.6", "lp");
  leg_example2->AddEntry(prof_my_sieie_en_0p18_0p8_signal_endcap_vs_pt_2024, "0.18 / 0.8", "lp");
  leg_example2->AddEntry(prof_my_sieie_en1_signal_endcap_vs_pt_2024, "1", "lp");
  leg_example2->AddEntry(prof_my_sieie_en_0p2_1p5_signal_endcap_vs_pt_2024, "0.2 / 1.5", "lp");
  leg_example2->AddEntry(prof_my_sieie_en_0p2_2_signal_endcap_vs_pt_2024, "0.2 / 2", "lp");
  leg_example2->Draw("same");

  my_canvas2->SetGrid();
  
  my_canvas2->Write();
  my_canvas2->SaveAs("compareSieie_sameEncut_endcap.pdf");
  my_canvas2->SaveAs("compareSieie_sameEncut_endcap.png");

  return 0;

}
