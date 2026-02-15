# Binary String Adder

A C++ implementation to add two binary strings and return their sum as a new binary string. This solution mimics the standard column-addition method used in elementary arithmetic.

---

## 🚀 Logic & Approach

The algorithm processes two strings, `a` and `b`, from right to left (least significant bit to most significant bit). It effectively handles carries and strings of unequal lengths.

### 1. The Pointer Strategy
We use two pointers, `i` and `j`, initialized to the end of strings `a` and `b`. This allows us to align the bits correctly without needing to pad the shorter string with zeros manually.

### 2. The Arithmetic Loop
The process continues as long as there is a digit left in either string OR a leftover `carry` from the previous addition.

* **Extraction:** At each step, we convert the characters `'0'` or `'1'` to integers. If a pointer has moved past the start of its string, we treat that value as `0`.
* **Summation:** We calculate the local sum: 
    $$sum = digitA + digitB + carry$$
* **Bit Placement:** The bit to write to the result is $sum \pmod 2$.
* **Carry Propagation:** The new carry for the next position is $\lfloor sum / 2 \rfloor$.



### 3. Result Construction
Since we calculate bits from right to left, they are initially appended to the result string in reverse order. A final reversal step ensures the most significant bit is at the front.

---

## 📊 Complexity Analysis

| Metric | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $O(\max(N, M))$ | We traverse each string at most once, where $N$ and $M$ are the lengths of the input strings. |
| **Space Complexity** | $O(\max(N, M))$ | The output string grows linearly with the size of the larger input (plus potentially one extra bit for a final carry). |

---

## 🛠 Edge Cases Handled
* **Carrying to a new digit:** Adding `11 + 1` correctly results in `100`.
* **Different lengths:** Adding `1010 + 1` correctly handles the leading zeros of the shorter string.
* **All zeros:** `0 + 0` correctly returns `0`.
* **Empty strings:** Handled by the loop conditions (though typically constraints guarantee non-empty inputs).



