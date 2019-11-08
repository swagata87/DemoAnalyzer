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
#include "TGraphErrors.h"
#include "THStack.h"

int PlotsieieRMSvsPU() {

  std::cout << "Get the root files " << std::endl;
  //Out_ptGT80_redefhists_2018

  //  TFile *file_2018 = new TFile("./Out_ptGT50_redefhists_2018.root");
  // TFile *file_2021 = new TFile("./Out_ptGT50_redefhists_2021.root");
  // TFile *file_2023 = new TFile("./Out_ptGT50_redefhists_2023.root");
  TFile *file_2024 = new TFile("./Out_redefhists_2024_pileup.root");

  //--Plotting Styles//
 
  gStyle->SetPadLeftMargin(0.25);
  /*
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
  TFile* outputFile = new TFile("defaultsieie_rms_vs_pu.root","RECREATE");
  outputFile->cd();

  //barrel
  TH1F* barrel_1 = (TH1F*)file_2024->Get("cmssw_sieie_signal_barrel_vs_PU_1");
  TH1F* barrel_2 = (TH1F*)file_2024->Get("cmssw_sieie_signal_barrel_vs_PU_2");
  TH1F* barrel_3 = (TH1F*)file_2024->Get("cmssw_sieie_signal_barrel_vs_PU_3");
  TH1F* barrel_4 = (TH1F*)file_2024->Get("cmssw_sieie_signal_barrel_vs_PU_4");

  TH1F* barrel_1_w = (TH1F*)file_2024->Get("my_sieie_w4p1_signal_barrel_vs_PU_1");
  TH1F* barrel_2_w = (TH1F*)file_2024->Get("my_sieie_w4p1_signal_barrel_vs_PU_2");
  TH1F* barrel_3_w = (TH1F*)file_2024->Get("my_sieie_w4p1_signal_barrel_vs_PU_3");
  TH1F* barrel_4_w = (TH1F*)file_2024->Get("my_sieie_w4p1_signal_barrel_vs_PU_4");

  TH1F* barrel_1_pr = (TH1F*)file_2024->Get("my_sieie_per_rechit_m1p25_signal_barrel_vs_PU_1");
  TH1F* barrel_2_pr = (TH1F*)file_2024->Get("my_sieie_per_rechit_m1p25_signal_barrel_vs_PU_2");
  TH1F* barrel_3_pr = (TH1F*)file_2024->Get("my_sieie_per_rechit_m1p25_signal_barrel_vs_PU_3");
  TH1F* barrel_4_pr = (TH1F*)file_2024->Get("my_sieie_per_rechit_m1p25_signal_barrel_vs_PU_4");

  //endcap
  TH1F* endcap_1 = (TH1F*)file_2024->Get("cmssw_sieie_signal_endcap_vs_PU_1");
  TH1F* endcap_2 = (TH1F*)file_2024->Get("cmssw_sieie_signal_endcap_vs_PU_2");
  TH1F* endcap_3 = (TH1F*)file_2024->Get("cmssw_sieie_signal_endcap_vs_PU_3");
  TH1F* endcap_4 = (TH1F*)file_2024->Get("cmssw_sieie_signal_endcap_vs_PU_4");

  TH1F* endcap_1_w = (TH1F*)file_2024->Get("my_sieie_w3p2_signal_endcap_vs_PU_1");
  TH1F* endcap_2_w = (TH1F*)file_2024->Get("my_sieie_w3p2_signal_endcap_vs_PU_2");
  TH1F* endcap_3_w = (TH1F*)file_2024->Get("my_sieie_w3p2_signal_endcap_vs_PU_3");
  TH1F* endcap_4_w = (TH1F*)file_2024->Get("my_sieie_w3p2_signal_endcap_vs_PU_4");

  TH1F* endcap_1_pr = (TH1F*)file_2024->Get("my_sieie_per_rechit_m1p25_signal_endcap_vs_PU_1");
  TH1F* endcap_2_pr = (TH1F*)file_2024->Get("my_sieie_per_rechit_m1p25_signal_endcap_vs_PU_2");
  TH1F* endcap_3_pr = (TH1F*)file_2024->Get("my_sieie_per_rechit_m1p25_signal_endcap_vs_PU_3");
  TH1F* endcap_4_pr = (TH1F*)file_2024->Get("my_sieie_per_rechit_m1p25_signal_endcap_vs_PU_4");

  std::vector<float> x_pu;
  std::vector<float> y_rms_sieie;
  std::vector<float> y_rms_sieie_w;
  std::vector<float> y_rms_sieie_pr;
  std::vector<float> y_mean_sieie;
  std::vector<float> y_mean_sieie_w;
  std::vector<float> y_mean_sieie_pr;

  std::vector<float> x_pu_err;
  std::vector<float> y_rms_sieie_err;
  std::vector<float> y_rms_sieie_err_w;
  std::vector<float> y_rms_sieie_err_pr;
  std::vector<float> y_mean_sieie_err;
  std::vector<float> y_mean_sieie_err_w;
  std::vector<float> y_mean_sieie_err_pr;

  x_pu.push_back( (60+55)/2.0 );
  x_pu_err.push_back( (60-55)/2.0 );
  y_rms_sieie.push_back( barrel_1->GetStdDev()  );
  y_rms_sieie_err.push_back( barrel_1->GetStdDevError()  );
  y_mean_sieie.push_back( barrel_1->GetMean()  );
  y_mean_sieie_err.push_back( barrel_1->GetMeanError()  );
  y_rms_sieie_w.push_back( barrel_1_w->GetStdDev()  );
  y_rms_sieie_err_w.push_back( barrel_1_w->GetStdDevError()  );
  y_mean_sieie_w.push_back( barrel_1_w->GetMean()  );
  y_mean_sieie_err_w.push_back( barrel_1_w->GetMeanError()  );
  y_rms_sieie_pr.push_back( barrel_1_pr->GetStdDev()  );
  y_rms_sieie_err_pr.push_back( barrel_1_pr->GetStdDevError()  );
  y_mean_sieie_pr.push_back( barrel_1_pr->GetMean()  );
  y_mean_sieie_err_pr.push_back( barrel_1_pr->GetMeanError()  );

  x_pu.push_back( (65+60)/2.0 );
  x_pu_err.push_back( (65-60)/2.0 );
  y_rms_sieie.push_back( barrel_2->GetStdDev()  );
  y_rms_sieie_err.push_back( barrel_2->GetStdDevError()  );
  y_mean_sieie.push_back( barrel_2->GetMean()  );
  y_mean_sieie_err.push_back( barrel_2->GetMeanError()  );
  y_rms_sieie_w.push_back( barrel_2_w->GetStdDev()  );
  y_rms_sieie_err_w.push_back( barrel_2_w->GetStdDevError()  );
  y_mean_sieie_w.push_back( barrel_2_w->GetMean()  );
  y_mean_sieie_err_w.push_back( barrel_2_w->GetMeanError()  );
  y_rms_sieie_pr.push_back( barrel_2_pr->GetStdDev()  );
  y_rms_sieie_err_pr.push_back( barrel_2_pr->GetStdDevError()  );
  y_mean_sieie_pr.push_back( barrel_2_pr->GetMean()  );
  y_mean_sieie_err_pr.push_back( barrel_2_pr->GetMeanError()  );

  x_pu.push_back( (70+65)/2.0 );
  x_pu_err.push_back( (70-65)/2.0 );
  y_rms_sieie.push_back( barrel_3->GetStdDev()  );
  y_rms_sieie_err.push_back( barrel_3->GetStdDevError()  );
  y_mean_sieie.push_back( barrel_3->GetMean()  );
  y_mean_sieie_err.push_back( barrel_3->GetMeanError()  );
  y_rms_sieie_w.push_back( barrel_3_w->GetStdDev()  );
  y_rms_sieie_err_w.push_back( barrel_3_w->GetStdDevError()  );
  y_mean_sieie_w.push_back( barrel_3_w->GetMean()  );
  y_mean_sieie_err_w.push_back( barrel_3_w->GetMeanError()  );
  y_rms_sieie_pr.push_back( barrel_3_pr->GetStdDev()  );
  y_rms_sieie_err_pr.push_back( barrel_3_pr->GetStdDevError()  );
  y_mean_sieie_pr.push_back( barrel_3_pr->GetMean()  );
  y_mean_sieie_err_pr.push_back( barrel_3_pr->GetMeanError()  );

  x_pu.push_back( (75+70)/2.0 );
  x_pu_err.push_back( (75-70)/2.0 );
  y_rms_sieie.push_back( barrel_4->GetStdDev()  );
  y_rms_sieie_err.push_back( barrel_4->GetStdDevError()  );
  y_mean_sieie.push_back( barrel_4->GetMean()  );
  y_mean_sieie_err.push_back( barrel_4->GetMeanError()  );
  y_rms_sieie_w.push_back( barrel_4_w->GetStdDev()  );
  y_rms_sieie_err_w.push_back( barrel_4_w->GetStdDevError()  );
  y_mean_sieie_w.push_back( barrel_4_w->GetMean()  );
  y_mean_sieie_err_w.push_back( barrel_4_w->GetMeanError()  );
  y_rms_sieie_pr.push_back( barrel_4_pr->GetStdDev()  );
  y_rms_sieie_err_pr.push_back( barrel_4_pr->GetStdDevError()  );
  y_mean_sieie_pr.push_back( barrel_4_pr->GetMean()  );
  y_mean_sieie_err_pr.push_back( barrel_4_pr->GetMeanError()  );

  /////draw RMS
  TCanvas* my_canvas1 = new TCanvas("canvas","canvas",800,600);
  my_canvas1->cd();
  TGraphErrors *gr1 = new TGraphErrors (4, &x_pu[0], &y_rms_sieie[0], &x_pu_err[0], &y_rms_sieie_err[0]);
  gr1->SetTitle("#sigma_{i#eta i#eta} RMS vs PU (barrel)");
  gr1->SetMarkerColor(2);
  gr1->SetLineColor(2);
  gr1->SetLineWidth(2);
  gr1->SetMarkerStyle(21);
  gr1->Draw("AP");
  gr1->GetYaxis()->SetTitle("Sieie RMS");
  gr1->GetXaxis()->SetTitle("nPU");
  gr1->GetHistogram()->SetMaximum(0.003);   // along                                                                                              
  gr1->GetHistogram()->SetMinimum(0.001);  //   Y                                                                                                        
  //  gr1->GetXaxis()->SetLimits(0.0,1.05);
  gr1->Write("cmsswsieie");

  TGraphErrors *gr2 = new TGraphErrors (4, &x_pu[0], &y_rms_sieie_w[0], &x_pu_err[0], &y_rms_sieie_err_w[0]);
  gr2->SetMarkerColor(3);
  gr2->SetLineColor(3);
  gr2->SetLineWidth(2);
  gr2->SetMarkerStyle(22);
  gr2->Draw("P:same");
  gr2->Write("sieie_w");

  TGraphErrors *gr3 = new TGraphErrors (4, &x_pu[0], &y_rms_sieie_pr[0], &x_pu_err[0], &y_rms_sieie_err_pr[0]);
  gr3->SetMarkerColor(4);
  gr3->SetLineColor(4);
  gr3->SetLineWidth(2);
  gr3->SetMarkerStyle(23);
  gr3->Draw("P:same");
  gr3->Write("sieie_pr");

  TLegend *leg_example_1 = new TLegend(0.6,0.74,0.94,0.94);
  leg_example_1->SetHeader("Sieie, signal, barrel","C"); // option "C" allows to center the header
  leg_example_1->SetFillColor(0);
  leg_example_1->SetTextFont(42);
  leg_example_1->SetBorderSize(0);
  leg_example_1->AddEntry(gr1, "default, w=4.7", "lp");
  leg_example_1->AddEntry(gr2, "w=4.1", "lp");
  leg_example_1->AddEntry(gr3, "per rechit * 1.25", "lp");
  leg_example_1->Draw("same");

  my_canvas1->SetGrid();
  my_canvas1->Write();
  my_canvas1->SaveAs("sieie_rms_vs_pu_barrel.pdf");
  my_canvas1->SaveAs("sieie_rms_vs_pu_barrel.png");

  ///draw mean
  TCanvas* my_canvas1_mean = new TCanvas("canvas_mean","canvas_mean",800,600);
  my_canvas1_mean->cd();
  TGraphErrors *gr1_mean = new TGraphErrors (4, &x_pu[0], &y_mean_sieie[0], &x_pu_err[0], &y_mean_sieie_err[0]);
  gr1_mean->SetTitle("#sigma_{i#eta i#eta} MEAN vs PU (barrel)");
  gr1_mean->SetMarkerColor(2);
  gr1_mean->SetLineColor(2);
  gr1_mean->SetLineWidth(2);
  gr1_mean->SetMarkerStyle(21);
  gr1_mean->Draw("AP");
  gr1_mean->GetYaxis()->SetTitle("Sieie MEAN");
  gr1_mean->GetXaxis()->SetTitle("nPU");
  gr1_mean->GetHistogram()->SetMaximum(0.03);   // along                                                                                              
  gr1_mean->GetHistogram()->SetMinimum(0.001);  //   Y                                                                                                        
  //  gr1_mean->GetXaxis()->SetLimits(0.0,1.05);
  gr1_mean->Write("cmsswsieie_mean");

  TGraphErrors *gr2_mean = new TGraphErrors (4, &x_pu[0], &y_mean_sieie_w[0], &x_pu_err[0], &y_mean_sieie_err_w[0]);
  gr2_mean->SetMarkerColor(3);
  gr2_mean->SetLineColor(3);
  gr2_mean->SetLineWidth(2);
  gr2_mean->SetMarkerStyle(22);
  gr2_mean->Draw("P:same");
  gr2_mean->Write("sieie_w");

  TGraphErrors *gr3_mean = new TGraphErrors (4, &x_pu[0], &y_mean_sieie_pr[0], &x_pu_err[0], &y_mean_sieie_err_pr[0]);
  gr3_mean->SetMarkerColor(4);
  gr3_mean->SetLineColor(4);
  gr3_mean->SetLineWidth(2);
  gr3_mean->SetMarkerStyle(23);
  gr3_mean->Draw("P:same");
  gr3_mean->Write("sieie_pr");

  TLegend *leg_example_1_mean = new TLegend(0.6,0.74,0.94,0.94);
  leg_example_1_mean->SetHeader("Sieie, signal, barrel","C"); // option "C" allows to center the header
  leg_example_1_mean->SetFillColor(0);
  leg_example_1_mean->SetTextFont(42);
  leg_example_1_mean->SetBorderSize(0);
  leg_example_1_mean->AddEntry(gr1_mean, "default, w=4.7", "lp");
  leg_example_1_mean->AddEntry(gr2_mean, "w=4.1", "lp");
  leg_example_1_mean->AddEntry(gr3_mean, "per rechit * 1.25", "lp");
  leg_example_1_mean->Draw("same");

  my_canvas1_mean->SetGrid();
  my_canvas1_mean->Write();
  my_canvas1_mean->SaveAs("sieie_mean_vs_pu_barrel.pdf");
  my_canvas1_mean->SaveAs("sieie_mean_vs_pu_barrel.png");

  ////endcap
  std::vector<float> x_pu_e;
  std::vector<float> x_pu_err_e;
  std::vector<float> y_rms_sieie_err_e;
  std::vector<float> y_rms_sieie_e;
  std::vector<float> y_mean_sieie_e;
  std::vector<float> y_mean_sieie_err_e;

  std::vector<float> y_rms_sieie_e_w;
  std::vector<float> y_mean_sieie_e_w;
  std::vector<float> y_rms_sieie_err_e_w;
  std::vector<float> y_mean_sieie_err_e_w;

  std::vector<float> y_rms_sieie_e_pr;
  std::vector<float> y_mean_sieie_e_pr;
  std::vector<float> y_rms_sieie_err_e_pr;
  std::vector<float> y_mean_sieie_err_e_pr;

  x_pu_e.push_back( (60+55)/2.0 );
  x_pu_err_e.push_back( (60-55)/2.0 );
  y_rms_sieie_e.push_back( endcap_1->GetStdDev()  );
  y_rms_sieie_err_e.push_back( endcap_1->GetStdDevError()  );
  y_mean_sieie_e.push_back( endcap_1->GetMean()  );
  y_mean_sieie_err_e.push_back( endcap_1->GetMeanError()  );
  y_rms_sieie_e_w.push_back( endcap_1_w->GetStdDev()  );
  y_rms_sieie_err_e_w.push_back( endcap_1_w->GetStdDevError()  );
  y_mean_sieie_e_w.push_back( endcap_1_w->GetMean()  );
  y_mean_sieie_err_e_w.push_back( endcap_1_w->GetMeanError()  );
  y_rms_sieie_e_pr.push_back( endcap_1_pr->GetStdDev()  );
  y_rms_sieie_err_e_pr.push_back( endcap_1_pr->GetStdDevError()  );
  y_mean_sieie_e_pr.push_back( endcap_1_pr->GetMean()  );
  y_mean_sieie_err_e_pr.push_back( endcap_1_pr->GetMeanError()  );

  x_pu_e.push_back( (65+60)/2.0 );
  x_pu_err_e.push_back( (65-60)/2.0 );
  y_rms_sieie_e.push_back( endcap_2->GetStdDev()  );
  y_rms_sieie_err_e.push_back( endcap_2->GetStdDevError()  );
  y_mean_sieie_e.push_back( endcap_2->GetMean()  );
  y_mean_sieie_err_e.push_back( endcap_2->GetMeanError()  );
  y_rms_sieie_e_w.push_back( endcap_2_w->GetStdDev()  );
  y_rms_sieie_err_e_w.push_back( endcap_2_w->GetStdDevError()  );
  y_mean_sieie_e_w.push_back( endcap_2_w->GetMean()  );
  y_mean_sieie_err_e_w.push_back( endcap_2_w->GetMeanError()  );
  y_rms_sieie_e_pr.push_back( endcap_2_pr->GetStdDev()  );
  y_rms_sieie_err_e_pr.push_back( endcap_2_pr->GetStdDevError()  );
  y_mean_sieie_e_pr.push_back( endcap_2_pr->GetMean()  );
  y_mean_sieie_err_e_pr.push_back( endcap_2_pr->GetMeanError()  );

  x_pu_e.push_back( (70+65)/2.0 );
  x_pu_err_e.push_back( (70-65)/2.0 );
  y_rms_sieie_e.push_back( endcap_3->GetStdDev()  );
  y_rms_sieie_err_e.push_back( endcap_3->GetStdDevError()  );
  y_mean_sieie_e.push_back( endcap_3->GetMean()  );
  y_mean_sieie_err_e.push_back( endcap_3->GetMeanError()  );
  y_rms_sieie_e_w.push_back( endcap_3_w->GetStdDev()  );
  y_rms_sieie_err_e_w.push_back( endcap_3_w->GetStdDevError()  );
  y_mean_sieie_e_w.push_back( endcap_3_w->GetMean()  );
  y_mean_sieie_err_e_w.push_back( endcap_3_w->GetMeanError()  );
  y_rms_sieie_e_pr.push_back( endcap_3_pr->GetStdDev()  );
  y_rms_sieie_err_e_pr.push_back( endcap_3_pr->GetStdDevError()  );
  y_mean_sieie_e_pr.push_back( endcap_3_pr->GetMean()  );
  y_mean_sieie_err_e_pr.push_back( endcap_3_pr->GetMeanError()  );

  x_pu_e.push_back( (75+70)/2.0 );
  x_pu_err_e.push_back( (75-70)/2.0 );
  y_rms_sieie_e.push_back( endcap_4->GetStdDev()  );
  y_rms_sieie_err_e.push_back( endcap_4->GetStdDevError()  );
  y_mean_sieie_e.push_back( endcap_4->GetMean()  );
  y_mean_sieie_err_e.push_back( endcap_4->GetMeanError()  );
  y_rms_sieie_e_w.push_back( endcap_4_w->GetStdDev()  );
  y_rms_sieie_err_e_w.push_back( endcap_4_w->GetStdDevError()  );
  y_mean_sieie_e_w.push_back( endcap_4_w->GetMean()  );
  y_mean_sieie_err_e_w.push_back( endcap_4_w->GetMeanError()  );
  y_rms_sieie_e_pr.push_back( endcap_4_pr->GetStdDev()  );
  y_rms_sieie_err_e_pr.push_back( endcap_4_pr->GetStdDevError()  );
  y_mean_sieie_e_pr.push_back( endcap_4_pr->GetMean()  );
  y_mean_sieie_err_e_pr.push_back( endcap_4_pr->GetMeanError()  );

  //draw rms
  TCanvas* my_canvas1_e = new TCanvas("canvase","canvase",800,600);
  my_canvas1_e->cd();
  TGraphErrors *gr1_e = new TGraphErrors (4, &x_pu_e[0], &y_rms_sieie_e[0], &x_pu_err_e[0], &y_rms_sieie_err_e[0]);
  gr1_e->SetTitle("#sigma_{i#eta i#eta} RMS vs PU (endcap)");
  gr1_e->SetMarkerColor(2);
  gr1_e->SetLineColor(2);
  gr1_e->SetLineWidth(2);
  gr1_e->SetMarkerStyle(21);
  gr1_e->Draw("AP");
  gr1_e->GetYaxis()->SetTitle("Sieie RMS");
  gr1_e->GetXaxis()->SetTitle("nPU");
  gr1_e->GetHistogram()->SetMaximum(0.009);   // along                                                                                                 
  gr1_e->GetHistogram()->SetMinimum(0.006);  //   Y                                                                                           
  //  gr1->GetXaxis()->SetLimits(0.0,1.05);
  gr1_e->Write("cmsswsieie_e");

  TGraphErrors *gr2_e = new TGraphErrors (4, &x_pu_e[0], &y_rms_sieie_e_w[0], &x_pu_err_e[0], &y_rms_sieie_err_e_w[0]);
  gr2_e->SetMarkerColor(3);
  gr2_e->SetLineColor(3);
  gr2_e->SetLineWidth(2);
  gr2_e->SetMarkerStyle(22);
  gr2_e->Draw("P:same");
  gr2_e->Write("cmsswsieie_e_w");

  TGraphErrors *gr3_e = new TGraphErrors (4, &x_pu_e[0], &y_rms_sieie_e_pr[0], &x_pu_err_e[0], &y_rms_sieie_err_e_pr[0]);
  gr3_e->SetMarkerColor(4);
  gr3_e->SetLineColor(4);
  gr3_e->SetLineWidth(2);
  gr3_e->SetMarkerStyle(23);
  gr3_e->Draw("P:same");
  gr3_e->Write("cmsswsieie_e_pr");
  
  TLegend *leg_example = new TLegend(0.65,0.74,0.94,0.94);
  leg_example->SetHeader("Sieie, signal, endcap","C"); // option "C" allows to center the header
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(gr1_e, "default, w=4.7", "lp");
  leg_example->AddEntry(gr2_e, "w=3.2", "lp");
  leg_example->AddEntry(gr3_e, "per rechit * 1.25", "lp");
  leg_example->Draw("same");

  my_canvas1_e->SetGrid();
  my_canvas1_e->Write();
  my_canvas1_e->SaveAs("sieie_rms_vs_pu_endcap.pdf");
  my_canvas1_e->SaveAs("sieie_rms_vs_pu_endcap.png");


  /////draw mean
  TCanvas* my_canvas1_e_mean = new TCanvas("canvase_mean","canvase_mean",800,600);
  my_canvas1_e_mean->cd();
  TGraphErrors *gr1_mean_e = new TGraphErrors (4, &x_pu_e[0], &y_mean_sieie_e[0], &x_pu_err_e[0], &y_mean_sieie_err_e[0]);
  gr1_mean_e->SetTitle("#sigma_{i#eta i#eta} MEAN vs PU (endcap)");
  gr1_mean_e->SetMarkerColor(2);
  gr1_mean_e->SetLineColor(2);
  gr1_mean_e->SetLineWidth(2);
  gr1_mean_e->SetMarkerStyle(21);
  gr1_mean_e->Draw("AP");
  gr1_mean_e->GetYaxis()->SetTitle("Sieie MEAN");
  gr1_mean_e->GetXaxis()->SetTitle("nPU");
  gr1_mean_e->GetHistogram()->SetMaximum(0.09);   // along                                                                                                 
  gr1_mean_e->GetHistogram()->SetMinimum(0.006);  //   Y                                                                                           
  //  gr1_mean->GetXaxis()->SetLimits(0.0,1.05);
  gr1_mean_e->Write("cmsswsieie_e");

  TGraphErrors *gr2_mean_e = new TGraphErrors (4, &x_pu_e[0], &y_mean_sieie_e_w[0], &x_pu_err_e[0], &y_mean_sieie_err_e_w[0]);
  gr2_mean_e->SetMarkerColor(3);
  gr2_mean_e->SetLineColor(3);
  gr2_mean_e->SetLineWidth(2);
  gr2_mean_e->SetMarkerStyle(22);
  gr2_mean_e->Draw("P:same");
  gr2_mean_e->Write("cmsswsieie_e_w");

  TGraphErrors *gr3_mean_e = new TGraphErrors (4, &x_pu_e[0], &y_mean_sieie_e_pr[0], &x_pu_err_e[0], &y_mean_sieie_err_e_pr[0]);
  gr3_mean_e->SetMarkerColor(4);
  gr3_mean_e->SetLineColor(4);
  gr3_mean_e->SetLineWidth(2);
  gr3_mean_e->SetMarkerStyle(23);
  gr3_mean_e->Draw("P:same");
  gr3_mean_e->Write("cmsswsieie_e_pr");
  
  TLegend *leg_example_mean = new TLegend(0.65,0.74,0.94,0.94);
  leg_example_mean->SetHeader("Sieie, signal, endcap","C"); // option "C" allows to center the header
  leg_example_mean->SetFillColor(0);
  leg_example_mean->SetTextFont(42);
  leg_example_mean->SetBorderSize(0);
  leg_example_mean->AddEntry(gr1_mean_e, "default, w=4.7", "lp");
  leg_example_mean->AddEntry(gr2_mean_e, "w=3.2", "lp");
  leg_example_mean->AddEntry(gr3_mean_e, "per rechit * 1.25", "lp");
  leg_example_mean->Draw("same");

  my_canvas1_e_mean->SetGrid();
  my_canvas1_e_mean->Write();
  my_canvas1_e_mean->SaveAs("sieie_mean_vs_pu_endcap.pdf");
  my_canvas1_e_mean->SaveAs("sieie_mean_vs_pu_endcap.png");



  return 0;

}
