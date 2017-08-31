#!/bin/bash
DIR=JOBS14_btagging
VER=V5
COMMAND="../addjobs.py"

DIRS="bkgh bkgl central jetm1sig jetp1sig jetresm jetresp metm1sig metp1sig pileupdown pileupup bsplittingdown bsplittingup csplittingdown csplittingup bfragdown bfragup bdecayup bdecaydown"

BDIR=$PWD
for D in $DIRS ; do
echo $D
cd ${DIR}"_"${D}"_"${VER}
$COMMAND
cd $BDIR
done

