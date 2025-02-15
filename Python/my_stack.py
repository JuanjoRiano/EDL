from my_node import Node

class Stack:
    def __init__(self):
        self.head = None
        self.size = 0
    
    def get_size(self):
        return self.size
    
    def is_empty(self):
        return self.head is None
    
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
        self.size += 1
        
    def pop(self):
        if self.is_empty():
            raise Exception("The stack is empty.")
        
        data = self.head.data
        self.head = self.head.next
        self.size -= 1
        return data
    
    def peek(self):
        if self.is_empty():
            raise Exception("The stack is empty.")
        
        return self.head.data
    
    def show_stack(self):
        current_node = self.head
        while current_node:
            print(current_node.data, end = " -> ")
            current_node = current_node.next
        print("None")
        