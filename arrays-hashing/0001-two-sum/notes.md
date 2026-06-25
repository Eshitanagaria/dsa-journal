## Problem
[Two Sum](https://leetcode.com/problems/two-sum/) — Easy

## Approach
- First tried brute force, two nested loops, O(n^2). Works but TLE risk on large input.
- Realized: for each number, I just need to check if (target - number) has been seen before.
- Use a hashmap to store value -> index as I go. One pass.

## Complexity
Time: O(n)
Space: O(n)

## Learnings
- "Have I seen X before" pattern -> hashmap, almost always O(n) beats O(n^2) nested check.
