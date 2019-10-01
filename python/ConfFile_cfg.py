import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")
#process.load("Configuration.StandardSequences.GeometryRecoDB_cff")
#process.load("Configuration.StandardSequences.MagneticField_cff")
#process.load("Configuration.EventContent.EventContent_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("Geometry.CaloEventSetup.CaloTopology_cfi");
process.load("Geometry.CaloEventSetup.CaloGeometry_cfi");
process.load("Geometry.CMSCommonData.cmsIdealGeometryXML_cfi");
process.load("Configuration.Geometry.GeometryECALHCAL_cff")

process.MessageLogger.cerr.FwkReport.reportEvery = 1000

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run2_mc', '')     # MC

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
                                fileNames = cms.untracked.vstring(
#            '/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/NoPUEcalAging2023_102X_upgrade2018_realistic_EcalAging_mid2023_400fb_v1-v1/100000/B782D51E-4965-B04E-87DB-4A742ED021AC.root' 
                                 '/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/GEN-SIM-RECO/NoPUEcalAging2022_102X_upgrade2018_realistic_EcalAging_mid2022_315fb_v1-v1/100000/FF27DADE-0845-2E4E-94D7-98E1486239F8.root',
                                 '/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/GEN-SIM-RECO/NoPUEcalAging2022_102X_upgrade2018_realistic_EcalAging_mid2022_315fb_v1-v1/100000/EED53B85-40EC-894B-901B-2A7C172033C9.root',
                                 '/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/GEN-SIM-RECO/NoPUEcalAging2022_102X_upgrade2018_realistic_EcalAging_mid2022_315fb_v1-v1/100000/E80B9B74-265B-114C-8E02-30E09254612D.root'
                )
                            )

process.demo = cms.EDAnalyzer('DemoAnalyzer',
       tracks = cms.untracked.InputTag('generalTracks'),
       electrons = cms.InputTag('gedGsfElectrons'),
       EBRecHitCollection = cms.InputTag("ecalRecHit","EcalRecHitsEB"), #RECO 
       EERecHitCollection = cms.InputTag("ecalRecHit","EcalRecHitsEE"), #RECO
       #EERecHitCollection = cms.InputTag("reducedEcalRecHitsEE"), #AOD
       #EBRecHitCollection = cms.InputTag("reducedEcalRecHitsEB"), #AOD
       pileupCollection     = cms.InputTag("addPileupInfo"),

                              )
process.TFileService = cms.Service("TFileService", fileName = cms.string('RedefNtup_w_4p7_RECO.root'))

process.p = cms.Path(process.demo)
