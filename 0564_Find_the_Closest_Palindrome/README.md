# 564. Find the Closest Palindrome

Difficulty: <font color=#FF0000>Hard</font>

## Description

Given a string `n` representing an integer, return *the closest integer (not including itself), which is a palindrome*. If there is a tie, return ***the smaller one***.

The closest is defined as the absolute difference minimized between two integers.



**Example 1:**

```
Input: n = "123"
Output: "121"
```

**Example 2:**

```
Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
```

**Example 3 (Carry):**

```
Input: n = "10199"
Output: "10201"
Explanation: 10101 is not the closest palindrome.
```

**Example 4 (Borrow):**

```
Input: n = "99000"
Output: "98989"
Explanation: 99099 is not the closest palindrome.
```

**Example 5 (Borrow and reduce digit):**

```
Input: n = "10"
Output: "9"
Explanation: 9 and 11 are the closest palindromes but we return the smallest which is 9.
```



 

**Constraints:**

- `0 <= num <= 2^31 - 1`



## Result

| Time Submitted | Status                            | Runtime | Memory  | Language |
| -------------- | --------------------------------- | ------- | ------- | -------- |
|                | <font color=#00A000></font> |      |  | cpp      |

 