#!/usr/bin/python


import sys

class TreeNode:
	def __init__(self, data, parent=None):
		self.data = data
		self.parent = parent

	def __str__(self):
		return str(self.data)


class Tree:
	def __init__(self):
		self.tree = []

	def insert(self, data, parent):
		if self.tree == []:
			self.tree.append(TreeNode(data))
			return

		i = 0
		for el in self.tree:
			if el.data == parent:
				self.tree.append(TreeNode(data, self.find(parent)))
				break
			i = i + 1

	def find(self, data):
		i = 0
		for el in self.tree:
			if el.data == data:
				return i
			i = i + 1

		return None

	def delete(self, data):
		i = 0
		for el in self.tree:
			if el.data == data:
				self.tree.pop(i)
			i = i + 1


	def getParents(self, data):
		for el in self.tree:
			if el.data == data:
				if el.parent == None:
					return None
				return self.tree[el.parent]

		return None

	def getChild(self, data):
		child = []
		for el in self.tree:
			if el.parent == None:
				continue

			if self.tree[el.parent].data == data:
				child.append(el)

		return child

t = Tree()
t.insert(5, -1)
t.insert(4, 5)
t.insert(3, 5)
t.insert(2, 5)

for el in t.tree:
	print str(el.data) + " " + str(el.parent)


