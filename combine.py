#!/usr/bin/python3

import csv

dup = {}
d = open("data.csv", "r")
csv = csv.reader(d, delimiter=',')
for r in csv:
	if(dup.get(r[0]) != None):
		dup[r[0]] += int(r[1])
	else:
		dup[r[0]] = int(r[1])

o = open("combined_data.csv", "w+")
for i in range(len(dup)):
	o.write(list(dup.items())[i][0] + "," + str(list(dup.items())[i][1]))
	o.write("\n")
o.close()
	
