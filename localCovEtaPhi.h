//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Nov 11 12:18:13 2019 by ROOT version 6.14/09
// from TTree EventTree/EventData
// found on file: RedefNtup_AOD_2024.root
//////////////////////////////////////////////////////////

#ifndef localCovEtaPhi_h
#define localCovEtaPhi_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"

class localCovEtaPhi {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxcrysEta = 1;
   static constexpr Int_t kMaxcrysPhi = 1;
   static constexpr Int_t kMaxcrysThr = 1;
   static constexpr Int_t kMaxele_genmatched = 1;
   static constexpr Int_t kMaxtrkCharge = 1;
   static constexpr Int_t kMaxcmssw_eleSigmaIetaIeta = 1;
   static constexpr Int_t kMaxcmssw_eleSigmaIphiIphi = 1;
   static constexpr Int_t kMaxcmssw_eleR9 = 1;
   static constexpr Int_t kMaxcmssw_eleHoE = 1;
   static constexpr Int_t kMaxeleScEta = 1;
   static constexpr Int_t kMaxeleScEn = 1;
   static constexpr Int_t kMaxelePt = 1;
   static constexpr Int_t kMaxptRecoEle_by_ptGenEle = 1;
   static constexpr Int_t kMaxdR_recoEle_genEle = 1;
   static constexpr Int_t kMaxpuTrue = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_per_rechit = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_per_rechit_m1p05 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_per_rechit_m1p1 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_per_rechit_m1p15 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_per_rechit_m1p2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_per_rechit_m1p25 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_per_rechit = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_per_rechit_m1p05 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_per_rechit_m1p1 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_per_rechit_m1p15 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_per_rechit_m1p2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_per_rechit_m1p25 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_per_rechit = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_per_rechit_m1p05 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_per_rechit_m1p1 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_per_rechit_m1p15 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_per_rechit_m1p2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_per_rechit_m1p25 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w4p6 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w4p5 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w4p4 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w4p3 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w4p2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w4p1 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w4p0 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w3p8 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w3p7 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w3p6 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w3p5 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w3p4 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w3p3 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w3p2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_w3p0 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w4p6 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w4p5 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w4p4 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w4p3 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w4p2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w4p1 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w4p0 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w3p8 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w3p7 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w3p6 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w3p5 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w3p4 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w3p3 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w3p2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_w3p0 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w4p6 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w4p5 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w4p4 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w4p3 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w4p2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w4p1 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w4p0 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w3p8 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w3p7 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w3p6 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w3p5 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w3p4 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w3p3 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w3p2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIphiIphi_w3p0 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en0p2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en0p15 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en0p5 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en1 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en0p2_noRelNoiseCut = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en0p15_noRelNoiseCut = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en0p5_noRelNoiseCut = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en1_noRelNoiseCut = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en_0p1_0p4 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en_0p15_0p5 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en_0p16_0p6 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en_0p2_1 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en_0p2_1p5 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en_0p2_2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_en_0p18_0p8 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en0p2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en0p15 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en0p5 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en1 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en0p2_noRelNoiseCut = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en0p15_noRelNoiseCut = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en0p5_noRelNoiseCut = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en1_noRelNoiseCut = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en_0p1_0p4 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en_0p15_0p5 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en_0p16_0p6 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en_0p2_1 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en_0p2_1p5 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en_0p2_2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIphi_en_0p18_0p8 = 1;
   static constexpr Int_t kMaxgen_status = 1;
   static constexpr Int_t kMaxgen_pdgid = 1;
   static constexpr Int_t kMaxgen_pt = 1;

