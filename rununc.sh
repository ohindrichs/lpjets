#!/bin/bash
JOBDIR=JOB15
TYP=JOBS15_parton
VER=V11JECS

cp ttbarxsec.cfg ttbarxsec.tmp

#rm inputs/$JOBDIR/*txt
#cp inputs/$JOBDIR/backup/*txt inputs/$JOBDIR
#./updateconfig.py sigmajet 0 sigmajetwj 0
#./jobsub ${TYP}_precentral_${VER} ttbarxsec.exe ttbarxsec.cfg
#rm inputs/$JOBDIR/*txt
#cp inputs/$JOBDIR/backupsmall/*txt inputs/$JOBDIR
#./updateconfig.py nbtag bkg sigmajet 0 sigmajetwj 0
#./jobsub ${TYP}_prebkg_${VER} ttbarxsec.exe ttbarxsec.cfg
#rm inputs/$JOBDIR/*txt
#cp inputs/$JOBDIR/backup/tt_fsrup_PowhegP8.txt inputs/$JOBDIR
#cp inputs/$JOBDIR/backup/tt_fsrdown_PowhegP8.txt inputs/$JOBDIR
#cp inputs/$JOBDIR/backup/tt_PowhegP8.txt inputs/$JOBDIR
#./updateconfig.py sigmajet -1 sigmajetwj -1
#./jobsub ${TYP}_prejetm1_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet -0.5 sigmajetwj -0.5
#./jobsub ${TYP}_prejetm05_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet 0.5 sigmajetwj 0.5
#./jobsub ${TYP}_prejetp05_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet 1 sigmajetwj 1
#./jobsub ${TYP}_prejetp1_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet 0 sigmajetwj -1
#./jobsub ${TYP}_prewjetm1_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet 0 sigmajetwj -0.5
#./jobsub ${TYP}_prewjetm05_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet 0 sigmajetwj 0.5
#./jobsub ${TYP}_prewjetp05_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet 0 sigmajetwj 1
#./jobsub ${TYP}_prewjetp1_${VER} ttbarxsec.exe ttbarxsec.cfg

#rm inputs/$JOBDIR/*txt
#cp inputs/$JOBDIR/backup/*txt inputs/$JOBDIR
#./updateconfig.py sigmajet 0 scalejetwj 0
#./jobsub ${TYP}_precentral_${VER} ttbarxsec.exe ttbarxsec.cfg
#rm inputs/$JOBDIR/*txt
#cp inputs/$JOBDIR/backupsmall/*txt inputs/$JOBDIR
#./updateconfig.py nbtag bkg sigmajet 0 scalejetwj 0
#./jobsub ${TYP}_prebkg_${VER} ttbarxsec.exe ttbarxsec.cfg
#rm inputs/$JOBDIR/*txt
#cp inputs/$JOBDIR/backup/tt_fsrup_PowhegP8.txt inputs/$JOBDIR
#cp inputs/$JOBDIR/backup/tt_fsrdown_PowhegP8.txt inputs/$JOBDIR
#cp inputs/$JOBDIR/backup/tt_PowhegP8.txt inputs/$JOBDIR
#./updateconfig.py sigmajet 0 scalejetwj -0.01
#./jobsub ${TYP}_prewjetm1_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet 0 scalejetwj -0.005
#./jobsub ${TYP}_prewjetm05_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet 0 scalejetwj 0.005
#./jobsub ${TYP}_prewjetp05_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet 0 scalejetwj 0.01
#./jobsub ${TYP}_prewjetp1_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet -0.01 scalejetwj -0.01
#./jobsub ${TYP}_prejetm1_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet -0.005 scalejetwj -0.005
#./jobsub ${TYP}_prejetm05_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet 0.005 scalejetwj 0.005
#./jobsub ${TYP}_prejetp05_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmajet 0.01 scalejetwj 0.01
#./jobsub ${TYP}_prejetp1_${VER} ttbarxsec.exe ttbarxsec.cfg

