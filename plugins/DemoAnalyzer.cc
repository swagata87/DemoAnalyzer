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

class DemoAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
public:
  explicit DemoAnalyzer(const edm::ParameterSet&);
  ~DemoAnalyzer();
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  
  edm::Service<TFileService> fs;
  TTree   *tree = fs->make<TTree>("EventTree", "EventData");
  
  std::vector<int>   trkCharge;
  std::vector<double>  cmssw_eleSigmaIetaIeta;
  std::vector<float>  cmssw_eleR9;
  std::vector<float>  cmssw_eleHoE;
  std::vector<float>  eleScEta;
  std::vector<float>  eleScEn;
  std::vector<float>  elePt;
  std::vector<float>  puTrue;
  std::vector<double>  my_eleSigmaIetaIeta;
  std::vector<double>  my_eleSigmaIetaIeta_w4p0;
  std::vector<double>  my_eleSigmaIetaIeta_w3p5;
  std::vector<double>  my_eleSigmaIetaIeta_w3p0;

  std::vector<double>  my_eleSigmaIetaIeta_en0p15;
  std::vector<double>  my_eleSigmaIetaIeta_en0p2;
  std::vector<double>  my_eleSigmaIetaIeta_en0p5;
  std::vector<double>  my_eleSigmaIetaIeta_en1;

  std::vector<double>  my_eleSigmaIetaIeta_en_0p1_0p4;
  std::vector<double>  my_eleSigmaIetaIeta_en_0p15_0p5;
  std::vector<double>  my_eleSigmaIetaIeta_en_0p16_0p6;
  std::vector<double>  my_eleSigmaIetaIeta_en_0p2_1;
  std::vector<double>  my_eleSigmaIetaIeta_en_0p2_1p5;
  std::vector<double>  my_eleSigmaIetaIeta_en_0p2_2;
  std::vector<double>  my_eleSigmaIetaIeta_en_0p18_0p8;

  std::vector<int>  ele_genmatched;

  std::vector<int>    gen_status;
  std::vector<int>    gen_pdgid;
  //  std::vector<int>    gen_isPromptFinalState;
  //  std::vector<int>    gen_isLastCopy;
  //  std::vector<int>    gen_isHardProcess;
  std::vector<float>  gen_pt;

private:
  virtual void beginJob() override;
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;
  
  // ----------member data ---------------------------
  edm::EDGetTokenT<TrackCollection> tracksToken_;  //used to select what tracks to read from configuration file
  edm::EDGetTokenT<edm::View<reco::GsfElectron> > eleToken_;
  edm::EDGetTokenT<EcalRecHitCollection> EBRecHitCollectionT_;
  edm::EDGetTokenT<EcalRecHitCollection> EERecHitCollectionT_;
  edm::ESHandle<CaloTopology> theCaloTopology;
  edm::EDGetTokenT<std::vector<PileupSummaryInfo> >     puCollection_;
  edm::EDGetTokenT<std::vector<reco::GenParticle> >     genParticlesCollection_;

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