   // Declaration of leaf types
   vector<float>   *crysEta_;
   vector<float>   *crysPhi_;
   vector<float>   *crysThr_;
   vector<int>     *ele_genmatched_;
   vector<int>     *trkCharge_;
   vector<double>  *cmssw_eleSigmaIetaIeta_;
   vector<double>  *cmssw_eleSigmaIphiIphi_;
   vector<float>   *cmssw_eleR9_;
   vector<float>   *cmssw_eleHoE_;
   vector<float>   *eleScEta_;
   vector<float>   *eleScEn_;
   vector<float>   *elePt_;
   vector<float>   *ptRecoEle_by_ptGenEle_;
   vector<float>   *dR_recoEle_genEle_;
   vector<float>   *puTrue_;
   vector<double>  *my_eleSigmaIetaIeta_;
   vector<double>  *my_eleSigmaIphiIphi_;
   vector<double>  *my_eleSigmaIetaIphi_;
   vector<double>  *my_eleSigmaIetaIeta_per_rechit_;
   vector<double>  *my_eleSigmaIetaIeta_per_rechit_m1p05_;
   vector<double>  *my_eleSigmaIetaIeta_per_rechit_m1p1_;
   vector<double>  *my_eleSigmaIetaIeta_per_rechit_m1p15_;
   vector<double>  *my_eleSigmaIetaIeta_per_rechit_m1p2_;
   vector<double>  *my_eleSigmaIetaIeta_per_rechit_m1p25_;
   vector<double>  *my_eleSigmaIetaIphi_per_rechit_;
   vector<double>  *my_eleSigmaIetaIphi_per_rechit_m1p05_;
   vector<double>  *my_eleSigmaIetaIphi_per_rechit_m1p1_;
   vector<double>  *my_eleSigmaIetaIphi_per_rechit_m1p15_;
   vector<double>  *my_eleSigmaIetaIphi_per_rechit_m1p2_;
   vector<double>  *my_eleSigmaIetaIphi_per_rechit_m1p25_;
   vector<double>  *my_eleSigmaIphiIphi_per_rechit_;
   vector<double>  *my_eleSigmaIphiIphi_per_rechit_m1p05_;
   vector<double>  *my_eleSigmaIphiIphi_per_rechit_m1p1_;
   vector<double>  *my_eleSigmaIphiIphi_per_rechit_m1p15_;
   vector<double>  *my_eleSigmaIphiIphi_per_rechit_m1p2_;
   vector<double>  *my_eleSigmaIphiIphi_per_rechit_m1p25_;
   vector<double>  *my_eleSigmaIetaIeta_w4p6_;
   vector<double>  *my_eleSigmaIetaIeta_w4p5_;
   vector<double>  *my_eleSigmaIetaIeta_w4p4_;
   vector<double>  *my_eleSigmaIetaIeta_w4p3_;
   vector<double>  *my_eleSigmaIetaIeta_w4p2_;
   vector<double>  *my_eleSigmaIetaIeta_w4p1_;
   vector<double>  *my_eleSigmaIetaIeta_w4p0_;
   vector<double>  *my_eleSigmaIetaIeta_w3p8_;
   vector<double>  *my_eleSigmaIetaIeta_w3p7_;
   vector<double>  *my_eleSigmaIetaIeta_w3p6_;
   vector<double>  *my_eleSigmaIetaIeta_w3p5_;
   vector<double>  *my_eleSigmaIetaIeta_w3p4_;
   vector<double>  *my_eleSigmaIetaIeta_w3p3_;
   vector<double>  *my_eleSigmaIetaIeta_w3p2_;
   vector<double>  *my_eleSigmaIetaIeta_w3p0_;
   vector<double>  *my_eleSigmaIetaIphi_w4p6_;
   vector<double>  *my_eleSigmaIetaIphi_w4p5_;
   vector<double>  *my_eleSigmaIetaIphi_w4p4_;
   vector<double>  *my_eleSigmaIetaIphi_w4p3_;
   vector<double>  *my_eleSigmaIetaIphi_w4p2_;
   vector<double>  *my_eleSigmaIetaIphi_w4p1_;
   vector<double>  *my_eleSigmaIetaIphi_w4p0_;
   vector<double>  *my_eleSigmaIetaIphi_w3p8_;
   vector<double>  *my_eleSigmaIetaIphi_w3p7_;
   vector<double>  *my_eleSigmaIetaIphi_w3p6_;
   vector<double>  *my_eleSigmaIetaIphi_w3p5_;
   vector<double>  *my_eleSigmaIetaIphi_w3p4_;
   vector<double>  *my_eleSigmaIetaIphi_w3p3_;
   vector<double>  *my_eleSigmaIetaIphi_w3p2_;
   vector<double>  *my_eleSigmaIetaIphi_w3p0_;
   vector<double>  *my_eleSigmaIphiIphi_w4p6_;
   vector<double>  *my_eleSigmaIphiIphi_w4p5_;
   vector<double>  *my_eleSigmaIphiIphi_w4p4_;
   vector<double>  *my_eleSigmaIphiIphi_w4p3_;
   vector<double>  *my_eleSigmaIphiIphi_w4p2_;
   vector<double>  *my_eleSigmaIphiIphi_w4p1_;
   vector<double>  *my_eleSigmaIphiIphi_w4p0_;
   vector<double>  *my_eleSigmaIphiIphi_w3p8_;
   vector<double>  *my_eleSigmaIphiIphi_w3p7_;
   vector<double>  *my_eleSigmaIphiIphi_w3p6_;
   vector<double>  *my_eleSigmaIphiIphi_w3p5_;
   vector<double>  *my_eleSigmaIphiIphi_w3p4_;
   vector<double>  *my_eleSigmaIphiIphi_w3p3_;
   vector<double>  *my_eleSigmaIphiIphi_w3p2_;
   vector<double>  *my_eleSigmaIphiIphi_w3p0_;
   vector<double>  *my_eleSigmaIetaIeta_en0p2_;
   vector<double>  *my_eleSigmaIetaIeta_en0p15_;
   vector<double>  *my_eleSigmaIetaIeta_en0p5_;
   vector<double>  *my_eleSigmaIetaIeta_en1_;
   vector<double>  *my_eleSigmaIetaIeta_en0p2_noRelNoiseCut_;
   vector<double>  *my_eleSigmaIetaIeta_en0p15_noRelNoiseCut_;
   vector<double>  *my_eleSigmaIetaIeta_en0p5_noRelNoiseCut_;
   vector<double>  *my_eleSigmaIetaIeta_en1_noRelNoiseCut_;
   vector<double>  *my_eleSigmaIetaIeta_en_0p1_0p4_;
   vector<double>  *my_eleSigmaIetaIeta_en_0p15_0p5_;
   vector<double>  *my_eleSigmaIetaIeta_en_0p16_0p6_;
   vector<double>  *my_eleSigmaIetaIeta_en_0p2_1_;
   vector<double>  *my_eleSigmaIetaIeta_en_0p2_1p5_;
   vector<double>  *my_eleSigmaIetaIeta_en_0p2_2_;
   vector<double>  *my_eleSigmaIetaIeta_en_0p18_0p8_;
   vector<double>  *my_eleSigmaIetaIphi_en0p2_;
   vector<double>  *my_eleSigmaIetaIphi_en0p15_;
   vector<double>  *my_eleSigmaIetaIphi_en0p5_;
   vector<double>  *my_eleSigmaIetaIphi_en1_;
   vector<double>  *my_eleSigmaIetaIphi_en0p2_noRelNoiseCut_;
   vector<double>  *my_eleSigmaIetaIphi_en0p15_noRelNoiseCut_;
   vector<double>  *my_eleSigmaIetaIphi_en0p5_noRelNoiseCut_;
   vector<double>  *my_eleSigmaIetaIphi_en1_noRelNoiseCut_;
   vector<double>  *my_eleSigmaIetaIphi_en_0p1_0p4_;
   vector<double>  *my_eleSigmaIetaIphi_en_0p15_0p5_;
   vector<double>  *my_eleSigmaIetaIphi_en_0p16_0p6_;
   vector<double>  *my_eleSigmaIetaIphi_en_0p2_1_;
   vector<double>  *my_eleSigmaIetaIphi_en_0p2_1p5_;
   vector<double>  *my_eleSigmaIetaIphi_en_0p2_2_;
   vector<double>  *my_eleSigmaIetaIphi_en_0p18_0p8_;
   vector<int>     *gen_status_;
   vector<int>     *gen_pdgid_;
   vector<float>   *gen_pt_;

