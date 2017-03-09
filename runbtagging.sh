#!/bin/bash
JOBDIR=JOB14
TYP=JOBS14_btagging
VER=V2

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
./updateconfig.py sigmajet -1
./jobsub ${TYP}_jetm1sig_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmajet 1
./jobsub ${TYP}_jetp1sig_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py jetres -1
./jobsub ${TYP}_jetresm_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py jetres 1
./jobsub ${TYP}_jetresp_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmamet -1
./jobsub ${TYP}_metm1sig_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py sigmamet 1
./jobsub ${TYP}_metp1sig_${VER} ttbarxsec.exe ttbarxsec.cfg
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
#./updateconfig.py renscale -1
#./jobsub ${TYP}_rsdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py renscale 1
#./jobsub ${TYP}_rsup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py facscale -1
#./jobsub ${TYP}_fsdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py facscale 1
#./jobsub ${TYP}_fsup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py btagunc -1
#./jobsub ${TYP}_btagdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py btagunc 1
#./jobsub ${TYP}_btagup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py ltagunc -1
#./jobsub ${TYP}_ltagdown_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py ltagunc 1
#./jobsub ${TYP}_ltagup_${VER} ttbarxsec.exe ttbarxsec.cfg
#./updateconfig.py pileupunc -1
./jobsub ${TYP}_pileupdown_${VER} ttbarxsec.exe ttbarxsec.cfg
./updateconfig.py pileupunc 1
./jobsub ${TYP}_pileupup_${VER} ttbarxsec.exe ttbarxsec.cfg
mv ttbarxsec.tmp ttbarxsec.cfg
