import math
from typing import List, Optional

class Node:
    def __init__(self,val, left, right):
        self.val = val
        self.right = right
        self.left = left


class Tree:
    def __init__(self, data):
        self.data = data
        self.max_level = int(math.log2(len(self.data)+1))
        self.node_list = []
    
    def get_root(self):
        if self.node_list == []:
            return None
        else:
            return self.node_list[0]

    def make_node(self):
        last_index = len(self.data)
        if last_index == 0:
            self.node_list = []
            return 
        count = 0
        node_list = []
        node_list = [0 for i in range(len(self.data))]
        while count < last_index:
            
            flag = last_index -count
            index = last_index -count -1
            flag_level = int(math.floor(math.log2(flag))) +1
            # print(f"{self.data[flag-1]}: {flag_level}")

            if self.isBottom(flag_level):
                # print(f"up index: {index}")
                node_list[index] =  Node(self.data[index], None, None) 
            else:
                # print(f"index: {index}")
                temp_left = node_list[(index+1)*2 -1 ]
                temp_right = node_list[(index+1)*2+1 -1]
                if temp_left.val == "null":
                    temp_left = None
                if temp_right.val == "null":
                    temp_right = None
                node_list[index] = Node(self.data[index], temp_left, temp_right )
                
            count = count+1
        
        self.node_list = node_list
        # print(len(self.node_list))
        # print(self.node_list[5].val)
    
    def get_node(self,_index:int):
        return self.node_list[_index]

    def print_tree(self):
        print("> tree")
        for i, element in enumerate(self.node_list):
            # print(f"i: {i}")
            print(element.val, end=" ")
            if i+1+1 == 2**(math.floor(math.log2(i+1)) +1):
                print("")
        print(" ")

    def isBottom(self, _flag_level:int) -> bool:
        _return = False
        # print(f"{_flag_level} / {self.max_level}")
        if _flag_level == self.max_level :
            _return = True
        return _return

    def test_level(self):
        print(self.max_level)



data = [3,9,20,"null","null",15,7]
# data = [1]
# data = []

t = Tree(data)
t.make_node()
t.print_tree()
# print("> example")
# print(f"root的左下是: {t.get_node(0).right.val}")
# print(f"20的右下是: {t.get_node(0).right.right.val}")




class Solution:
    def levelOrder(self, root: Optional[Tree]) -> List[List[int]]:
        if root is None:
            return []

        queue = [root]
        ans = []
        while(queue):
            tmp_queue = []
            tmp_ans = []
            for ele in queue:
                tmp_ans.append(ele.val)
                if ele.left is not None:
                    tmp_queue.append(ele.left)
                if ele.right is not None:
                    tmp_queue.append(ele.right)
            ans.append(tmp_ans)
            queue = tmp_queue
        else:
            return ans

s = Solution()
print("")
print("> leetcode 102")
print(f"input: {data}")
print(f"output: {s.levelOrder(t.get_root())}")