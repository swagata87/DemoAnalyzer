// -*- C++ -*-
//
// Package:    Demo/DemoAnalyzer
// Class:      DemoAnalyzer
//
/**\class DemoAnalyzer DemoAnalyzer.cc Demo/DemoAnalyzer/plugins/DemoAnalyzer.cc
   
   Description: [one line class summary]
   
   Implementation:
   [Notes on implementation]
*/
//
// Original Author:  Swagata Mukherjee
//         Created:  Fri, 27 Sep 2019 13:18:56 GMT
//
//


// system include files
#include <memory>

// user include files
#include "DataFormats/GsfTrackReco/interface/GsfTrackFwd.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterTools.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalTools.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterLazyTools.h"
#include "Geometry/CaloTopology/interface/CaloTopology.h"
#include "Geometry/CaloEventSetup/interface/CaloTopologyRecord.h"
#include "Geometry/Records/interface/CaloTopologyRecord.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "Geometry/CaloEventSetup/plugins/CaloTopologyBuilder.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"
#include "Geometry/CaloTopology/interface/CaloSubdetectorTopology.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
//#include "DataFormats/TrackReco/interface/Track.h"
///#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaRecHitIsolation.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHit.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "CondFormats/EcalObjects/interface/EcalPFRecHitThresholds.h"
#include "CondFormats/DataRecord/interface/EcalPFRecHitThresholdsRcd.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/METReco/interface/BeamHaloSummary.h"
#include "TTree.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include <cmath>
#include "TVector3.h"
#include "TLorentzVector.h"

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<>
// This will improve performance in multithreaded jobs.


using reco::TrackCollection;
//using reco::PFRecHitCollection;

class DemoAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
public:
  explicit DemoAnalyzer(const edm::ParameterSet&);
  ~DemoAnalyzer();
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  
  edm::Service<TFileService> fs;
  TTree   *tree = fs->make<TTree>("EventTree", "EventData");

  //ID
  std::vector<std::vector<int> > eleIDbits;
  //  std::vector<UShort_t>  eleIDbit;
  //
  std::vector<double>  cmssw_eleSigmaIetaIeta;
  std::vector<double>  cmssw_eleSigmaIphiIphi;
  std::vector<float>  cmssw_eleR9;
  std::vector<float>  cmssw_eleHoE;
  std::vector<float>  cmssw_eleHoEfull5x5;
  std::vector<float>  eleScEta;
  std::vector<float>  eleScEn;
  std::vector<float>  elePt;
  std::vector<float>  ele_fbrem;
  std::vector<float>  ele_missingHit;
  std::vector<float>  ele_psEorawE;
  std::vector<float>  ele_1oEm1op;
  std::vector<float>  ele_eSCoPout;
  std::vector<float>  ele_eSCoP;
  std::vector<float>  ele_convVtxFitProb;
  std::vector<float>  ele_gsfTrackChi2;
  std::vector<float>  ele_nHit;
  std::vector<float>  ele_deltaEtaSuperClusterTrackAtVtx;
  std::vector<float>  ele_deltaPhiSuperClusterTrackAtVtx;
  std::vector<float>  ele_deltaEtaSeedClusterTrackAtCalo;
  std::vector<float>  elePFChIso;
  std::vector<float>  elePFPhoIso;
  std::vector<float>  elePFNeuIso;
  std::vector<float>  ele_etaWidth;
  std::vector<float>  ele_phiWidth;
  std::vector<float>  ele_closestCtfTrackNLayers;
  std::vector<float>  ele_closestCtfTrackNormChi2;
  std::vector<float>  ele_1mE1x5oE5x5;
  std::vector<float>  ptRecoEle_by_ptGenEle;
  std::vector<float>  dR_recoEle_genEle;
  std::vector<float>  ptRecoPho_by_ptGenPho;
  std::vector<float>  dR_recoPho_genPho;
  std::vector<float>  puTrue;
  std::vector<float>  rho;
  std::vector<double>  my_eleSigmaIetaIeta;
  std::vector<double>  my_eleSigmaIetaIphi;
  std::vector<double>  my_eleSigmaIphiIphi;
  //
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p1;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p2;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p25;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p5;
  //
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p1;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p2;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p25;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p5;
  //
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p1;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p2;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p25;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p5;
  //
  std::vector<int>  ele_genmatched;
  std::vector<int>  pho_genmatched;
  std::vector<int>    gen_status;
  std::vector<int>    gen_pdgid;
  std::vector<float>  gen_pt;

  ///beamhalo
  std::vector<int> evt_CSCLooseHaloId;
  std::vector<int> evt_CSCTightHaloId;
  std::vector<int> evt_CSCTightHaloId2015;
  std::vector<int> evt_CSCTightHaloIdTrkMuUnveto;
  std::vector<int> evt_EcalLooseHaloId;
  std::vector<int> evt_EcalTightHaloId;
  std::vector<int> evt_EventSmellsLikeHalo;
  std::vector<int> evt_ExtremeTightId;
  std::vector<int> evt_GlobalLooseHaloId;
  std::vector<int> evt_GlobalSuperTightHaloId2016;
  std::vector<int> evt_GlobalTightHaloId;
  std::vector<int> evt_GlobalTightHaloId2016;
  std::vector<int> evt_HcalLooseHaloId;
  std::vector<int> evt_HcalTightHaloId;
  std::vector<int> evt_LooseId;
  std::vector<int> evt_TightId;

  ////ootpho
  std::vector<double> ootphoSeedTime;
  std::vector<double> ootphoPt;
  std::vector<double> ootphoPhi;
  std::vector<double> ootphoScEn;
  std::vector<double> ootphoScEta;
  std::vector<double> cmssw_ootphoSigmaIetaIeta;
  std::vector<double> my_ootphoSigmaIetaIeta;
  std::vector<double> my_ootphoSigmaIetaIphi;
  std::vector<double> my_ootphoSigmaIphiIphi;
  std::vector<double> my_ootphoSigmaIphiIphi_per_rechit;
  std::vector<double> my_ootphoSigmaIphiIphi_per_rechit_m1p1;
  std::vector<double> my_ootphoSigmaIphiIphi_per_rechit_m1p2;
  std::vector<double> my_ootphoSigmaIphiIphi_per_rechit_m1p25;
  std::vector<double> my_ootphoSigmaIphiIphi_per_rechit_m1p5;
  std::vector<double> my_ootphoSigmaIetaIphi_per_rechit;
  std::vector<double> my_ootphoSigmaIetaIphi_per_rechit_m1p1;
  std::vector<double> my_ootphoSigmaIetaIphi_per_rechit_m1p2;
  std::vector<double> my_ootphoSigmaIetaIphi_per_rechit_m1p25;
  std::vector<double> my_ootphoSigmaIetaIphi_per_rechit_m1p5;
  std::vector<double> my_ootphoSigmaIetaIeta_per_rechit;
  std::vector<double> my_ootphoSigmaIetaIeta_per_rechit_m1p1;
  std::vector<double> my_ootphoSigmaIetaIeta_per_rechit_m1p2;
  std::vector<double> my_ootphoSigmaIetaIeta_per_rechit_m1p25;
  std::vector<double> my_ootphoSigmaIetaIeta_per_rechit_m1p5;

  /// normal photon
  std::vector<double> phoPt;
  std::vector<double> phoPhi;
  std::vector<double> phoScEn;
  std::vector<double> phoScEta;
  std::vector<double> cmssw_phoSigmaIetaIeta;
  std::vector<double> my_phoSigmaIetaIeta;
  std::vector<double> my_phoSigmaIetaIphi;
  std::vector<double> my_phoSigmaIphiIphi;
  std::vector<double> my_phoSigmaIphiIphi_per_rechit;
  std::vector<double> my_phoSigmaIphiIphi_per_rechit_m1p1;
  std::vector<double> my_phoSigmaIphiIphi_per_rechit_m1p2;
  std::vector<double> my_phoSigmaIphiIphi_per_rechit_m1p25;
  std::vector<double> my_phoSigmaIphiIphi_per_rechit_m1p5;
  std::vector<double> my_phoSigmaIetaIphi_per_rechit;
  std::vector<double> my_phoSigmaIetaIphi_per_rechit_m1p1;
  std::vector<double> my_phoSigmaIetaIphi_per_rechit_m1p2;
  std::vector<double> my_phoSigmaIetaIphi_per_rechit_m1p25;
  std::vector<double> my_phoSigmaIetaIphi_per_rechit_m1p5;
  std::vector<double> my_phoSigmaIetaIeta_per_rechit;
  std::vector<double> my_phoSigmaIetaIeta_per_rechit_m1p1;
  std::vector<double> my_phoSigmaIetaIeta_per_rechit_m1p2;
  std::vector<double> my_phoSigmaIetaIeta_per_rechit_m1p25;
  std::vector<double> my_phoSigmaIetaIeta_per_rechit_m1p5;