{
  //now do what ever initialization is needed
  tree->Branch("ele_genmatched_",&ele_genmatched);
  tree->Branch("trkCharge_",&trkCharge);
  tree->Branch("cmssw_eleSigmaIetaIeta_",&cmssw_eleSigmaIetaIeta);
  tree->Branch("cmssw_eleR9_",&cmssw_eleR9);
  tree->Branch("cmssw_eleHoE_",&cmssw_eleHoE);
  tree->Branch("eleScEta_",&eleScEta);
  tree->Branch("eleScEn_",&eleScEn);
  tree->Branch("elePt_",&elePt);
  tree->Branch("puTrue_", &puTrue);
  tree->Branch("my_eleSigmaIetaIeta_",&my_eleSigmaIetaIeta);
  tree->Branch("my_eleSigmaIetaIeta_w4p0_",&my_eleSigmaIetaIeta_w4p0);
  tree->Branch("my_eleSigmaIetaIeta_w3p5_",&my_eleSigmaIetaIeta_w3p5);
  tree->Branch("my_eleSigmaIetaIeta_w3p0_",&my_eleSigmaIetaIeta_w3p0);
  tree->Branch("my_eleSigmaIetaIeta_en0p2_",&my_eleSigmaIetaIeta_en0p2);
  tree->Branch("my_eleSigmaIetaIeta_en0p15_",&my_eleSigmaIetaIeta_en0p15);
  tree->Branch("my_eleSigmaIetaIeta_en0p5_",&my_eleSigmaIetaIeta_en0p5);
  tree->Branch("my_eleSigmaIetaIeta_en1_",&my_eleSigmaIetaIeta_en1);

  tree->Branch("my_eleSigmaIetaIeta_en_0p1_0p4_",&my_eleSigmaIetaIeta_en_0p1_0p4);
  tree->Branch("my_eleSigmaIetaIeta_en_0p15_0p5_",&my_eleSigmaIetaIeta_en_0p15_0p5);
  tree->Branch("my_eleSigmaIetaIeta_en_0p16_0p6_",&my_eleSigmaIetaIeta_en_0p16_0p6);
  tree->Branch("my_eleSigmaIetaIeta_en_0p2_1_",&my_eleSigmaIetaIeta_en_0p2_1);
  tree->Branch("my_eleSigmaIetaIeta_en_0p2_1p5_",&my_eleSigmaIetaIeta_en_0p2_1p5);
  tree->Branch("my_eleSigmaIetaIeta_en_0p2_2_",&my_eleSigmaIetaIeta_en_0p2_2);
  tree->Branch("my_eleSigmaIetaIeta_en_0p18_0p8_",&my_eleSigmaIetaIeta_en_0p18_0p8);
  
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
  //   std::cout << "\n --New Event-- \n" ;
  using namespace edm;
  
  trkCharge.clear();
  ele_genmatched.clear();
  cmssw_eleSigmaIetaIeta.clear();
  cmssw_eleR9.clear();
  cmssw_eleHoE.clear();
  eleScEta.clear();
  eleScEn.clear();
  elePt.clear();
  my_eleSigmaIetaIeta.clear();
  my_eleSigmaIetaIeta_w4p0.clear();
  my_eleSigmaIetaIeta_w3p5.clear();
  my_eleSigmaIetaIeta_w3p0.clear();
  my_eleSigmaIetaIeta_en0p2.clear();
  my_eleSigmaIetaIeta_en0p15.clear();
  my_eleSigmaIetaIeta_en0p5.clear();
  my_eleSigmaIetaIeta_en1.clear();

  my_eleSigmaIetaIeta_en_0p1_0p4.clear();
  my_eleSigmaIetaIeta_en_0p15_0p5.clear();
  my_eleSigmaIetaIeta_en_0p16_0p6.clear();
  my_eleSigmaIetaIeta_en_0p2_1.clear();
  my_eleSigmaIetaIeta_en_0p2_1p5.clear();
  my_eleSigmaIetaIeta_en_0p2_2.clear();
  my_eleSigmaIetaIeta_en_0p18_0p8.clear();

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
  
  
  for(const auto& ele : iEvent.get(eleToken_) ) {
    
    int genmatched=0;
    
    
    if (genParticlesHandle.isValid()) {
      for (std::vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {
	const reco::Candidate *p = (const reco::Candidate*)&(*ip);
	//      if ( (p->status()==1) && abs(p->pdgId() == 11) ) std::cout << "dR = " << reco::deltaR(ele,*p) << " ele pt = " << ele.pt() << " gen pt = " << p->pt() <<std::endl;
	if ( (p->status()==1) && abs(p->pdgId() == 11) && ((reco::deltaR(ele,*p))<0.04) ) genmatched=1;
      }  
    }
    
    ele_genmatched.push_back(genmatched);
    
    cmssw_eleSigmaIetaIeta.push_back(ele.full5x5_sigmaIetaIeta());
    cmssw_eleR9.push_back(ele.full5x5_r9());
    cmssw_eleHoE.push_back(ele.hcalOverEcal());
    eleScEta.push_back(ele.superCluster()->eta());
    eleScEn.push_back(ele.superCluster()->energy());
    elePt.push_back(ele.pt());

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

    //noZS::EcalClusterTools
    //    using ClusterTools = EcalClusterToolsT<true>;     
    using ClusterTools = noZS::EcalClusterTools;     
    std::vector<float> mylocalCovariances = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0,0);
    std::vector<float> mylocalCovariances_w4p0 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.0,0,0);
    std::vector<float> mylocalCovariances_w3p5 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,3.5,0,0);
    std::vector<float> mylocalCovariances_w3p0 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,3.0,0,0);
    std::vector<float> mylocalCovariances_en0p2 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.2,0.2);
    std::vector<float> mylocalCovariances_en0p15 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.15,0.15);
    std::vector<float> mylocalCovariances_en0p5 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.5,0.5);
    std::vector<float> mylocalCovariances_en1 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,1.0,1.0);

    std::vector<float> mylocalCovariances_en_0p1_0p4 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.1,0.4);
    std::vector<float> mylocalCovariances_en_0p15_0p5 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.15,0.5);
    std::vector<float> mylocalCovariances_en_0p16_0p6 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.16,0.6);
    std::vector<float> mylocalCovariances_en_0p2_1 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.2,1.0);
    std::vector<float> mylocalCovariances_en_0p2_1p5 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.2,1.5);
    std::vector<float> mylocalCovariances_en_0p2_2 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.2,2);
    std::vector<float> mylocalCovariances_en_0p18_0p8 = ClusterTools::localCovariances(seedCluster, recHits, caloTopology,4.7,0.18,0.8);

    //    std::vector<float> mylocalCovariances = EcalClusterTools::localCovariances(seedCluster, recHits, caloTopology);

    float sigmaIetaIeta = sqrt(mylocalCovariances[0]);
    my_eleSigmaIetaIeta.push_back(sigmaIetaIeta);

    float sigmaIetaIeta_w4p0 = sqrt(mylocalCovariances_w4p0[0]);
    my_eleSigmaIetaIeta_w4p0.push_back(sigmaIetaIeta_w4p0);

    float sigmaIetaIeta_w3p5 = sqrt(mylocalCovariances_w3p5[0]);
    my_eleSigmaIetaIeta_w3p5.push_back(sigmaIetaIeta_w3p5);

    float sigmaIetaIeta_w3p0 = sqrt(mylocalCovariances_w3p0[0]);
    my_eleSigmaIetaIeta_w3p0.push_back(sigmaIetaIeta_w3p0);

    float sigmaIetaIeta_en0p15 = sqrt(mylocalCovariances_en0p15[0]);
    my_eleSigmaIetaIeta_en0p15.push_back(sigmaIetaIeta_en0p15);

    float sigmaIetaIeta_en0p2 = sqrt(mylocalCovariances_en0p2[0]);
    my_eleSigmaIetaIeta_en0p2.push_back(sigmaIetaIeta_en0p2);

    float sigmaIetaIeta_en0p5 = sqrt(mylocalCovariances_en0p5[0]);
    my_eleSigmaIetaIeta_en0p5.push_back(sigmaIetaIeta_en0p5);

    float sigmaIetaIeta_en1 = sqrt(mylocalCovariances_en1[0]);
    my_eleSigmaIetaIeta_en1.push_back(sigmaIetaIeta_en1);

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
