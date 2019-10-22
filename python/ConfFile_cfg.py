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

process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('PhysicsTools.HepMCCandAlgos.genParticles_cfi')

#from SimGeneral.HepPDTESSource.pythiapdt_cfi import *
#from RecoJets.Configuration.GenJetParticles_cff import *

process.MessageLogger.cerr.FwkReport.reportEvery = 500

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run2_mc', '')     # MC

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(5000) )

process.source = cms.Source("PoolSource",
                                fileNames = cms.untracked.vstring(
#                                    'file:/eos/cms/store/group/phys_egamma/CMSPOS2019/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8__RunIIAutumn18MiniAOD__102X_upgrade2018_realistic_v15-v1__MINIAODSIM__F1B849B9-9B5D-1041-B5CD-73DB6C24072A.root'
#            '/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/NoPUEcalAging2023_102X_upgrade2018_realistic_EcalAging_mid2023_400fb_v1-v1/100000/B782D51E-4965-B04E-87DB-4A742ED021AC.root' 
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/4B82E385-367D-B947-9207-A8C03E836D6F.root', #AODSIM 2024
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/4B82D862-1E4E-2447-8798-479E52D96373.root',
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/FD0BE6B3-105C-4B46-856E-8E75903B25BD.root',
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/FC70F977-60BE-DD49-A0AD-1A1C9DD1FC88.root',
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/FC59F2EB-5398-654A-80BA-EC07E47F96E4.root'
#                                 '/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/GEN-SIM-RECO/NoPUEcalAging2022_102X_upgrade2018_realistic_EcalAging_mid2022_315fb_v1-v1/100000/FF27DADE-0845-2E4E-94D7-98E1486239F8.root',
#                                 '/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/GEN-SIM-RECO/NoPUEcalAging2022_102X_upgrade2018_realistic_EcalAging_mid2022_315fb_v1-v1/100000/EED53B85-40EC-894B-901B-2A7C172033C9.root',
#                                 '/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/GEN-SIM-RECO/NoPUEcalAging2022_102X_upgrade2018_realistic_EcalAging_mid2022_315fb_v1-v1/100000/E80B9B74-265B-114C-8E02-30E09254612D.root'
#2018
                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/270000/FE2EA85F-2F46-9B41-B6FF-E724174EE4CE.root',#2018 AOD
#2023
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/FFD71080-0F4A-1340-962F-D23AC2252C7C.root' #2023 AOD
#2021
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/FF3F1F82-05A1-5247-BF2D-10CC42EF827B.root'
                )
                            )

process.demo = cms.EDAnalyzer('DemoAnalyzer',
       tracks = cms.untracked.InputTag('generalTracks'),
       electrons = cms.InputTag('gedGsfElectrons'),
       #electrons = cms.InputTag('slimmedElectrons'),
       #EBRecHitCollection = cms.InputTag("ecalRecHit","EcalRecHitsEB"), #RECO 
       #EERecHitCollection = cms.InputTag("ecalRecHit","EcalRecHitsEE"), #RECO
       EERecHitCollection = cms.InputTag("reducedEcalRecHitsEE"), #AOD
       EBRecHitCollection = cms.InputTag("reducedEcalRecHitsEB"), #AOD

       #EERecHitCollection = cms.InputTag("reducedEERecHits"), #miniAOD
       #EBRecHitCollection = cms.InputTag("reducedEBRecHits"), #miniAOD

       pileupCollection     = cms.InputTag("addPileupInfo"),
       genParticleSrc       = cms.InputTag("genParticles"),

                              )
process.TFileService = cms.Service("TFileService", fileName = cms.string('RedefNtup_AOD_2018.root'))

process.p = cms.Path(process.demo)
