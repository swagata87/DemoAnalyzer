import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")
#from RecoEgamma.EgammaTools.EgammaPostRecoTools import setupEgammaPostRecoSeq

from EgammaUser.EgammaPostRecoTools.EgammaPostRecoTools import setupEgammaPostRecoSeq

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

process.MessageLogger.cerr.FwkReport.reportEvery = 5000

from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, '106X_mcRun3_2024_realistic_v4', '')     # 2024 MC
#process.GlobalTag = GlobalTag(process.GlobalTag, '106X_mcRun3_2023_realistic_v3', '')     # 2023 MC
#process.GlobalTag = GlobalTag(process.GlobalTag, '106X_mcRun3_2021_realistic_v3', '')     # 2021 MC
process.GlobalTag = GlobalTag(process.GlobalTag, '102X_upgrade2018_realistic_v15', '')     # 2018 MC

#process.GlobalTag = GlobalTag(process.GlobalTag, '102X_dataRun2_Sep2018Rereco_v1', '')     # 2018 data

#process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
#    ignoreTotal = cms.untracked.int32(1),
#    moduleMemorySummary = cms.untracked.bool(True),
#)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(2000) )

setupEgammaPostRecoSeq(process,
#                       era='2017-UL',
                       era='2018-Prompt',
                       phoIDModules=['RecoEgamma.PhotonIdentification.Identification.cutBasedPhotonID_Fall17_94X_V2_cff']
)  

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
                                #'/store/mc/Run3Summer19MiniAOD/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_14TeV_Pythia8/MINIAODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/130000/00DF0005-F507-2C4B-BF8B-C46342D7194E.root'
                                '/store/mc/RunIIAutumn18MiniAOD/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/80000/E7AE77A2-59DD-6C4B-AF91-8263DA41EFD8.root'
                                )
)


#                                    '/store/mc/Run3Summer19MiniAOD/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_14TeV_Pythia8/MINIAODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/50000/009129B2-0220-9A46-B52B-899F04A3370C.root'

#                                    '/store/mc/Run3Summer19MiniAOD/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_14TeV_Pythia8/MINIAODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v1/130000/01B67698-CB4E-C747-BD67-139C1177E86F.root'
#                                    ''
#                                    '/store/mc/Run3Summer19MiniAOD/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/MINIAODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/FE3A7D24-F46E-8744-B92B-F6115FD395A0.root'
#                                    '/store/mc/RunIIAutumn18MiniAOD/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/100000/701296C8-FBEE-EC4E-9C28-6101E8E302E8.root'
#                                    '/store/mc/Run3Summer19MiniAOD/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_14TeV_Pythia8/MINIAODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v1/270000/968165AE-7E35-9D4C-B751-09B747ED1576.root'
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/4B82E385-367D-B947-9207-A8C03E836D6F.root', #AODSIM 2024
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/270000/FE2EA85F-2F46-9B41-B6FF-E724174EE4CE.root',#2018 AOD
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/FFD71080-0F4A-1340-962F-D23AC2252C7C.root', #2023 AOD
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/FF3F1F82-05A1-5247-BF2D-10CC42EF827B.root',
#ttbar 2021
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/130000/FFAAB973-1618-0448-BC66-9A5B3982B782.root',
#data 2018
#                      '/store/data/Run2018A/EGamma/AOD/17Sep2018-v2/810000/FFEE3B45-775E-D443-9CC7-916C9F3A67BF.root'
                            #)
#                            )

process.demo = cms.EDAnalyzer('DemoAnalyzer',
       rhoLabel  = cms.InputTag("fixedGridRhoFastjetAll"),
#       electrons = cms.InputTag('gedGsfElectrons'),
       electrons = cms.InputTag('slimmedElectrons'),
#       EERecHitCollection = cms.InputTag("reducedEcalRecHitsEE"), #AOD
#       EBRecHitCollection = cms.InputTag("reducedEcalRecHitsEB"), #AOD
       EERecHitCollection = cms.InputTag("reducedEgamma","reducedEERecHits","PAT"), #miniAOD
       EBRecHitCollection = cms.InputTag("reducedEgamma","reducedEBRecHits","PAT"), #miniAOD
#       pileupCollection     = cms.InputTag("addPileupInfo"),
       pileupCollection     = cms.InputTag("slimmedAddPileupInfo"),
#       genParticleSrc       = cms.InputTag("genParticles"),
       genParticleSrc       = cms.InputTag("prunedGenParticles"),
       ootPhotons       = cms.InputTag("ootPhotons"),
#       Photons       = cms.InputTag("gedPhotons"),
       Photons       = cms.InputTag("slimmedPhotons"),
       RunEle_       = cms.bool(True),
       RunPho_       = cms.bool(False),

                              )
process.TFileService = cms.Service("TFileService", fileName = cms.string('testEle.root'))

process.p = cms.Path(process.egammaPostRecoSeq * process.demo)
