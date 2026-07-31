Level order traversal means visiting nodes level by level, from left to right. Since all nodes at one level must be processed before moving to the next, we use a queue. A queue follows FIFO order, so the first node discovered is the first one processed. We start by pushing the root into the queue. For each level, we first record the current queue size, because that represents the number of nodes in that level. We process exactly those nodes, push their children into the queue, and then move to the next level. This gives an O(n) time complexity since every node is visited once, and O(w) space complexity, where w is the maximum width of the tree
##  mental trick to remember

###  Whenever you hear:

* Shortest path in an unweighted graph → Queue (BFS)
* Level order traversal → Queue (BFS)
* Visit one branch completely first → Stack/Recursion (DFS)

### One sentence that sticks:

A queue makes every node "wait its turn," which is exactly why it visits a tree level by level. A stack lets the newest node jump the line, which is why it dives deep into one branch first. Humans reinvented waiting lines and then were surprised they turned out useful in algorithms too.
