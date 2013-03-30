#!/usr/bin/python

import sys
import os

func_dict = {}
if __name__ == '__main__':
	func_length = 0
	i = 0
	for root, dirs, files in os.walk(os.getcwd()):
		#print root, dirs, files 	#print source
		for filename in files:
			f2 = root + "/" + filename
			#print f2
			i = 0
			func_length = 0
			file_extension = filename[filename.rfind('.'):]
			#print file_extension
			if file_extension != ".h" and file_extension != '.c' and file_extension != ".cc" and file_extension != ".cpp":
				continue
			for line in file(f2):
				if line[0] == "{":
					func_name = last_line
					func_line = i
					func_length = 1
				elif line[0] == '}':	
					func_dict[func_length] = func_dict.get(func_length, 0) + 1
					if func_length >= 64:
						print ("fn_length:%4d"%func_length), ("%32s:%4d"%(filename, func_line), func_name)
					func_length = 0	
				elif func_length > 0:
					func_length = func_length + 1
				i = i + 1	
				last_line = line
	
	for l in sorted(func_dict):
		print "fn_length:%4d, fun_num:%d"%(l, func_dict[l])
	tl = 0.
	fnn = 0
	for l in sorted(func_dict):
		tl = tl + func_dict[l]*l
		fnn = fnn + func_dict[l]
	#print tl, fnn
	if fnn != 0:
		print "avaerage_fn_length:", tl / fnn
			
			
