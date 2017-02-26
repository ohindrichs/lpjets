import os, sys, subprocess
from ROOT import TFile, TTree, TH1D

def getweigthinfo(files):
	totnum = 0.
	totnumtrue = 0.
	totnumtrueW = 0.
	goodfiles = []
	for fname in files:
	#	p = subprocess.Popen(['ls', '-l', fname], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	#	info =  p.stderr.read()
	#	if 'cannot access' in info:
	#		print 'ERROR', fname
	#		continue

		#fname = fname.replace('/eos/uscms', 'root://cmseos.fnal.gov/')
		tf = TFile(fname)
		if tf.IsZombie() == True:
			print "Zombie file: " + fname
			continue
		goodfiles.append(fname)
		tree = tf.Get('Events')
		num = tree.GetEntries()
		totnum += num
		if 'MC' in files[0]:
			hist = tf.Get('PUDistribution')
			histW = tf.Get('PUDistribution_w')
			numtrue = hist.Integral()
			numtrueW = histW.Integral()
			totnumtrue += numtrue
			totnumtrueW += numtrueW
	return totnumtrueW, totnumtrue, totnum, goodfiles

def collectfiles(dirname):
	content = os.listdir(dirname)
	files = [c for c in content if c.startswith('ur_') and c.endswith('.root')]
	if(len(files) != 0):
		nums = [int(n.split('ur_')[1].split('.root')[0]) for n in files]
		nums = sorted(nums)
		missing = []
		c = 1
		n = 0
		while n < len(nums):
			if c != nums[n]:
				n-=1
				missing.append(c)
			n+=1
			c+=1
		print dirname, missing
		files = [os.path.join(dirname, c) for c in files]
		return files

	files = []
	for c in content:
		if c == 'failed':
			continue
		newpath = os.path.join(dirname, c)
		if os.path.isdir(newpath) == True:
			files += collectfiles(newpath)

	return files	

setnames = {}

