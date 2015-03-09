#!/usr/bin/python


import sys

class StackNode:
	def __init__(self, data, next=None):
		self.data = data
		self.next = next

	def __str__(self):
		return str(self.data)


class Stack:
	def __init__(self, data):
		self.stack = StackNode(data)

	def Push(self, data):
		if self.stack == None:
			self.stack = StackNode(data)
			return
		self.stack = StackNode(data, self.stack)

	def Pop(self):
		if(self.stack == None):
			return None
		data = self.stack.data
		self.stack = self.stack.next

		return data

	def Top(self):
		return self.stack.data

s = Stack(5)
s.Push(4)
s.Push(3)
s.Push(2)
s.Push(1)

print s.Top()
print s.Top()
print s.Top()
print s.Top()
print s.Top()
