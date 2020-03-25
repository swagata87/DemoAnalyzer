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

process.MessageLogger.cerr.FwkReport.reportEvery = 5000

from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, '106X_mcRun3_2024_realistic_v4', '')     # 2024 MC
process.GlobalTag = GlobalTag(process.GlobalTag, '106X_mcRun3_2023_realistic_v3', '')     # 2023 MC
#process.GlobalTag = GlobalTag(process.GlobalTag, '106X_mcRun3_2021_realistic_v3', '')     # 2021 MC
#process.GlobalTag = GlobalTag(process.GlobalTag, '102X_upgrade2018_realistic_v15', '')     # 2018 MC

#process.GlobalTag = GlobalTag(process.GlobalTag, '102X_dataRun2_Sep2018Rereco_v1', '')     # 2018 data

#process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
#    ignoreTotal = cms.untracked.int32(1),
#    moduleMemorySummary = cms.untracked.bool(True),
#)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
                                fileNames = cms.untracked.vstring(
                                    '/store/mc/RunIIAutumn18MiniAOD/QCD_Pt-15to7000_TuneCP5_Flat_13TeV_pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15_ext1-v1/110000/FF7E6F76-76B3-2345-840B-073E02E94CC5.root'
#                                    '/store/mc/RunIIAutumn18MiniAOD/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/100000/701296C8-FBEE-EC4E-9C28-6101E8E302E8.root'
#                                    '/store/mc/Run3Summer19MiniAOD/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_14TeV_Pythia8/MINIAODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/50000/E65C97CA-5D68-6541-899E-FB1817AAE8FC.root'
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/4B82E385-367D-B947-9207-A8C03E836D6F.root', #AODSIM 2024
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/4B82D862-1E4E-2447-8798-479E52D96373.root',
             #'/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/FD0BE6B3-105C-4B46-856E-8E75903B25BD.root',
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/FC70F977-60BE-DD49-A0AD-1A1C9DD1FC88.root',
             #'/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/FC59F2EB-5398-654A-80BA-EC07E47F96E4.root',
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/2C277334-7B6F-B34A-AF76-7C7EA6436E51.root',
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/2E3D064E-E7BA-E947-A8C0-F923EF558C74.root',
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/3171AAC4-929A-9940-8CCE-5436C93B09B1.root',
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/31C34317-54B4-C542-BDD2-725F520AD99D.root',
#             '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/327D45A3-A9DE-B641-B68E-A856B58F97A1.root'
#
#
#2018
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/270000/FE2EA85F-2F46-9B41-B6FF-E724174EE4CE.root',#2018 AOD
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/120001/72DDC91F-6BC8-D343-A44C-6D537B8547FC.root',
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/120001/76FA30CA-F518-ED4D-8AA4-AD2D43E74742.root',
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/120001/77299BB6-3845-E246-B8BE-22A4D464B5EA.root',
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/120001/7A836983-300B-CD4D-8765-EFC6496BA19C.root',
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/270000/F7081D33-4A27-A747-8EC5-456347EFCC5B.root',
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/270000/EF5F6A2B-D0F6-F24D-8C4D-75CA685B4717.root',
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/270000/EB92479B-8BC9-F84F-A53C-F956EB116B16.root'
#
#2023
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/FFD71080-0F4A-1340-962F-D23AC2252C7C.root', #2023 AOD
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/DE8D397F-BC95-4546-A75C-4ABCAAEF312B.root',
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/DEE779FF-58CF-1549-9998-5C0B977B484F.root',
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/DF106A6B-F79C-604F-803A-3AC0B943E48C.root',
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/DF1555B1-2759-774B-AB6A-41F634BC4249.root',
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/DEC3582C-898A-FE46-A4F8-406458571104.root',
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/FEC0C010-7842-1840-9631-D4BD5D4BFB8F.root',
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/FB52F145-FD45-154E-AE97-64922112A127.root'
#
#2021
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/FF3F1F82-05A1-5247-BF2D-10CC42EF827B.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/DE7689B8-0271-A844-B24D-A9A842DB07FE.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/DF62A0BD-0D6C-1E43-8B98-FC720604AB7F.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/F27584A0-93BA-A549-9233-F121DE8B987A.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/E040E1D7-5ADD-EE49-923F-FF232F91A4A6.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/FFA6A719-AD74-1142-A198-B156CA209F64.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/FEDAEDC2-5BD7-D940-8007-74BA138E6DA5.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/FE9571BD-5EDF-4640-814B-97C8991C29B0.root'
#
#ttbar 2021
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/130000/FFAAB973-1618-0448-BC66-9A5B3982B782.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/130000/FF5B2ED5-5666-EE46-9931-C798D499CD41.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/130000/FF3F01D0-E987-8E46-AA2E-194FF05F321A.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/130000/FE457F3E-5B26-5A47-A1A3-446D6E67A8D1.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/130000/FD57C4BE-A2BD-2F4F-B98F-D62DB3CA4582.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/130000/FCDDB225-D06F-DC4D-A78E-B2334067DE9F.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/130000/FC9F444E-36CE-5844-AC7C-5299778DF5FA.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/130000/FC426CBF-E4EE-A24A-9373-F0FB1F9CBB62.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/130000/FBC95308-64F4-7347-8EB7-3F7EB8F3311C.root'
#ttbar 2023
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/270000/FD9E64EB-DD92-E749-9CFE-CE533589FF45.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/270000/FC3B656E-4940-A243-A55C-C170CC987C0C.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/270000/FB37F697-DFA6-2240-AC75-2C484A41D5E3.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/270000/F8979FD8-855F-6545-BCF1-8C711DDDB7CF.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/270000/FB226979-B563-E14D-9905-D2C46F645474.root'
#ttbar 2024
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/0282C29D-BFFC-9F47-AA7F-A14B338540DC.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/FA798B45-239F-5E47-8A62-37492AB59C92.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/F6C1C26C-88E4-1F40-B30C-518F998E87EF.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/F5CFADE7-8E1C-3943-A4DE-37F057FEEDF3.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/F1F1F908-D1D2-B948-B103-63FC3E24F0D3.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/F1D2D566-33E6-184F-8D2C-9B542C116ADC.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/F10025D6-879B-5344-B57A-A23DE3A6D63D.root',
#                 '/store/mc/Run3Summer19DRPremix/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/AODSIM/2024Scenario_106X_mcRun3_2024_realistic_v4-v2/260000/F0EEA87A-CBB8-7044-9163-81341A10C344.root'                 
#ttbar 2018
#                  '/store/mc/RunIIAutumn18DRPremix/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/80002/FFCFF097-1022-B34B-9DF6-88ACBEF04C4E.root',
#                  '/store/mc/RunIIAutumn18DRPremix/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/80002/FF144AC0-B92E-2E46-B3F0-5EFCC40DE3A2.root'
#
#qcd 2023
#                   '/store/mc/Run3Summer19DR/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/AODSIM/106X_mcRun3_2023_realistic_v3-v2/130000/0C401890-FA53-314A-81D4-3722E1ED42B8.root',
#                   '/store/mc/Run3Summer19DR/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/AODSIM/106X_mcRun3_2023_realistic_v3-v2/130000/D577EEF4-651D-6A46-8C56-618EE0637823.root',
#                   '/store/mc/Run3Summer19DR/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/AODSIM/106X_mcRun3_2023_realistic_v3-v2/130000/D2DD2466-17B4-4F43-98AC-CFAE0CE13EE1.root',
#                   '/store/mc/Run3Summer19DR/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/AODSIM/106X_mcRun3_2023_realistic_v3-v2/130000/D2B4E15D-BDC6-2541-A6C9-70FF612E4744.root',
#                   '/store/mc/Run3Summer19DR/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/AODSIM/106X_mcRun3_2023_realistic_v3-v2/130000/D03583CC-469F-514E-8D24-82619D0F1C3F.root'
#qcd 2024
#                    '/store/mc/Run3Summer19DR/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/AODSIM/106X_mcRun3_2024_realistic_v4-v2/260000/F9648BFF-87B3-F14A-855C-D27B45E1E8A8.root',
#                    '/store/mc/Run3Summer19DR/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/AODSIM/106X_mcRun3_2024_realistic_v4-v2/260000/DF02971F-1550-B543-9776-431A5D1D102C.root',
#                    '/store/mc/Run3Summer19DR/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/AODSIM/106X_mcRun3_2024_realistic_v4-v2/260000/DD0C9F6B-9E39-534A-9090-FCD24FEDFB0D.root',
#                    '/store/mc/Run3Summer19DR/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/AODSIM/106X_mcRun3_2024_realistic_v4-v2/260000/D8654C10-2098-0E49-A849-EAE16D322DA7.root',
#                    '/store/mc/Run3Summer19DR/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/AODSIM/106X_mcRun3_2024_realistic_v4-v2/260000/D4B1FB75-7C74-624E-976B-11D223A216BA.root',
#                    '/store/mc/Run3Summer19DR/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/AODSIM/106X_mcRun3_2024_realistic_v4-v2/260000/D37962E8-B35E-E641-90B3-0C88707046C0.root'
#data 2018
#                      '/store/data/Run2018A/EGamma/AOD/17Sep2018-v2/810000/FFEE3B45-775E-D443-9CC7-916C9F3A67BF.root'
#                     '/store/data/Run2018D/EGamma/AOD/PromptReco-v2/000/321/457/00000/DEE4367C-75A7-E811-A0AD-02163E019F53.root'
#                      '/store/data/Run2018D/EGamma/AOD/PromptReco-v2/000/320/804/00000/74C9E64F-3599-E811-B1D0-02163E019EC2.root'
#Gjet
#                      '/store/mc/Run3Summer19DRPremix/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_14TeV_Pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v1/270002/FFFFCB4B-3AF1-A84D-810B-F281E56E6FF2.root', #2023
#                      '/store/mc/Run3Summer19DRPremix/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_14TeV_Pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v1/260000/81CC98A1-B20B-814D-8687-2AD27C2EF019.root',
#                      '/store/mc/Run3Summer19DRPremix/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_14TeV_Pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v1/260000/80A10012-7693-3D47-963D-E60C8CC7C0D9.root',
#                      '/store/mc/Run3Summer19DRPremix/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_14TeV_Pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v1/260000/7B97329D-CB46-2F40-AC2C-3E9E0DD7E088.root',
#                      '/store/mc/Run3Summer19DRPremix/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_14TeV_Pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v1/260000/797E9558-D103-7949-9721-72AAFBAD4E49.root'
#                       '/store/mc/Run3Summer19DRPremix/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_14TeV_Pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v1/50001/554AB958-6644-5644-8E59-16B6FC431051.root' #2021
                )
                            )

process.demo = cms.EDAnalyzer('DemoAnalyzer',
#       tracks = cms.untracked.InputTag('generalTracks'),
#       electrons = cms.InputTag('gedGsfElectrons'),
       electrons = cms.InputTag('slimmedElectrons'),
       #EBRecHitCollection = cms.InputTag("ecalRecHit","EcalRecHitsEB"), #RECO 
       #EERecHitCollection = cms.InputTag("ecalRecHit","EcalRecHitsEE"), #RECO
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
       RunEle_       = cms.bool(False),
       RunPho_       = cms.bool(True),

                              )
#process.TFileService = cms.Service("TFileService", fileName = cms.string('RedefNtup_AOD_pho.root'))
#process.TFileService = cms.Service("TFileService", fileName = cms.string('RedefNtup_AOD.root'))
process.TFileService = cms.Service("TFileService", fileName = cms.string('test.root'))

process.p = cms.Path(process.demo)
