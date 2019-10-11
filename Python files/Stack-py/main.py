""" Stacks """"

class Stack:
    """ Create a Stack Class with various methods """
     def __init__(self):
         """ Create a constructor with the items """
         self.items = []

     def push(self, item):
         """ Adds a value onto the end of the stack """
         self.items.append(item)

     def pop(self):
         """ Removes and returns the value at the end of the stack """
         return self.items.pop()

     def peek(self):
         """ Returns the value at the end of the stack """
         return self.items[len(self.items)-1]

     def size(self):
         """ Returns the length of the items in the Stack """
         return len(self.items)

    def is_empty(self):
        """ It checks if the Stack is empty and return a boolean value """
         return self.items == []