private:
  virtual void beginJob() override;
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;

  //  virtual  void setbit(UShort_t& x, UShort_t bit);
  
  // ----------member data ---------------------------

  edm::EDGetTokenT<double> rhoLabel_;
  //  edm::EDGetTokenT<edm::View<reco::GsfElectron> > eleToken_;
  edm::EDGetTokenT<edm::View<pat::Electron> > eleToken_;
  edm::EDGetTokenT<edm::View<reco::Photon> > ootphoToken_;
  edm::EDGetTokenT<edm::View<reco::Photon> > phoToken_;
  edm::EDGetTokenT<EcalRecHitCollection> EBRecHitCollectionT_;
  edm::EDGetTokenT<EcalRecHitCollection> EERecHitCollectionT_;
  edm::ESHandle<CaloTopology> theCaloTopology;
  edm::ESHandle<CaloGeometry> theCaloGeometry;
  edm::EDGetTokenT<std::vector<PileupSummaryInfo> >     puCollection_;
  edm::EDGetTokenT<std::vector<reco::GenParticle> >     genParticlesCollection_;
  edm::EDGetTokenT<reco::BeamHaloSummary> beamHaloSummaryToken_;

  bool RunEle ;
  bool RunPho ;


};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
DemoAnalyzer::DemoAnalyzer(const edm::ParameterSet& iConfig)
  :
  rhoLabel_(consumes<double>(iConfig.getParameter<edm::InputTag>("rhoLabel"))),
  //eleToken_(consumes<edm::View<reco::GsfElectron> >(iConfig.getParameter<edm::InputTag>("electrons"))),
  eleToken_(consumes<edm::View<pat::Electron> >(iConfig.getParameter<edm::InputTag>("electrons"))),
  ootphoToken_(consumes<edm::View<reco::Photon> >(iConfig.getParameter<edm::InputTag>("ootPhotons"))),
  phoToken_(consumes<edm::View<reco::Photon> >(iConfig.getParameter<edm::InputTag>("Photons"))),
  EBRecHitCollectionT_(consumes<EcalRecHitCollection>(iConfig.getParameter<edm::InputTag>("EBRecHitCollection"))),
  EERecHitCollectionT_(consumes<EcalRecHitCollection>(iConfig.getParameter<edm::InputTag>("EERecHitCollection"))),
  puCollection_(consumes<std::vector<PileupSummaryInfo> >(iConfig.getParameter<edm::InputTag>("pileupCollection"))),
  genParticlesCollection_(consumes<std::vector<reco::GenParticle> >(iConfig.getParameter<edm::InputTag>("genParticleSrc"))),
  beamHaloSummaryToken_(consumes<reco::BeamHaloSummary>(edm::InputTag("BeamHaloSummary"))),
  RunEle(iConfig.getParameter<bool>("RunEle_")),
  RunPho(iConfig.getParameter<bool>("RunPho_"))


