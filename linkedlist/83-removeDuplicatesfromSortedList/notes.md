---
id: 83
title: Remove Duplicates from Sorted List
difficulty: Easy
topic: Linked List
---

## Approach 1: First attempt
- What I tried: Used a pointer temp to traverse the linked list and compared each node with its next node. If their values matched, I skipped the next node by updating temp->next.
- Why it didn't work / was slow: Forgot to move temp forward when values were different, causing an infinite loop. Also, didn't handle an empty linked list (head == NULL).

## Approach 2: Optimal (final)
- Key insight: Since the linked list is sorted, duplicates are always adjacent. Compare the current node with the next node. If values match, skip the next node; otherwise, move the pointer forward.
- Why this is better: Modifies the linked list in-place without using extra data structures. Keeping the pointer at the same node after deletion also handles consecutive duplicates correctly

## Complexity
Time: O(N)
Space: O(1)

## Learnings
- Always handle edge cases like an empty linked list.
- When deleting a node, update pointers carefully.
- Don't advance the pointer immediately after deletion, as there may be more consecutive duplicates.
- Ensure the pointer moves forward when no deletion occurs to avoid infinite loops.