setnames['DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8'] = 'DYJets.txt'
#setnames['WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8'] = 'WJets.txt'
setnames['WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8'] = 'WJets.txt'
setnames['QCD_Pt-30to50_EMEnriched_TuneCUETP8M1_13TeV_pythia8'] = 'QCDEM50.txt'
setnames['QCD_Pt-50to80_EMEnriched_TuneCUETP8M1_13TeV_pythia8'] = 'QCDEM80.txt'
setnames['QCD_Pt-80to120_EMEnriched_TuneCUETP8M1_13TeV_pythia8'] = 'QCDEM120.txt'
setnames['QCD_Pt-120to170_EMEnriched_TuneCUETP8M1_13TeV_pythia8'] = 'QCDEM170.txt'
setnames['QCD_Pt-170to300_EMEnriched_TuneCUETP8M1_13TeV_pythia8'] = 'QCDEM300.txt'
setnames['QCD_Pt-300toInf_EMEnriched_TuneCUETP8M1_13TeV_pythia8'] = 'QCDEMInf.txt'
setnames['QCD_Pt-30to50_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8'] = 'QCDMu50.txt'
setnames['QCD_Pt-50to80_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8'] = 'QCDMu80.txt'
setnames['QCD_Pt-80to120_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8'] = 'QCDMu120.txt'
setnames['QCD_Pt-120to170_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8'] = 'QCDMu170.txt'
setnames['QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8'] = 'QCDMu300.txt'
setnames['QCD_Pt-300to470_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8'] = 'QCDMu470.txt'
setnames['QCD_Pt-470to600_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8'] = 'QCDMu600.txt'
setnames['QCD_Pt-600to800_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8'] = 'QCDMu800.txt'
setnames['QCD_Pt-800to1000_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8'] = 'QCDMu1000.txt'
setnames['QCD_Pt-1000toInf_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8'] = 'QCDMuInf.txt'
setnames['ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1'] = 'STs.txt'
#setnames['ST_t-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1'] = 'STt.txt'
setnames['ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1'] = 'STt_topbar.txt'
setnames['ST_t-channel_top_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1'] = 'STt_top.txt'
setnames['ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1'] = 'Wtbar.txt'
setnames['ST_tW_top_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1'] = 'Wt.txt'
#setnames['TT_TuneCUETP8M1_13TeV-powheg-pythia8'] = 'tt_PowhegP8.txt'
setnames['TT_TuneCUETP8M2T4_13TeV-powheg-pythia8'] = 'tt_PowhegP8.txt'
setnames['TT_TuneCUETP8M1_13TeV-powheg-scaledown-pythia8'] = 'tt_scaledown_PowhegP8.txt'
setnames['TT_TuneCUETP8M1_13TeV-powheg-scaleup-pythia8'] = 'tt_scaleup_PowhegP8.txt'
setnames['TT_TuneCUETP8M2T4_13TeV-powheg-isrdown-pythia8'] = 'tt_isrdown_PowhegP8.txt'
setnames['TT_TuneCUETP8M2T4_13TeV-powheg-isrup-pythia8'] = 'tt_isrup_PowhegP8.txt'
setnames['TT_TuneCUETP8M2T4_13TeV-powheg-fsrdown-pythia8'] = 'tt_fsrdown_PowhegP8.txt'
setnames['TT_TuneCUETP8M2T4_13TeV-powheg-fsrup-pythia8'] = 'tt_fsrup_PowhegP8.txt'
setnames['TT_TuneCUETP8M2T4_mtop1695_13TeV-powheg-pythia8'] = 'tt_mtop1695_PowhegP8.txt'
setnames['TT_TuneCUETP8M2T4_mtop1755_13TeV-powheg-pythia8'] = 'tt_mtop1755_PowhegP8.txt'
#setnames['TT_TuneCUETP8M1_mtop1715_13TeV-powheg-pythia8'] = 'tt_mtop1695_PowhegP8.txt'
#setnames['TT_TuneCUETP8M1_mtop1735_13TeV-powheg-pythia8'] = 'tt_mtop1755_PowhegP8.txt'
setnames['TT_TuneEE5C_13TeV-powheg-herwigpp'] = 'tt_PowhegHpp.txt'
setnames['TT_TuneEE5C_13TeV-amcatnlo-herwigpp'] = 'tt_MCatNLOHpp.txt'
setnames['TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8'] = 'tt_MCatNLO.txt'
setnames['TTJets_TuneCUETP8M2T4_13TeV-amcatnloFXFX-pythia8'] = 'tt_aMCatNLO.txt'
setnames['TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8'] = 'tt_Madgraph.txt'
setnames['SingleMuon'] = 'DATAMU.txt'
setnames['SingleElectron'] = 'DATAEL.txt'
setnames['TT_TuneCUETP8M2T4down_13TeV-powheg-pythia8'] = 'tt_tunedown_PowhegP8.txt'
setnames['TT_TuneCUETP8M2T4up_13TeV-powheg-pythia8'] = 'tt_tuneup_PowhegP8.txt'
		

dirname = sys.argv[1]


dirs = os.listdir(dirname)

table = ''
for d in dirs:
	newpath = os.path.join(dirname, d)
	if os.path.isdir(newpath) == False: continue
	if d not in setnames:
		print 'No short name for', d
		continue
	files = collectfiles(newpath)
	nfiles = len(files)
	print d, len(files)
	w, uw, ntree, goodfiles = getweigthinfo(files)
	print setnames[d].replace('.txt', ':'), len(goodfiles),nfiles, ntree, uw
	print setnames[d].replace('.txt', '_W = '), w	
	newline= d.replace('_', '\_') + ' & ' + str(round(uw/1.E6, 2)) + '(' + str(round(w/1.E6,2)) + ') & \\\\'
	table += newline + '\n'

	goodfiles = [f.replace('/eos/uscms', 'root://cmseos.fnal.gov/') for f in goodfiles]	
	f = open(setnames[d], 'w')
	for n in goodfiles:
		f.write(n+'\n')

	f.close()
	

print table


