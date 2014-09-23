# -*- coding: utf-8 -*-
'''
Created on 2014-09-22

@author: caojin
'''
class stack:
	def __init__(self):
		self.s_data = []
		self.s_min = []
		self.stack_size = 0
		
	def _push(self, data):
		if self.stack_size == 0 or self.s_min[self.stack_size - 1] > data:
			self.s_data.append(data)
			self.s_min.append(data)
			self.stack_size += 1
		elif self.s_min[self.stack_size - 1] <= data:
			self.s_data.append(data);
			self.s_min.append(self.s_min[self.stack_size - 1])
			self.stack_size += 1
			
	def _pop(self):
		self.s_min.pop()
		return self.s_data.pop()
		
	def _get_min(self):
		return self.s_min[len(self.s_min) - 1]
		
if __name__ == '__main__':
	s = stack()
	s._push(1)
	s._push(2)
	s._push(3)
	s._push(0)
	
	for i in range(0, s.stack_size):
		print s._get_min()
		s._pop()