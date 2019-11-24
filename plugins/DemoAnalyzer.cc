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
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaRecHitIsolation.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHit.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/Math/interface/deltaR.h"
//#include "DataFormats/ParticleFlowReco/interface/PFRecHit.h"
//#include "DataFormats/ParticleFlowReco/interface/PFRecHitFwd.h"
#include "CondFormats/EcalObjects/interface/EcalPFRecHitThresholds.h"
#include "CondFormats/DataRecord/interface/EcalPFRecHitThresholdsRcd.h"
//#include "RecoParticleFlow/PFClusterProducer/interface/PFRecHitQTestBase.h"
////#include "RecoParticleFlow/PFClusterProducer/plugins/PFRecHitProducer.h"
//#include "RecoParticleFlow/PFClusterProducer/interface/PFRecHitCreatorBase.h"

#include "TTree.h"
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

  std::vector<float>  crysEta;
  std::vector<float>  crysPhi;
  std::vector<float>  crysThr;
  std::vector<int>   trkCharge;
  std::vector<double>  cmssw_eleSigmaIetaIeta;
  std::vector<double>  cmssw_eleSigmaIphiIphi;
  //  std::vector<double>  cmssw_eleSigmaIetaIphi;
  std::vector<float>  cmssw_eleR9;
  std::vector<float>  cmssw_eleHoE;
  std::vector<float>  eleScEta;
  std::vector<float>  eleScEn;
  std::vector<float>  elePt;
  std::vector<float>  ptRecoEle_by_ptGenEle;
  std::vector<float>  dR_recoEle_genEle;
  std::vector<float>  puTrue;
  std::vector<double>  my_eleSigmaIetaIeta;
  std::vector<double>  my_eleSigmaIetaIphi;
  std::vector<double>  my_eleSigmaIphiIphi;
  //
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p05;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p1;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p15;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p2;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p25;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p3;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p4;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p5;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p6;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p7;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p8;
  std::vector<double>  my_eleSigmaIetaIeta_per_rechit_m1p9;
  //
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p05;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p1;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p15;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p2;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p25;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p3;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p4;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p5;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p6;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p7;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p8;
  std::vector<double>  my_eleSigmaIetaIphi_per_rechit_m1p9;
  //
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p05;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p1;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p15;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p2;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p25;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p3;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p4;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p5;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p6;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p7;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p8;
  std::vector<double>  my_eleSigmaIphiIphi_per_rechit_m1p9;
  //
  std::vector<double>  my_eleSigmaIetaIeta_w4p6;
  std::vector<double>  my_eleSigmaIetaIeta_w4p5;
  std::vector<double>  my_eleSigmaIetaIeta_w4p4;
  std::vector<double>  my_eleSigmaIetaIeta_w4p3;
  std::vector<double>  my_eleSigmaIetaIeta_w4p2;
  std::vector<double>  my_eleSigmaIetaIeta_w4p1;
  std::vector<double>  my_eleSigmaIetaIeta_w4p0;
  std::vector<double>  my_eleSigmaIetaIeta_w3p8;
  std::vector<double>  my_eleSigmaIetaIeta_w3p7;
  std::vector<double>  my_eleSigmaIetaIeta_w3p6;
  std::vector<double>  my_eleSigmaIetaIeta_w3p5;
  std::vector<double>  my_eleSigmaIetaIeta_w3p4;
  std::vector<double>  my_eleSigmaIetaIeta_w3p3;
  std::vector<double>  my_eleSigmaIetaIeta_w3p2;
  std::vector<double>  my_eleSigmaIetaIeta_w3p0;
  //
  std::vector<double>  my_eleSigmaIetaIphi_w4p6;
  std::vector<double>  my_eleSigmaIetaIphi_w4p5;
  std::vector<double>  my_eleSigmaIetaIphi_w4p4;
  std::vector<double>  my_eleSigmaIetaIphi_w4p3;
  std::vector<double>  my_eleSigmaIetaIphi_w4p2;
  std::vector<double>  my_eleSigmaIetaIphi_w4p1;
  std::vector<double>  my_eleSigmaIetaIphi_w4p0;
  std::vector<double>  my_eleSigmaIetaIphi_w3p8;
  std::vector<double>  my_eleSigmaIetaIphi_w3p7;
  std::vector<double>  my_eleSigmaIetaIphi_w3p6;
  std::vector<double>  my_eleSigmaIetaIphi_w3p5;
  std::vector<double>  my_eleSigmaIetaIphi_w3p4;
  std::vector<double>  my_eleSigmaIetaIphi_w3p3;
  std::vector<double>  my_eleSigmaIetaIphi_w3p2;
  std::vector<double>  my_eleSigmaIetaIphi_w3p0;
  //
  std::vector<double>  my_eleSigmaIphiIphi_w4p6;
  std::vector<double>  my_eleSigmaIphiIphi_w4p5;
  std::vector<double>  my_eleSigmaIphiIphi_w4p4;
  std::vector<double>  my_eleSigmaIphiIphi_w4p3;
  std::vector<double>  my_eleSigmaIphiIphi_w4p2;
  std::vector<double>  my_eleSigmaIphiIphi_w4p1;
  std::vector<double>  my_eleSigmaIphiIphi_w4p0;
  std::vector<double>  my_eleSigmaIphiIphi_w3p8;
  std::vector<double>  my_eleSigmaIphiIphi_w3p7;
  std::vector<double>  my_eleSigmaIphiIphi_w3p6;
  std::vector<double>  my_eleSigmaIphiIphi_w3p5;
  std::vector<double>  my_eleSigmaIphiIphi_w3p4;
  std::vector<double>  my_eleSigmaIphiIphi_w3p3;
  std::vector<double>  my_eleSigmaIphiIphi_w3p2;
  std::vector<double>  my_eleSigmaIphiIphi_w3p0;
  //
  std::vector<double>  my_eleSigmaIetaIeta_en0p15;
  std::vector<double>  my_eleSigmaIetaIeta_en0p2;
  std::vector<double>  my_eleSigmaIetaIeta_en0p5;
  std::vector<double>  my_eleSigmaIetaIeta_en1;
  std::vector<double>  my_eleSigmaIetaIeta_en0p15_noRelNoiseCut;
  std::vector<double>  my_eleSigmaIetaIeta_en0p2_noRelNoiseCut;
  std::vector<double>  my_eleSigmaIetaIeta_en0p5_noRelNoiseCut;
  std::vector<double>  my_eleSigmaIetaIeta_en1_noRelNoiseCut;
  std::vector<double>  my_eleSigmaIetaIeta_en_0p1_0p4;
  std::vector<double>  my_eleSigmaIetaIeta_en_0p15_0p5;
  std::vector<double>  my_eleSigmaIetaIeta_en_0p16_0p6;
  std::vector<double>  my_eleSigmaIetaIeta_en_0p2_1;
  std::vector<double>  my_eleSigmaIetaIeta_en_0p2_1p5;
  std::vector<double>  my_eleSigmaIetaIeta_en_0p2_2;
  std::vector<double>  my_eleSigmaIetaIeta_en_0p18_0p8;
  //
  std::vector<double>  my_eleSigmaIetaIphi_en0p15;
  std::vector<double>  my_eleSigmaIetaIphi_en0p2;
  std::vector<double>  my_eleSigmaIetaIphi_en0p5;
  std::vector<double>  my_eleSigmaIetaIphi_en1;
  std::vector<double>  my_eleSigmaIetaIphi_en0p15_noRelNoiseCut;
  std::vector<double>  my_eleSigmaIetaIphi_en0p2_noRelNoiseCut;
  std::vector<double>  my_eleSigmaIetaIphi_en0p5_noRelNoiseCut;
  std::vector<double>  my_eleSigmaIetaIphi_en1_noRelNoiseCut;
  std::vector<double>  my_eleSigmaIetaIphi_en_0p1_0p4;
  std::vector<double>  my_eleSigmaIetaIphi_en_0p15_0p5;
  std::vector<double>  my_eleSigmaIetaIphi_en_0p16_0p6;
  std::vector<double>  my_eleSigmaIetaIphi_en_0p2_1;
  std::vector<double>  my_eleSigmaIetaIphi_en_0p2_1p5;
  std::vector<double>  my_eleSigmaIetaIphi_en_0p2_2;
  std::vector<double>  my_eleSigmaIetaIphi_en_0p18_0p8;

  std::vector<int>  ele_genmatched;
  std::vector<int>    gen_status;
  std::vector<int>    gen_pdgid;
  //  std::vector<int>    gen_isPromptFinalState;
  //  std::vector<int>    gen_isLastCopy;
  //  std::vector<int>    gen_isHardProcess;
  std::vector<float>  gen_pt;

