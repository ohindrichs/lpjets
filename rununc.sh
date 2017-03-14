#!/bin/bash
JOBDIR=JOB14
TYP=JOBS14_pseudo
VER=V35

cp ttbarxsec.cfg ttbarxsec.tmp

rm inputs/$JOBDIR/*txt
cp inputs/$JOBDIR/backup/*txt inputs/$JOBDIR
./updateconfig.py PDFTEST 1
./jobsub ${TYP}_central_${VER} ttbarxsec.exe ttbarxsec.cfg
#BKG
rm inputs/$JOBDIR/*txt
cp inputs/$JOBDIR/backupsmall/*txt inputs/$JOBDIR
./updateconfig.py nbtag bkg
./jobsub ${TYP}_bkg_${VER} ttbarxsec.exe ttbarxsec.cfg

#./updateconfig.py ELECTRONS 0
#./jobsub ${TYP}_MU_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py MUONS 0
#./jobsub ${TYP}_EL_${VER} ttbarxsec.exe ttbarxsec.cfg

rm inputs/$JOBDIR/*txt
cp inputs/$JOBDIR/backup/DATA*.txt inputs/$JOBDIR
./updateconfig.py nbtag bkgl
./jobsub ${TYP}_bkgl_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py nbtag bkgh
./jobsub ${TYP}_bkgh_${VER} ttbarxsec.exe ttbarxsec.cfg
#UNC
rm inputs/$JOBDIR/*txt
cp inputs/$JOBDIR/backup/tt_PowhegP8.txt inputs/$JOBDIR
./updateconfig.py sigmajet -1 sigmajetwj -1
./jobsub ${TYP}_jetm1sig_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet -0.5 sigmajetwj -0.5
./jobsub ${TYP}_jetm05sig_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet 0.5 sigmajetwj 0.5
./jobsub ${TYP}_jetp05sig_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet 1 sigmajetwj 1
./jobsub ${TYP}_jetp1sig_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py jetres -1
./jobsub ${TYP}_jetresm_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py jetres 1
./jobsub ${TYP}_jetresp_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmamet -1
./jobsub ${TYP}_metm1sig_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmamet 1
./jobsub ${TYP}_metp1sig_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py topptweight -1
./jobsub ${TYP}_topdown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py topptweight 1
./jobsub ${TYP}_topup_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py toprapweight -1
./jobsub ${TYP}_trapdown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py toprapweight 1
./jobsub ${TYP}_trapup_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py ttptweight -1
./jobsub ${TYP}_ttptdown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py ttptweight 1
./jobsub ${TYP}_ttptup_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py renscale -1
./jobsub ${TYP}_rsdown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py renscale 1
./jobsub ${TYP}_rsup_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py facscale -1
./jobsub ${TYP}_fsdown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py facscale 1
./jobsub ${TYP}_fsup_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py btagunc -1
./jobsub ${TYP}_btagdown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py btagunc 1
./jobsub ${TYP}_btagup_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py ltagunc -1
./jobsub ${TYP}_ltagdown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py ltagunc 1
./jobsub ${TYP}_ltagup_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py pileupunc -1
./jobsub ${TYP}_pileupdown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py pileupunc 1
./jobsub ${TYP}_pileupup_${VER} ttbarxsec.exe ttbarxsec.cfg
rm inputs/$JOBDIR/*txt
cp inputs/$JOBDIR/backup/tt_fsrup_PowhegP8.txt inputs/$JOBDIR
./updateconfig.py sigmajet -1 sigmajetwj -1
./jobsub ${TYP}_fsrupjetm1_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet -0.5 sigmajetwj -0.5
./jobsub ${TYP}_fsrupjetm05_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet 0.5 sigmajetwj 0.5
./jobsub ${TYP}_fsrupjetp05_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet 1 sigmajetwj 1
./jobsub ${TYP}_fsrupjetp1_${VER} ttbarxsec.exe ttbarxsec.cfg
rm inputs/$JOBDIR/*txt
cp inputs/$JOBDIR/backup/tt_fsrdown_PowhegP8.txt inputs/$JOBDIR
./updateconfig.py sigmajet -1 sigmajetwj -1
./jobsub ${TYP}_fsrdownjetm1_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet -0.5 sigmajetwj -0.5
./jobsub ${TYP}_fsrdownjetm05_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet 0.5 sigmajetwj 0.5
./jobsub ${TYP}_fsrdownjetp05_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet 1 sigmajetwj 1
./jobsub ${TYP}_fsrdownjetp1_${VER} ttbarxsec.exe ttbarxsec.cfg
#rm inputs/$JOBDIR/*txt
#cp inputs/$JOBDIR/backup/tt_PowhegP8.txt inputs/$JOBDIR
#cp inputs/$JOBDIR/backup/tt_fsrdown_PowhegP8.txt inputs/$JOBDIR
#cp inputs/$JOBDIR/backup/tt_fsrup_PowhegP8.txt inputs/$JOBDIR
##CC
#./updateconfig.py sigmajet 0 sigmajetwj -0.19 
#./jobsub ${TYP}_CC_${VER} ttbarxsec.exe ttbarxsec.cfg
##PP
#./updateconfig.py sigmajet 0.8 sigmajetwj 0.45
#./jobsub ${TYP}_PP_${VER} ttbarxsec.exe ttbarxsec.cfg
##MM
#./updateconfig.py sigmajet -0.8 sigmajetwj -0.67 
#./jobsub ${TYP}_MM_${VER} ttbarxsec.exe ttbarxsec.cfg
##PM
#./updateconfig.py sigmajet -0.6 sigmajetwj -0.31 
#./jobsub ${TYP}_PM_${VER} ttbarxsec.exe ttbarxsec.cfg
##MP
#./updateconfig.py sigmajet 0.6 sigmajetwj 0.01
#./jobsub ${TYP}_MP_${VER} ttbarxsec.exe ttbarxsec.cfg
mv ttbarxsec.tmp ttbarxsec.cfg
