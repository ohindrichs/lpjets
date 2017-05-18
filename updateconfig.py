#!/usr/bin/env python2
import sys, os


print sys.argv

updates = {}

for i in range(0, (len(sys.argv)-1)/2):
	updates[sys.argv[2*i+1]] = sys.argv[2*i+2]


print updates


inf = open('ttbarxsec.tmp', 'r')
outf = open('ttbarxsec.cfg', 'w')

data = inf.read()
data = data.split('\n')
for l in data:
	l = l.split('#')[0]
	if '=' in l:
		val = l.split('=')[0].strip()
		if val in updates:
			outf.write(val + ' = ' + updates[val] + '\n')
		else:
			outf.write(l+'\n')


inf.close()
outf.close()
