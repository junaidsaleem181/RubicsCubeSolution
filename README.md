Rubik's cube is one the favorite puzzle game for everyone in the childhood. Solving a Rubik's cube is always an hectic task but in the current world
Artificial Intelligence has changed the game and computers are making it easy to solve such problems. In this solution I used two famour AI algorithms, Iterative
Deepening and Astar algorithm. 
This program loads the intial and final state of the cube and solves using the above mentioned algorithms.
Iterative Deepening starts from a depth of 1 and goes until the n prescribed depth.
For Astar the heuristic function that I used is to count the number of matched. In this way it solves the Rubrik cube.
Both the solutions are a bit slow as we have to generate 12 next possibles moves for each node and therefore the space and time complexity of these
algorithms is much high.
