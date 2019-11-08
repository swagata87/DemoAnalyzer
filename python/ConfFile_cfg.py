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

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1200) )

process.source = cms.Source("PoolSource",
                                fileNames = cms.untracked.vstring(
#                                    'file:/eos/cms/store/group/phys_egamma/CMSPOS2019/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8__RunIIAutumn18MiniAOD__102X_upgrade2018_realistic_v15-v1__MINIAODSIM__F1B849B9-9B5D-1041-B5CD-73DB6C24072A.root'
#            '/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/NoPUEcalAging2023_102X_upgrade2018_realistic_EcalAging_mid2023_400fb_v1-v1/100000/B782D51E-4965-B04E-87DB-4A742ED021AC.root' 
             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/4B82E385-367D-B947-9207-A8C03E836D6F.root', #AODSIM 2024
             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/4B82D862-1E4E-2447-8798-479E52D96373.root',
             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/FD0BE6B3-105C-4B46-856E-8E75903B25BD.root',
             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/FC70F977-60BE-DD49-A0AD-1A1C9DD1FC88.root',
             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/FC59F2EB-5398-654A-80BA-EC07E47F96E4.root',
            '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/2C277334-7B6F-B34A-AF76-7C7EA6436E51.root',
            '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/2E3D064E-E7BA-E947-A8C0-F923EF558C74.root',
            '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/3171AAC4-929A-9940-8CCE-5436C93B09B1.root',
            '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/31C34317-54B4-C542-BDD2-725F520AD99D.root',
            '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/327D45A3-A9DE-B641-B68E-A856B58F97A1.root'
#
#
#                                 '/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/GEN-SIM-RECO/NoPUEcalAging2022_102X_upgrade2018_realistic_EcalAging_mid2022_315fb_v1-v1/100000/FF27DADE-0845-2E4E-94D7-98E1486239F8.root',
#                                 '/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/GEN-SIM-RECO/NoPUEcalAging2022_102X_upgrade2018_realistic_EcalAging_mid2022_315fb_v1-v1/100000/EED53B85-40EC-894B-901B-2A7C172033C9.root',
#                                 '/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/GEN-SIM-RECO/NoPUEcalAging2022_102X_upgrade2018_realistic_EcalAging_mid2022_315fb_v1-v1/100000/E80B9B74-265B-114C-8E02-30E09254612D.root'
#2018
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/270000/FE2EA85F-2F46-9B41-B6FF-E724174EE4CE.root',#2018 AOD
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/120001/72DDC91F-6BC8-D343-A44C-6D537B8547FC.root',
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/120001/76FA30CA-F518-ED4D-8AA4-AD2D43E74742.root',
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/120001/77299BB6-3845-E246-B8BE-22A4D464B5EA.root',
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/120001/7A836983-300B-CD4D-8765-EFC6496BA19C.root',
#2023
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/FFD71080-0F4A-1340-962F-D23AC2252C7C.root', #2023 AOD
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/DE8D397F-BC95-4546-A75C-4ABCAAEF312B.root',
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/DEE779FF-58CF-1549-9998-5C0B977B484F.root',
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/DF106A6B-F79C-604F-803A-3AC0B943E48C.root',
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/DF1555B1-2759-774B-AB6A-41F634BC4249.root'
#2021
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/FF3F1F82-05A1-5247-BF2D-10CC42EF827B.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/DE7689B8-0271-A844-B24D-A9A842DB07FE.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/DF62A0BD-0D6C-1E43-8B98-FC720604AB7F.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/F27584A0-93BA-A549-9233-F121DE8B987A.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/E040E1D7-5ADD-EE49-923F-FF232F91A4A6.root'
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
#      pfrechits = cms.InputTag('particleFlowRecHitECAL'   , 'Cleaned'  ,       'RECO'), #AOD    
       #EERecHitCollection = cms.InputTag("reducedEERecHits"), #miniAOD
       #EBRecHitCollection = cms.InputTag("reducedEBRecHits"), #miniAOD
       pileupCollection     = cms.InputTag("addPileupInfo"),
       genParticleSrc       = cms.InputTag("genParticles"),

                              )
#process.TFileService = cms.Service("TFileService", fileName = cms.string('RedefNtup_AOD_2024.root'))
process.TFileService = cms.Service("TFileService", fileName = cms.string('test_AOD.root'))

process.p = cms.Path(process.demo)
