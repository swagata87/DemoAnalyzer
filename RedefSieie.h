//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct 18 13:22:01 2019 by ROOT version 6.14/09
// from TTree EventTree/EventData
// found on file: RedefNtup_AOD_2024.root
//////////////////////////////////////////////////////////

#ifndef RedefSieie_h
#define RedefSieie_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"

class RedefSieie {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxele_genmatched = 1;
   ////   static constexpr Int_t kMaxtrkCharge = 1;
   static constexpr Int_t kMaxcmssw_eleSigmaIetaIeta = 1;
   static constexpr Int_t kMaxcmssw_eleR9 = 1;
   static constexpr Int_t kMaxcmssw_eleHoE = 1;
   static constexpr Int_t kMaxeleScEta = 1;
   static constexpr Int_t kMaxeleScEn = 1;
   static constexpr Int_t kMaxelePt = 1;
   static constexpr Int_t kMaxpuTrue = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_per_rechit = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_per_rechit_m1p05 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_per_rechit_m1p1 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_per_rechit_m1p15 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_per_rechit_m1p2 = 1;
   static constexpr Int_t kMaxmy_eleSigmaIetaIeta_per_rechit_m1p25 = 1;
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
   static constexpr Int_t kMaxgen_status = 1;
   static constexpr Int_t kMaxgen_pdgid = 1;
   static constexpr Int_t kMaxgen_pt = 1;

   // Declaration of leaf types
   vector<int>     *ele_genmatched_;
   ///   vector<int>     *trkCharge_;
   vector<double>  *cmssw_eleSigmaIetaIeta_;
   vector<float>   *cmssw_eleR9_;
   vector<float>   *cmssw_eleHoE_;
   vector<float>   *eleScEta_;
   vector<float>   *eleScEn_;
   vector<float>   *elePt_;
   vector<float>   *puTrue_;
   vector<double>  *my_eleSigmaIetaIeta_;
   vector<double>  *my_eleSigmaIetaIeta_per_rechit_;
   vector<double>  *my_eleSigmaIetaIeta_per_rechit_m1p05_;
   vector<double>  *my_eleSigmaIetaIeta_per_rechit_m1p1_;
   vector<double>  *my_eleSigmaIetaIeta_per_rechit_m1p15_;
   vector<double>  *my_eleSigmaIetaIeta_per_rechit_m1p2_;
   vector<double>  *my_eleSigmaIetaIeta_per_rechit_m1p25_;
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
   vector<int>     *gen_status_;
   vector<int>     *gen_pdgid_;
   vector<float>   *gen_pt_;

   // List of branches
   TBranch        *b_ele_genmatched_;   //!
   ///   TBranch        *b_trkCharge_;   //!
   TBranch        *b_cmssw_eleSigmaIetaIeta_;   //!
   TBranch        *b_cmssw_eleR9_;   //!
   TBranch        *b_cmssw_eleHoE_;   //!
   TBranch        *b_eleScEta_;   //!
   TBranch        *b_eleScEn_;   //!
   TBranch        *b_elePt_;   //!
   TBranch        *b_puTrue_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_per_rechit_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_per_rechit_m1p05_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_per_rechit_m1p1_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_per_rechit_m1p15_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_per_rechit_m1p2_;   //!
   TBranch        *b_my_eleSigmaIetaIeta_per_rechit_m1p25_;   //!
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
   TBranch        *b_gen_status_;   //!
   TBranch        *b_gen_pdgid_;   //!
   TBranch        *b_gen_pt_;   //!

   RedefSieie(TTree *tree=0);
   virtual ~RedefSieie();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef RedefSieie_cxx
RedefSieie::RedefSieie(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/cms/store/group/phys_egamma/swmukher/Run3_Redef_Jan27_2020/all_2018.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/cms/store/group/phys_egamma/swmukher/Run3_Redef_Jan27_2020/all_2018.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/eos/cms/store/group/phys_egamma/swmukher/Run3_Redef_Jan27_2020/all_2018.root:/demo");
      dir->GetObject("EventTree",tree);

   }
   Init(tree);
}

