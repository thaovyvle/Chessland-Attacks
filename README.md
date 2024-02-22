# Chessland Attacks

Programming Language: C

Recreated a chessboard utilizing data structures, considering the positions of rooks and the absence of other pieces on the board. Implemented an algorithm that determines how many and which rooks can attack each piece.

# Story
In a nearby land there is quite the border dispute between many royal families. Each one has a champion chess piece (a rook) on a large 2D grid. The royal families would like to know how much peril their rook currently faces. Rooks can only attack other pieces in their rank or file (row/column). Additionally, a rook can only attack another rook if there is no other piece(s) directly in between the two. Unfortunately, the board is so large it is hard to eyeball whether 2 rooks can attack each other. You offer to solve the rook threat question in exchange for some coins.

# Problem
You will be given the rank and file of many rooks. Your objective is to determine how many and which rooks threaten each piece.

# Input
• Input will begin with a line containing 1 integers, n (1 ≤ n ≤ 100,000), representing the number of rooks to process. 

• The first line will be followed by n more lines. The i-th following line containstwo integers, r and c (1 ≤ r, c ≤ 1,000,000,000), representing the rank and file of the i-th rook. The i-th rook will have the ID of i.

• No two rooks will be in the same spot. The number of unique ranks and files will be at most 10,000.

# Output
• Output should contain n lines. The i-th line will start with an integer t, representing the number of rooks that can attack the i-th rook. 

• Following t should be t integers on the same line. 

• Each integer will represent the ID of the rook that can attack the current rook. 

• Each rook ID should occur only once in the line. 

• All integers in the line should be separated by spaces. 

• Order of the IDs does not matter.

# Sample #1 Input 

```text
  3
  1 1
  5 5
  6 1
```
