---
id: 1
title: Two Sum
difficulty: Easy
topic: Hashing
---

## Approach 1: Brute force
- Nested loop checking every pair, O(n^2)
- Works but inefficient for large inputs

## Approach 2: Optimal (final)
- Key insight: for each number, check if (target - number) was already seen
- Hashmap stores value -> index, single pass

## Complexity
Time: O(n)
Space: O(n)

## Learnings
- "Have I seen X before" -> hashmap, turns O(n^2) into O(n)
