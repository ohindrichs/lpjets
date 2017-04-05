#!/bin/bash
JOBDIR=JOB14
TYP=JOBS14_btagging
VER=V5

cp ttbarxsec.cfg ttbarxsec.tmp

rm inputs/$JOBDIR/*txt
cp inputs/$JOBDIR/backup/*txt inputs/$JOBDIR
./updateconfig.py PDFTEST 0
./jobsub ${TYP}_central_${VER} ttbarxsec.exe ttbarxsec.cfg
#BKG
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
./updateconfig.py pileupunc -1
./jobsub ${TYP}_pileupdown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py pileupunc 1
./jobsub ${TYP}_pileupup_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py bsplitting 0.75
./jobsub ${TYP}_bsplittingdown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py bsplitting 1.25
./jobsub ${TYP}_bsplittingup_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py csplitting 0.85
./jobsub ${TYP}_csplittingdown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py csplitting 1.15
./jobsub ${TYP}_csplittingup_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py bfrag -1
./jobsub ${TYP}_bfragdown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py bfrag 1
./jobsub ${TYP}_bfragup_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py bdecay -1
./jobsub ${TYP}_bdecaydown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py bdecay 1
./jobsub ${TYP}_bdecayup_${VER} ttbarxsec.exe ttbarxsec.cfg
mv ttbarxsec.tmp ttbarxsec.cfg
