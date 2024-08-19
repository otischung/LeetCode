# 650. 2 Keys Keyboard

Difficulty: <font color=#FF8B00>Medium</font>

## Description

There is only one character `'A'` on the screen of a notepad. You can perform one of two operations on this notepad for each step:

- Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
- Paste: You can paste the characters which are copied last time.

Given an integer `n`, return *the minimum number of operations to get the character* `'A'` *exactly* `n` *times on the screen*.



**Example 1:**

```
Input: n = 1
Output: 0
```

**Example 2:**

```
Input: n = 2
Output: 2
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
```

**Example 3:**

```
Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
```

**Example 4:**

```
Input: n = 4
Output: 4
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Copy All operation.
In step 4, we use Paste operation to get 'AAAA'.
```

**Example 5:**

```
Input: n = 5
Output: 5
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
In step 4, we use Paste operation to get 'AAAA'.
In step 5, we use Paste operation to get 'AAAAA'.
```

**Example 6:**

```
Input: n = 6
Output: 5
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Copy All operation.
In step 4, we use Paste operation to get 'AAAA'.
In step 5, we use Paste operation to get 'AAAAAA'.
```

 

**Constraints:**

- `1 <= n <= 1000`



## Result

| Time Submitted     | Status                            | Runtime | Memory | Language |
| ------------------ | --------------------------------- | ------- | ------ | -------- |
| Aug 19, 2024 11:29 | <font color=#00A000>Accept</font> | 0ms     | 7.66MB | cpp      |

 