#!/usr/bin/python


import sys

class BSTNode:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

	def __str__(self):
		return str(self.data)

class BST:
	def __init__(self, data):
		self.bst = BSTNode(data)
		self.left = None
		self.right = None

	def insert(self, data):
		node = self.bst
		lastNode = node

		while node != None:
			lastNode = node
			if data < node.data:
				node = node.left
			else:
				node = node.right


		newNode = BSTNode(data)
		if data < lastNode.data:
			lastNode.left = newNode
		else:
			lastNode.right = newNode



	def delete(self, data):
		foundNode = self.find(data)
		traverseNode = foundNode.right
		while traverseNode.left != None:
			traverseNode = traverseNode.left

		foundNode.data = traverseNode.data
		foundNode.right = traverseNode.right


	def find(self, data):
		node = self.bst
		while node != None:
			print node.data
			if node.data == data:
				return node

			if data < node.data:
				node = node.left
			else:
				node = node.right
		return None


bst = BST(50)
bst.insert(25)
bst.insert(75)

bst.insert(22)
bst.insert(19)
bst.insert(23)


bst.insert(30)
bst.insert(40)
bst.insert(43)

bst.find(23)
bst.delete(25)
print "-----"
bst.find(40)