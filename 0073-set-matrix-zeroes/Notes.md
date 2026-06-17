# Set Matrix Zeroes (Optimal Approach)

## Problem Statement

Given an `m × n` integer matrix, if an element is `0`, set its entire row and column to `0`.

### Example

**Input**

```text
1 1 1
1 0 1
1 1 1
```

**Output**

```text
1 0 1
0 0 0
1 0 1
```

---

# Approach 1: Brute Force

## Idea

Whenever a `0` is found:

- Mark its row.
- Mark its column.

Use two extra arrays:

```cpp
vector<int> row(n, 0);
vector<int> col(m, 0);
```

### Steps

1. Traverse the matrix.
2. If `matrix[i][j] == 0`
   - `row[i] = 1`
   - `col[j] = 1`
3. Traverse the matrix again.
4. If `row[i] == 1 || col[j] == 1`
   - Set `matrix[i][j] = 0`

### Complexity

| Metric | Value |
|----------|----------|
| Time | O(N × M) |
| Space | O(N + M) |

---

# Approach 2: Optimal (O(1) Space)

## Key Idea

Instead of using separate row and column arrays, use:

- First row as column markers.
- First column as row markers.

This eliminates the need for extra space.

---

## Visualization

### Original Matrix

```text
1 1 1 1
1 0 1 1
1 1 1 0
1 1 1 1
```

### Marking Phase

For `matrix[1][1] = 0`

```text
matrix[1][0] = 0
matrix[0][1] = 0
```

For `matrix[2][3] = 0`

```text
matrix[2][0] = 0
matrix[0][3] = 0
```

### Matrix After Marking

```text
1 0 1 0
0 0 1 1
0 1 1 0
1 1 1 1
```

Now:

- First row stores column markers.
- First column stores row markers.

---

# Algorithm

## Step 1: Check First Row

```cpp
bool firstrow = false;

for(int j = 0; j < m; j++)
{
    if(matrix[0][j] == 0)
        firstrow = true;
}
```

---

## Step 2: Check First Column

```cpp
bool firstcol = false;

for(int i = 0; i < n; i++)
{
    if(matrix[i][0] == 0)
        firstcol = true;
}
```

---

## Step 3: Mark Rows and Columns

```cpp
for(int i = 1; i < n; i++)
{
    for(int j = 1; j < m; j++)
    {
        if(matrix[i][j] == 0)
        {
            matrix[i][0] = 0;
            matrix[0][j] = 0;
        }
    }
}
```

### Marker Meaning

```text
matrix[i][0] = 0
→ Entire row i should become zero

matrix[0][j] = 0
→ Entire column j should become zero
```

---

## Step 4: Update Matrix Using Markers

```cpp
for(int i = 1; i < n; i++)
{
    for(int j = 1; j < m; j++)
    {
        if(matrix[i][0] == 0 || matrix[0][j] == 0)
        {
            matrix[i][j] = 0;
        }
    }
}
```

---

## Step 5: Handle First Row

```cpp
if(firstrow)
{
    for(int j = 0; j < m; j++)
    {
        matrix[0][j] = 0;
    }
}
```

---

## Step 6: Handle First Column

```cpp
if(firstcol)
{
    for(int i = 0; i < n; i++)
    {
        matrix[i][0] = 0;
    }
}
```

---

# Why Do We Need `firstrow` and `firstcol`?

## Interview Favorite Question

Consider:

```text
0 1 1
1 1 1
1 1 1
```

Here:

```cpp
matrix[0][0]
```

belongs to:

- First row
- First column

both at the same time.

After marking, we cannot determine:

- Was the first row originally zero?
- Was the first column originally zero?
- Or both?

Therefore, we store:

```cpp
bool firstrow;
bool firstcol;
```

to preserve the original state.

---

# Dry Run

## Input

```text
1 1 1
1 0 1
1 1 1
```

### After Marking

```text
1 0 1
0 0 1
1 1 1
```

Markers indicate:

- Row 1 → Zero
- Column 1 → Zero

### After Updating

```text
1 0 1
0 0 0
1 0 1
```

Correct Answer ✅

---

# Common Mistakes

## 1. Comparing With Character `'0'`

❌ Wrong

```cpp
if(matrix[i][j] == '0')
```

✅ Correct

```cpp
if(matrix[i][j] == 0)
```

The matrix contains integers, not characters.

---

## 2. Zeroing First Row/Column Before Marking

❌ Wrong Order

```text
Handle first row
Handle first column
Mark matrix
```

This destroys markers.

✅ Correct Order

```text
Check first row
Check first column
Mark rows and columns
Update matrix
Handle first row
Handle first column
```

---

## 3. Marking and Updating Together

❌ Wrong

```cpp
if(matrix[i][j] == 0)
{
    mark row and column
}

immediately update
```

✅ Correct

```text
Pass 1 → Mark
Pass 2 → Update
```

---

# Complexity Analysis

| Metric | Value |
|----------|----------|
| Time Complexity | O(N × M) |
| Space Complexity | O(1) |

---

# Interview Explanation (30 Seconds)

> We use the first row and first column as marker arrays instead of creating separate row and column arrays. Whenever a zero is found, we mark its row and column using `matrix[i][0]` and `matrix[0][j]`. Since `matrix[0][0]` belongs to both the first row and first column, we maintain two boolean variables `firstrow` and `firstcol` to preserve their original state. This achieves **O(N × M)** time complexity and **O(1)** extra space.