private:
  virtual void beginJob() override;
  //  virtual void analyze(const edm::Event&, const edm::EventSetup&, const reco::PFRecHit&) ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;
  
  // ----------member data ---------------------------
  edm::EDGetTokenT<TrackCollection> tracksToken_;  //used to select what tracks to read from configuration file
  edm::EDGetTokenT<edm::View<reco::GsfElectron> > eleToken_;
  edm::EDGetTokenT<EcalRecHitCollection> EBRecHitCollectionT_;
  edm::EDGetTokenT<EcalRecHitCollection> EERecHitCollectionT_;
  edm::ESHandle<CaloTopology> theCaloTopology;
  edm::ESHandle<CaloGeometry> theCaloGeometry;
  edm::EDGetTokenT<std::vector<PileupSummaryInfo> >     puCollection_;
  edm::EDGetTokenT<std::vector<reco::GenParticle> >     genParticlesCollection_;
  //  edm::EDGetTokenT<reco::PFRecHitCollection> PFRecHitCollectionT_ ;


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
  tracksToken_(consumes<TrackCollection>(iConfig.getUntrackedParameter<edm::InputTag>("tracks"))),
  eleToken_(consumes<edm::View<reco::GsfElectron> >(iConfig.getParameter<edm::InputTag>("electrons"))),
  EBRecHitCollectionT_(consumes<EcalRecHitCollection>(iConfig.getParameter<edm::InputTag>("EBRecHitCollection"))),
  EERecHitCollectionT_(consumes<EcalRecHitCollection>(iConfig.getParameter<edm::InputTag>("EERecHitCollection"))),
  puCollection_(consumes<std::vector<PileupSummaryInfo> >(iConfig.getParameter<edm::InputTag>("pileupCollection"))),
  genParticlesCollection_(consumes<std::vector<reco::GenParticle> >(iConfig.getParameter<edm::InputTag>("genParticleSrc")))
//  PFRecHitCollectionT_(consumes<reco::PFRecHitCollection>(iConfig.getParameter<edm::InputTag>("pfrechits")))

