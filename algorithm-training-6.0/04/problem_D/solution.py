from typing import Tuple, Optional

class Node:
    def __init__( self, val : int ) -> None:

        self.val: int = val
        self.left: Optional[Node] = None
        self.right: Optional[Node] = None

class Tree:
    def __init__(self) -> None:
        self.root: Optional[Node] = None

    def Print(self) -> None:
        return self.__print(self.root, 0)
    
    def Search(self, val : int) -> None:

        if self.__search(val) is None:
            print("NO")
        else:
            print("YES")

    def Add(self, val) -> None:

        if self.__add(val)[1]:
            print("DONE")
        else:
            print("ALREADY")

    def __search(self, val : int) -> Optional[Node]:

        curr = self.root

        while curr:
            if curr.val == val:
                return curr
            elif curr.val > val:
                curr = curr.left
            else:
                curr = curr.right
        
        return None
    
    def __add(self, val : int) -> Tuple[Node, bool]:

        if self.root is None:
            self.root = Node(val)
            return (self.root, True)
        
        curr = self.root

        while curr:

            if curr.val == val:
                return (curr, False)     
            elif curr.val > val and curr.left is None:
                curr.left = Node(val)
                return (curr.left, True)
            elif curr.val > val and curr.left is not None:
                curr = curr.left
            elif curr.val < val and curr.right is None:
                curr.right = Node(val)
                return (curr.right, True)
            else:
                assert curr.val < val and curr.right is not None
                curr = curr.right

        assert False

    def __print(self, node : Optional[Node], depth : int) -> None:
        if node is None:
            return
        
        self.__print( node.left, depth + 1)
        print("." * depth + str(node.val))
        self.__print( node.right, depth + 1)


if __name__ == '__main__':

    tree = Tree()

    while True:

        try:
            line = input()
        except EOFError:
            break

        if line == 'PRINTTREE':
            tree.Print()
        else:
            line = line.split()
            command = line[0]
            val = int(line[1])

            if command == 'ADD':
                tree.Add(val)
            else:
                tree.Search(val)