{
  //now do what ever initialization is needed

  //
  //ID
  //
  //  tree->Branch("eleIDbit_", &eleIDbit);
  tree->Branch("eleIDbits_", &eleIDbits);

  //
  tree->Branch("ele_genmatched_",&ele_genmatched);
  tree->Branch("pho_genmatched_",&pho_genmatched);
  tree->Branch("cmssw_eleSigmaIetaIeta_",&cmssw_eleSigmaIetaIeta);
  tree->Branch("cmssw_eleSigmaIphiIphi_",&cmssw_eleSigmaIphiIphi);
  tree->Branch("cmssw_eleR9_",&cmssw_eleR9);
  tree->Branch("cmssw_eleHoE_",&cmssw_eleHoE);
  tree->Branch("cmssw_eleHoEfull5x5_",&cmssw_eleHoEfull5x5);
  tree->Branch("eleScEta_",&eleScEta);
  tree->Branch("eleScEn_",&eleScEn);
  tree->Branch("elePt_",&elePt);
  tree->Branch("ele_fbrem_",&ele_fbrem);
  tree->Branch("ele_missingHit_",&ele_missingHit);
  tree->Branch("ele_psEorawE_",&ele_psEorawE);
  tree->Branch("ele_1oEm1op_",&ele_1oEm1op);
  tree->Branch("ele_eSCoP_",&ele_eSCoP);
  tree->Branch("ele_eSCoPout_",&ele_eSCoPout);
  tree->Branch("ele_convVtxFitProb_",&ele_convVtxFitProb);
  tree->Branch("ele_gsfTrackChi2_",&ele_gsfTrackChi2);
  tree->Branch("ele_nHit_",&ele_nHit);
  tree->Branch("ele_deltaEtaSuperClusterTrackAtVtx_",&ele_deltaEtaSuperClusterTrackAtVtx);
  tree->Branch("ele_deltaPhiSuperClusterTrackAtVtx_",&ele_deltaPhiSuperClusterTrackAtVtx);
  tree->Branch("ele_deltaEtaSeedClusterTrackAtCalo_",&ele_deltaEtaSeedClusterTrackAtCalo);
  tree->Branch("elePFChIso_",&elePFChIso);
  tree->Branch("elePFPhoIso_",&elePFPhoIso);
  tree->Branch("elePFNeuIso_",&elePFNeuIso);
  tree->Branch("ele_etaWidth_",&ele_etaWidth);
  tree->Branch("ele_phiWidth_",&ele_phiWidth);
  tree->Branch("ele_closestCtfTrackNLayers_",&ele_closestCtfTrackNLayers);
  tree->Branch("ele_closestCtfTrackNormChi2_",&ele_closestCtfTrackNormChi2);
  tree->Branch("ele_1mE1x5oE5x5_",&ele_1mE1x5oE5x5);
  tree->Branch("ptRecoEle_by_ptGenEle_",&ptRecoEle_by_ptGenEle);
  tree->Branch("dR_recoEle_genEle_",&dR_recoEle_genEle);
  tree->Branch("ptRecoPho_by_ptGenPho_",&ptRecoPho_by_ptGenPho);
  tree->Branch("dR_recoPho_genPho_",&dR_recoPho_genPho);
  tree->Branch("puTrue_", &puTrue);
  tree->Branch("rho_", &rho);
  tree->Branch("my_eleSigmaIetaIeta_",&my_eleSigmaIetaIeta);
  tree->Branch("my_eleSigmaIphiIphi_",&my_eleSigmaIphiIphi);
  tree->Branch("my_eleSigmaIetaIphi_",&my_eleSigmaIetaIphi);
  //
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_",&my_eleSigmaIetaIeta_per_rechit);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p1_",&my_eleSigmaIetaIeta_per_rechit_m1p1);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p2_",&my_eleSigmaIetaIeta_per_rechit_m1p2);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p25_",&my_eleSigmaIetaIeta_per_rechit_m1p25);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p5_",&my_eleSigmaIetaIeta_per_rechit_m1p5);
  //
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_",&my_eleSigmaIetaIphi_per_rechit);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p1_",&my_eleSigmaIetaIphi_per_rechit_m1p1);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p2_",&my_eleSigmaIetaIphi_per_rechit_m1p2);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p25_",&my_eleSigmaIetaIphi_per_rechit_m1p25);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p5_",&my_eleSigmaIetaIphi_per_rechit_m1p5);
  //
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_",&my_eleSigmaIphiIphi_per_rechit);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p1_",&my_eleSigmaIphiIphi_per_rechit_m1p1);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p2_",&my_eleSigmaIphiIphi_per_rechit_m1p2);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p25_",&my_eleSigmaIphiIphi_per_rechit_m1p25);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p5_",&my_eleSigmaIphiIphi_per_rechit_m1p5);
  //
  tree->Branch("gen_status_",&gen_status);
  tree->Branch("gen_pdgid_",&gen_pdgid);
  tree->Branch("gen_pt_",&gen_pt);

  ///beamhalo
  tree->Branch("evt_CSCLooseHaloId_",&evt_CSCLooseHaloId);
  tree->Branch("evt_CSCTightHaloId_",&evt_CSCTightHaloId);
  tree->Branch("evt_CSCTightHaloId2015_",&evt_CSCTightHaloId2015);
  tree->Branch("evt_CSCTightHaloIdTrkMuUnveto_",&evt_CSCTightHaloIdTrkMuUnveto);
  tree->Branch("evt_EcalLooseHaloId_",&evt_EcalLooseHaloId);
  tree->Branch("evt_EcalTightHaloId_",&evt_EcalTightHaloId);
  tree->Branch("evt_EventSmellsLikeHalo_",&evt_EventSmellsLikeHalo);
  tree->Branch("evt_ExtremeTightId_",&evt_ExtremeTightId);
  tree->Branch("evt_GlobalLooseHaloId_",&evt_GlobalLooseHaloId);
  tree->Branch("evt_GlobalSuperTightHaloId2016_",&evt_GlobalSuperTightHaloId2016);
  tree->Branch("evt_GlobalTightHaloId_",&evt_GlobalTightHaloId);
  tree->Branch("evt_GlobalTightHaloId2016_",&evt_GlobalTightHaloId2016);
  tree->Branch("evt_HcalLooseHaloId_",&evt_HcalLooseHaloId);
  tree->Branch("evt_HcalTightHaloId_",&evt_HcalTightHaloId);
  tree->Branch("evt_LooseId_",&evt_LooseId);
  tree->Branch("evt_TightId_",&evt_TightId);

  ////ootphoton
  tree->Branch("ootphoSeedTime_",&ootphoSeedTime);
  tree->Branch("ootphoPt_",&ootphoPt);
  tree->Branch("ootphoPhi_",&ootphoPhi);
  tree->Branch("ootphoScEn_",&ootphoScEn);
  tree->Branch("ootphoScEta_",&ootphoScEta);
  tree->Branch("cmssw_ootphoSigmaIetaIeta_",&cmssw_ootphoSigmaIetaIeta);
  tree->Branch("my_ootphoSigmaIetaIeta_",&my_ootphoSigmaIetaIeta);
  tree->Branch("my_ootphoSigmaIetaIphi_",&my_ootphoSigmaIetaIphi);
  tree->Branch("my_ootphoSigmaIphiIphi_",&my_ootphoSigmaIphiIphi);
  tree->Branch("my_ootphoSigmaIphiIphi_per_rechit_",&my_ootphoSigmaIphiIphi_per_rechit);
  tree->Branch("my_ootphoSigmaIphiIphi_per_rechit_m1p1_",&my_ootphoSigmaIphiIphi_per_rechit_m1p1);
  tree->Branch("my_ootphoSigmaIphiIphi_per_rechit_m1p2_",&my_ootphoSigmaIphiIphi_per_rechit_m1p2);
  tree->Branch("my_ootphoSigmaIphiIphi_per_rechit_m1p25_",&my_ootphoSigmaIphiIphi_per_rechit_m1p25);
  tree->Branch("my_ootphoSigmaIphiIphi_per_rechit_m1p5_",&my_ootphoSigmaIphiIphi_per_rechit_m1p5);
  tree->Branch("my_ootphoSigmaIetaIphi_per_rechit_",&my_ootphoSigmaIetaIphi_per_rechit);
  tree->Branch("my_ootphoSigmaIetaIphi_per_rechit_m1p1_",&my_ootphoSigmaIetaIphi_per_rechit_m1p1);
  tree->Branch("my_ootphoSigmaIetaIphi_per_rechit_m1p2_",&my_ootphoSigmaIetaIphi_per_rechit_m1p2);
  tree->Branch("my_ootphoSigmaIetaIphi_per_rechit_m1p25_",&my_ootphoSigmaIetaIphi_per_rechit_m1p25);
  tree->Branch("my_ootphoSigmaIetaIphi_per_rechit_m1p5_",&my_ootphoSigmaIetaIphi_per_rechit_m1p5);
  tree->Branch("my_ootphoSigmaIetaIeta_per_rechit_",&my_ootphoSigmaIetaIeta_per_rechit);
  tree->Branch("my_ootphoSigmaIetaIeta_per_rechit_m1p1_",&my_ootphoSigmaIetaIeta_per_rechit_m1p1);
  tree->Branch("my_ootphoSigmaIetaIeta_per_rechit_m1p2_",&my_ootphoSigmaIetaIeta_per_rechit_m1p2);
  tree->Branch("my_ootphoSigmaIetaIeta_per_rechit_m1p25_",&my_ootphoSigmaIetaIeta_per_rechit_m1p25);
  tree->Branch("my_ootphoSigmaIetaIeta_per_rechit_m1p5_",&my_ootphoSigmaIetaIeta_per_rechit_m1p5);

  ////normal photon
  tree->Branch("phoPt_",&phoPt);
  tree->Branch("phoPhi_",&phoPhi);
  tree->Branch("phoScEn_",&phoScEn);
  tree->Branch("phoScEta_",&phoScEta);
  tree->Branch("cmssw_phoSigmaIetaIeta_",&cmssw_phoSigmaIetaIeta);
  tree->Branch("my_phoSigmaIetaIeta_",&my_phoSigmaIetaIeta);
  tree->Branch("my_phoSigmaIetaIphi_",&my_phoSigmaIetaIphi);
  tree->Branch("my_phoSigmaIphiIphi_",&my_phoSigmaIphiIphi);
  tree->Branch("my_phoSigmaIphiIphi_per_rechit_",&my_phoSigmaIphiIphi_per_rechit);
  tree->Branch("my_phoSigmaIphiIphi_per_rechit_m1p1_",&my_phoSigmaIphiIphi_per_rechit_m1p1);
  tree->Branch("my_phoSigmaIphiIphi_per_rechit_m1p2_",&my_phoSigmaIphiIphi_per_rechit_m1p2);
  tree->Branch("my_phoSigmaIphiIphi_per_rechit_m1p25_",&my_phoSigmaIphiIphi_per_rechit_m1p25);
  tree->Branch("my_phoSigmaIphiIphi_per_rechit_m1p5_",&my_phoSigmaIphiIphi_per_rechit_m1p5);
  tree->Branch("my_phoSigmaIetaIphi_per_rechit_",&my_phoSigmaIetaIphi_per_rechit);
  tree->Branch("my_phoSigmaIetaIphi_per_rechit_m1p1_",&my_phoSigmaIetaIphi_per_rechit_m1p1);
  tree->Branch("my_phoSigmaIetaIphi_per_rechit_m1p2_",&my_phoSigmaIetaIphi_per_rechit_m1p2);
  tree->Branch("my_phoSigmaIetaIphi_per_rechit_m1p25_",&my_phoSigmaIetaIphi_per_rechit_m1p25);
  tree->Branch("my_phoSigmaIetaIphi_per_rechit_m1p5_",&my_phoSigmaIetaIphi_per_rechit_m1p5);
  tree->Branch("my_phoSigmaIetaIeta_per_rechit_",&my_phoSigmaIetaIeta_per_rechit);
  tree->Branch("my_phoSigmaIetaIeta_per_rechit_m1p1_",&my_phoSigmaIetaIeta_per_rechit_m1p1);
  tree->Branch("my_phoSigmaIetaIeta_per_rechit_m1p2_",&my_phoSigmaIetaIeta_per_rechit_m1p2);
  tree->Branch("my_phoSigmaIetaIeta_per_rechit_m1p25_",&my_phoSigmaIetaIeta_per_rechit_m1p25);
  tree->Branch("my_phoSigmaIetaIeta_per_rechit_m1p5_",&my_phoSigmaIetaIeta_per_rechit_m1p5);


}


