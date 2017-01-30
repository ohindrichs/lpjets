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


tdir = sys.argv[1]

files = os.listdir(tdir)

files = [f for f in files if '.stdout' in f]

lumis = []
for f in files:
	fd = open(os.path.join(tdir, f))
	for l in fd:
		if 'SYNC' in l:
			l = l.split(':')
			lumis.append(l[1]+':'+l[2])



print len(lumis)

lumis = set(lumis)
print len(lumis)

mylumi = 0.

for l in lumis:
	if l in lumimap:
		mylumi += lumimap[l]
	else:
		print 'Not found:', l 

print len(lumimap)
print mylumi




