---
id: 462
title: Minimum Moves to Equal Array Elements II
difficulty: Medium
topic: Maths
---

## Approach 1: First attempt
- What I tried: Using Mean
- Why it didn't work / was slow: Approach was wron in itself, though some testcases passed

## Approach 2: Optimal (final)
- Key insight: Use Median
- Why this is better: The median minimizes the sum of absolute differences between all elements and a common target value.

## Complexity
Time: O(NlogN)
Space: O(1)

## Learnings
- Use Quickselect to find the median in linear time, avoiding the sort overhead and achieve a TC of O(N).
