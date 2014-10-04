# -*- coding: utf-8 -*-
'''
Created on 2014-09-16

@author: caojin

@reference: http://blog.csdn.net/u013088799/article/details/39587403
'''

class Request:
	member = ''
	front = 1 # 1 means to in front of the very person

class StaffRequest:
	member = ''
	requests = [] # list of Request, and length of this list <= 10

def calc_queue_order(staff_list, staff_request_list):
	'''
	If there is an queue order satisfies everyone, print it, else return none
	'''