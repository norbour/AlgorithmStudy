# -*- coding: utf-8 -*-
'''
Created on 2014-09-16

@author: caojin
'''

import Queue

class stack:
	def __init__(self, stack_size):
		self.queue1 = Queue.Queue(stack_size)
		self.queue2 = Queue.Queue(stack_size)
		
	def push(self, elem):
		if self.queue1.full() or self.queue2.full():
			return
		elif self.queue1.empty():
			self.queue2.put(elem)
		elif self.queue2.empty():
			self.queue1.put(elem)
			
	def pop(self):
		if self.queue1.empty() and self.queue2.empty():
			return
		elif self.queue1.empty():
			while self.queue2.qsize() > 1:
				self.queue1.put(self.queue2.get())
			return self.queue2.get()
		elif self.queue2.empty():
			while self.queue1.qsize() > 1:
				self.queue2.put(self.queue1.get())
			return self.queue1.get()
			
if __name__ == '__main__':
	s = stack(10)
	for i in range(0, 10):
		s.push(i)
		
	for i in range(0, 10):
		print s.pop()