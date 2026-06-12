# Find Median from Data Stream

## Key Insight

The median only depends on the middle element(s) of the sorted order.

Instead of storing all elements in sorted order, maintain:

- A Max Heap for the smaller half of elements.
- A Min Heap for the larger half of elements.

This allows us to quickly access the middle element(s).

---

## Heap Responsibilities

### Max Heap (Left Half)

Stores the smaller half of the numbers.

Properties:

- Contains smaller elements.
- Top element is the largest among the smaller half.

```cpp
priority_queue<int> max_heap;
```

---

### Min Heap (Right Half)

Stores the larger half of the numbers.

Properties:

- Contains larger elements.
- Top element is the smallest among the larger half.

```cpp
priority_queue<int, vector<int>, greater<int>> min_heap;
```

---

## Invariants

Maintain:

```text
max_heap.size() == min_heap.size()
```

or

```text
max_heap.size() == min_heap.size() + 1
```

Meaning:

- Both heaps have equal size, or
- Max Heap has one extra element.

Also ensure:

```text
All elements in max_heap <= All elements in min_heap
```

---

## Add Number

### Step 1

Insert into Max Heap.

```cpp
max_heap.push(num);
```

---

### Step 2

Move the largest element of the left half to the right half.

```cpp
min_heap.push(max_heap.top());
max_heap.pop();
```

This maintains ordering between the two halves.

---

### Step 3

Rebalance if the right half becomes larger.

```cpp
if(min_heap.size() > max_heap.size())
{
    max_heap.push(min_heap.top());
    min_heap.pop();
}
```

This restores the size invariant.

---

## Finding Median

### Odd Number of Elements

Max Heap contains one extra element.

```cpp
return max_heap.top();
```

Example:

```text
[1,2,3]
Median = 2
```

---

### Even Number of Elements

The middle two elements are:

```cpp
max_heap.top()
min_heap.top()
```

Median:

```cpp
(max_heap.top() + min_heap.top()) / 2.0
```

Example:

```text
[1,2,3,4]
Median = (2 + 3) / 2 = 2.5
```

---

## Why Heap Operations are O(log n)

A Binary Heap is a Complete Binary Tree.

For a complete binary tree:

```text
Nodes      Height
1          0
3          1
7          2
15         3
31         4
```

Height:

```text
log₂(n)
```

### Push Operation

A newly inserted element may move from a leaf to the root.

Maximum movement:

```text
O(log n)
```

### Pop Operation

After removing the root, the replacement element may move from root to leaf.

Maximum movement:

```text
O(log n)
```

Therefore:

```text
push() = O(log n)
pop() = O(log n)
```

---

## Complexity Analysis

### addNum()

Performs a constant number of heap push/pop operations.

```text
O(log n)
```

### findMedian()

Only accesses heap tops.

```text
O(1)
```

### Space Complexity

All inserted elements are stored in either Max Heap or Min Heap.

```text
O(n)
```

---

## Interview One-Liner

Median only depends on the boundary between the lower half and upper half of the numbers, so maintain the lower half in a Max Heap and the upper half in a Min Heap while keeping the heaps balanced.
