# -*- coding: utf-8 -*-
'''
Created on 2014-09-23

@author: caojin
'''

import Queue

class binary_tree_node:
	'''
	'''
	data = ''
	lchild = None
	rchild = None

	def __init__(self, data):
		self.data = data

	def add_child(self, left_node = None, right_node = None):
		self.lchild = left_node
		self.rchild = right_node

	def traverse_by_level(self):
		node_queue = Queue.Queue(50)
		node_queue.put(self)
		while not node_queue.empty():
			node = node_queue.get()
			print node.data
			if node.lchild != None:
				node_queue.put(node.lchild)
			if node.rchild != None:
				node_queue.put(node.rchild)

if __name__ == '__main__':
	node1 = binary_tree_node('A')
	node2 = binary_tree_node('B')
	node3 = binary_tree_node('C')
	node4 = binary_tree_node('D')
	node5 = binary_tree_node('E')

	node1.add_child(node2, node3)
	node2.add_child(node4, node5)

	node1.traverse_by_level()