"""Each ListNode holds a reference to its previous node
as well as its next node in the List."""


class ListNode:
    def __init__(self, value, prev=None, next=None):
        self.value = value
        self.prev = prev
        self.next = next

    """Wrap the given value in a ListNode and insert it
  after this node. Note that this node could already
  have a next node it is point to."""

    def insert_after(self, value):
        current_next = self.next
        self.next = ListNode(value, self, current_next)
        if current_next:
            current_next.prev = self.next

    """Wrap the given value in a ListNode and insert it
  before this node. Note that this node could already
  have a previous node it is point to."""

    def insert_before(self, value):
        current_prev = self.prev
        self.prev = ListNode(value, current_prev, self)
        if current_prev:
            current_prev.next = self.prev

    """Rearranges this ListNode's previous and next pointers
  accordingly, effectively deleting this ListNode."""

    def delete(self):
        if self.prev:
            self.prev.next = self.next
        if self.next:
            self.next.prev = self.prev


"""Our doubly-linked list class. It holds references to
the list's head and tail nodes."""


class DoublyLinkedList:
    def __init__(self, node=None):
        self.head = node
        self.tail = node
        self.length = 1 if node is not None else 0

    def __len__(self):
        return self.length

    def add_to_head(self, value, isNode=False):
        # create new node...
        new_node = ListNode(value) if not isNode else value

        # if list is currently empty...
        if self.head is None:
            # set head and tail to new node
            self.head = new_node
            self.tail = new_node
        else:
            # current head's previous value should be set to the new node
            self.head.prev = new_node
            # new node next value should be set to existing head.
            new_node.next = self.head
            # current head should be replaced
            self.head = new_node
            # increment length
        if not isNode:
            self.length += 1

    def remove_from_head(self):
        if not self.head and not self.tail:
            return None

        # store reference to tail node
        current_head = self.head

        # decrement length
        self.length -= 1

        if self.length <= 1:
            self.head = None
            self.tail = None
            return current_head.value

        # set the prev node as the head...
        self.head = current_head.next
        # prev value for new head should be none
        self.head.prev = None
        # return the removed head value
        # after removing its prev pointer
        current_head.next = None
        return current_head.value

    def add_to_tail(self, value, isNode=False):
        # create new node...
        new_node = ListNode(value) if not isNode else value

        # if list is currently empty...
        if self.tail is None:
            # set head and tail to new node
            self.head = new_node
            self.tail = new_node
        else:
            # current tail's next value should be set to the new node
            self.tail.next = new_node
            # new node prev value should be set to existing tail.
            new_node.prev = self.tail
            # current tail should be replaced
            self.tail = new_node
        # increment length
        if not isNode:
            self.length += 1

    def remove_from_tail(self):
        if not self.head and not self.tail:
            return None
        # store reference to tail node
        current_tail = self.tail

        # decrement length
        self.length -= 1

        if self.length <= 1:
            self.head = None
            self.tail = None
            return current_tail.value

        # set the prev node as the tail...
        self.tail = current_tail.prev
        # next value for new tail should be none
        self.tail.next = None
        # return the removed tail value
        # after removing its prev pointer
        current_tail.prev = None
        return current_tail.value

    def move_to_front(self, node):
        if node.prev and node.next:
            node.prev.next = node.next
            node.next.prev = node.prev
        elif node.prev:
            node.prev.next = None
            self.tail = node.prev
        self.add_to_head(node, True)

    def move_to_end(self, node):
        if node.prev and node.next:
            node.prev.next = node.next
            node.next.prev = node.prev
        elif node.next:
            node.next.prev = None
            self.head = node.next
        self.add_to_tail(node, True)

    def delete(self, node):
        if self.length == 1:
            self.head = None
            self.tail = None
        if node == self.head:
            self.head = node.next
        elif node == self.tail:
            self.tail = node.prev
        self.length -= 1
        node.delete()

    def get_max(self):
        current_node = self.head
        max_value = 0
        # while the current node exists
        while current_node:
            # check if it's greater than our current max
            if current_node.value > max_value:
                # and assign it
                max_value = current_node.value
            # then bump our node to the right
            current_node = current_node.next
        return max_value