{
  //now do what ever initialization is needed
  tree->Branch("crysEta_",&crysEta);
  tree->Branch("crysPhi_",&crysPhi);
  tree->Branch("crysThr_",&crysThr);

  tree->Branch("ele_genmatched_",&ele_genmatched);
  tree->Branch("trkCharge_",&trkCharge);
  tree->Branch("cmssw_eleSigmaIetaIeta_",&cmssw_eleSigmaIetaIeta);
  tree->Branch("cmssw_eleSigmaIphiIphi_",&cmssw_eleSigmaIphiIphi);
  //  tree->Branch("cmssw_eleSigmaIetaIphi_",&cmssw_eleSigmaIetaIphi);
  tree->Branch("cmssw_eleR9_",&cmssw_eleR9);
  tree->Branch("cmssw_eleHoE_",&cmssw_eleHoE);
  tree->Branch("eleScEta_",&eleScEta);
  tree->Branch("eleScEn_",&eleScEn);
  tree->Branch("elePt_",&elePt);
  tree->Branch("ptRecoEle_by_ptGenEle_",&ptRecoEle_by_ptGenEle);
  tree->Branch("dR_recoEle_genEle_",&dR_recoEle_genEle);
  tree->Branch("puTrue_", &puTrue);
  tree->Branch("my_eleSigmaIetaIeta_",&my_eleSigmaIetaIeta);
  tree->Branch("my_eleSigmaIphiIphi_",&my_eleSigmaIphiIphi);
  tree->Branch("my_eleSigmaIetaIphi_",&my_eleSigmaIetaIphi);
  //
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_",&my_eleSigmaIetaIeta_per_rechit);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p05_",&my_eleSigmaIetaIeta_per_rechit_m1p05);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p1_",&my_eleSigmaIetaIeta_per_rechit_m1p1);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p15_",&my_eleSigmaIetaIeta_per_rechit_m1p15);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p2_",&my_eleSigmaIetaIeta_per_rechit_m1p2);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p25_",&my_eleSigmaIetaIeta_per_rechit_m1p25);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p3_",&my_eleSigmaIetaIeta_per_rechit_m1p3);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p4_",&my_eleSigmaIetaIeta_per_rechit_m1p4);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p5_",&my_eleSigmaIetaIeta_per_rechit_m1p5);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p6_",&my_eleSigmaIetaIeta_per_rechit_m1p6);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p7_",&my_eleSigmaIetaIeta_per_rechit_m1p7);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p8_",&my_eleSigmaIetaIeta_per_rechit_m1p8);
  tree->Branch("my_eleSigmaIetaIeta_per_rechit_m1p9_",&my_eleSigmaIetaIeta_per_rechit_m1p9);
  //
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_",&my_eleSigmaIetaIphi_per_rechit);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p05_",&my_eleSigmaIetaIphi_per_rechit_m1p05);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p1_",&my_eleSigmaIetaIphi_per_rechit_m1p1);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p15_",&my_eleSigmaIetaIphi_per_rechit_m1p15);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p2_",&my_eleSigmaIetaIphi_per_rechit_m1p2);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p25_",&my_eleSigmaIetaIphi_per_rechit_m1p25);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p3_",&my_eleSigmaIetaIphi_per_rechit_m1p3);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p4_",&my_eleSigmaIetaIphi_per_rechit_m1p4);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p5_",&my_eleSigmaIetaIphi_per_rechit_m1p5);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p6_",&my_eleSigmaIetaIphi_per_rechit_m1p6);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p7_",&my_eleSigmaIetaIphi_per_rechit_m1p7);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p8_",&my_eleSigmaIetaIphi_per_rechit_m1p8);
  tree->Branch("my_eleSigmaIetaIphi_per_rechit_m1p9_",&my_eleSigmaIetaIphi_per_rechit_m1p9);
  //
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_",&my_eleSigmaIphiIphi_per_rechit);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p05_",&my_eleSigmaIphiIphi_per_rechit_m1p05);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p1_",&my_eleSigmaIphiIphi_per_rechit_m1p1);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p15_",&my_eleSigmaIphiIphi_per_rechit_m1p15);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p2_",&my_eleSigmaIphiIphi_per_rechit_m1p2);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p25_",&my_eleSigmaIphiIphi_per_rechit_m1p25);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p3_",&my_eleSigmaIphiIphi_per_rechit_m1p3);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p4_",&my_eleSigmaIphiIphi_per_rechit_m1p4);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p5_",&my_eleSigmaIphiIphi_per_rechit_m1p5);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p6_",&my_eleSigmaIphiIphi_per_rechit_m1p6);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p7_",&my_eleSigmaIphiIphi_per_rechit_m1p7);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p8_",&my_eleSigmaIphiIphi_per_rechit_m1p8);
  tree->Branch("my_eleSigmaIphiIphi_per_rechit_m1p9_",&my_eleSigmaIphiIphi_per_rechit_m1p9);
  //
  tree->Branch("my_eleSigmaIetaIeta_w4p6_",&my_eleSigmaIetaIeta_w4p6);
  tree->Branch("my_eleSigmaIetaIeta_w4p5_",&my_eleSigmaIetaIeta_w4p5);
  tree->Branch("my_eleSigmaIetaIeta_w4p4_",&my_eleSigmaIetaIeta_w4p4);
  tree->Branch("my_eleSigmaIetaIeta_w4p3_",&my_eleSigmaIetaIeta_w4p3);
  tree->Branch("my_eleSigmaIetaIeta_w4p2_",&my_eleSigmaIetaIeta_w4p2);
  tree->Branch("my_eleSigmaIetaIeta_w4p1_",&my_eleSigmaIetaIeta_w4p1);
  tree->Branch("my_eleSigmaIetaIeta_w4p0_",&my_eleSigmaIetaIeta_w4p0);
  tree->Branch("my_eleSigmaIetaIeta_w3p8_",&my_eleSigmaIetaIeta_w3p8);
  tree->Branch("my_eleSigmaIetaIeta_w3p7_",&my_eleSigmaIetaIeta_w3p7);
  tree->Branch("my_eleSigmaIetaIeta_w3p6_",&my_eleSigmaIetaIeta_w3p6);
  tree->Branch("my_eleSigmaIetaIeta_w3p5_",&my_eleSigmaIetaIeta_w3p5);
  tree->Branch("my_eleSigmaIetaIeta_w3p4_",&my_eleSigmaIetaIeta_w3p4);
  tree->Branch("my_eleSigmaIetaIeta_w3p3_",&my_eleSigmaIetaIeta_w3p3);
  tree->Branch("my_eleSigmaIetaIeta_w3p2_",&my_eleSigmaIetaIeta_w3p2);
  tree->Branch("my_eleSigmaIetaIeta_w3p0_",&my_eleSigmaIetaIeta_w3p0);
  //
  tree->Branch("my_eleSigmaIetaIphi_w4p6_",&my_eleSigmaIetaIphi_w4p6);
  tree->Branch("my_eleSigmaIetaIphi_w4p5_",&my_eleSigmaIetaIphi_w4p5);
  tree->Branch("my_eleSigmaIetaIphi_w4p4_",&my_eleSigmaIetaIphi_w4p4);
  tree->Branch("my_eleSigmaIetaIphi_w4p3_",&my_eleSigmaIetaIphi_w4p3);
  tree->Branch("my_eleSigmaIetaIphi_w4p2_",&my_eleSigmaIetaIphi_w4p2);
  tree->Branch("my_eleSigmaIetaIphi_w4p1_",&my_eleSigmaIetaIphi_w4p1);
  tree->Branch("my_eleSigmaIetaIphi_w4p0_",&my_eleSigmaIetaIphi_w4p0);
  tree->Branch("my_eleSigmaIetaIphi_w3p8_",&my_eleSigmaIetaIphi_w3p8);
  tree->Branch("my_eleSigmaIetaIphi_w3p7_",&my_eleSigmaIetaIphi_w3p7);
  tree->Branch("my_eleSigmaIetaIphi_w3p6_",&my_eleSigmaIetaIphi_w3p6);
  tree->Branch("my_eleSigmaIetaIphi_w3p5_",&my_eleSigmaIetaIphi_w3p5);
  tree->Branch("my_eleSigmaIetaIphi_w3p4_",&my_eleSigmaIetaIphi_w3p4);
  tree->Branch("my_eleSigmaIetaIphi_w3p3_",&my_eleSigmaIetaIphi_w3p3);
  tree->Branch("my_eleSigmaIetaIphi_w3p2_",&my_eleSigmaIetaIphi_w3p2);
  tree->Branch("my_eleSigmaIetaIphi_w3p0_",&my_eleSigmaIetaIphi_w3p0);
  //
  tree->Branch("my_eleSigmaIphiIphi_w4p6_",&my_eleSigmaIphiIphi_w4p6);
  tree->Branch("my_eleSigmaIphiIphi_w4p5_",&my_eleSigmaIphiIphi_w4p5);
  tree->Branch("my_eleSigmaIphiIphi_w4p4_",&my_eleSigmaIphiIphi_w4p4);
  tree->Branch("my_eleSigmaIphiIphi_w4p3_",&my_eleSigmaIphiIphi_w4p3);
  tree->Branch("my_eleSigmaIphiIphi_w4p2_",&my_eleSigmaIphiIphi_w4p2);
  tree->Branch("my_eleSigmaIphiIphi_w4p1_",&my_eleSigmaIphiIphi_w4p1);
  tree->Branch("my_eleSigmaIphiIphi_w4p0_",&my_eleSigmaIphiIphi_w4p0);
  tree->Branch("my_eleSigmaIphiIphi_w3p8_",&my_eleSigmaIphiIphi_w3p8);
  tree->Branch("my_eleSigmaIphiIphi_w3p7_",&my_eleSigmaIphiIphi_w3p7);
  tree->Branch("my_eleSigmaIphiIphi_w3p6_",&my_eleSigmaIphiIphi_w3p6);
  tree->Branch("my_eleSigmaIphiIphi_w3p5_",&my_eleSigmaIphiIphi_w3p5);
  tree->Branch("my_eleSigmaIphiIphi_w3p4_",&my_eleSigmaIphiIphi_w3p4);
  tree->Branch("my_eleSigmaIphiIphi_w3p3_",&my_eleSigmaIphiIphi_w3p3);
  tree->Branch("my_eleSigmaIphiIphi_w3p2_",&my_eleSigmaIphiIphi_w3p2);
  tree->Branch("my_eleSigmaIphiIphi_w3p0_",&my_eleSigmaIphiIphi_w3p0);
  //
  tree->Branch("my_eleSigmaIetaIeta_en0p2_",&my_eleSigmaIetaIeta_en0p2);
  tree->Branch("my_eleSigmaIetaIeta_en0p15_",&my_eleSigmaIetaIeta_en0p15);
  tree->Branch("my_eleSigmaIetaIeta_en0p5_",&my_eleSigmaIetaIeta_en0p5);
  tree->Branch("my_eleSigmaIetaIeta_en1_",&my_eleSigmaIetaIeta_en1);
  tree->Branch("my_eleSigmaIetaIeta_en0p2_noRelNoiseCut_",&my_eleSigmaIetaIeta_en0p2_noRelNoiseCut);
  tree->Branch("my_eleSigmaIetaIeta_en0p15_noRelNoiseCut_",&my_eleSigmaIetaIeta_en0p15_noRelNoiseCut);
  tree->Branch("my_eleSigmaIetaIeta_en0p5_noRelNoiseCut_",&my_eleSigmaIetaIeta_en0p5_noRelNoiseCut);
  tree->Branch("my_eleSigmaIetaIeta_en1_noRelNoiseCut_",&my_eleSigmaIetaIeta_en1_noRelNoiseCut);
  tree->Branch("my_eleSigmaIetaIeta_en_0p1_0p4_",&my_eleSigmaIetaIeta_en_0p1_0p4);
  tree->Branch("my_eleSigmaIetaIeta_en_0p15_0p5_",&my_eleSigmaIetaIeta_en_0p15_0p5);
  tree->Branch("my_eleSigmaIetaIeta_en_0p16_0p6_",&my_eleSigmaIetaIeta_en_0p16_0p6);
  tree->Branch("my_eleSigmaIetaIeta_en_0p2_1_",&my_eleSigmaIetaIeta_en_0p2_1);
  tree->Branch("my_eleSigmaIetaIeta_en_0p2_1p5_",&my_eleSigmaIetaIeta_en_0p2_1p5);
  tree->Branch("my_eleSigmaIetaIeta_en_0p2_2_",&my_eleSigmaIetaIeta_en_0p2_2);
  tree->Branch("my_eleSigmaIetaIeta_en_0p18_0p8_",&my_eleSigmaIetaIeta_en_0p18_0p8);
  //
  tree->Branch("my_eleSigmaIetaIphi_en0p2_",&my_eleSigmaIetaIphi_en0p2);
  tree->Branch("my_eleSigmaIetaIphi_en0p15_",&my_eleSigmaIetaIphi_en0p15);
  tree->Branch("my_eleSigmaIetaIphi_en0p5_",&my_eleSigmaIetaIphi_en0p5);
  tree->Branch("my_eleSigmaIetaIphi_en1_",&my_eleSigmaIetaIphi_en1);
  tree->Branch("my_eleSigmaIetaIphi_en0p2_noRelNoiseCut_",&my_eleSigmaIetaIphi_en0p2_noRelNoiseCut);
  tree->Branch("my_eleSigmaIetaIphi_en0p15_noRelNoiseCut_",&my_eleSigmaIetaIphi_en0p15_noRelNoiseCut);
  tree->Branch("my_eleSigmaIetaIphi_en0p5_noRelNoiseCut_",&my_eleSigmaIetaIphi_en0p5_noRelNoiseCut);
  tree->Branch("my_eleSigmaIetaIphi_en1_noRelNoiseCut_",&my_eleSigmaIetaIphi_en1_noRelNoiseCut);
  tree->Branch("my_eleSigmaIetaIphi_en_0p1_0p4_",&my_eleSigmaIetaIphi_en_0p1_0p4);
  tree->Branch("my_eleSigmaIetaIphi_en_0p15_0p5_",&my_eleSigmaIetaIphi_en_0p15_0p5);
  tree->Branch("my_eleSigmaIetaIphi_en_0p16_0p6_",&my_eleSigmaIetaIphi_en_0p16_0p6);
  tree->Branch("my_eleSigmaIetaIphi_en_0p2_1_",&my_eleSigmaIetaIphi_en_0p2_1);
  tree->Branch("my_eleSigmaIetaIphi_en_0p2_1p5_",&my_eleSigmaIetaIphi_en_0p2_1p5);
  tree->Branch("my_eleSigmaIetaIphi_en_0p2_2_",&my_eleSigmaIetaIphi_en_0p2_2);
  tree->Branch("my_eleSigmaIetaIphi_en_0p18_0p8_",&my_eleSigmaIetaIphi_en_0p18_0p8);

  
  tree->Branch("gen_status_",&gen_status);
  tree->Branch("gen_pdgid_",&gen_pdgid);
  //  tree->Branch("gen_isPromptFinalState_",&gen_isPromptFinalState);
  // tree->Branch("gen_isLastCopy_",&gen_isLastCopy);
  // tree->Branch("gen_isHardProcess_",&gen_isHardProcess);
  tree->Branch("gen_pt_",&gen_pt);


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

  crysEta.clear();
  crysPhi.clear();
  crysThr.clear();
  
  trkCharge.clear();
  ele_genmatched.clear();
  cmssw_eleSigmaIetaIeta.clear();
  cmssw_eleSigmaIphiIphi.clear();
  //  cmssw_eleSigmaIetaIphi.clear();
  cmssw_eleR9.clear();
  cmssw_eleHoE.clear();
  eleScEta.clear();
  eleScEn.clear();
  elePt.clear();
  ptRecoEle_by_ptGenEle.clear();
  dR_recoEle_genEle.clear();
  my_eleSigmaIetaIeta.clear();
  my_eleSigmaIetaIphi.clear();
  my_eleSigmaIphiIphi.clear();
  //
  my_eleSigmaIetaIeta_per_rechit.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p05.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p1.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p15.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p2.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p25.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p3.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p4.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p5.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p6.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p7.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p8.clear();
  my_eleSigmaIetaIeta_per_rechit_m1p9.clear();
  //
  my_eleSigmaIetaIphi_per_rechit.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p05.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p1.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p15.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p2.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p25.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p3.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p4.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p5.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p6.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p7.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p8.clear();
  my_eleSigmaIetaIphi_per_rechit_m1p9.clear();
  //
  my_eleSigmaIphiIphi_per_rechit.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p05.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p1.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p15.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p2.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p25.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p3.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p4.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p5.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p6.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p7.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p8.clear();
  my_eleSigmaIphiIphi_per_rechit_m1p9.clear();
  //
  my_eleSigmaIetaIeta_w4p6.clear();
  my_eleSigmaIetaIeta_w4p5.clear();
  my_eleSigmaIetaIeta_w4p4.clear();
  my_eleSigmaIetaIeta_w4p3.clear();
  my_eleSigmaIetaIeta_w4p2.clear();
  my_eleSigmaIetaIeta_w4p1.clear();
  my_eleSigmaIetaIeta_w4p0.clear();
  my_eleSigmaIetaIeta_w3p8.clear();
  my_eleSigmaIetaIeta_w3p7.clear();
  my_eleSigmaIetaIeta_w3p6.clear();
  my_eleSigmaIetaIeta_w3p5.clear();
  my_eleSigmaIetaIeta_w3p4.clear();
  my_eleSigmaIetaIeta_w3p3.clear();
  my_eleSigmaIetaIeta_w3p2.clear();
  my_eleSigmaIetaIeta_w3p0.clear();
  //
  my_eleSigmaIetaIphi_w4p6.clear();
  my_eleSigmaIetaIphi_w4p5.clear();
  my_eleSigmaIetaIphi_w4p4.clear();
  my_eleSigmaIetaIphi_w4p3.clear();
  my_eleSigmaIetaIphi_w4p2.clear();
  my_eleSigmaIetaIphi_w4p1.clear();
  my_eleSigmaIetaIphi_w4p0.clear();
  my_eleSigmaIetaIphi_w3p8.clear();
  my_eleSigmaIetaIphi_w3p7.clear();
  my_eleSigmaIetaIphi_w3p6.clear();
  my_eleSigmaIetaIphi_w3p5.clear();
  my_eleSigmaIetaIphi_w3p4.clear();
  my_eleSigmaIetaIphi_w3p3.clear();
  my_eleSigmaIetaIphi_w3p2.clear();
  my_eleSigmaIetaIphi_w3p0.clear();
  //
  my_eleSigmaIphiIphi_w4p6.clear();
  my_eleSigmaIphiIphi_w4p5.clear();
  my_eleSigmaIphiIphi_w4p4.clear();
  my_eleSigmaIphiIphi_w4p3.clear();
  my_eleSigmaIphiIphi_w4p2.clear();
  my_eleSigmaIphiIphi_w4p1.clear();
  my_eleSigmaIphiIphi_w4p0.clear();
  my_eleSigmaIphiIphi_w3p8.clear();
  my_eleSigmaIphiIphi_w3p7.clear();
  my_eleSigmaIphiIphi_w3p6.clear();
  my_eleSigmaIphiIphi_w3p5.clear();
  my_eleSigmaIphiIphi_w3p4.clear();
  my_eleSigmaIphiIphi_w3p3.clear();
  my_eleSigmaIphiIphi_w3p2.clear();
  my_eleSigmaIphiIphi_w3p0.clear();
  //
  my_eleSigmaIetaIeta_en0p2.clear();
  my_eleSigmaIetaIeta_en0p15.clear();
  my_eleSigmaIetaIeta_en0p5.clear();
  my_eleSigmaIetaIeta_en1.clear();
  my_eleSigmaIetaIeta_en0p2_noRelNoiseCut.clear();
  my_eleSigmaIetaIeta_en0p15_noRelNoiseCut.clear();
  my_eleSigmaIetaIeta_en0p5_noRelNoiseCut.clear();
  my_eleSigmaIetaIeta_en1_noRelNoiseCut.clear();
  my_eleSigmaIetaIeta_en_0p1_0p4.clear();
  my_eleSigmaIetaIeta_en_0p15_0p5.clear();
  my_eleSigmaIetaIeta_en_0p16_0p6.clear();
  my_eleSigmaIetaIeta_en_0p2_1.clear();
  my_eleSigmaIetaIeta_en_0p2_1p5.clear();
  my_eleSigmaIetaIeta_en_0p2_2.clear();
  my_eleSigmaIetaIeta_en_0p18_0p8.clear();
  //
  my_eleSigmaIetaIphi_en0p2.clear();
  my_eleSigmaIetaIphi_en0p15.clear();
  my_eleSigmaIetaIphi_en0p5.clear();
  my_eleSigmaIetaIphi_en1.clear();
  my_eleSigmaIetaIphi_en0p2_noRelNoiseCut.clear();
  my_eleSigmaIetaIphi_en0p15_noRelNoiseCut.clear();
  my_eleSigmaIetaIphi_en0p5_noRelNoiseCut.clear();
  my_eleSigmaIetaIphi_en1_noRelNoiseCut.clear();
  my_eleSigmaIetaIphi_en_0p1_0p4.clear();
  my_eleSigmaIetaIphi_en_0p15_0p5.clear();
  my_eleSigmaIetaIphi_en_0p16_0p6.clear();
  my_eleSigmaIetaIphi_en_0p2_1.clear();
  my_eleSigmaIetaIphi_en_0p2_1p5.clear();
  my_eleSigmaIetaIphi_en_0p2_2.clear();
  my_eleSigmaIetaIphi_en_0p18_0p8.clear();

  //
  puTrue.clear();
  gen_status.clear();
  gen_pdgid.clear();
  // gen_isPromptFinalState.clear();
  // gen_isLastCopy.clear();
  // gen_isHardProcess.clear();
  gen_pt.clear();

  ////
 
  edm::Handle<std::vector<PileupSummaryInfo> > genPileupHandle;
  iEvent.getByToken(puCollection_, genPileupHandle);
  
  if (genPileupHandle.isValid()) {
    for (std::vector<PileupSummaryInfo>::const_iterator pu = genPileupHandle->begin(); pu != genPileupHandle->end(); ++pu) {
      puTrue.push_back(pu->getTrueNumInteractions());
    }
  }
  ////

  //  edm::Handle<GenParticleCollection> genParticlesHandle;
  //iEvent.getByLabel("genParticles", genParticles);

  edm::Handle<std::vector<reco::GenParticle> > genParticlesHandle;
  iEvent.getByToken(genParticlesCollection_, genParticlesHandle);

  if (genParticlesHandle.isValid()) {
    for (std::vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {
      const reco::Candidate *p = (const reco::Candidate*)&(*ip);
      gen_status.push_back(p->status());
      gen_pdgid.push_back(p->pdgId());
      gen_pt.push_back(p->pt());
    }  
  }

  for(const auto& track : iEvent.get(tracksToken_) ) {
    trkCharge.push_back(track.charge());
  }
  

  //  edm::Handle<reco::PFRecHitCollection> hits;                                                                                                                     
  // iEvent.getByToken(PFRecHitCollectionT_, hits);  
  //  for ( reco::PFRecHitCollection::const_iterator rh = hits->begin(); rh != hits->end(); ++rh) {
  // std::cout << " pf rechit det id " <<  rh.DetId() << std::endl;
  // }

  //  for(const auto& rh : iEvent.get(PFRecHitCollectionT_) ) {

  //    std::cout << " pf rechit det id " <<  rh.detId() << std::endl;
  //  edm::ESHandle<EcalPFRecHitThresholds> ths;            
  //  iSetup.get<EcalPFRecHitThresholdsRcd>().get(ths);                                                                                                                
  //  float pf_rechit_threshold = (*ths)[rh.detId()];
  //  std::cout << "pf_rechit_threshold = " << pf_rechit_threshold << std::endl;
  // }
  
  for(const auto& ele : iEvent.get(eleToken_) ) {
    // std::cout << "\n ---/// New Electron .... " << std::endl;
    int genmatched=0;
        
    if (genParticlesHandle.isValid()) {
      for (std::vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {
	const reco::Candidate *p = (const reco::Candidate*)&(*ip);
	//      if ( (p->status()==1) && abs(p->pdgId() == 11) ) std::cout << "dR = " << reco::deltaR(ele,*p) << " ele pt = " << ele.pt() << " gen pt = " << p->pt() <<std::endl;
	if ( (p->status()==1) && abs(p->pdgId() == 11) ) {
	  dR_recoEle_genEle.push_back(reco::deltaR(ele,*p));
	  ptRecoEle_by_ptGenEle.push_back( (ele.pt()/p->pt()) );
	  if ( ((reco::deltaR(ele,*p))<0.04) && ((ele.pt()/p->pt())>0.7) &&   ((ele.pt()/p->pt())<1.3) ) genmatched=1;
	}  
      }
    }
    ele_genmatched.push_back(genmatched);
    // std::cout << "cmssw sieie " << ele.full5x5_sigmaIetaIeta() << std::endl;
    cmssw_eleSigmaIetaIeta.push_back(ele.full5x5_sigmaIetaIeta());
    cmssw_eleSigmaIphiIphi.push_back(ele.full5x5_sigmaIphiIphi());
    // cmssw_eleSigmaIetaIphi.push_back(ele.full5x5_sigmaIetaIphi());
    cmssw_eleR9.push_back(ele.full5x5_r9());
    cmssw_eleHoE.push_back(ele.hcalOverEcal());
    eleScEta.push_back(ele.superCluster()->eta());
    eleScEn.push_back(ele.superCluster()->energy());
    elePt.push_back(ele.pt());

    //    const reco::PFRecHit hit;
    //    edm::Handle<reco::PFRecHit> hit;
    // iEvent.getByToken(PFRecHitCollectionT_, hit);
    // edm::ESHandle<EcalPFRecHitThresholds> ths;
    // iSetup.get<EcalPFRecHitThresholdsRcd>().get(ths);
    //   float pf_rechit_threshold = (*ths)[hit.detId()];
    // std::cout << "pf_rechit_threshold = " << (*ths) << std::endl;

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

    //    std::cout << "will do iSetup.get<CaloGeometryRecord>().get(theCaloGeometry) \n";
    iSetup.get<CaloGeometryRecord>().get(theCaloGeometry);
    // std::cout << "ok have theCaloGeometry now--> get the product now \n" ;
    const CaloGeometry* caloGeometry;
    if (theCaloGeometry)  caloGeometry = theCaloGeometry.product();
    // std::cout << "have (product ) caloGeometry now \n " ; 

    //noZS::EcalClusterTools
    //    using ClusterTools = EcalClusterToolsT<true>;     
    using ClusterTools = noZS::EcalClusterTools;     
    std::vector<float> mylocalCovariances = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0,0 ) ;
    std::vector<float> mylocalCovariances_w4p6 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.6,0,0 ) ;
    std::vector<float> mylocalCovariances_w4p5 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.5,0,0 ) ;
    std::vector<float> mylocalCovariances_w4p4 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.4,0,0 ) ;
    std::vector<float> mylocalCovariances_w4p3 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.3,0,0 ) ;
    std::vector<float> mylocalCovariances_w4p2 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.2,0,0 ) ;
    std::vector<float> mylocalCovariances_w4p1 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.1,0,0 ) ;
    std::vector<float> mylocalCovariances_w4p0 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.0,0,0 ) ;
    std::vector<float> mylocalCovariances_w3p8 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,3.8,0,0 ) ;
    std::vector<float> mylocalCovariances_w3p7 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,3.7,0,0 ) ;
    std::vector<float> mylocalCovariances_w3p6 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,3.6,0,0 ) ;
    std::vector<float> mylocalCovariances_w3p5 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,3.5,0,0 ) ;
    std::vector<float> mylocalCovariances_w3p4 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,3.4,0,0 ) ;
    std::vector<float> mylocalCovariances_w3p3 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,3.3,0,0 ) ;
    std::vector<float> mylocalCovariances_w3p2 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,3.2,0,0 ) ;
    std::vector<float> mylocalCovariances_w3p0 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,3.0,0,0 ) ;
    std::vector<float> mylocalCovariances_en0p2 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.2,0.2 ) ;
    std::vector<float> mylocalCovariances_en0p15 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.15,0.15 ) ;
    std::vector<float> mylocalCovariances_en0p5 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.5,0.5 ) ;
    std::vector<float> mylocalCovariances_en1 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,1.0,1.0 ) ;
    std::vector<float> mylocalCovariances_en0p2_noRelNoiseCut = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,100,0.2,0.2 ) ;
    std::vector<float> mylocalCovariances_en0p15_noRelNoiseCut = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,100,0.15,0.15 ) ;
    std::vector<float> mylocalCovariances_en0p5_noRelNoiseCut = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,100,0.5,0.5 ) ;
    std::vector<float> mylocalCovariances_en1_noRelNoiseCut = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,100,1.0,1.0 ) ;
    std::vector<float> mylocalCovariances_en_0p1_0p4 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.1,0.4 ) ;
    std::vector<float> mylocalCovariances_en_0p15_0p5 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.15,0.5 ) ;
    std::vector<float> mylocalCovariances_en_0p16_0p6 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.16,0.6 ) ;
    std::vector<float> mylocalCovariances_en_0p2_1 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.2,1.0 ) ;
    std::vector<float> mylocalCovariances_en_0p2_1p5 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.2,1.5 ) ;
    std::vector<float> mylocalCovariances_en_0p2_2 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.2,2 ) ;
    std::vector<float> mylocalCovariances_en_0p18_0p8 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.18,0.8 ) ;
    //
    std::vector<float> mylocalCovariances_per_rechit ;
    std::vector<float> mylocalCovariances_per_rechit_m1p05 ;
    std::vector<float> mylocalCovariances_per_rechit_m1p1 ;
    std::vector<float> mylocalCovariances_per_rechit_m1p15 ;
    std::vector<float> mylocalCovariances_per_rechit_m1p2 ;
    std::vector<float> mylocalCovariances_per_rechit_m1p25 ;
    std::vector<float> mylocalCovariances_per_rechit_m1p3 ;
    std::vector<float> mylocalCovariances_per_rechit_m1p4 ;
    std::vector<float> mylocalCovariances_per_rechit_m1p5 ;
    std::vector<float> mylocalCovariances_per_rechit_m1p6 ;
    std::vector<float> mylocalCovariances_per_rechit_m1p7 ;
    std::vector<float> mylocalCovariances_per_rechit_m1p8 ;
    std::vector<float> mylocalCovariances_per_rechit_m1p9 ;
    std::vector<float> mylocalCovariances_per_rechit_thresholds ;
    std::vector<float> mylocalCovariances_per_rechit_crys_eta ;
    std::vector<float> mylocalCovariances_per_rechit_crys_phi ;
    //
    
    if (theCaloGeometry) {
      // std::cout << "now access ClusterTools::localCovariancesnew to get mylocalCovariances cov, thr, cryseta, crysphi " << std::endl;
 
      mylocalCovariances_per_rechit = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1).cov;
      mylocalCovariances_per_rechit_m1p05 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.05).cov;
      mylocalCovariances_per_rechit_m1p1 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.1).cov;
      mylocalCovariances_per_rechit_m1p15 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.15).cov;
      mylocalCovariances_per_rechit_m1p2 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.2).cov;
      mylocalCovariances_per_rechit_m1p25 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry,  &iSetup, 4.7, 1.25).cov;
      mylocalCovariances_per_rechit_m1p3 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.3).cov;
      mylocalCovariances_per_rechit_m1p4 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.4).cov;
      mylocalCovariances_per_rechit_m1p5 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.5).cov;
      mylocalCovariances_per_rechit_m1p6 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.6).cov;
      mylocalCovariances_per_rechit_m1p7 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.7).cov;
      mylocalCovariances_per_rechit_m1p8 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.8).cov;
      mylocalCovariances_per_rechit_m1p9 = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1.9).cov;
      mylocalCovariances_per_rechit_thresholds = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry,  &iSetup, 4.7, 1).thr;
      mylocalCovariances_per_rechit_crys_eta = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry, &iSetup, 4.7, 1).cryseta;
      mylocalCovariances_per_rechit_crys_phi = ClusterTools::localCovariancesnew(seedCluster, recHits, caloTopology, caloGeometry,  &iSetup, 4.7, 1).crysphi;
      
      //      std::cout << "mylocalCovariances_per_rechit_thresholds.size() = " << mylocalCovariances_per_rechit_thresholds.size() << std::endl;
      
      for (unsigned int i=0; i<mylocalCovariances_per_rechit_thresholds.size(); i++) {
	//std::cout << "eta / phi / thresholds = " << mylocalCovariances_per_rechit_crys_eta.at(i) << " / " << mylocalCovariances_per_rechit_crys_phi.at(i) << " / " <<   mylocalCovariances_per_rechit_thresholds.at(i) << std::endl;
	crysEta.push_back(mylocalCovariances_per_rechit_crys_eta.at(i));
	crysPhi.push_back(mylocalCovariances_per_rechit_crys_phi.at(i));
	crysThr.push_back(mylocalCovariances_per_rechit_thresholds.at(i));
      }
      //      std::cout << "filled branches crysEta, crysPhi, crysThr " << std::endl;
    }

    float sigmaIetaIeta = sqrt(mylocalCovariances[0]);
    my_eleSigmaIetaIeta.push_back(sigmaIetaIeta);
    float sigmaIetaIphi = sqrt(mylocalCovariances[1]);
    my_eleSigmaIetaIphi.push_back(sigmaIetaIphi);
    float sigmaIphiIphi = sqrt(mylocalCovariances[2]);
    my_eleSigmaIphiIphi.push_back(sigmaIphiIphi);
    //
    float sigmaIetaIeta_w4p6 = sqrt(mylocalCovariances_w4p6[0]);
    my_eleSigmaIetaIeta_w4p6.push_back(sigmaIetaIeta_w4p6);
    float sigmaIetaIeta_w4p5 = sqrt(mylocalCovariances_w4p5[0]);
    my_eleSigmaIetaIeta_w4p5.push_back(sigmaIetaIeta_w4p5);
    float sigmaIetaIeta_w4p4 = sqrt(mylocalCovariances_w4p4[0]);
    my_eleSigmaIetaIeta_w4p4.push_back(sigmaIetaIeta_w4p4);
    float sigmaIetaIeta_w4p3 = sqrt(mylocalCovariances_w4p3[0]);
    my_eleSigmaIetaIeta_w4p3.push_back(sigmaIetaIeta_w4p3);
    float sigmaIetaIeta_w4p2 = sqrt(mylocalCovariances_w4p2[0]);
    my_eleSigmaIetaIeta_w4p2.push_back(sigmaIetaIeta_w4p2);
    float sigmaIetaIeta_w4p1 = sqrt(mylocalCovariances_w4p1[0]);
    my_eleSigmaIetaIeta_w4p1.push_back(sigmaIetaIeta_w4p1);
    float sigmaIetaIeta_w4p0 = sqrt(mylocalCovariances_w4p0[0]);
    my_eleSigmaIetaIeta_w4p0.push_back(sigmaIetaIeta_w4p0);
    float sigmaIetaIeta_w3p8 = sqrt(mylocalCovariances_w3p8[0]);
    my_eleSigmaIetaIeta_w3p8.push_back(sigmaIetaIeta_w3p8);
    float sigmaIetaIeta_w3p7 = sqrt(mylocalCovariances_w3p7[0]);
    my_eleSigmaIetaIeta_w3p7.push_back(sigmaIetaIeta_w3p7);
    float sigmaIetaIeta_w3p6 = sqrt(mylocalCovariances_w3p6[0]);
    my_eleSigmaIetaIeta_w3p6.push_back(sigmaIetaIeta_w3p6);
    float sigmaIetaIeta_w3p5 = sqrt(mylocalCovariances_w3p5[0]);
    my_eleSigmaIetaIeta_w3p5.push_back(sigmaIetaIeta_w3p5);
    float sigmaIetaIeta_w3p4 = sqrt(mylocalCovariances_w3p4[0]);
    my_eleSigmaIetaIeta_w3p4.push_back(sigmaIetaIeta_w3p4);
    float sigmaIetaIeta_w3p3 = sqrt(mylocalCovariances_w3p3[0]);
    my_eleSigmaIetaIeta_w3p3.push_back(sigmaIetaIeta_w3p3);
    float sigmaIetaIeta_w3p2 = sqrt(mylocalCovariances_w3p2[0]);
    my_eleSigmaIetaIeta_w3p2.push_back(sigmaIetaIeta_w3p2);
    float sigmaIetaIeta_w3p0 = sqrt(mylocalCovariances_w3p0[0]);
    my_eleSigmaIetaIeta_w3p0.push_back(sigmaIetaIeta_w3p0);
    //
    //ietaiphi
    float sigmaIetaIphi_w4p6 = sqrt(mylocalCovariances_w4p6[1]);
    my_eleSigmaIetaIphi_w4p6.push_back(sigmaIetaIphi_w4p6);
    float sigmaIetaIphi_w4p5 = sqrt(mylocalCovariances_w4p5[1]);
    my_eleSigmaIetaIphi_w4p5.push_back(sigmaIetaIphi_w4p5);
    float sigmaIetaIphi_w4p4 = sqrt(mylocalCovariances_w4p4[1]);
    my_eleSigmaIetaIphi_w4p4.push_back(sigmaIetaIphi_w4p4);
    float sigmaIetaIphi_w4p3 = sqrt(mylocalCovariances_w4p3[1]);
    my_eleSigmaIetaIphi_w4p3.push_back(sigmaIetaIphi_w4p3);
    float sigmaIetaIphi_w4p2 = sqrt(mylocalCovariances_w4p2[1]);
    my_eleSigmaIetaIphi_w4p2.push_back(sigmaIetaIphi_w4p2);
    float sigmaIetaIphi_w4p1 = sqrt(mylocalCovariances_w4p1[1]);
    my_eleSigmaIetaIphi_w4p1.push_back(sigmaIetaIphi_w4p1);
    float sigmaIetaIphi_w4p0 = sqrt(mylocalCovariances_w4p0[1]);
    my_eleSigmaIetaIphi_w4p0.push_back(sigmaIetaIphi_w4p0);
    float sigmaIetaIphi_w3p8 = sqrt(mylocalCovariances_w3p8[1]);
    my_eleSigmaIetaIphi_w3p8.push_back(sigmaIetaIphi_w3p8);
    float sigmaIetaIphi_w3p7 = sqrt(mylocalCovariances_w3p7[1]);
    my_eleSigmaIetaIphi_w3p7.push_back(sigmaIetaIphi_w3p7);
    float sigmaIetaIphi_w3p6 = sqrt(mylocalCovariances_w3p6[1]);
    my_eleSigmaIetaIphi_w3p6.push_back(sigmaIetaIphi_w3p6);
    float sigmaIetaIphi_w3p5 = sqrt(mylocalCovariances_w3p5[1]);
    my_eleSigmaIetaIphi_w3p5.push_back(sigmaIetaIphi_w3p5);
    float sigmaIetaIphi_w3p4 = sqrt(mylocalCovariances_w3p4[1]);
    my_eleSigmaIetaIphi_w3p4.push_back(sigmaIetaIphi_w3p4);
    float sigmaIetaIphi_w3p3 = sqrt(mylocalCovariances_w3p3[1]);
    my_eleSigmaIetaIphi_w3p3.push_back(sigmaIetaIphi_w3p3);
    float sigmaIetaIphi_w3p2 = sqrt(mylocalCovariances_w3p2[1]);
    my_eleSigmaIetaIphi_w3p2.push_back(sigmaIetaIphi_w3p2);
    float sigmaIetaIphi_w3p0 = sqrt(mylocalCovariances_w3p0[1]);
    my_eleSigmaIetaIphi_w3p0.push_back(sigmaIetaIphi_w3p0);
    //
    float sigmaIphiIphi_w4p6 = sqrt(mylocalCovariances_w4p6[2]);
    my_eleSigmaIphiIphi_w4p6.push_back(sigmaIphiIphi_w4p6);
    float sigmaIphiIphi_w4p5 = sqrt(mylocalCovariances_w4p5[2]);
    my_eleSigmaIphiIphi_w4p5.push_back(sigmaIphiIphi_w4p5);
    float sigmaIphiIphi_w4p4 = sqrt(mylocalCovariances_w4p4[2]);
    my_eleSigmaIphiIphi_w4p4.push_back(sigmaIphiIphi_w4p4);
    float sigmaIphiIphi_w4p3 = sqrt(mylocalCovariances_w4p3[2]);
    my_eleSigmaIphiIphi_w4p3.push_back(sigmaIphiIphi_w4p3);
    float sigmaIphiIphi_w4p2 = sqrt(mylocalCovariances_w4p2[2]);
    my_eleSigmaIphiIphi_w4p2.push_back(sigmaIphiIphi_w4p2);
    float sigmaIphiIphi_w4p1 = sqrt(mylocalCovariances_w4p1[2]);
    my_eleSigmaIphiIphi_w4p1.push_back(sigmaIphiIphi_w4p1);
    float sigmaIphiIphi_w4p0 = sqrt(mylocalCovariances_w4p0[2]);
    my_eleSigmaIphiIphi_w4p0.push_back(sigmaIphiIphi_w4p0);
    float sigmaIphiIphi_w3p8 = sqrt(mylocalCovariances_w3p8[2]);
    my_eleSigmaIphiIphi_w3p8.push_back(sigmaIphiIphi_w3p8);
    float sigmaIphiIphi_w3p7 = sqrt(mylocalCovariances_w3p7[2]);
    my_eleSigmaIphiIphi_w3p7.push_back(sigmaIphiIphi_w3p7);
    float sigmaIphiIphi_w3p6 = sqrt(mylocalCovariances_w3p6[2]);
    my_eleSigmaIphiIphi_w3p6.push_back(sigmaIphiIphi_w3p6);
    float sigmaIphiIphi_w3p5 = sqrt(mylocalCovariances_w3p5[2]);
    my_eleSigmaIphiIphi_w3p5.push_back(sigmaIphiIphi_w3p5);
    float sigmaIphiIphi_w3p4 = sqrt(mylocalCovariances_w3p4[2]);
    my_eleSigmaIphiIphi_w3p4.push_back(sigmaIphiIphi_w3p4);
    float sigmaIphiIphi_w3p3 = sqrt(mylocalCovariances_w3p3[2]);
    my_eleSigmaIphiIphi_w3p3.push_back(sigmaIphiIphi_w3p3);
    float sigmaIphiIphi_w3p2 = sqrt(mylocalCovariances_w3p2[2]);
    my_eleSigmaIphiIphi_w3p2.push_back(sigmaIphiIphi_w3p2);
    float sigmaIphiIphi_w3p0 = sqrt(mylocalCovariances_w3p0[2]);
    my_eleSigmaIphiIphi_w3p0.push_back(sigmaIphiIphi_w3p0);

    //OB
    float sigmaIetaIeta_en0p15 = sqrt(mylocalCovariances_en0p15[0]);
    my_eleSigmaIetaIeta_en0p15.push_back(sigmaIetaIeta_en0p15);
    float sigmaIetaIeta_en0p2 = sqrt(mylocalCovariances_en0p2[0]);
    my_eleSigmaIetaIeta_en0p2.push_back(sigmaIetaIeta_en0p2);
    float sigmaIetaIeta_en0p5 = sqrt(mylocalCovariances_en0p5[0]);
    my_eleSigmaIetaIeta_en0p5.push_back(sigmaIetaIeta_en0p5);
    float sigmaIetaIeta_en1 = sqrt(mylocalCovariances_en1[0]);
    my_eleSigmaIetaIeta_en1.push_back(sigmaIetaIeta_en1);
    float sigmaIetaIeta_en0p15_noRelNoiseCut = sqrt(mylocalCovariances_en0p15_noRelNoiseCut[0]);
    my_eleSigmaIetaIeta_en0p15_noRelNoiseCut.push_back(sigmaIetaIeta_en0p15_noRelNoiseCut);
    float sigmaIetaIeta_en0p2_noRelNoiseCut = sqrt(mylocalCovariances_en0p2_noRelNoiseCut[0]);
    my_eleSigmaIetaIeta_en0p2_noRelNoiseCut.push_back(sigmaIetaIeta_en0p2_noRelNoiseCut);
    float sigmaIetaIeta_en0p5_noRelNoiseCut = sqrt(mylocalCovariances_en0p5_noRelNoiseCut[0]);
    my_eleSigmaIetaIeta_en0p5_noRelNoiseCut.push_back(sigmaIetaIeta_en0p5_noRelNoiseCut);
    float sigmaIetaIeta_en1_noRelNoiseCut = sqrt(mylocalCovariances_en1_noRelNoiseCut[0]);
    my_eleSigmaIetaIeta_en1_noRelNoiseCut.push_back(sigmaIetaIeta_en1_noRelNoiseCut);
    float sigmaIetaIeta_en_0p1_0p4 = sqrt(mylocalCovariances_en_0p1_0p4[0]);
    my_eleSigmaIetaIeta_en_0p1_0p4.push_back(sigmaIetaIeta_en_0p1_0p4);
    float sigmaIetaIeta_en_0p15_0p5 = sqrt(mylocalCovariances_en_0p15_0p5[0]);
    my_eleSigmaIetaIeta_en_0p15_0p5.push_back(sigmaIetaIeta_en_0p15_0p5);
    float sigmaIetaIeta_en_0p16_0p6 = sqrt(mylocalCovariances_en_0p16_0p6[0]);
    my_eleSigmaIetaIeta_en_0p16_0p6.push_back(sigmaIetaIeta_en_0p16_0p6);
    float sigmaIetaIeta_en_0p2_1 = sqrt(mylocalCovariances_en_0p2_1[0]);
    my_eleSigmaIetaIeta_en_0p2_1.push_back(sigmaIetaIeta_en_0p2_1);
    float sigmaIetaIeta_en_0p2_1p5 = sqrt(mylocalCovariances_en_0p2_1p5[0]);
    my_eleSigmaIetaIeta_en_0p2_1p5.push_back(sigmaIetaIeta_en_0p2_1p5);
    float sigmaIetaIeta_en_0p2_2 = sqrt(mylocalCovariances_en_0p2_2[0]);
    my_eleSigmaIetaIeta_en_0p2_2.push_back(sigmaIetaIeta_en_0p2_2);
    float sigmaIetaIeta_en_0p18_0p8 = sqrt(mylocalCovariances_en_0p18_0p8[0]);
    my_eleSigmaIetaIeta_en_0p18_0p8.push_back(sigmaIetaIeta_en_0p18_0p8);

    //ietaiphi
    float sigmaIetaIphi_en0p15 = sqrt(mylocalCovariances_en0p15[0]);
    my_eleSigmaIetaIphi_en0p15.push_back(sigmaIetaIphi_en0p15);

    float sigmaIetaIphi_en0p2 = sqrt(mylocalCovariances_en0p2[0]);
    my_eleSigmaIetaIphi_en0p2.push_back(sigmaIetaIphi_en0p2);

    float sigmaIetaIphi_en0p5 = sqrt(mylocalCovariances_en0p5[0]);
    my_eleSigmaIetaIphi_en0p5.push_back(sigmaIetaIphi_en0p5);

    float sigmaIetaIphi_en1 = sqrt(mylocalCovariances_en1[0]);
    my_eleSigmaIetaIphi_en1.push_back(sigmaIetaIphi_en1);

    float sigmaIetaIphi_en0p15_noRelNoiseCut = sqrt(mylocalCovariances_en0p15_noRelNoiseCut[0]);
    my_eleSigmaIetaIphi_en0p15_noRelNoiseCut.push_back(sigmaIetaIphi_en0p15_noRelNoiseCut);

    float sigmaIetaIphi_en0p2_noRelNoiseCut = sqrt(mylocalCovariances_en0p2_noRelNoiseCut[0]);
    my_eleSigmaIetaIphi_en0p2_noRelNoiseCut.push_back(sigmaIetaIphi_en0p2_noRelNoiseCut);

    float sigmaIetaIphi_en0p5_noRelNoiseCut = sqrt(mylocalCovariances_en0p5_noRelNoiseCut[0]);
    my_eleSigmaIetaIphi_en0p5_noRelNoiseCut.push_back(sigmaIetaIphi_en0p5_noRelNoiseCut);

    float sigmaIetaIphi_en1_noRelNoiseCut = sqrt(mylocalCovariances_en1_noRelNoiseCut[0]);
    my_eleSigmaIetaIphi_en1_noRelNoiseCut.push_back(sigmaIetaIphi_en1_noRelNoiseCut);

    float sigmaIetaIphi_en_0p1_0p4 = sqrt(mylocalCovariances_en_0p1_0p4[0]);
    my_eleSigmaIetaIphi_en_0p1_0p4.push_back(sigmaIetaIphi_en_0p1_0p4);

    float sigmaIetaIphi_en_0p15_0p5 = sqrt(mylocalCovariances_en_0p15_0p5[0]);
    my_eleSigmaIetaIphi_en_0p15_0p5.push_back(sigmaIetaIphi_en_0p15_0p5);

    float sigmaIetaIphi_en_0p16_0p6 = sqrt(mylocalCovariances_en_0p16_0p6[0]);
    my_eleSigmaIetaIphi_en_0p16_0p6.push_back(sigmaIetaIphi_en_0p16_0p6);

    float sigmaIetaIphi_en_0p2_1 = sqrt(mylocalCovariances_en_0p2_1[0]);
    my_eleSigmaIetaIphi_en_0p2_1.push_back(sigmaIetaIphi_en_0p2_1);

    float sigmaIetaIphi_en_0p2_1p5 = sqrt(mylocalCovariances_en_0p2_1p5[0]);
    my_eleSigmaIetaIphi_en_0p2_1p5.push_back(sigmaIetaIphi_en_0p2_1p5);

    float sigmaIetaIphi_en_0p2_2 = sqrt(mylocalCovariances_en_0p2_2[0]);
    my_eleSigmaIetaIphi_en_0p2_2.push_back(sigmaIetaIphi_en_0p2_2);

    float sigmaIetaIphi_en_0p18_0p8 = sqrt(mylocalCovariances_en_0p18_0p8[0]);
    my_eleSigmaIetaIphi_en_0p18_0p8.push_back(sigmaIetaIphi_en_0p18_0p8);

    //
    float sigmaIetaIeta_per_rechit = sqrt(mylocalCovariances_per_rechit[0]); 
    my_eleSigmaIetaIeta_per_rechit.push_back(sigmaIetaIeta_per_rechit);

    float sigmaIetaIeta_per_rechit_m1p05 = sqrt(mylocalCovariances_per_rechit_m1p05[0]); 
    my_eleSigmaIetaIeta_per_rechit_m1p05.push_back(sigmaIetaIeta_per_rechit_m1p05);

    float sigmaIetaIeta_per_rechit_m1p1 = sqrt(mylocalCovariances_per_rechit_m1p1[0]); 
    my_eleSigmaIetaIeta_per_rechit_m1p1.push_back(sigmaIetaIeta_per_rechit_m1p1);

    float sigmaIetaIeta_per_rechit_m1p15 = sqrt(mylocalCovariances_per_rechit_m1p15[0]); 
    my_eleSigmaIetaIeta_per_rechit_m1p15.push_back(sigmaIetaIeta_per_rechit_m1p15);

    float sigmaIetaIeta_per_rechit_m1p2 = sqrt(mylocalCovariances_per_rechit_m1p2[0]); 
    my_eleSigmaIetaIeta_per_rechit_m1p2.push_back(sigmaIetaIeta_per_rechit_m1p2);

    float sigmaIetaIeta_per_rechit_m1p25 = sqrt(mylocalCovariances_per_rechit_m1p25[0]); 
    my_eleSigmaIetaIeta_per_rechit_m1p25.push_back(sigmaIetaIeta_per_rechit_m1p25);
    //
    float sigmaIetaIeta_per_rechit_m1p3 = sqrt(mylocalCovariances_per_rechit_m1p3[0]); 
    my_eleSigmaIetaIeta_per_rechit_m1p3.push_back(sigmaIetaIeta_per_rechit_m1p3);

    float sigmaIetaIeta_per_rechit_m1p4 = sqrt(mylocalCovariances_per_rechit_m1p4[0]); 
    my_eleSigmaIetaIeta_per_rechit_m1p4.push_back(sigmaIetaIeta_per_rechit_m1p4);

    float sigmaIetaIeta_per_rechit_m1p5 = sqrt(mylocalCovariances_per_rechit_m1p5[0]); 
    my_eleSigmaIetaIeta_per_rechit_m1p5.push_back(sigmaIetaIeta_per_rechit_m1p5);

    float sigmaIetaIeta_per_rechit_m1p6 = sqrt(mylocalCovariances_per_rechit_m1p6[0]); 
    my_eleSigmaIetaIeta_per_rechit_m1p6.push_back(sigmaIetaIeta_per_rechit_m1p6);

    float sigmaIetaIeta_per_rechit_m1p7 = sqrt(mylocalCovariances_per_rechit_m1p7[0]); 
    my_eleSigmaIetaIeta_per_rechit_m1p7.push_back(sigmaIetaIeta_per_rechit_m1p7);

    float sigmaIetaIeta_per_rechit_m1p8 = sqrt(mylocalCovariances_per_rechit_m1p8[0]); 
    my_eleSigmaIetaIeta_per_rechit_m1p8.push_back(sigmaIetaIeta_per_rechit_m1p8);

    float sigmaIetaIeta_per_rechit_m1p9 = sqrt(mylocalCovariances_per_rechit_m1p9[0]); 
    my_eleSigmaIetaIeta_per_rechit_m1p9.push_back(sigmaIetaIeta_per_rechit_m1p9);

    //
    float sigmaIetaIphi_per_rechit = sqrt(mylocalCovariances_per_rechit[1]); 
    my_eleSigmaIetaIphi_per_rechit.push_back(sigmaIetaIphi_per_rechit);

    float sigmaIetaIphi_per_rechit_m1p05 = sqrt(mylocalCovariances_per_rechit_m1p05[1]); 
    my_eleSigmaIetaIphi_per_rechit_m1p05.push_back(sigmaIetaIphi_per_rechit_m1p05);

    float sigmaIetaIphi_per_rechit_m1p1 = sqrt(mylocalCovariances_per_rechit_m1p1[1]); 
    my_eleSigmaIetaIphi_per_rechit_m1p1.push_back(sigmaIetaIphi_per_rechit_m1p1);

    float sigmaIetaIphi_per_rechit_m1p15 = sqrt(mylocalCovariances_per_rechit_m1p15[1]); 
    my_eleSigmaIetaIphi_per_rechit_m1p15.push_back(sigmaIetaIphi_per_rechit_m1p15);

    float sigmaIetaIphi_per_rechit_m1p2 = sqrt(mylocalCovariances_per_rechit_m1p2[1]); 
    my_eleSigmaIetaIphi_per_rechit_m1p2.push_back(sigmaIetaIphi_per_rechit_m1p2);
    
    float sigmaIetaIphi_per_rechit_m1p25 = sqrt(mylocalCovariances_per_rechit_m1p25[1]); 
    my_eleSigmaIetaIphi_per_rechit_m1p25.push_back(sigmaIetaIphi_per_rechit_m1p25);

    float sigmaIetaIphi_per_rechit_m1p3 = sqrt(mylocalCovariances_per_rechit_m1p3[1]); 
    my_eleSigmaIetaIphi_per_rechit_m1p3.push_back(sigmaIetaIphi_per_rechit_m1p3);

    float sigmaIetaIphi_per_rechit_m1p4 = sqrt(mylocalCovariances_per_rechit_m1p4[1]); 
    my_eleSigmaIetaIphi_per_rechit_m1p4.push_back(sigmaIetaIphi_per_rechit_m1p4);

    float sigmaIetaIphi_per_rechit_m1p5 = sqrt(mylocalCovariances_per_rechit_m1p5[1]); 
    my_eleSigmaIetaIphi_per_rechit_m1p5.push_back(sigmaIetaIphi_per_rechit_m1p5);

    float sigmaIetaIphi_per_rechit_m1p6 = sqrt(mylocalCovariances_per_rechit_m1p6[1]); 
    my_eleSigmaIetaIphi_per_rechit_m1p6.push_back(sigmaIetaIphi_per_rechit_m1p6);

    float sigmaIetaIphi_per_rechit_m1p7 = sqrt(mylocalCovariances_per_rechit_m1p7[1]); 
    my_eleSigmaIetaIphi_per_rechit_m1p7.push_back(sigmaIetaIphi_per_rechit_m1p7);

    float sigmaIetaIphi_per_rechit_m1p8 = sqrt(mylocalCovariances_per_rechit_m1p8[1]); 
    my_eleSigmaIetaIphi_per_rechit_m1p8.push_back(sigmaIetaIphi_per_rechit_m1p8);

    float sigmaIetaIphi_per_rechit_m1p9 = sqrt(mylocalCovariances_per_rechit_m1p9[1]); 
    my_eleSigmaIetaIphi_per_rechit_m1p9.push_back(sigmaIetaIphi_per_rechit_m1p9);

    // 
    float sigmaIphiIphi_per_rechit = sqrt(mylocalCovariances_per_rechit[2]); 
    my_eleSigmaIphiIphi_per_rechit.push_back(sigmaIphiIphi_per_rechit);

    float sigmaIphiIphi_per_rechit_m1p05 = sqrt(mylocalCovariances_per_rechit_m1p05[2]); 
    my_eleSigmaIphiIphi_per_rechit_m1p05.push_back(sigmaIphiIphi_per_rechit_m1p05);

    float sigmaIphiIphi_per_rechit_m1p1 = sqrt(mylocalCovariances_per_rechit_m1p1[2]); 
    my_eleSigmaIphiIphi_per_rechit_m1p1.push_back(sigmaIphiIphi_per_rechit_m1p1);

    float sigmaIphiIphi_per_rechit_m1p15 = sqrt(mylocalCovariances_per_rechit_m1p15[2]); 
    my_eleSigmaIphiIphi_per_rechit_m1p15.push_back(sigmaIphiIphi_per_rechit_m1p15);

    float sigmaIphiIphi_per_rechit_m1p2 = sqrt(mylocalCovariances_per_rechit_m1p2[2]); 
    my_eleSigmaIphiIphi_per_rechit_m1p2.push_back(sigmaIphiIphi_per_rechit_m1p2);

    float sigmaIphiIphi_per_rechit_m1p25 = sqrt(mylocalCovariances_per_rechit_m1p25[2]); 
    my_eleSigmaIphiIphi_per_rechit_m1p25.push_back(sigmaIphiIphi_per_rechit_m1p25);

    float sigmaIphiIphi_per_rechit_m1p3 = sqrt(mylocalCovariances_per_rechit_m1p3[2]); 
    my_eleSigmaIphiIphi_per_rechit_m1p3.push_back(sigmaIphiIphi_per_rechit_m1p3);

    float sigmaIphiIphi_per_rechit_m1p4 = sqrt(mylocalCovariances_per_rechit_m1p4[2]); 
    my_eleSigmaIphiIphi_per_rechit_m1p4.push_back(sigmaIphiIphi_per_rechit_m1p4);

    float sigmaIphiIphi_per_rechit_m1p5 = sqrt(mylocalCovariances_per_rechit_m1p5[2]); 
    my_eleSigmaIphiIphi_per_rechit_m1p5.push_back(sigmaIphiIphi_per_rechit_m1p5);

    float sigmaIphiIphi_per_rechit_m1p6 = sqrt(mylocalCovariances_per_rechit_m1p6[2]); 
    my_eleSigmaIphiIphi_per_rechit_m1p6.push_back(sigmaIphiIphi_per_rechit_m1p6);

    float sigmaIphiIphi_per_rechit_m1p7 = sqrt(mylocalCovariances_per_rechit_m1p7[2]); 
    my_eleSigmaIphiIphi_per_rechit_m1p7.push_back(sigmaIphiIphi_per_rechit_m1p7);

    float sigmaIphiIphi_per_rechit_m1p8 = sqrt(mylocalCovariances_per_rechit_m1p8[2]); 
    my_eleSigmaIphiIphi_per_rechit_m1p8.push_back(sigmaIphiIphi_per_rechit_m1p8);

    float sigmaIphiIphi_per_rechit_m1p9 = sqrt(mylocalCovariances_per_rechit_m1p9[2]); 
    my_eleSigmaIphiIphi_per_rechit_m1p9.push_back(sigmaIphiIphi_per_rechit_m1p9);


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
