# -*- coding: utf-8 -*-
'''
Created on 2014-09-23

@author: caojin

@reference http://www.cnblogs.com/zhengyuxin/articles/1938300.html
'''

def get_num_in_pos(num, pos):
	'''
	'''
	temp = 1
	
	for i in range(0, pos - 1):
		temp = temp * 10
		
	return (num / temp) % 10
	
def radix_sort(num_array):
	'''
	'''
	bucket = []
	for i in range(0, 10):
		bucket.append([0])
		
	print bucket
	
	for pos in range(1, 10):
		for i in range(0, len(num_array)):
			num = get_num_in_pos(num_array[i], pos)
			bucket[num][0] += 1
			bucket[num].append(num_array[i])
			
		print bucket
			
		array_index = 0	
		for i in range(0, 10):
			while len(bucket[i]) > 1:
				num_array[array_index] = bucket[i][1]
				del bucket[i][1]
				array_index += 1
			bucket[i][0] = 0
			
if __name__ == '__main__':
	num_array = [151, 312, 454, 603, 986, 358, 427, 569]
	radix_sort(num_array)
	for i in range(0, len(num_array)):
		print num_array[i]