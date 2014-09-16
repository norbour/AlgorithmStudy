# -*- coding: utf-8 -*-
'''
Created on 2013-03-12

@author: caojin
'''
import string

def num_border(exp, index):
	'''
	detect the border of an integer from exp[index], 
	so that the integer was supposed to be exp[index:tail]
	'''
	tail = index;

	while exp[tail] >= '0' and exp[tail] <= '9':
		tail += 1
		
	return tail
	
def operator_priority(opr):
	'''
	get priority value of operator: +- 1 and */ 2
	'''
	if opr == '+' or opr == '-':
		return 1
	elif opr == '*' or opr == '/':
		return 2
		
def exp_suffix_format(exp):
	'''
	convert an expression string to its suffix format
	'''
	stack = []
	suffixexp = []
	
	i = 0
	while i < len(exp):
		if exp[i] >= '0' and exp[i] <= '9':
			tail = num_border(exp, i)
			suffixexp.append(exp[i:tail])
			i = tail
			continue
		elif exp[i] == '+' or exp[i] == '-' or exp[i] == '*' or exp[i] == '/':
			if len(stack) != 0 and operator_priority(exp[i]) <= operator_priority(stack[len(stack) - 1]):
				while len(stack) != 0:
					suffixexp.append(stack.pop());
				stack.append(exp[i])
			else:
				stack.append(exp[i])
			i += 1
		elif exp[i] == '(':
			stack.append(exp[i]);
			i += 1
		elif exp[i] == ')':
			while stack[len(stack) - 1] != '(':
				suffixexp.append(stack.pop())
			stack.pop()
			i += 1
	while len(stack) != 0:
		suffixexp.append(stack.pop())
		
	return suffixexp;
	
def operate(arg1, arg2, opr):
	'''
	excute operation and return the result as string
	'''
	if opr == '+':
		return string.atoi(arg1) + string.atoi(arg2)
	elif opr == '-':
		return string.atoi(arg1) - string.atoi(arg2)
	elif opr == '*':
		return string.atoi(arg1) * string.atoi(arg2)
	elif opr == '/':
		return string.atoi(arg1) / string.atoi(arg2)
	
def exp_clac(suffixexp):
	'''
	calculate the expression which is in suffix format
	and return the result as string
	'''
	stack = []
	for i in range(0, len(suffixexp)):
		if suffixexp[i] != '+' and suffixexp[i] != '-' and suffixexp[i] != '*' and suffixexp[i] != '/':
			stack.append(suffixexp[i])
		else:
			arg2 = stack.pop()
			arg1 = stack.pop()
			stack.append(str(operate(arg1, arg2, suffixexp[i])))
	
	return stack.pop()
	
if __name__ == '__main__':
	exp = "126+2+3+5*((3+5/1)+21)";
	print exp_suffix_format(exp)
	print exp_clac(exp_suffix_format(exp))
				