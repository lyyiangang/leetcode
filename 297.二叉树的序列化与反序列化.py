#
# @lc app=leetcode.cn id=297 lang=python3
#
# [297] 二叉树的序列化与反序列化
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from curses import noecho
from lib2to3.pgen2 import token


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return ''
        res = []
        self.ser_helper(root, res)
        result = '#'.join(res)
        print(result)
        return result 

    def ser_helper(self, root, res):
        if root is None:
            res.append('null')
            return 
        res.append(str(root.val))
        self.ser_helper(root.left, res)
        self.ser_helper(root.right, res)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == '':
            return None
        tokens = data.split('#')
        root = self.des_helper(tokens)
        return root

    def des_helper(self, tokens):
        if len(tokens) < 1:
            return None
        cur_token = tokens.pop(0)
        if cur_token == 'null':
            return None
        root = TreeNode(int(cur_token))
        root.left = self.des_helper(tokens)
        root.right = self.des_helper(tokens)
        return root

         

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
# @lc code=end