DemoAnalyzer::~DemoAnalyzer()
{
  
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  
}

//
// member functions
//

// ------------ method called for each event  ------------
void
DemoAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  
  //  std::cout << "\n \n --New Event-- \n" ;
  using namespace edm;
  
  eleIDbits.clear();
  //  eleIDbit.clear();

  ele_genmatched.clear();
  pho_genmatched.clear();
  cmssw_eleSigmaIetaIeta.clear();
  cmssw_eleSigmaIphiIphi.clear();
  cmssw_eleR9.clear();
  cmssw_eleHoE.clear();
  cmssw_eleHoEfull5x5.clear();
  eleScEta.clear();
  eleScEn.clear();
  elePt.clear();
  ele_fbrem.clear();
  ele_missingHit.clear();
  ele_psEorawE.clear();
  ele_1oEm1op.clear();
  ele_eSCoP.clear();
  ele_eSCoPout.clear();
  ele_convVtxFitProb.clear();
  ele_gsfTrackChi2.clear();
  ele_nHit.clear();
  ele_deltaEtaSuperClusterTrackAtVtx.clear();
  ele_deltaPhiSuperClusterTrackAtVtx.clear();
  ele_deltaEtaSeedClusterTrackAtCalo.clear();
  elePFChIso.clear();
  elePFPhoIso.clear();
  elePFNeuIso.clear();
  ele_etaWidth.clear();
  ele_phiWidth.clear();
  ele_closestCtfTrackNLayers.clear();
  ele_closestCtfTrackNormChi2.clear();
  ele_1mE1x5oE5x5.clear();
  ptRecoEle_by_ptGenEle.clear();
  dR_recoEle_genEle.clear();
  ptRecoPho_by_ptGenPho.clear();
  dR_recoPho_genPho.clear();
  my_eleSigmaIetaIeta.clear();
  my_eleSigmaIetaIphi.clear();
  my_eleSigmaIphiIphi.clear();
  //
  my_eleSigmaIetaIeta_per_rechit.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p1.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p2.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p25.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p5.clear();
  //
  my_eleSigmaIetaIphi_per_rechit.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p1.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p2.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p25.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p5.clear();
  //
  my_eleSigmaIphiIphi_per_rechit.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p1.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p2.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p25.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p5.clear();
  //
  puTrue.clear();
  rho.clear();
  gen_status.clear();
  gen_pdgid.clear();
  gen_pt.clear();

  ///beamhalo
  evt_CSCLooseHaloId.clear();
  evt_CSCTightHaloId.clear();
  evt_CSCTightHaloId2015.clear();
  evt_CSCTightHaloIdTrkMuUnveto.clear();
  evt_EcalLooseHaloId.clear();
  evt_EcalTightHaloId.clear();
  evt_EventSmellsLikeHalo.clear();
  evt_ExtremeTightId.clear();
  evt_GlobalLooseHaloId.clear();
  evt_GlobalSuperTightHaloId2016.clear();
  evt_GlobalTightHaloId.clear();
  evt_GlobalTightHaloId2016.clear();
  evt_HcalLooseHaloId.clear();
  evt_HcalTightHaloId.clear();
  evt_LooseId.clear();
  evt_TightId.clear();
  
  ////oot photon
  ootphoSeedTime.clear();
  ootphoPt.clear();
  ootphoPhi.clear();
  ootphoScEn.clear();
  ootphoScEta.clear();
  cmssw_ootphoSigmaIetaIeta.clear();
  my_ootphoSigmaIetaIeta.clear();
  my_ootphoSigmaIetaIphi.clear();
  my_ootphoSigmaIphiIphi.clear();
  my_ootphoSigmaIphiIphi_per_rechit.clear();
  my_ootphoSigmaIphiIphi_per_rechit_m1p1.clear();
  my_ootphoSigmaIphiIphi_per_rechit_m1p2.clear();
  my_ootphoSigmaIphiIphi_per_rechit_m1p25.clear();
  my_ootphoSigmaIphiIphi_per_rechit_m1p5.clear();
  my_ootphoSigmaIetaIphi_per_rechit.clear();
  my_ootphoSigmaIetaIphi_per_rechit_m1p1.clear();
  my_ootphoSigmaIetaIphi_per_rechit_m1p2.clear();
  my_ootphoSigmaIetaIphi_per_rechit_m1p25.clear();
  my_ootphoSigmaIetaIphi_per_rechit_m1p5.clear();
  my_ootphoSigmaIetaIeta_per_rechit.clear();
  my_ootphoSigmaIetaIeta_per_rechit_m1p1.clear();
  my_ootphoSigmaIetaIeta_per_rechit_m1p2.clear();
  my_ootphoSigmaIetaIeta_per_rechit_m1p25.clear();
  my_ootphoSigmaIetaIeta_per_rechit_m1p5.clear();
  //
  //normal photon
  //
  phoPt.clear();
  phoPhi.clear();
  phoScEn.clear();
  phoScEta.clear();
  cmssw_phoSigmaIetaIeta.clear();
  my_phoSigmaIetaIeta.clear();
  my_phoSigmaIetaIphi.clear();
  my_phoSigmaIphiIphi.clear();
  my_phoSigmaIphiIphi_per_rechit.clear();
  my_phoSigmaIphiIphi_per_rechit_m1p1.clear();
  my_phoSigmaIphiIphi_per_rechit_m1p2.clear();
  my_phoSigmaIphiIphi_per_rechit_m1p25.clear();
  my_phoSigmaIphiIphi_per_rechit_m1p5.clear();
  my_phoSigmaIetaIphi_per_rechit.clear();
  my_phoSigmaIetaIphi_per_rechit_m1p1.clear();
  my_phoSigmaIetaIphi_per_rechit_m1p2.clear();
  my_phoSigmaIetaIphi_per_rechit_m1p25.clear();
  my_phoSigmaIetaIphi_per_rechit_m1p5.clear();
  my_phoSigmaIetaIeta_per_rechit.clear();
  my_phoSigmaIetaIeta_per_rechit_m1p1.clear();
  my_phoSigmaIetaIeta_per_rechit_m1p2.clear();
  my_phoSigmaIetaIeta_per_rechit_m1p25.clear();
  my_phoSigmaIetaIeta_per_rechit_m1p5.clear();
  
  edm::Handle<std::vector<reco::GenParticle> > genParticlesHandle;
  
  ////
  if ( ! iEvent.isRealData()) {
    edm::Handle<std::vector<PileupSummaryInfo> > genPileupHandle;
    iEvent.getByToken(puCollection_, genPileupHandle);
    if (genPileupHandle.isValid()) {
      for (std::vector<PileupSummaryInfo>::const_iterator pu = genPileupHandle->begin(); pu != genPileupHandle->end(); ++pu) {
	puTrue.push_back(pu->getTrueNumInteractions());
      }
    }
    
    iEvent.getByToken(genParticlesCollection_, genParticlesHandle);
    
    if (genParticlesHandle.isValid()) {
      for (std::vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {
	const reco::Candidate *p = (const reco::Candidate*)&(*ip);
	gen_status.push_back(p->status());
	gen_pdgid.push_back(p->pdgId());
	gen_pt.push_back(p->pt());
      }  
    }
  } // check real data
  
  edm::Handle<double> rhoHandle;
  iEvent.getByToken(rhoLabel_, rhoHandle);
  rho.push_back(*(rhoHandle.product()));

  if ( iEvent.isRealData() ) {  
    
    edm::Handle<reco::BeamHaloSummary> beamHaloSummaryHandle;
    iEvent.getByToken(beamHaloSummaryToken_, beamHaloSummaryHandle);
    
    if(beamHaloSummaryHandle.isValid()){
      ///beamhalo
      evt_CSCLooseHaloId.push_back(beamHaloSummaryHandle->CSCLooseHaloId());
      evt_CSCTightHaloId.push_back(beamHaloSummaryHandle->CSCTightHaloId());
      evt_CSCTightHaloId2015.push_back(beamHaloSummaryHandle->CSCTightHaloId2015());
      evt_CSCTightHaloIdTrkMuUnveto.push_back(beamHaloSummaryHandle->CSCTightHaloIdTrkMuUnveto());
      evt_EcalLooseHaloId.push_back(beamHaloSummaryHandle->EcalLooseHaloId());
      evt_EcalTightHaloId.push_back(beamHaloSummaryHandle->EcalTightHaloId());
      evt_EventSmellsLikeHalo.push_back(beamHaloSummaryHandle->EventSmellsLikeHalo());
      evt_ExtremeTightId.push_back(beamHaloSummaryHandle->ExtremeTightId());
      evt_GlobalLooseHaloId.push_back(beamHaloSummaryHandle->GlobalLooseHaloId());
      evt_GlobalSuperTightHaloId2016.push_back(beamHaloSummaryHandle->GlobalSuperTightHaloId2016());
      evt_GlobalTightHaloId.push_back(beamHaloSummaryHandle->GlobalTightHaloId());
      evt_GlobalTightHaloId2016.push_back(beamHaloSummaryHandle->GlobalTightHaloId2016());
      evt_HcalLooseHaloId.push_back(beamHaloSummaryHandle->HcalLooseHaloId());
      evt_HcalTightHaloId.push_back(beamHaloSummaryHandle->HcalTightHaloId());
      evt_LooseId.push_back(beamHaloSummaryHandle->LooseId());
      evt_TightId.push_back(beamHaloSummaryHandle->TightId());


    }

    for(const auto& ootpho : iEvent.get(ootphoToken_) ) {
      ootphoPt.push_back(ootpho.pt());
      ootphoPhi.push_back(ootpho.phi());
      ootphoScEn.push_back(ootpho.superCluster()->energy());
      ootphoScEta.push_back(ootpho.superCluster()->eta());
      cmssw_ootphoSigmaIetaIeta.push_back(ootpho.full5x5_sigmaIetaIeta());

      const reco::SuperCluster& ootsuperClus = *ootpho.superCluster();
      const reco::CaloCluster &ootseedCluster = *ootsuperClus.seed();

      DetId seed = ootseedCluster.hitsAndFractions()[0].first;

      const bool ootiseb = ootseedCluster.hitsAndFractions()[0].first.subdetId() == EcalBarrel;
      edm::Handle<EcalRecHitCollection> ootEBRecHits_;
      edm::Handle<EcalRecHitCollection> ootEERecHits_;
      iEvent.getByToken(EBRecHitCollectionT_, ootEBRecHits_);
      iEvent.getByToken(EERecHitCollectionT_, ootEERecHits_);
      const EcalRecHitCollection *ootrecHits = ootiseb ? ootEBRecHits_.product() : ootEERecHits_.product();
      
      EcalRecHitCollection::const_iterator theSeedHit = ootrecHits->find(seed);
      if (theSeedHit != ootrecHits->end()) {
	ootphoSeedTime.push_back((*theSeedHit).time());
      } else{
	ootphoSeedTime.push_back(999);
      }

      iSetup.get<CaloTopologyRecord>().get(theCaloTopology);
      const CaloTopology* ootcaloTopology = theCaloTopology.product();
      
      //    std::cout << "will do iSetup.get<CaloGeometryRecord>().get(theCaloGeometry) \n";
      iSetup.get<CaloGeometryRecord>().get(theCaloGeometry);
      // std::cout << "ok have theCaloGeometry now--> get the product now \n" ;
      const CaloGeometry* caloGeometry;
      if (theCaloGeometry)  caloGeometry = theCaloGeometry.product();
      
      using ClusterTools = noZS::EcalClusterTools;     
      
      std::vector<float> ootmylocalCovariances = ClusterTools::localCovariances(ootseedCluster, ootrecHits, ootcaloTopology,4.7,0,0 ) ;
      
      std::vector<float> ootmylocalCovariances_per_rechit ;
      std::vector<float> ootmylocalCovariances_per_rechit_m1p1 ;
      std::vector<float> ootmylocalCovariances_per_rechit_m1p2 ;
      std::vector<float> ootmylocalCovariances_per_rechit_m1p25 ;
      std::vector<float> ootmylocalCovariances_per_rechit_m1p5 ;
      
      if (theCaloGeometry) {
	ootmylocalCovariances_per_rechit = ClusterTools::localCovariancesnew(ootseedCluster, ootrecHits, ootcaloTopology, caloGeometry, &iSetup, 4.7, 1).cov;
	ootmylocalCovariances_per_rechit_m1p1 = ClusterTools::localCovariancesnew(ootseedCluster, ootrecHits, ootcaloTopology, caloGeometry, &iSetup, 4.7, 1.1).cov;
	ootmylocalCovariances_per_rechit_m1p2 = ClusterTools::localCovariancesnew(ootseedCluster, ootrecHits, ootcaloTopology, caloGeometry, &iSetup, 4.7, 1.2).cov;
	ootmylocalCovariances_per_rechit_m1p25 = ClusterTools::localCovariancesnew(ootseedCluster, ootrecHits, ootcaloTopology, caloGeometry, &iSetup, 4.7, 1.25).cov;
	ootmylocalCovariances_per_rechit_m1p5 = ClusterTools::localCovariancesnew(ootseedCluster, ootrecHits, ootcaloTopology, caloGeometry, &iSetup, 4.7, 1.5).cov;
	
      }
      
      float ootsigmaIetaIeta = sqrt(ootmylocalCovariances[0]);
      my_ootphoSigmaIetaIeta.push_back(ootsigmaIetaIeta);
      
      float ootsigmaIetaIeta_per_rechit = sqrt(ootmylocalCovariances_per_rechit[0]);
      my_ootphoSigmaIetaIeta_per_rechit.push_back(ootsigmaIetaIeta_per_rechit);

      float ootsigmaIetaIeta_per_rechit_m1p1 = sqrt(ootmylocalCovariances_per_rechit_m1p1[0]);
      my_ootphoSigmaIetaIeta_per_rechit_m1p1.push_back(ootsigmaIetaIeta_per_rechit_m1p1);
      
      float ootsigmaIetaIeta_per_rechit_m1p2 = sqrt(ootmylocalCovariances_per_rechit_m1p2[0]);
      my_ootphoSigmaIetaIeta_per_rechit_m1p2.push_back(ootsigmaIetaIeta_per_rechit_m1p2);
      
      float ootsigmaIetaIeta_per_rechit_m1p25 = sqrt(ootmylocalCovariances_per_rechit_m1p25[0]);
      my_ootphoSigmaIetaIeta_per_rechit_m1p25.push_back(ootsigmaIetaIeta_per_rechit_m1p25);
      
      float ootsigmaIetaIeta_per_rechit_m1p5 = sqrt(ootmylocalCovariances_per_rechit_m1p5[0]);
      my_ootphoSigmaIetaIeta_per_rechit_m1p5.push_back(ootsigmaIetaIeta_per_rechit_m1p5);
      //
      
      float ootsigmaIetaIphi = sqrt(ootmylocalCovariances[1]);
      my_ootphoSigmaIetaIphi.push_back(ootsigmaIetaIphi);
      
      float ootsigmaIetaIphi_per_rechit = sqrt(ootmylocalCovariances_per_rechit[1]);
      my_ootphoSigmaIetaIphi_per_rechit.push_back(ootsigmaIetaIphi_per_rechit);
      
      float ootsigmaIetaIphi_per_rechit_m1p1 = sqrt(ootmylocalCovariances_per_rechit_m1p1[1]);
      my_ootphoSigmaIetaIphi_per_rechit_m1p1.push_back(ootsigmaIetaIphi_per_rechit_m1p1);
      
      float ootsigmaIetaIphi_per_rechit_m1p2 = sqrt(ootmylocalCovariances_per_rechit_m1p2[1]);
      my_ootphoSigmaIetaIphi_per_rechit_m1p2.push_back(ootsigmaIetaIphi_per_rechit_m1p2);
      
      float ootsigmaIetaIphi_per_rechit_m1p25 = sqrt(ootmylocalCovariances_per_rechit_m1p25[1]);
      my_ootphoSigmaIetaIphi_per_rechit_m1p25.push_back(ootsigmaIetaIphi_per_rechit_m1p25);
      
      float ootsigmaIetaIphi_per_rechit_m1p5 = sqrt(ootmylocalCovariances_per_rechit_m1p5[1]);
      my_ootphoSigmaIetaIphi_per_rechit_m1p5.push_back(ootsigmaIetaIphi_per_rechit_m1p5);
      
      //
      float ootsigmaIphiIphi = sqrt(ootmylocalCovariances[2]);
      my_ootphoSigmaIphiIphi.push_back(ootsigmaIphiIphi);
      
      float ootsigmaIphiIphi_per_rechit = sqrt(ootmylocalCovariances_per_rechit[2]);
      my_ootphoSigmaIphiIphi_per_rechit.push_back(ootsigmaIphiIphi_per_rechit);
      
      float ootsigmaIphiIphi_per_rechit_m1p1 = sqrt(ootmylocalCovariances_per_rechit_m1p1[2]);
      my_ootphoSigmaIphiIphi_per_rechit_m1p1.push_back(ootsigmaIphiIphi_per_rechit_m1p1);
      
      float ootsigmaIphiIphi_per_rechit_m1p2 = sqrt(ootmylocalCovariances_per_rechit_m1p2[2]);
      my_ootphoSigmaIphiIphi_per_rechit_m1p2.push_back(ootsigmaIphiIphi_per_rechit_m1p2);
      
      float ootsigmaIphiIphi_per_rechit_m1p25 = sqrt(ootmylocalCovariances_per_rechit_m1p25[2]);
      my_ootphoSigmaIphiIphi_per_rechit_m1p25.push_back(ootsigmaIphiIphi_per_rechit_m1p25);
      
      float ootsigmaIphiIphi_per_rechit_m1p5 = sqrt(ootmylocalCovariances_per_rechit_m1p5[2]);
      my_ootphoSigmaIphiIphi_per_rechit_m1p5.push_back(ootsigmaIphiIphi_per_rechit_m1p5);
      
    }
  } // real data check
  
  if (RunPho) {
    ////normal photon
    for(const auto& pho : iEvent.get(phoToken_) ) {
      //std::cout << "\n new photon " << std::endl;

      int thispho_genmatched=0;
      double thispho_min_dr=9999.9;
      double thispho_ptR=9999.9;
      if ( ! iEvent.isRealData()) {
	
	if (genParticlesHandle.isValid()) {
	  for (std::vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {
	    const reco::Candidate *p = (const reco::Candidate*)&(*ip);

	    if ( (p->status()==1) && ((abs(p->pdgId())) == 22) )  {

	      double this_dr=reco::deltaR(pho,*p);
	      if (this_dr<thispho_min_dr) {
		thispho_min_dr=this_dr;
		thispho_ptR=pho.pt()/p->pt();
	      }

	      // if ( ((reco::deltaR(pho,*p))<0.04) && ((pho.pt()/p->pt())>0.7) &&   ((pho.pt()/p->pt())<1.3) ) {
	      //	thispho_genmatched=1;
		
	    }
	  }
	}
      }
    
      if ( (thispho_min_dr<0.08) && (thispho_ptR>0.8) && (thispho_ptR<1.2) )  thispho_genmatched=1;

      //      std::cout << "thispho_genmatched " << thispho_genmatched <<  " dr " << thispho_min_dr << " ptRatio " << thispho_ptR << std::endl;      
      pho_genmatched.push_back(thispho_genmatched);
      dR_recoPho_genPho.push_back(thispho_min_dr);
      ptRecoPho_by_ptGenPho.push_back(thispho_ptR);
      phoPt.push_back(pho.pt());
      phoPhi.push_back(pho.phi());
      phoScEn.push_back(pho.superCluster()->energy());
      phoScEta.push_back(pho.superCluster()->eta());
      cmssw_phoSigmaIetaIeta.push_back(pho.full5x5_sigmaIetaIeta());

      const reco::SuperCluster& phosuperClus = *pho.superCluster();
      const reco::CaloCluster &phoseedCluster = *phosuperClus.seed();
      const bool phoiseb = phoseedCluster.hitsAndFractions()[0].first.subdetId() == EcalBarrel;
      edm::Handle<EcalRecHitCollection> phoEBRecHits_;
      edm::Handle<EcalRecHitCollection> phoEERecHits_;
      iEvent.getByToken(EBRecHitCollectionT_, phoEBRecHits_);
      iEvent.getByToken(EERecHitCollectionT_, phoEERecHits_);
      const EcalRecHitCollection *phorecHits = phoiseb ? phoEBRecHits_.product() : phoEERecHits_.product();
      
      iSetup.get<CaloTopologyRecord>().get(theCaloTopology);
      const CaloTopology* phocaloTopology = theCaloTopology.product();
      
      iSetup.get<CaloGeometryRecord>().get(theCaloGeometry);
      const CaloGeometry* caloGeometry;
      if (theCaloGeometry)  caloGeometry = theCaloGeometry.product();
      
      using ClusterTools = noZS::EcalClusterTools;     
      
      std::vector<float> phomylocalCovariances = ClusterTools::localCovariances(phoseedCluster, phorecHits, phocaloTopology,4.7,0,0 ) ;
      std::vector<float> phomylocalCovariances_per_rechit ;
      std::vector<float> phomylocalCovariances_per_rechit_m1p1 ;
      std::vector<float> phomylocalCovariances_per_rechit_m1p2 ;
      std::vector<float> phomylocalCovariances_per_rechit_m1p25 ;
      std::vector<float> phomylocalCovariances_per_rechit_m1p5 ;
      
      if (theCaloGeometry) {
	phomylocalCovariances_per_rechit = ClusterTools::localCovariancesnew(phoseedCluster, phorecHits, phocaloTopology, caloGeometry, &iSetup, 4.7, 1).cov;
	phomylocalCovariances_per_rechit_m1p1 = ClusterTools::localCovariancesnew(phoseedCluster, phorecHits, phocaloTopology, caloGeometry, &iSetup, 4.7, 1.1).cov;
	phomylocalCovariances_per_rechit_m1p2 = ClusterTools::localCovariancesnew(phoseedCluster, phorecHits, phocaloTopology, caloGeometry, &iSetup, 4.7, 1.2).cov;
	phomylocalCovariances_per_rechit_m1p25 = ClusterTools::localCovariancesnew(phoseedCluster, phorecHits, phocaloTopology, caloGeometry, &iSetup, 4.7, 1.25).cov;
	phomylocalCovariances_per_rechit_m1p5 = ClusterTools::localCovariancesnew(phoseedCluster, phorecHits, phocaloTopology, caloGeometry, &iSetup, 4.7, 1.5).cov;
	
      }
      
      float phosigmaIetaIeta = sqrt(phomylocalCovariances[0]);
      my_phoSigmaIetaIeta.push_back(phosigmaIetaIeta);
      
      float phosigmaIetaIeta_per_rechit = sqrt(phomylocalCovariances_per_rechit[0]);
      my_phoSigmaIetaIeta_per_rechit.push_back(phosigmaIetaIeta_per_rechit);
      
      float phosigmaIetaIeta_per_rechit_m1p1 = sqrt(phomylocalCovariances_per_rechit_m1p1[0]);
      my_phoSigmaIetaIeta_per_rechit_m1p1.push_back(phosigmaIetaIeta_per_rechit_m1p1);
      
      float phosigmaIetaIeta_per_rechit_m1p2 = sqrt(phomylocalCovariances_per_rechit_m1p2[0]);
      my_phoSigmaIetaIeta_per_rechit_m1p2.push_back(phosigmaIetaIeta_per_rechit_m1p2);
      
      float phosigmaIetaIeta_per_rechit_m1p25 = sqrt(phomylocalCovariances_per_rechit_m1p25[0]);
      my_phoSigmaIetaIeta_per_rechit_m1p25.push_back(phosigmaIetaIeta_per_rechit_m1p25);
      
      float phosigmaIetaIeta_per_rechit_m1p5 = sqrt(phomylocalCovariances_per_rechit_m1p5[0]);
      my_phoSigmaIetaIeta_per_rechit_m1p5.push_back(phosigmaIetaIeta_per_rechit_m1p5);
      //
      
      float phosigmaIetaIphi = sqrt(phomylocalCovariances[1]);
      my_phoSigmaIetaIphi.push_back(phosigmaIetaIphi);
      
      float phosigmaIetaIphi_per_rechit = sqrt(phomylocalCovariances_per_rechit[1]);
      my_phoSigmaIetaIphi_per_rechit.push_back(phosigmaIetaIphi_per_rechit);
      
      float phosigmaIetaIphi_per_rechit_m1p1 = sqrt(phomylocalCovariances_per_rechit_m1p1[1]);
      my_phoSigmaIetaIphi_per_rechit_m1p1.push_back(phosigmaIetaIphi_per_rechit_m1p1);
      
      float phosigmaIetaIphi_per_rechit_m1p2 = sqrt(phomylocalCovariances_per_rechit_m1p2[1]);
      my_phoSigmaIetaIphi_per_rechit_m1p2.push_back(phosigmaIetaIphi_per_rechit_m1p2);
      
      float phosigmaIetaIphi_per_rechit_m1p25 = sqrt(phomylocalCovariances_per_rechit_m1p25[1]);
      my_phoSigmaIetaIphi_per_rechit_m1p25.push_back(phosigmaIetaIphi_per_rechit_m1p25);
      
      float phosigmaIetaIphi_per_rechit_m1p5 = sqrt(phomylocalCovariances_per_rechit_m1p5[1]);
      my_phoSigmaIetaIphi_per_rechit_m1p5.push_back(phosigmaIetaIphi_per_rechit_m1p5);
      
      //
      float phosigmaIphiIphi = sqrt(phomylocalCovariances[2]);
      my_phoSigmaIphiIphi.push_back(phosigmaIphiIphi);
      
      float phosigmaIphiIphi_per_rechit = sqrt(phomylocalCovariances_per_rechit[2]);
      my_phoSigmaIphiIphi_per_rechit.push_back(phosigmaIphiIphi_per_rechit);
      
      float phosigmaIphiIphi_per_rechit_m1p1 = sqrt(phomylocalCovariances_per_rechit_m1p1[2]);
      my_phoSigmaIphiIphi_per_rechit_m1p1.push_back(phosigmaIphiIphi_per_rechit_m1p1);
      
      float phosigmaIphiIphi_per_rechit_m1p2 = sqrt(phomylocalCovariances_per_rechit_m1p2[2]);
      my_phoSigmaIphiIphi_per_rechit_m1p2.push_back(phosigmaIphiIphi_per_rechit_m1p2);
      
      float phosigmaIphiIphi_per_rechit_m1p25 = sqrt(phomylocalCovariances_per_rechit_m1p25[2]);
      my_phoSigmaIphiIphi_per_rechit_m1p25.push_back(phosigmaIphiIphi_per_rechit_m1p25);
      
      float phosigmaIphiIphi_per_rechit_m1p5 = sqrt(phomylocalCovariances_per_rechit_m1p5[2]);
      my_phoSigmaIphiIphi_per_rechit_m1p5.push_back(phosigmaIphiIphi_per_rechit_m1p5);
      
    }
    
  }

  if (RunEle) {  
    
    //    edm::Handle<edm::View<pat::Electron> > electronHandle;
    // iEvent.getByToken(eleToken_, electronHandle);

    //    for (edm::View<pat::Electron>::const_iterator ele = electronHandle->begin(); ele != electronHandle->end(); ++ele) {
     for(const auto& ele : iEvent.get(eleToken_) ) {
      // std::cout << "\n ---/// New Electron .... " << std::endl;

      ///ele ID
      //      UShort_t tmpeleIDbit = 0;   
      //  bool isPassVeto   = ele->electronID("cutBasedElectronID-Fall17-94X-V2-veto");
      //  if (isPassVeto)   setbit(tmpeleIDbit, 0);    

      //      bool isPassLoose  = ele->electronID("cutBasedElectronID-Fall17-94X-V2-loose");
      // if (isPassLoose)  setbit(tmpeleIDbit, 1);
   
      //      bool isPassMedium = ele->electronID("cutBasedElectronID-Fall17-94X-V2-medium");
      // if (isPassMedium) setbit(tmpeleIDbit, 2);    

      //      bool isPassTight  = ele->electronID("cutBasedElectronID-Fall17-94X-V2-tight");
      // if (isPassTight)  setbit(tmpeleIDbit, 3);    

      //      bool isPassHEEP   = ele->electronID("heepElectronID-HEEPV70");
      // if (isPassHEEP)   setbit(tmpeleIDbit, 4);

      //      eleIDbit.push_back(tmpeleIDbit);

       eleIDbits.push_back({          
            ele.userInt("cutBasedElectronID-Fall17-94X-V2-veto"),
	    ele.userInt("cutBasedElectronID-Fall17-94X-V2-loose"),
	    ele.userInt("cutBasedElectronID-Fall17-94X-V2-medium"),
	    ele.userInt("cutBasedElectronID-Fall17-94X-V2-tight"),
	    ele.userInt("heepElectronID-HEEPV70")});
      
      int genmatched=0;
      double min_dr=9999.9;
      double ptR=9999.9;
      //int status=99;
      //unsigned int mypdg=99;

      if ( ! iEvent.isRealData()) {
	
	if (genParticlesHandle.isValid()) {
	  // std::cout << "---- starting gen loop ----" << std::endl;
	  for (std::vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {
	    const reco::Candidate *p = (const reco::Candidate*)&(*ip);
	    //if ( (p->status()==1) && abs(p->pdgId() == 11) ) std::cout << "dR = " << reco::deltaR(ele,*p) << " ele pt = " << ele->pt() << " gen pt = " << p->pt() <<std::endl;
	    //std::cout << "status " << p->status() << " pdg " << p->pdgId() << std::endl;
	    if ( (p->status()==1) &&  ((abs(p->pdgId())) == 11) ) {
	      // std::cout << "found ele/positron with status 1, check dR with reco ele " << std::endl;
	      double this_dr=reco::deltaR(ele,*p);
	      //std::cout << "this_dr " << this_dr << std::endl;
	      //mypdg=p->pdgId();
	      if (this_dr<min_dr) {
		//	std::cout << "this_dr is < min_dr " << min_dr << " set new min_dr "<< std::endl;
		min_dr=this_dr;
		ptR=ele.pt()/p->pt();
		//	std::cout << "ptRatio " << ptR << std::endl;
	      }
	       //      if ( ((reco::deltaR(ele,*p))<0.04) && ((ele->pt()/p->pt())>0.7) &&   ((ele->pt()/p->pt())<1.3) ) genmatched=1;
	    }
	  }
	}
      }

    
      if ( (min_dr<0.04) && (ptR>0.7) && (ptR<1.3) )  genmatched=1;

      ele_genmatched.push_back(genmatched);
      dR_recoEle_genEle.push_back(min_dr);
      ptRecoEle_by_ptGenEle.push_back(ptR);
      cmssw_eleSigmaIetaIeta.push_back(ele.full5x5_sigmaIetaIeta());
      cmssw_eleSigmaIphiIphi.push_back(ele.full5x5_sigmaIphiIphi());
      cmssw_eleR9.push_back(ele.full5x5_r9());
      cmssw_eleHoE.push_back(ele.hcalOverEcal());
      cmssw_eleHoEfull5x5.push_back(ele.full5x5_hcalOverEcal());
      eleScEta.push_back(ele.superCluster()->eta());
      eleScEn.push_back(ele.superCluster()->energy());
      elePt.push_back(ele.pt());
      ele_1mE1x5oE5x5.push_back(1-(ele.full5x5_e1x5()/ele.full5x5_e5x5()));      
      ele_etaWidth.push_back(ele.superCluster()->etaWidth());
      ele_phiWidth.push_back(ele.superCluster()->phiWidth());
      ele_closestCtfTrackNLayers.push_back(ele.closestCtfTrackNLayers());
      ele_closestCtfTrackNormChi2.push_back(ele.closestCtfTrackNormChi2());
      ele_deltaEtaSuperClusterTrackAtVtx.push_back(ele.deltaEtaSuperClusterTrackAtVtx());
      ele_deltaPhiSuperClusterTrackAtVtx.push_back(ele.deltaPhiSuperClusterTrackAtVtx());
      ele_deltaEtaSeedClusterTrackAtCalo.push_back(ele.deltaEtaSeedClusterTrackAtCalo());
      ele_fbrem.push_back(ele.fbrem());
      ele_missingHit.push_back(ele.gsfTrack()->hitPattern().numberOfLostHits(reco::HitPattern::MISSING_INNER_HITS));
      ele_nHit.push_back(ele.gsfTrack()->hitPattern().trackerLayersWithMeasurement());
      ele_gsfTrackChi2.push_back(ele.gsfTrack()->normalizedChi2());
      ele_convVtxFitProb.push_back(ele.convVtxFitProb());
      ele_eSCoP.push_back(ele.eSuperClusterOverP());
      ele_eSCoPout.push_back(ele.eEleClusterOverPout());
      ele_1oEm1op.push_back( (1.0/ele.ecalEnergy()) - (1.0/ele.trackMomentumAtVtx().r()) );
      ele_psEorawE.push_back( ele.superCluster()->preshowerEnergy()/ele.superCluster()->rawEnergy() );

      reco::GsfElectron::PflowIsolationVariables pfIso = ele.pfIsolationVariables();
      elePFChIso.push_back(pfIso.sumChargedHadronPt);
      elePFPhoIso.push_back(pfIso.sumPhotonEt);
      elePFNeuIso.push_back(pfIso.sumNeutralHadronEt);

      const reco::SuperCluster& superClus = *ele.superCluster();
      const reco::CaloCluster &seedCluster = *superClus.seed();
      const bool iseb = seedCluster.hitsAndFractions()[0].first.subdetId() == EcalBarrel;
      edm::Handle<EcalRecHitCollection> EBRecHits_;
      edm::Handle<EcalRecHitCollection> EERecHits_;
      iEvent.getByToken(EBRecHitCollectionT_, EBRecHits_);
      iEvent.getByToken(EERecHitCollectionT_, EERecHits_);
      const EcalRecHitCollection *recHits = iseb ? EBRecHits_.product() : EERecHits_.product();
      
      iSetup.get<CaloTopologyRecord>().get(theCaloTopology);
      const CaloTopology* caloTopology = theCaloTopology.product();
      
      iSetup.get<CaloGeometryRecord>().get(theCaloGeometry);
      const CaloGeometry* caloGeometry;
      if (theCaloGeometry)  caloGeometry = theCaloGeometry.product();
      using ClusterTools = noZS::EcalClusterTools;     
      std::vector<float> mylocalCovariances = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0,0 ) ;
      //
      std::vector<float> mylocalCovariances_per_rechit ;
      std::vector<float> mylocalCovariances_per_rechit_m1p1 ;
      std::vector<float> mylocalCovariances_per_rechit_m1p2 ;
      std::vector<float> mylocalCovariances_per_rechit_m1p25 ;
      std::vector<float> mylocalCovariances_per_rechit_m1p5 ;
      //
      
      if (theCaloGeometry) {
	
	mylocalCovariances_per_rechit = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1).cov;
	mylocalCovariances_per_rechit_m1p1 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.1).cov;
	mylocalCovariances_per_rechit_m1p2 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.2).cov;
	mylocalCovariances_per_rechit_m1p25 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry,  &iSetup, 4.7, 1.25).cov;
	mylocalCovariances_per_rechit_m1p5 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.5).cov;
	
      }
      
      float sigmaIetaIeta = sqrt(mylocalCovariances[0]);
      my_eleSigmaIetaIeta.push_back(sigmaIetaIeta);
      float sigmaIetaIphi = sqrt(mylocalCovariances[1]);
      my_eleSigmaIetaIphi.push_back(sigmaIetaIphi);
      float sigmaIphiIphi = sqrt(mylocalCovariances[2]);
      my_eleSigmaIphiIphi.push_back(sigmaIphiIphi);
      //
      //ietaiphi
      //
      float sigmaIetaIeta_per_rechit = sqrt(mylocalCovariances_per_rechit[0]); 
      my_eleSigmaIetaIeta_per_rechit.push_back(sigmaIetaIeta_per_rechit);
      
      float sigmaIetaIeta_per_rechit_m1p1 = sqrt(mylocalCovariances_per_rechit_m1p1[0]); 
      my_eleSigmaIetaIeta_per_rechit_m1p1.push_back(sigmaIetaIeta_per_rechit_m1p1);
      
      float sigmaIetaIeta_per_rechit_m1p2 = sqrt(mylocalCovariances_per_rechit_m1p2[0]); 
      my_eleSigmaIetaIeta_per_rechit_m1p2.push_back(sigmaIetaIeta_per_rechit_m1p2);
      
      float sigmaIetaIeta_per_rechit_m1p25 = sqrt(mylocalCovariances_per_rechit_m1p25[0]); 
      my_eleSigmaIetaIeta_per_rechit_m1p25.push_back(sigmaIetaIeta_per_rechit_m1p25);
      //
      float sigmaIetaIeta_per_rechit_m1p5 = sqrt(mylocalCovariances_per_rechit_m1p5[0]); 
      my_eleSigmaIetaIeta_per_rechit_m1p5.push_back(sigmaIetaIeta_per_rechit_m1p5);
      
      //
      float sigmaIetaIphi_per_rechit = sqrt(mylocalCovariances_per_rechit[1]); 
      my_eleSigmaIetaIphi_per_rechit.push_back(sigmaIetaIphi_per_rechit);
      
      float sigmaIetaIphi_per_rechit_m1p1 = sqrt(mylocalCovariances_per_rechit_m1p1[1]); 
      my_eleSigmaIetaIphi_per_rechit_m1p1.push_back(sigmaIetaIphi_per_rechit_m1p1);
      
      float sigmaIetaIphi_per_rechit_m1p2 = sqrt(mylocalCovariances_per_rechit_m1p2[1]); 
      my_eleSigmaIetaIphi_per_rechit_m1p2.push_back(sigmaIetaIphi_per_rechit_m1p2);
      
      float sigmaIetaIphi_per_rechit_m1p25 = sqrt(mylocalCovariances_per_rechit_m1p25[1]); 
      my_eleSigmaIetaIphi_per_rechit_m1p25.push_back(sigmaIetaIphi_per_rechit_m1p25);
      
      float sigmaIetaIphi_per_rechit_m1p5 = sqrt(mylocalCovariances_per_rechit_m1p5[1]); 
      my_eleSigmaIetaIphi_per_rechit_m1p5.push_back(sigmaIetaIphi_per_rechit_m1p5);
      
      // 
      float sigmaIphiIphi_per_rechit = sqrt(mylocalCovariances_per_rechit[2]); 
      my_eleSigmaIphiIphi_per_rechit.push_back(sigmaIphiIphi_per_rechit);
      
      float sigmaIphiIphi_per_rechit_m1p1 = sqrt(mylocalCovariances_per_rechit_m1p1[2]); 
      my_eleSigmaIphiIphi_per_rechit_m1p1.push_back(sigmaIphiIphi_per_rechit_m1p1);
      
      float sigmaIphiIphi_per_rechit_m1p2 = sqrt(mylocalCovariances_per_rechit_m1p2[2]); 
      my_eleSigmaIphiIphi_per_rechit_m1p2.push_back(sigmaIphiIphi_per_rechit_m1p2);
      
      float sigmaIphiIphi_per_rechit_m1p25 = sqrt(mylocalCovariances_per_rechit_m1p25[2]); 
      my_eleSigmaIphiIphi_per_rechit_m1p25.push_back(sigmaIphiIphi_per_rechit_m1p25);
      
      float sigmaIphiIphi_per_rechit_m1p5 = sqrt(mylocalCovariances_per_rechit_m1p5[2]); 
      my_eleSigmaIphiIphi_per_rechit_m1p5.push_back(sigmaIphiIphi_per_rechit_m1p5);
      
    }
    
  }
  
  tree->Fill();
  
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
  ESHandle<SetupData> pSetup;
  iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void
DemoAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void
DemoAnalyzer::endJob()
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
DemoAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

  //Specify that only 'tracks' is allowed
  //To use, remove the default given above and uncomment below
  //ParameterSetDescription desc;
  //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
  //descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(DemoAnalyzer);
