---
id: 2942
title: Find Words Containing Character
difficulty: Easy
topic: Strings
---

## Approach 1: Brute Force

- **What I tried:**
  - Traverse each word in the `words` array.
  - For every word, iterate through all its characters using a helper function `present()`.
  - If the target character `x` is found, store the index of that word in the answer vector.

- **Key intuition:**
  - Since we only need to know whether a word contains the given character, a simple linear scan through each word is sufficient.

- **Why this works:**
  - Every character of every word is checked at most once.
  - Whenever `x` is found in a word, its index is added to the result.

## Complexity

Time: **O(N × M)**

- `N` = number of words
- `M` = average length of a word

Space: **O(1)** *(excluding the output vector)*

## Learnings

- A helper function can make the main solution cleaner by separating the character-search logic.
- For checking the existence of a character in a string, a simple linear scan is often enough.
- The output vector is not counted when analyzing auxiliary space complexity.