#!/usr/bin/python

import sys
import os

func_dict = {}
func_list = []
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
					func_list.append(func_name)
				last_line = line
	last_func = ""
	dup_cnt = 0
	for func in sorted(func_list):
		if last_func != func:
			dup_cnt = 1
		else:
			dup_cnt = dup_cnt + 1
					
		if dup_cnt == 2:
			print last_func
		if dup_cnt >= 2:
			print func
		last_func = func
			
			
