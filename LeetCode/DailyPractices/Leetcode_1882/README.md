# Assign Tasks

You are given:

- `servers` where `servers[i]` is the processing power of server `i`
- `tasks` where each task has a processing duration `tasks[i]`

Each task must be assigned to a free server, and once a server starts a task, it becomes unavailable until `current_time + task_duration`.

If multiple servers are free at the same time, the server with the smallest weight is chosen; if weights are equal, the smaller index is preferred.

Return the index of the server assigned to each task in order.

---

## 🧠 Problem Question

You have `n` servers and `m` tasks. Each task arrives in order, and you must schedule it on one of the free servers. A server is considered free when it has completed its previous task. The goal is to assign the task to the best available server while respecting the arrival order and the server availability constraints.

---

## 🚀 Solution Approach

This problem is best solved with a greedy strategy using two priority queues:

### 1. Free servers heap
We keep all currently available servers in a min-heap ordered by:

- server weight
- server index

This ensures that whenever we need to assign a task, the best available server is chosen immediately.

### 2. Busy servers heap
We also track servers that are currently occupied in another min-heap ordered by:

- the time when the server becomes free
- server index

This lets us efficiently move servers back to the free pool when their assigned task finishes.

### 3. Simulation over task order
We process tasks from left to right:

- If some servers become free by the current time, we return them to the free-servers heap.
- If no server is available, we jump the simulation time to the next time when a server will be free.
- We then assign the current task to the smallest-weight available server.
- We record the server index and push its release time into the busy heap.

This greedy choice is correct because among all currently available servers, choosing the least-weight one minimizes the server selection cost while preserving the required scheduling constraints.

---

## 🔧 C++ Implementation Idea

The core logic is implemented in `main.cpp` using:

- `priority_queue<pair<int, int>, ...>` for free servers
- `priority_queue<pair<int, int>, ...>` for busy servers

The algorithm keeps the simulation time synchronized with task arrivals and server availability.

---

## 📊 Complexity Analysis

| Metric | Complexity | Why |
| :--- | :--- | :--- |
| Time | `O((n + m) log n)` | Each server enters and leaves the heaps a bounded number of times, and each heap operation is logarithmic. |
| Space | `O(n + m)` | We store the free and busy server heaps and the result array. |

---

## ✅ Key Insight

The problem is essentially a scheduling problem with a greedy selection rule:

- keep track of which servers are free
- track when occupied servers become available again
- always choose the best free server
- advance time only when necessary

This leads to an efficient and correct solution for the provided constraints.
