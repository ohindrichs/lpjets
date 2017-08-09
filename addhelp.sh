#!/bin/bash
DIR=JOBS15_parton
VER=V11
WORKDIR=$PWD

EX="central jetm1 jetp1 jetold jetm1sigma jetp1sigma jetresp1 jetresm1 metm1 metp1 lepm1 lepp1 btagdown btagup ltagdown ltagup pileupup pileupdown "
VAR="topdown topup trapdown trapup ttptdown ttptup jetptup jetptdown "
THEO="fsdown fsup rsup rsdown fsrsup fsrsdown bfragdown bfragup bdecaydown bdecayup bsplittingup bsplittingdown csplittingup csplittingdown "
BKG="bkg bkgl bkgh "
#OTHER="fsrdownjetm1 fsrdownjetm05 fsrdownjetp05 fsrdownjetp1 fsrupjetm1 fsrupjetm05 fsrupjetp05 fsrupjetp1 jetm05sig jetp05sig "
#VARJET="jetm1 jetm05 jetp05 jetp1"
PRE="precentral prebkg prejetm1 prejetm05 prejetp05 prejetp1 prewjetm1 prewjetm05 prewjetp05 prewjetp1 "

ALL=$BKG$EX$VAR$THEO$OTHER
#ALL=$PRE

for N in $ALL; do
echo $N
cd ${DIR}_${N}_${VER}
../addjobs.py
#../resubmitallmissing.py
cd $WORKDIR
done


