# Leetcode-2096.-Step-By-Step-Directions-From-a-Binary-Tree-Node-to-Another

# 🧭 Get Directions from One Node to Another in a Binary Tree

This project implements an algorithm to **find a path of directions** from one node to another in a binary tree using a combination of **Lowest Common Ancestor (LCA)** and **DFS traversal**.

---

## 🧠 Approach

The solution works in three clear steps:

1. **Find the LCA (Lowest Common Ancestor)** of `startValue` and `destValue`.
2. **Perform DFS** from the LCA to both `startValue` and `destValue`, recording the paths:
   - `'L'` for left, `'R'` for right
3. **Convert the path to start into `'U'` (upward moves)** and then append the path to destination.

This ensures we move from the starting node up to the LCA and then down to the destination.

---

## 🔄 Example


```cpp

    5
   / \
  1   2
     / \
    3   6


```

- LCA: 2
- Path from LCA to 3: "L" → becomes "U"
- Path from LCA to 6: "R"

✅ Final Output: `"UR"`

---

## ⏱ Time and Space Complexity

| Metric              | Value                     |
|---------------------|---------------------------|
| 🕒 Time Complexity   | `O(N)` (visit all nodes once) |
| 💾 Space Complexity  | `O(h)` (call stack depth `h` = tree height) |

---

## ✍️ Author

**Ridham Garg**  
🎓 B.Tech in Computer Engineering, Thapar University, Patiala  
🧠 Passionate about solving real-world problems through tree and graph algorithms!