   // List of branches
   TBranch        *b_crysEta_;   //!
   TBranch        *b_crysPhi_;   //!
   TBranch        *b_crysThr_;   //!
   TBranch        *b_ele_genmatched_;   //!
   TBranch        *b_trkCharge_;   //!
   TBranch        *b_cmssw_eleSigmaIetaIeta_;   //!
   TBranch        *b_cmssw_eleSigmaIphiIphi_;   //!
   TBranch        *b_cmssw_eleR9_;   //!
   TBranch        *b_cmssw_eleHoE_;   //!
   TBranch        *b_eleScEta_;   //!
   TBranch        *b_eleScEn_;   //!
   TBranch        *b_elePt_;   //!
   TBranch        *b_ptRecoEle_by_ptGenEle_;   //!
   TBranch        *b_dR_recoEle_genEle_;   //!
   TBranch        *b_puTrue_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_per_rechit_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_per_rechit_m1p05_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_per_rechit_m1p1_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_per_rechit_m1p15_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_per_rechit_m1p2_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_per_rechit_m1p25_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_per_rechit_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_per_rechit_m1p05_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_per_rechit_m1p1_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_per_rechit_m1p15_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_per_rechit_m1p2_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_per_rechit_m1p25_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_per_rechit_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_per_rechit_m1p05_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_per_rechit_m1p1_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_per_rechit_m1p15_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_per_rechit_m1p2_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_per_rechit_m1p25_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w4p6_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w4p5_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w4p4_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w4p3_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w4p2_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w4p1_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w4p0_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w3p8_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w3p7_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w3p6_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w3p5_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w3p4_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w3p3_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w3p2_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_w3p0_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w4p6_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w4p5_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w4p4_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w4p3_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w4p2_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w4p1_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w4p0_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w3p8_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w3p7_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w3p6_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w3p5_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w3p4_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w3p3_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w3p2_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_w3p0_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w4p6_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w4p5_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w4p4_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w4p3_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w4p2_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w4p1_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w4p0_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w3p8_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w3p7_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w3p6_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w3p5_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w3p4_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w3p3_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w3p2_;   //!
   TBranch        *b_my_eleSigmaIphiIphi_w3p0_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en0p2_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en0p15_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en0p5_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en1_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en0p2_noRelNoiseCut_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en0p15_noRelNoiseCut_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en0p5_noRelNoiseCut_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en1_noRelNoiseCut_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en_0p1_0p4_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en_0p15_0p5_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en_0p16_0p6_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en_0p2_1_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en_0p2_1p5_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en_0p2_2_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_en_0p18_0p8_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en0p2_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en0p15_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en0p5_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en1_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en0p2_noRelNoiseCut_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en0p15_noRelNoiseCut_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en0p5_noRelNoiseCut_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en1_noRelNoiseCut_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en_0p1_0p4_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en_0p15_0p5_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en_0p16_0p6_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en_0p2_1_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en_0p2_1p5_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en_0p2_2_;   //!
   TBranch        *b_my_eleSigmaIetaIphi_en_0p18_0p8_;   //!
   TBranch        *b_gen_status_;   //!
   TBranch        *b_gen_pdgid_;   //!
   TBranch        *b_gen_pt_;   //!

