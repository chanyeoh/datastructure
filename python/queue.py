#!/usr/bin/python


import sys

class QueueNode:
	def __init__(self, data, next=None):
		self.data = data
		self.next = next
		self.last = None

	def __str__(self):
		return str(self.data)


class Queue:
	def __init__(self, data):
		self.queue = QueueNode(data)

	def enqueue(self, data):
		if self.queue == None:
			self.queue = QueueNode(data)
			return
		newQueue = QueueNode(data)

		if self.queue.next == None:
			self.queue.next = newQueue
		else:
			self.queue.last.next = newQueue	
			
		
		self.queue.last = newQueue

	def dequeue(self):
		if(self.queue == None):
			return None
		data = self.queue.data
		self.queue = self.queue.next

		return data


	def front(self):
		return self.queue.data

q = Queue(5)
q.enqueue(4)
q.enqueue(3)
q.enqueue(2)
q.enqueue(1)

print q.dequeue()
print q.dequeue()
print q.dequeue()
print q.dequeue()
print q.dequeue()