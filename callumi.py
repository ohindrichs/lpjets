from ROOT import TFile, TTree
import sys, os

lfile = open('lumi.cvs')

lumimap = {}
lumi = 0.
for l in lfile:
	if l[0] == '#': continue
	#print l
	l = l.split(',')
	run = l[0].split(':')[0]
	ls = l[1].split(':')[0]
	lumimap[run+':'+ls] = float(l[6])
	lumi += float(l[6])

print lumi

tfile = sys.argv[1]

tf = TFile(tfile)

tr = tf.Get('runls')


lumis = []
for n in range(0, tr.GetEntries()):
	tr.GetEntry(n)
	lumis.append(str(tr.run)+':'+str(tr.lumisec))
	
print len(lumis)

lumis = set(lumis)
print len(lumis)

mylumi = 0.
mislumi = 0.

for l,v in lumimap.iteritems():
	if l not in lumis:
		print 'Not in Data'
		mislumi += v

for l in lumis:
	if l in lumimap:
		mylumi += lumimap[l]
	else:
		print 'Not in CVS:', l 

print len(lumimap)
print mylumi, mislumi