#rm inputs/$JOBDIR/*txt
#cp inputs/$JOBDIR/backup/*txt inputs/$JOBDIR
#./updateconfig.py PDFTEST 1
#./jobsub ${TYP}_central_${VER} ttbarxsec.exe ttbarxsec.cfg
##BKG
#rm inputs/$JOBDIR/*txt
#cp inputs/$JOBDIR/backupsmall/*txt inputs/$JOBDIR
#./updateconfig.py nbtag bkg
#./jobsub ${TYP}_bkg_${VER} ttbarxsec.exe ttbarxsec.cfg
#rm inputs/$JOBDIR/*txt
#cp inputs/$JOBDIR/backup/DATA*.txt inputs/$JOBDIR
#./updateconfig.py nbtag bkgl
#./jobsub ${TYP}_bkgl_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py nbtag bkgh
#./jobsub ${TYP}_bkgh_${VER} ttbarxsec.exe ttbarxsec.cfg
##UNC
rm inputs/$JOBDIR/*txt
cp inputs/$JOBDIR/backup/tt_PowhegP8.txt inputs/$JOBDIR
JECSOURCES="AbsoluteStat AbsoluteScale AbsoluteMPFBias Fragmentation SinglePionECAL SinglePionHCAL TimePtEta RelativePtBB RelativePtEC1 RelativePtEC2 RelativeBal RelativeFSR RelativeStatFSR RelativeStatEC PileUpDataMC PileUpPtRef PileUpPtBB PileUpPtEC1 PileUpPtEC2"
for SOURCE in $JECSOURCES; do
./updateconfig.py sigmajet -1 sigmajetwj -1 jecuncertaintyb ${SOURCE} jecuncertaintyqcd ${SOURCE}
./jobsub ${TYP}_jecdown${SOURCE}_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet 1 sigmajetwj 1 jecuncertaintyb ${SOURCE} jecuncertaintyqcd ${SOURCE}
./jobsub ${TYP}_jecup${SOURCE}_${VER} ttbarxsec.exe ttbarxsec.cfg
done
./updateconfig.py sigmajet -1 sigmajetwj -1 jecuncertaintyb FlavorPureBottom jecuncertaintyqcd NONE
./jobsub ${TYP}_jecdownFlavorPureBottom_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet 1 sigmajetwj 1 jecuncertaintyb FlavorPureBottom jecuncertaintyqcd NONE
./jobsub ${TYP}_jecupFlavorPureBottom_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet -1 sigmajetwj -1 jecuncertaintyb NONE jecuncertaintyqcd FlavorQCD
./jobsub ${TYP}_jecdownFlavorQCD_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet 1 sigmajetwj 1 jecuncertaintyb NONE jecuncertaintyqcd FlavorQCD
./jobsub ${TYP}_jecupFlavorQCD_${VER} ttbarxsec.exe ttbarxsec.cfg

#./updateconfig.py sigmajet 1 sigmajetwj 1
#./jobsub ${TYP}_jetp1_${VER} ttbarxsec.exe ttbarxsec.cfg


##./updateconfig.py sigmajet -1 sigmajetwj -1
##./jobsub ${TYP}_jetm1sigma_${VER} ttbarxsec.exe ttbarxsec.cfg
##./updateconfig.py sigmajet 1 sigmajetwj 1
##./jobsub ${TYP}_jetp1sigma_${VER} ttbarxsec.exe ttbarxsec.cfg
##./updateconfig.py sigmajet 0 sigmajetwj 0
##./jobsub ${TYP}_jetold_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py jetres -1
#./jobsub ${TYP}_jetresm1_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py jetres 1
#./jobsub ${TYP}_jetresp1_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmamet -1
#./jobsub ${TYP}_metm1_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmamet 1
#./jobsub ${TYP}_metp1_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmalep -1
#./jobsub ${TYP}_lepm1_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py sigmalep 1
#./jobsub ${TYP}_lepp1_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py btagunc -1
#./jobsub ${TYP}_btagdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py btagunc 1
#./jobsub ${TYP}_btagup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py ltagunc -1
#./jobsub ${TYP}_ltagdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py ltagunc 1
#./jobsub ${TYP}_ltagup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py pileupunc -1
#./jobsub ${TYP}_pileupdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py pileupunc 1
#./jobsub ${TYP}_pileupup_${VER} ttbarxsec.exe ttbarxsec.cfg
#
#./updateconfig.py renscale -1
#./jobsub ${TYP}_rsdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py renscale 1
#./jobsub ${TYP}_rsup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py facscale -1
#./jobsub ${TYP}_fsdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py facscale 1
#./jobsub ${TYP}_fsup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py facscale -1 renscale -1
#./jobsub ${TYP}_fsrsdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py facscale 1 renscale 1
#./jobsub ${TYP}_fsrsup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py bfrag -1
#./jobsub ${TYP}_bfragdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py bfrag 1
#./jobsub ${TYP}_bfragup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py bdecay -1
#./jobsub ${TYP}_bdecaydown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py bdecay 1
#./jobsub ${TYP}_bdecayup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py bsplitting 0.75
#./jobsub ${TYP}_bsplittingdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py bsplitting 1.25
#./jobsub ${TYP}_bsplittingup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py csplitting 0.85
#./jobsub ${TYP}_csplittingdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py csplitting 1.15
#./jobsub ${TYP}_csplittingup_${VER} ttbarxsec.exe ttbarxsec.cfg
#
#./updateconfig.py topptweight -1
#./jobsub ${TYP}_topdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py topptweight 1
#./jobsub ${TYP}_topup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py toprapweight -1
#./jobsub ${TYP}_trapdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py toprapweight 1
#./jobsub ${TYP}_trapup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py ttptweight -1
#./jobsub ${TYP}_ttptdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py ttptweight 1
#./jobsub ${TYP}_ttptup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py jetptweight 1
#./jobsub ${TYP}_jetptup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py jetptweight -1
#./jobsub ${TYP}_jetptdown_${VER} ttbarxsec.exe ttbarxsec.cfg

mv ttbarxsec.tmp ttbarxsec.cfg
