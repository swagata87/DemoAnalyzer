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

#include "TTree.h"


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
  puCollection_(consumes<std::vector<PileupSummaryInfo> >(iConfig.getParameter<edm::InputTag>("pileupCollection")))

{
  //now do what ever initialization is needed
  
  tree->Branch("trkCharge_",&trkCharge);
  tree->Branch("cmssw_eleSigmaIetaIeta_",&cmssw_eleSigmaIetaIeta);
  tree->Branch("cmssw_eleR9_",&cmssw_eleR9);
  tree->Branch("cmssw_eleHoE_",&cmssw_eleHoE);
  tree->Branch("eleScEta_",&eleScEta);
  tree->Branch("eleScEn_",&eleScEn);
  tree->Branch("elePt_",&elePt);
  tree->Branch("puTrue_", &puTrue);
  tree->Branch("my_eleSigmaIetaIeta_",&my_eleSigmaIetaIeta);
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
  //  std::cout << "\n --New Event-- \n" ;
  using namespace edm;
  
  trkCharge.clear();
  cmssw_eleSigmaIetaIeta.clear();
  cmssw_eleR9.clear();
  cmssw_eleHoE.clear();
  eleScEta.clear();
  eleScEn.clear();
  elePt.clear();
  my_eleSigmaIetaIeta.clear();
  puTrue.clear();

  edm::Handle<std::vector<PileupSummaryInfo> > genPileupHandle;
  iEvent.getByToken(puCollection_, genPileupHandle);
  
  if (genPileupHandle.isValid()) {
    for (std::vector<PileupSummaryInfo>::const_iterator pu = genPileupHandle->begin(); pu != genPileupHandle->end(); ++pu) {
      puTrue.push_back(pu->getTrueNumInteractions());
    }
  }
  
  for(const auto& track : iEvent.get(tracksToken_) ) {
    trkCharge.push_back(track.charge());
  }
  
  
  for(const auto& ele : iEvent.get(eleToken_) ) {

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
    std::vector<float> mylocalCovariances = EcalClusterTools::localCovariances(seedCluster, recHits, caloTopology);
    float sigmaIetaIeta = sqrt(mylocalCovariances[0]);
    my_eleSigmaIetaIeta.push_back(sigmaIetaIeta);
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