   localCovEtaPhi(TTree *tree=0);
   virtual ~localCovEtaPhi();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef localCovEtaPhi_cxx
localCovEtaPhi::localCovEtaPhi(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("all3proc_2024.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("all3proc_2024.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("all3proc_2024.root:/demo");
      dir->GetObject("EventTree",tree);

   }
   Init(tree);
}

localCovEtaPhi::~localCovEtaPhi()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t localCovEtaPhi::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t localCovEtaPhi::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void localCovEtaPhi::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   crysEta_ = 0;
   crysPhi_ = 0;
   crysThr_ = 0;
   ele_genmatched_ = 0;
   trkCharge_ = 0;
   cmssw_eleSigmaIetaIeta_ = 0;
   cmssw_eleSigmaIphiIphi_ = 0;
   cmssw_eleR9_ = 0;
   cmssw_eleHoE_ = 0;
   eleScEta_ = 0;
   eleScEn_ = 0;
   elePt_ = 0;
   ptRecoEle_by_ptGenEle_ = 0;
   dR_recoEle_genEle_ = 0;
   puTrue_ = 0;
   my_eleSigmaIetaIeta_ = 0;
   my_eleSigmaIphiIphi_ = 0;
   my_eleSigmaIetaIphi_ = 0;
   my_eleSigmaIetaIeta_per_rechit_ = 0;
   my_eleSigmaIetaIeta_per_rechit_m1p05_ = 0;
   my_eleSigmaIetaIeta_per_rechit_m1p1_ = 0;
   my_eleSigmaIetaIeta_per_rechit_m1p15_ = 0;
   my_eleSigmaIetaIeta_per_rechit_m1p2_ = 0;
   my_eleSigmaIetaIeta_per_rechit_m1p25_ = 0;
   my_eleSigmaIetaIphi_per_rechit_ = 0;
   my_eleSigmaIetaIphi_per_rechit_m1p05_ = 0;
   my_eleSigmaIetaIphi_per_rechit_m1p1_ = 0;
   my_eleSigmaIetaIphi_per_rechit_m1p15_ = 0;
   my_eleSigmaIetaIphi_per_rechit_m1p2_ = 0;
   my_eleSigmaIetaIphi_per_rechit_m1p25_ = 0;
   my_eleSigmaIphiIphi_per_rechit_ = 0;
   my_eleSigmaIphiIphi_per_rechit_m1p05_ = 0;
   my_eleSigmaIphiIphi_per_rechit_m1p1_ = 0;
   my_eleSigmaIphiIphi_per_rechit_m1p15_ = 0;
   my_eleSigmaIphiIphi_per_rechit_m1p2_ = 0;
   my_eleSigmaIphiIphi_per_rechit_m1p25_ = 0;
   my_eleSigmaIetaIeta_w4p6_ = 0;
   my_eleSigmaIetaIeta_w4p5_ = 0;
   my_eleSigmaIetaIeta_w4p4_ = 0;
   my_eleSigmaIetaIeta_w4p3_ = 0;
   my_eleSigmaIetaIeta_w4p2_ = 0;
   my_eleSigmaIetaIeta_w4p1_ = 0;
   my_eleSigmaIetaIeta_w4p0_ = 0;
   my_eleSigmaIetaIeta_w3p8_ = 0;
   my_eleSigmaIetaIeta_w3p7_ = 0;
   my_eleSigmaIetaIeta_w3p6_ = 0;
   my_eleSigmaIetaIeta_w3p5_ = 0;
   my_eleSigmaIetaIeta_w3p4_ = 0;
   my_eleSigmaIetaIeta_w3p3_ = 0;
   my_eleSigmaIetaIeta_w3p2_ = 0;
   my_eleSigmaIetaIeta_w3p0_ = 0;
   my_eleSigmaIetaIphi_w4p6_ = 0;
   my_eleSigmaIetaIphi_w4p5_ = 0;
   my_eleSigmaIetaIphi_w4p4_ = 0;
   my_eleSigmaIetaIphi_w4p3_ = 0;
   my_eleSigmaIetaIphi_w4p2_ = 0;
   my_eleSigmaIetaIphi_w4p1_ = 0;
   my_eleSigmaIetaIphi_w4p0_ = 0;
   my_eleSigmaIetaIphi_w3p8_ = 0;
   my_eleSigmaIetaIphi_w3p7_ = 0;
   my_eleSigmaIetaIphi_w3p6_ = 0;
   my_eleSigmaIetaIphi_w3p5_ = 0;
   my_eleSigmaIetaIphi_w3p4_ = 0;
   my_eleSigmaIetaIphi_w3p3_ = 0;
   my_eleSigmaIetaIphi_w3p2_ = 0;
   my_eleSigmaIetaIphi_w3p0_ = 0;
   my_eleSigmaIphiIphi_w4p6_ = 0;
   my_eleSigmaIphiIphi_w4p5_ = 0;
   my_eleSigmaIphiIphi_w4p4_ = 0;
   my_eleSigmaIphiIphi_w4p3_ = 0;
   my_eleSigmaIphiIphi_w4p2_ = 0;
   my_eleSigmaIphiIphi_w4p1_ = 0;
   my_eleSigmaIphiIphi_w4p0_ = 0;
   my_eleSigmaIphiIphi_w3p8_ = 0;
   my_eleSigmaIphiIphi_w3p7_ = 0;
   my_eleSigmaIphiIphi_w3p6_ = 0;
   my_eleSigmaIphiIphi_w3p5_ = 0;
   my_eleSigmaIphiIphi_w3p4_ = 0;
   my_eleSigmaIphiIphi_w3p3_ = 0;
   my_eleSigmaIphiIphi_w3p2_ = 0;
   my_eleSigmaIphiIphi_w3p0_ = 0;
   my_eleSigmaIetaIeta_en0p2_ = 0;
   my_eleSigmaIetaIeta_en0p15_ = 0;
   my_eleSigmaIetaIeta_en0p5_ = 0;
   my_eleSigmaIetaIeta_en1_ = 0;
   my_eleSigmaIetaIeta_en0p2_noRelNoiseCut_ = 0;
   my_eleSigmaIetaIeta_en0p15_noRelNoiseCut_ = 0;
   my_eleSigmaIetaIeta_en0p5_noRelNoiseCut_ = 0;
   my_eleSigmaIetaIeta_en1_noRelNoiseCut_ = 0;
   my_eleSigmaIetaIeta_en_0p1_0p4_ = 0;
   my_eleSigmaIetaIeta_en_0p15_0p5_ = 0;
   my_eleSigmaIetaIeta_en_0p16_0p6_ = 0;
   my_eleSigmaIetaIeta_en_0p2_1_ = 0;
   my_eleSigmaIetaIeta_en_0p2_1p5_ = 0;
   my_eleSigmaIetaIeta_en_0p2_2_ = 0;
   my_eleSigmaIetaIeta_en_0p18_0p8_ = 0;
   my_eleSigmaIetaIphi_en0p2_ = 0;
   my_eleSigmaIetaIphi_en0p15_ = 0;
   my_eleSigmaIetaIphi_en0p5_ = 0;
   my_eleSigmaIetaIphi_en1_ = 0;
   my_eleSigmaIetaIphi_en0p2_noRelNoiseCut_ = 0;
   my_eleSigmaIetaIphi_en0p15_noRelNoiseCut_ = 0;
   my_eleSigmaIetaIphi_en0p5_noRelNoiseCut_ = 0;
   my_eleSigmaIetaIphi_en1_noRelNoiseCut_ = 0;
   my_eleSigmaIetaIphi_en_0p1_0p4_ = 0;
   my_eleSigmaIetaIphi_en_0p15_0p5_ = 0;
   my_eleSigmaIetaIphi_en_0p16_0p6_ = 0;
   my_eleSigmaIetaIphi_en_0p2_1_ = 0;
   my_eleSigmaIetaIphi_en_0p2_1p5_ = 0;
   my_eleSigmaIetaIphi_en_0p2_2_ = 0;
   my_eleSigmaIetaIphi_en_0p18_0p8_ = 0;
   gen_status_ = 0;
   gen_pdgid_ = 0;
   gen_pt_ = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("crysEta_", &crysEta_, &b_crysEta_);
   fChain->SetBranchAddress("crysPhi_", &crysPhi_, &b_crysPhi_);
   fChain->SetBranchAddress("crysThr_", &crysThr_, &b_crysThr_);
   fChain->SetBranchAddress("ele_genmatched_", &ele_genmatched_, &b_ele_genmatched_);
   fChain->SetBranchAddress("trkCharge_", &trkCharge_, &b_trkCharge_);
   fChain->SetBranchAddress("cmssw_eleSigmaIetaIeta_", &cmssw_eleSigmaIetaIeta_, &b_cmssw_eleSigmaIetaIeta_);
   fChain->SetBranchAddress("cmssw_eleSigmaIphiIphi_", &cmssw_eleSigmaIphiIphi_, &b_cmssw_eleSigmaIphiIphi_);
   fChain->SetBranchAddress("cmssw_eleR9_", &cmssw_eleR9_, &b_cmssw_eleR9_);
   fChain->SetBranchAddress("cmssw_eleHoE_", &cmssw_eleHoE_, &b_cmssw_eleHoE_);
   fChain->SetBranchAddress("eleScEta_", &eleScEta_, &b_eleScEta_);
   fChain->SetBranchAddress("eleScEn_", &eleScEn_, &b_eleScEn_);
   fChain->SetBranchAddress("elePt_", &elePt_, &b_elePt_);
   fChain->SetBranchAddress("ptRecoEle_by_ptGenEle_", &ptRecoEle_by_ptGenEle_, &b_ptRecoEle_by_ptGenEle_);
   fChain->SetBranchAddress("dR_recoEle_genEle_", &dR_recoEle_genEle_, &b_dR_recoEle_genEle_);
   fChain->SetBranchAddress("puTrue_", &puTrue_, &b_puTrue_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_", &my_eleSigmaIetaIeta_, &b_my_eleSigmaIetaIeta_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_", &my_eleSigmaIphiIphi_, &b_my_eleSigmaIphiIphi_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_", &my_eleSigmaIetaIphi_, &b_my_eleSigmaIetaIphi_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_per_rechit_", &my_eleSigmaIetaIeta_per_rechit_, &b_my_eleSigmaIetaIeta_per_rechit_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_per_rechit_m1p05_", &my_eleSigmaIetaIeta_per_rechit_m1p05_, &b_my_eleSigmaIetaIeta_per_rechit_m1p05_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_per_rechit_m1p1_", &my_eleSigmaIetaIeta_per_rechit_m1p1_, &b_my_eleSigmaIetaIeta_per_rechit_m1p1_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_per_rechit_m1p15_", &my_eleSigmaIetaIeta_per_rechit_m1p15_, &b_my_eleSigmaIetaIeta_per_rechit_m1p15_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_per_rechit_m1p2_", &my_eleSigmaIetaIeta_per_rechit_m1p2_, &b_my_eleSigmaIetaIeta_per_rechit_m1p2_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_per_rechit_m1p25_", &my_eleSigmaIetaIeta_per_rechit_m1p25_, &b_my_eleSigmaIetaIeta_per_rechit_m1p25_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_per_rechit_", &my_eleSigmaIetaIphi_per_rechit_, &b_my_eleSigmaIetaIphi_per_rechit_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_per_rechit_m1p05_", &my_eleSigmaIetaIphi_per_rechit_m1p05_, &b_my_eleSigmaIetaIphi_per_rechit_m1p05_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_per_rechit_m1p1_", &my_eleSigmaIetaIphi_per_rechit_m1p1_, &b_my_eleSigmaIetaIphi_per_rechit_m1p1_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_per_rechit_m1p15_", &my_eleSigmaIetaIphi_per_rechit_m1p15_, &b_my_eleSigmaIetaIphi_per_rechit_m1p15_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_per_rechit_m1p2_", &my_eleSigmaIetaIphi_per_rechit_m1p2_, &b_my_eleSigmaIetaIphi_per_rechit_m1p2_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_per_rechit_m1p25_", &my_eleSigmaIetaIphi_per_rechit_m1p25_, &b_my_eleSigmaIetaIphi_per_rechit_m1p25_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_per_rechit_", &my_eleSigmaIphiIphi_per_rechit_, &b_my_eleSigmaIphiIphi_per_rechit_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_per_rechit_m1p05_", &my_eleSigmaIphiIphi_per_rechit_m1p05_, &b_my_eleSigmaIphiIphi_per_rechit_m1p05_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_per_rechit_m1p1_", &my_eleSigmaIphiIphi_per_rechit_m1p1_, &b_my_eleSigmaIphiIphi_per_rechit_m1p1_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_per_rechit_m1p15_", &my_eleSigmaIphiIphi_per_rechit_m1p15_, &b_my_eleSigmaIphiIphi_per_rechit_m1p15_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_per_rechit_m1p2_", &my_eleSigmaIphiIphi_per_rechit_m1p2_, &b_my_eleSigmaIphiIphi_per_rechit_m1p2_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_per_rechit_m1p25_", &my_eleSigmaIphiIphi_per_rechit_m1p25_, &b_my_eleSigmaIphiIphi_per_rechit_m1p25_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w4p6_", &my_eleSigmaIetaIeta_w4p6_, &b_my_eleSigmaIetaIeta_w4p6_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w4p5_", &my_eleSigmaIetaIeta_w4p5_, &b_my_eleSigmaIetaIeta_w4p5_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w4p4_", &my_eleSigmaIetaIeta_w4p4_, &b_my_eleSigmaIetaIeta_w4p4_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w4p3_", &my_eleSigmaIetaIeta_w4p3_, &b_my_eleSigmaIetaIeta_w4p3_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w4p2_", &my_eleSigmaIetaIeta_w4p2_, &b_my_eleSigmaIetaIeta_w4p2_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w4p1_", &my_eleSigmaIetaIeta_w4p1_, &b_my_eleSigmaIetaIeta_w4p1_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w4p0_", &my_eleSigmaIetaIeta_w4p0_, &b_my_eleSigmaIetaIeta_w4p0_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w3p8_", &my_eleSigmaIetaIeta_w3p8_, &b_my_eleSigmaIetaIeta_w3p8_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w3p7_", &my_eleSigmaIetaIeta_w3p7_, &b_my_eleSigmaIetaIeta_w3p7_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w3p6_", &my_eleSigmaIetaIeta_w3p6_, &b_my_eleSigmaIetaIeta_w3p6_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w3p5_", &my_eleSigmaIetaIeta_w3p5_, &b_my_eleSigmaIetaIeta_w3p5_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w3p4_", &my_eleSigmaIetaIeta_w3p4_, &b_my_eleSigmaIetaIeta_w3p4_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w3p3_", &my_eleSigmaIetaIeta_w3p3_, &b_my_eleSigmaIetaIeta_w3p3_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w3p2_", &my_eleSigmaIetaIeta_w3p2_, &b_my_eleSigmaIetaIeta_w3p2_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_w3p0_", &my_eleSigmaIetaIeta_w3p0_, &b_my_eleSigmaIetaIeta_w3p0_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w4p6_", &my_eleSigmaIetaIphi_w4p6_, &b_my_eleSigmaIetaIphi_w4p6_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w4p5_", &my_eleSigmaIetaIphi_w4p5_, &b_my_eleSigmaIetaIphi_w4p5_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w4p4_", &my_eleSigmaIetaIphi_w4p4_, &b_my_eleSigmaIetaIphi_w4p4_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w4p3_", &my_eleSigmaIetaIphi_w4p3_, &b_my_eleSigmaIetaIphi_w4p3_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w4p2_", &my_eleSigmaIetaIphi_w4p2_, &b_my_eleSigmaIetaIphi_w4p2_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w4p1_", &my_eleSigmaIetaIphi_w4p1_, &b_my_eleSigmaIetaIphi_w4p1_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w4p0_", &my_eleSigmaIetaIphi_w4p0_, &b_my_eleSigmaIetaIphi_w4p0_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w3p8_", &my_eleSigmaIetaIphi_w3p8_, &b_my_eleSigmaIetaIphi_w3p8_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w3p7_", &my_eleSigmaIetaIphi_w3p7_, &b_my_eleSigmaIetaIphi_w3p7_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w3p6_", &my_eleSigmaIetaIphi_w3p6_, &b_my_eleSigmaIetaIphi_w3p6_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w3p5_", &my_eleSigmaIetaIphi_w3p5_, &b_my_eleSigmaIetaIphi_w3p5_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w3p4_", &my_eleSigmaIetaIphi_w3p4_, &b_my_eleSigmaIetaIphi_w3p4_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w3p3_", &my_eleSigmaIetaIphi_w3p3_, &b_my_eleSigmaIetaIphi_w3p3_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w3p2_", &my_eleSigmaIetaIphi_w3p2_, &b_my_eleSigmaIetaIphi_w3p2_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_w3p0_", &my_eleSigmaIetaIphi_w3p0_, &b_my_eleSigmaIetaIphi_w3p0_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w4p6_", &my_eleSigmaIphiIphi_w4p6_, &b_my_eleSigmaIphiIphi_w4p6_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w4p5_", &my_eleSigmaIphiIphi_w4p5_, &b_my_eleSigmaIphiIphi_w4p5_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w4p4_", &my_eleSigmaIphiIphi_w4p4_, &b_my_eleSigmaIphiIphi_w4p4_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w4p3_", &my_eleSigmaIphiIphi_w4p3_, &b_my_eleSigmaIphiIphi_w4p3_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w4p2_", &my_eleSigmaIphiIphi_w4p2_, &b_my_eleSigmaIphiIphi_w4p2_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w4p1_", &my_eleSigmaIphiIphi_w4p1_, &b_my_eleSigmaIphiIphi_w4p1_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w4p0_", &my_eleSigmaIphiIphi_w4p0_, &b_my_eleSigmaIphiIphi_w4p0_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w3p8_", &my_eleSigmaIphiIphi_w3p8_, &b_my_eleSigmaIphiIphi_w3p8_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w3p7_", &my_eleSigmaIphiIphi_w3p7_, &b_my_eleSigmaIphiIphi_w3p7_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w3p6_", &my_eleSigmaIphiIphi_w3p6_, &b_my_eleSigmaIphiIphi_w3p6_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w3p5_", &my_eleSigmaIphiIphi_w3p5_, &b_my_eleSigmaIphiIphi_w3p5_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w3p4_", &my_eleSigmaIphiIphi_w3p4_, &b_my_eleSigmaIphiIphi_w3p4_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w3p3_", &my_eleSigmaIphiIphi_w3p3_, &b_my_eleSigmaIphiIphi_w3p3_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w3p2_", &my_eleSigmaIphiIphi_w3p2_, &b_my_eleSigmaIphiIphi_w3p2_);
   fChain->SetBranchAddress("my_eleSigmaIphiIphi_w3p0_", &my_eleSigmaIphiIphi_w3p0_, &b_my_eleSigmaIphiIphi_w3p0_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en0p2_", &my_eleSigmaIetaIeta_en0p2_, &b_my_eleSigmaIetaIeta_en0p2_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en0p15_", &my_eleSigmaIetaIeta_en0p15_, &b_my_eleSigmaIetaIeta_en0p15_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en0p5_", &my_eleSigmaIetaIeta_en0p5_, &b_my_eleSigmaIetaIeta_en0p5_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en1_", &my_eleSigmaIetaIeta_en1_, &b_my_eleSigmaIetaIeta_en1_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en0p2_noRelNoiseCut_", &my_eleSigmaIetaIeta_en0p2_noRelNoiseCut_, &b_my_eleSigmaIetaIeta_en0p2_noRelNoiseCut_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en0p15_noRelNoiseCut_", &my_eleSigmaIetaIeta_en0p15_noRelNoiseCut_, &b_my_eleSigmaIetaIeta_en0p15_noRelNoiseCut_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en0p5_noRelNoiseCut_", &my_eleSigmaIetaIeta_en0p5_noRelNoiseCut_, &b_my_eleSigmaIetaIeta_en0p5_noRelNoiseCut_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en1_noRelNoiseCut_", &my_eleSigmaIetaIeta_en1_noRelNoiseCut_, &b_my_eleSigmaIetaIeta_en1_noRelNoiseCut_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en_0p1_0p4_", &my_eleSigmaIetaIeta_en_0p1_0p4_, &b_my_eleSigmaIetaIeta_en_0p1_0p4_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en_0p15_0p5_", &my_eleSigmaIetaIeta_en_0p15_0p5_, &b_my_eleSigmaIetaIeta_en_0p15_0p5_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en_0p16_0p6_", &my_eleSigmaIetaIeta_en_0p16_0p6_, &b_my_eleSigmaIetaIeta_en_0p16_0p6_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en_0p2_1_", &my_eleSigmaIetaIeta_en_0p2_1_, &b_my_eleSigmaIetaIeta_en_0p2_1_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en_0p2_1p5_", &my_eleSigmaIetaIeta_en_0p2_1p5_, &b_my_eleSigmaIetaIeta_en_0p2_1p5_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en_0p2_2_", &my_eleSigmaIetaIeta_en_0p2_2_, &b_my_eleSigmaIetaIeta_en_0p2_2_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_en_0p18_0p8_", &my_eleSigmaIetaIeta_en_0p18_0p8_, &b_my_eleSigmaIetaIeta_en_0p18_0p8_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en0p2_", &my_eleSigmaIetaIphi_en0p2_, &b_my_eleSigmaIetaIphi_en0p2_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en0p15_", &my_eleSigmaIetaIphi_en0p15_, &b_my_eleSigmaIetaIphi_en0p15_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en0p5_", &my_eleSigmaIetaIphi_en0p5_, &b_my_eleSigmaIetaIphi_en0p5_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en1_", &my_eleSigmaIetaIphi_en1_, &b_my_eleSigmaIetaIphi_en1_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en0p2_noRelNoiseCut_", &my_eleSigmaIetaIphi_en0p2_noRelNoiseCut_, &b_my_eleSigmaIetaIphi_en0p2_noRelNoiseCut_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en0p15_noRelNoiseCut_", &my_eleSigmaIetaIphi_en0p15_noRelNoiseCut_, &b_my_eleSigmaIetaIphi_en0p15_noRelNoiseCut_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en0p5_noRelNoiseCut_", &my_eleSigmaIetaIphi_en0p5_noRelNoiseCut_, &b_my_eleSigmaIetaIphi_en0p5_noRelNoiseCut_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en1_noRelNoiseCut_", &my_eleSigmaIetaIphi_en1_noRelNoiseCut_, &b_my_eleSigmaIetaIphi_en1_noRelNoiseCut_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en_0p1_0p4_", &my_eleSigmaIetaIphi_en_0p1_0p4_, &b_my_eleSigmaIetaIphi_en_0p1_0p4_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en_0p15_0p5_", &my_eleSigmaIetaIphi_en_0p15_0p5_, &b_my_eleSigmaIetaIphi_en_0p15_0p5_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en_0p16_0p6_", &my_eleSigmaIetaIphi_en_0p16_0p6_, &b_my_eleSigmaIetaIphi_en_0p16_0p6_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en_0p2_1_", &my_eleSigmaIetaIphi_en_0p2_1_, &b_my_eleSigmaIetaIphi_en_0p2_1_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en_0p2_1p5_", &my_eleSigmaIetaIphi_en_0p2_1p5_, &b_my_eleSigmaIetaIphi_en_0p2_1p5_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en_0p2_2_", &my_eleSigmaIetaIphi_en_0p2_2_, &b_my_eleSigmaIetaIphi_en_0p2_2_);
   fChain->SetBranchAddress("my_eleSigmaIetaIphi_en_0p18_0p8_", &my_eleSigmaIetaIphi_en_0p18_0p8_, &b_my_eleSigmaIetaIphi_en_0p18_0p8_);
   fChain->SetBranchAddress("gen_status_", &gen_status_, &b_gen_status_);
   fChain->SetBranchAddress("gen_pdgid_", &gen_pdgid_, &b_gen_pdgid_);
   fChain->SetBranchAddress("gen_pt_", &gen_pt_, &b_gen_pt_);
   Notify();
}

Bool_t localCovEtaPhi::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void localCovEtaPhi::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t localCovEtaPhi::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef localCovEtaPhi_cxx
