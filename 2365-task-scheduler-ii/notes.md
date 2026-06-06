## Task Scheduler II (LC 2365)

## Key Difference from LC 621:
    - LC 621: Can rearrange tasks.
    - LC 2365: Must maintain given order.

## Pattern:
    HashMap + Simulation

## State:
    task -> last execution day

## Key Insight:
    Next task is already fixed.
    Only determine whether it can be executed today.

 ## If:
    lastDay = d
    space = k

## Earliest valid day:
     d + k + 1

## If currentDay < earliestValidDay:
    jump currentDay to earliestValidDay

## Mistake I Made:
     Used:
     curr - lastDay >= space

## Correct Thinking:
    Directly compute earliest valid day:
    lastDay + space + 1

## Complexity:
    O(n)

## Revision Trigger:
    "Order fixed + cooldown"
    => HashMap of last execution day
