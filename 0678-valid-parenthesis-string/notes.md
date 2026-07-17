# 678. Valid Parenthesis String

## Problem

Given a string `s` containing only three types of characters: `(`, `)`, and `*`,
check whether `s` is **valid**, where `*` can be treated as:
- a single `(`
- a single `)`
- or the empty string `""`

---

## My First Intuition — Brute Force Backtracking

Whenever a `*` is encountered, branch into 3 possibilities and recursively check each:

```cpp
bool solve(int index, int openCount, string& s) {
    if (openCount < 0) return false;             // too many ')' already
    if (index == s.size()) return openCount == 0;

    char c = s[index];
    if (c == '(') return solve(index + 1, openCount + 1, s);
    if (c == ')') return solve(index + 1, openCount - 1, s);

    // c == '*'
    return solve(index + 1, openCount + 1, s) ||   // treat * as '('
           solve(index + 1, openCount - 1, s) ||   // treat * as ')'
           solve(index + 1, openCount, s);         // treat * as ''
}
```

**Problem:** every `*` creates 3 branches → **O(3^n)** in the worst case. Too slow, TLE.

---

## Step 1 — Memoization (DP)

Key observation: `solve(index, open_count)` only depends on `index` and `open_count`,
**not** on which specific path (star assignments) got us there. So identical
`(index, open_count)` states can be cached.

```cpp
class Solution {
public:
    unordered_map<int, bool> memo; // key = index * (n+1) + openCount

    bool solve(int index, int openCount, string& s) {
        if (openCount < 0) return false;
        if (index == s.size()) return openCount == 0;

        int key = index * (s.size() + 1) + openCount;
        if (memo.count(key)) return memo[key];

        char c = s[index];
        bool result;
        if (c == '(') result = solve(index + 1, openCount + 1, s);
        else if (c == ')') result = solve(index + 1, openCount - 1, s);
        else {
            result = solve(index + 1, openCount + 1, s) ||
                     solve(index + 1, openCount - 1, s) ||
                     solve(index + 1, openCount, s);
        }
        return memo[key] = result;
    }

    bool checkValidString(string s) {
        return solve(0, 0, s);
    }
};
```

- States: `index` × `open_count` → **O(n²)** states
- Each state does O(1) work (aside from recursive calls, which are cached)
- **Total: O(n²) time, O(n²) space**

This alone is already a massive improvement and a perfectly valid interview answer.

---

## Step 2 — From DP to Greedy (state compression)

**Insight:** at any fixed `index`, the set of all reachable `open_count` values
always forms a **contiguous range**. If `open_count = 2` and `open_count = 5` are
both reachable at some index, then `3` and `4` must be reachable too — because
each step only changes the count by `-1`, `0`, or `+1`.

➡️ So instead of tracking every individual reachable value, we only need to track
the **range boundaries**: `lo` (minimum possible open count) and `hi` (maximum
possible open count).

This collapses O(n) possible values per index into just 2 numbers → **O(n) time, O(1) space**.

### Greedy Algorithm

Maintain:
- `lo` = minimum possible number of open `(` so far
- `hi` = maximum possible number of open `(` so far

For each character:

| char | lo | hi |
|------|-----|-----|
| `(`  | lo++ | hi++ |
| `)`  | lo-- | hi-- |
| `*`  | lo-- (best case: treat as `)`) | hi++ (best case: treat as `(`) |

After each step:
- **If `hi < 0`** → even the best-case assignment has too many `)` → return `False` immediately (prune).
- **If `lo < 0`** → clamp `lo = 0`. This discards the "worst case" branch where `*` was
  treated as `)` but that made things invalid — negative open count is never valid, so
  we just reset the floor of the achievable range.

At the end: return `lo == 0` (there exists *some* valid assignment where everything balances out).

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;

        for (char c : s) {
            if (c == '(') {
                lo++;
                hi++;
            } else if (c == ')') {
                lo--;
                hi--;
            } else { // '*'
                lo--;
                hi++;
            }

            if (hi < 0) return false;   // even best case invalid, prune
            lo = max(lo, 0);            // discard unreachable worst case
        }

        return lo == 0;
    }
};
```

**Time:** O(n) &nbsp;|&nbsp; **Space:** O(1)

---

## Why This Is a Greedy Algorithm

- We never commit to a specific assignment for `*` (`(`, `)`, or empty).
- Instead, we track a **range of possibilities** `[lo, hi]` in a single left-to-right pass.
- No backtracking, no revisiting — as soon as `hi < 0`, we prune immediately and return `False`.
- Clamping `lo` to `0` is also a greedy move: "discard the unreachable worst case, keep going
  with only the achievable range."
- This local, single-pass reasoning — without exploring every explicit assignment — is
  what makes it greedy.

---

## Progression Summary

| Approach | What it tracks | Complexity |
|---|---|---|
| Brute force backtracking | Exact `open_count` for every path | O(3^n) time |
| Memoized DP | Exact `open_count`, deduplicated states | O(n²) time, O(n²) space |
| Greedy (range tracking) | Only `[lo, hi]` range of `open_count` | O(n) time, O(1) space |

**Pattern to remember:** backtracking → memoized DP → greedy via range-compression.
This pattern (compressing a set of reachable DP states into a min/max range) shows up
in several other problems too — worth recognizing when a DP state space collapses into
a contiguous interval.

---

## Dry Run Example: `s = "(*))"`

| char | lo before | hi before | lo after | hi after | notes |
|------|-----------|-----------|----------|----------|-------|
| `(`  | 0 | 0 | 1 | 1 | |
| `*`  | 1 | 1 | 0 | 2 | lo-- , hi++ |
| `)`  | 0 | 2 | -1 → clamp to 0 | 1 | lo clamped |
| `)`  | 0 | 1 | -1 → clamp to 0 | 0 | lo clamped |

Final: `lo == 0` → **Valid** ✅
