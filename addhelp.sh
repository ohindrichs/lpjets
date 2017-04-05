#!/bin/bash
DIR=JOBS14_pseudo
VER=V73
COMMAND2="../addjobs.py"
#COMMAND="../resubmit.py R"
#COMMAND=""
#COMMAND="../resubmitallmissing.py"
#cd ${DIR}_central_${VER}
#../addjobs.py
#cd ..
WORKDIR=$PWD

BKG="bkg bkgl bkgh "
EX="central jetm1 jetp1 jetresp1 jetresm1 metm1 metp1 btagdown btagup ltagdown ltagup pileupup pileupdown "
VAR="topdown topup trapdown trapup ttptdown ttptup "
THEO="hddown hdup fsdown fsup rsup rsdown bfragdown bfragup bdecaydown bdecayup bsplittingup bsplittingdown csplittingup csplittingdown "
#OTHER="fsrdownjetm1 fsrdownjetm05 fsrdownjetp05 fsrdownjetp1 fsrupjetm1 fsrupjetm05 fsrupjetp05 fsrupjetp1 jetm05sig jetp05sig "
#VARJET="jetm1 jetm05 jetp05 jetp1"
PRE="precentral prebkg prejetm1 prejetm05 prejetp05 prejetp1"

ALL=$BKG$EX$VAR$THEO$OTHER
#ALL=$PRE

for N in $ALL; do
echo $N
cd ${DIR}_${N}_${VER}
../addjobs.py
#../resubmitallmissing.py
cd $WORKDIR
done


