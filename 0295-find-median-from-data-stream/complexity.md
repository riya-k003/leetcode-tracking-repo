# Complexity Analysis (With Diagrams)

## Why Heap Operations are O(log n)

A heap is a **Complete Binary Tree**.

### Example Heap

```text
              50
           /      \
         40        30
       /   \      /   \
     20    10   15     5
```

Number of nodes:

```text
Level 0 → 1 node
Level 1 → 2 nodes
Level 2 → 4 nodes
```

Notice that every level doubles the number of nodes.

For a complete binary tree:

```text
Nodes ≈ 2^Height

Height ≈ log₂(Nodes)
```

Therefore:

```text
Height = O(log n)
```

---

## Why push() is O(log n)

Suppose we insert **60**.

### Step 1: Insert at last position

```text
              50
           /      \
         40        30
       /   \      /   \
     20    10   15     5
    /
   60
```

Heap property is violated.

---

### Step 2: Bubble Up

Swap with parent.

```text
              50
           /      \
         40        30
       /   \      /   \
     60    10   15     5
    /
   20
```

---

### Step 3: Bubble Up Again

```text
              50
           /      \
         60        30
       /   \      /   \
     40    10   15     5
    /
   20
```

---

### Step 4: Bubble Up Again

```text
              60
           /      \
         50        30
       /   \      /   \
     40    10   15     5
    /
   20
```

The element moved:

```text
Leaf → Parent → Parent → Root
```

Maximum movement possible:

```text
Height of heap
```

Since:

```text
Height = O(log n)
```

Therefore:

```text
push() = O(log n)
```

---

## Why pop() is O(log n)

Suppose we remove the root.

### Initial Heap

```text
              60
           /      \
         50        30
       /   \      /   \
     40    10   15     5
```

---

### Move Last Element to Root

```text
               5
           /      \
         50        30
       /   \      /   \
     40    10   15
```

Heap property is violated.

---

### Bubble Down

```text
              50
           /      \
          5        30
       /   \      /   \
     40    10   15
```

---

### Bubble Down Again

```text
              50
           /      \
         40        30
       /   \      /   \
      5    10   15
```

The element moved:

```text
Root → Child → Child
```

Maximum movement:

```text
Height of heap
```

Therefore:

```text
pop() = O(log n)
```

---

# Complexity of addNum()

Your code:

```cpp
max_heap.push(num);
min_heap.push(max_heap.top());
max_heap.pop();

if(min_heap.size() > max_heap.size())
{
    max_heap.push(min_heap.top());
    min_heap.pop();
}
```

Operations performed:

```text
1 push into max_heap
1 push into min_heap
1 pop from max_heap

Possibly:
1 push into max_heap
1 pop from min_heap
```

Each operation:

```text
O(log n)
```

Total:

```text
O(log n) + O(log n) + O(log n) + ...
```

Constant number of heap operations.

Therefore:

```text
addNum() = O(log n)
```

---

# Complexity of findMedian()

For odd elements:

```cpp
max_heap.top()
```

For even elements:

```cpp
max_heap.top()
min_heap.top()
```

Heap top access:

```text
O(1)
```

because the root is directly available.

No traversal.
No reordering.

Therefore:

```text
findMedian() = O(1)
```

---

# Space Complexity

Every inserted element is stored in exactly one heap.

Example:

```text
Numbers:
1 2 3 4 5 6
```

Stored as:

```text
Max Heap (smaller half)
       3
      / \
     2   1

Min Heap (larger half)
       4
      / \
     5   6
```

Total elements stored:

```text
3 + 3 = 6
```

For n inserted numbers:

```text
Total stored elements = n
```

Therefore:

```text
Space Complexity = O(n)
```

---

# Final Complexity Table

| Operation | Complexity | Reason |
|------------|------------|---------|
| addNum() | O(log n) | Constant number of heap push/pop operations |
| findMedian() | O(1) | Only access heap tops |
| Space | O(n) | All inserted elements are stored |

---

# Interview Explanation (30 Seconds)

A heap is a complete binary tree whose height is O(log n). During insertion or deletion, an element can move at most from root to leaf or leaf to root, so push and pop take O(log n). Since addNum() performs only a constant number of heap operations, it is O(log n). Finding the median only requires reading the top elements of the heaps, so it is O(1). Both heaps together store all inserted elements, giving O(n) space.
