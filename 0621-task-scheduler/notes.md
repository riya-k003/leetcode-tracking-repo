## Pattern:
Heap + Cooldown Queue

## Problem Type:
Scheduling with cooldown constraints

## Key Insight:
Always execute the highest-frequency task among all currently available tasks.

## Why?
Tasks with higher frequency are hardest to place later and are more likely to create idle slots.

## Data Structures:
1. Max Heap -> Available tasks
   (remainingFreq, task)

2. Cooldown Queue -> Tasks waiting to become available again
   (releaseTime, remainingFreq, task)

## Important Observations:
- Cooldown is per task, not global.
- After executing at time t:
  nextAvailableTime = t + n + 1
- Remaining frequency travels with the task.
- Cooldown queue can be FIFO because release times are generated in increasing order.
- If heap becomes empty, jump directly to the earliest release time instead of simulating idle slots.

## Mistakes I Made:
1. Tried using a global cooldown/gap variable.
2. Forgot that remaining frequency can travel with the task.
3. Used a map during simulation unnecessarily.
4. Initially released only one cooldown task instead of all available ones.
5. Forgot to jump directly to the earliest release time.
6. Completely forgot the mathematical greedy solution.

### Alternative Solution:
## Mathematical Greedy

# Formula:
(maxFreq - 1) * (n + 1) + countMaxFreq

# Final Answer:
max(totalTasks, formulaResult)

# What Finally Clicked:
Think of the problem as:
"Available tasks" + "Tasks in cooldown"

Available tasks -> Max Heap
Cooldown tasks -> Queue

## Revision Trigger:
# If I see:
- Cooldown
- Waiting period
- Execute best available task
- Resource temporarily unavailable

# Think:
Heap + Queue
