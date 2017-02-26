#!/bin/bash
DIR=JOBS14_pseudo
VER=V22
COMMAND2="../addjobs.py"
#COMMAND="../resubmit.py R"
#COMMAND=""
#COMMAND="../resubmitallmissing.py"
#cd ${DIR}_central_${VER}
#../addjobs.py
#cd ..
WORKDIR=$PWD

BKG="bkg bkgl bkgh "
EX="central jetm1sig jetp1sig jetresp jetresm metm1sig metp1sig btagdown btagup ltagdown ltagup pileupup pileupdown "
VAR="topdown topup trapdown trapup ttptdown ttptup "
THEO="hddown hdup fsdown fsup rsup rsdown "
OTHER="fsrdownjetm1 fsrdownjetm05 fsrdownjetp05 fsrdownjetp1 fsrupjetm1 fsrupjetm05 fsrupjetp05 fsrupjetp1 jetm05sig jetp05sig "

ALL=$BKG$EX$VAR$THEO$OTHER

for N in $ALL; do
echo $N
cd ${DIR}_${N}_${VER}
../addjobs.py
cd $WORKDIR
done


