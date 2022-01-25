// Question
// Given a tree, calculate the maximum ancestor for all the leaf nodes. Maximum ancestor of a leaf node is the maximum of it's ancestors and the leaf itself.

// Example:

// 		4
// 	  /   \
//      5     3
//     /     / \
//    1     2   6

// Ouput -
// 1: 5
// 2: 4
// 6: 6


// Solution
// I did a recursive approach, didn't particularly solve it in an optimal way and it took me a while and the interviewer had to give me 1-2 hints as well.


def maxAncestor(root):
	if not root: return None
	
	maxAncestor = -1
	output = {}
	
	if not root.left and not root.right:
		output[root] = helper(maxAncestor, root)
	elif root.left:
		helper(root, root.left)
	elif root.right:
		helper(root, root.right)
		
	def helper(currMax, node):
		if not node: return None
		
		if not node.left and not node.right:
			output[node] = max(currMax, node)
		elif node.left:
			helper(max(currMax, node), node.left)
		elif node.right:
			helper(max(currMax, node), node.right)
		
	return output



// I was asked 2 follow-up questions:

// What if it wasn't a binary tree and instead each node had multiple children?
// Ans: I said that I would loop over all of the children, but the algorithm would essentially stay the same. I did edit my previous algorithm and added these changes in.

// What if the nodes were given as edges? Ex:

// 4 5
// 4 3
// 5 1
// 3 2
// 3 6
// Ans: To this, I asked a clarification on if the edges could be bi-directional. (He said no.) I answered that it would essentially stay the same as the previous algorithm. I would just need to construct an adjacency list to know what all the children were and then traverse through that.

// We ran out of time at this point so I didn't code this part.

// Role: Test Engineer
// Location: NYC