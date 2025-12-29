# AVL-Tree-Implementation

## 🏗️ Data Structure Explained
  An AVL tree is a type of self-balancing binary search tree used in OOP. The core idea is that for every node in the tree, the height difference between its left and right subtrees is always at most 1.
  
## 👷‍♂️ My implementation explained
  Height is kept at O(logn), this means that:
  - Insert function operates at O(logn)
  - This implementation assumes that the height of a leaf is 0 and the height of a nullptr is -1
  - After a new node is inserted, it is then adjusted using rotations
  - A rotation is only preformed when the balance is less than -1 or more than 1
  
## 📝 What i learned
  - Balance factor is defined as -> b=height(l) - height(r)
  - Self balancing is achieved using rotations of pointer nodes
  - There are 4 types of rotations: Left rotation, Right rotation, Left then Right rotation, Right then Left     rotation.

## 📝 TO-DO
  - Add Search Function
  - Add Delete Function
