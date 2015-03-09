#!/usr/bin/python


import sys

class ListNode:
	def __init__(self, data, next=None):
		self.data = data
		self.next = next

	def __str__(self):
		return str(self.data)


class List:
	def __init__(self, data):
		self.list = ListNode(data)
		self.size = 1


	def insert(self, data, position=-1):
		if(self.list == None):
			self.list = ListNode(data)
			return


		if (position == 0):
			self.list = ListNode(data, self.list)
			return
		
		# Get the temporary List
		tempList = self.list
		i = 1

		# Loops through the temporary and then adds the element
		while tempList.next != None:
			if(position != -1 and i == position):
				break
			tempList = tempList.next
			i = i + 1

		# Set the next data
		tempList.next = ListNode(data, tempList.next)

		# Increment the size
		self.size = self.size + 1



	def delete(self, data):
		if(self.list == None):
			return
		# Get the temporary List
		tempList = self.list
		if(tempList.data == data):
			self.list = tempList.next
			return


		while tempList.next != None:
			if(tempList.next.data == data):
				tempList.next = tempList.next.next
				break

			tempList = tempList.next


		self.size = self.size - 1


	def getSize(self):
		return self.size 


	def find(self, data):
		tempList = self.list
		i = 0

		while tempList.next != None:
			if tempList.data == data:
				return i

			i = i + 1
			tempList = tempList.next
		return None

	def getList(self):
		return self.list


L = List(5)
L.insert(3)
L.insert(2)
L.insert(4,1)

print L.find(5)

tt = L.getList()
while tt != None:
	print tt
	tt = tt.next