RedefSieie::~RedefSieie()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t RedefSieie::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t RedefSieie::LoadTree(Long64_t entry)
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

void RedefSieie::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   ele_genmatched_ = 0;
   ////   trkCharge_ = 0;
   cmssw_eleSigmaIetaIeta_ = 0;
   cmssw_eleR9_ = 0;
   cmssw_eleHoE_ = 0;
   eleScEta_ = 0;
   eleScEn_ = 0;
   elePt_ = 0;
   puTrue_ = 0;
   my_eleSigmaIetaIeta_ = 0;
   my_eleSigmaIetaIeta_per_rechit_ = 0;
   my_eleSigmaIetaIeta_per_rechit_m1p05_ = 0;
   my_eleSigmaIetaIeta_per_rechit_m1p1_ = 0;
   my_eleSigmaIetaIeta_per_rechit_m1p15_ = 0;
   my_eleSigmaIetaIeta_per_rechit_m1p2_ = 0;
   my_eleSigmaIetaIeta_per_rechit_m1p25_ = 0;
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
   gen_status_ = 0;
   gen_pdgid_ = 0;
   gen_pt_ = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ele_genmatched_", &ele_genmatched_, &b_ele_genmatched_);
   ///   fChain->SetBranchAddress("trkCharge_", &trkCharge_, &b_trkCharge_);
   fChain->SetBranchAddress("cmssw_eleSigmaIetaIeta_", &cmssw_eleSigmaIetaIeta_, &b_cmssw_eleSigmaIetaIeta_);
   fChain->SetBranchAddress("cmssw_eleR9_", &cmssw_eleR9_, &b_cmssw_eleR9_);
   fChain->SetBranchAddress("cmssw_eleHoE_", &cmssw_eleHoE_, &b_cmssw_eleHoE_);
   fChain->SetBranchAddress("eleScEta_", &eleScEta_, &b_eleScEta_);
   fChain->SetBranchAddress("eleScEn_", &eleScEn_, &b_eleScEn_);
   fChain->SetBranchAddress("elePt_", &elePt_, &b_elePt_);
   fChain->SetBranchAddress("puTrue_", &puTrue_, &b_puTrue_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_", &my_eleSigmaIetaIeta_, &b_my_eleSigmaIetaIeta_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_per_rechit_", &my_eleSigmaIetaIeta_per_rechit_, &b_my_eleSigmaIetaIeta_per_rechit_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_per_rechit_m1p05_", &my_eleSigmaIetaIeta_per_rechit_m1p05_, &b_my_eleSigmaIetaIeta_per_rechit_m1p05_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_per_rechit_m1p1_", &my_eleSigmaIetaIeta_per_rechit_m1p1_, &b_my_eleSigmaIetaIeta_per_rechit_m1p1_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_per_rechit_m1p15_", &my_eleSigmaIetaIeta_per_rechit_m1p15_, &b_my_eleSigmaIetaIeta_per_rechit_m1p15_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_per_rechit_m1p2_", &my_eleSigmaIetaIeta_per_rechit_m1p2_, &b_my_eleSigmaIetaIeta_per_rechit_m1p2_);
   fChain->SetBranchAddress("my_eleSigmaIetaIeta_per_rechit_m1p25_", &my_eleSigmaIetaIeta_per_rechit_m1p25_, &b_my_eleSigmaIetaIeta_per_rechit_m1p25_);
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
   fChain->SetBranchAddress("gen_status_", &gen_status_, &b_gen_status_);
   fChain->SetBranchAddress("gen_pdgid_", &gen_pdgid_, &b_gen_pdgid_);
   fChain->SetBranchAddress("gen_pt_", &gen_pt_, &b_gen_pt_);
   Notify();
}

Bool_t RedefSieie::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void RedefSieie::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t RedefSieie::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef RedefSieie_cxx
