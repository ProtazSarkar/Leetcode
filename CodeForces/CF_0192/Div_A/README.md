A bigram in a string is a pair of adjacent characters. For example, the string helloello contains 8
 bigrams: he, el, ll, lo, oe, el, ll, lo.

Monocarp has cards with letters: c1
 cards with the letter a, c2
 cards with the letter b, ..., ck
 cards with the k
-th letter of the Latin alphabet. He wants to make a string from these cards, using each card exactly once. The resulting string must contain at least two equal bigrams. The order of characters in each bigram matters; for example, the string aba does not have two equal bigrams.

Determine whether it is possible to make a string that satisfies these requirements.

Input
The first line contains one integer t
 (1≤t≤104
) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer k
 (1≤k≤10
);
the second line contains k
 integers c1,c2,…,ck
 (1≤ci≤108
), where ci
 is the number of cards with the i
-th letter of the Latin alphabet.
Output
For each test case, output YES if it is possible to construct a string satisfying the condition, or NO otherwise.

Each letter can be output in any case. For example, yes, Yes, yEs will be recognized as a positive answer.