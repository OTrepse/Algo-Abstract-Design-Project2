## Students names: 
### Ryan Esperto UFID: 49218645
### Derek Camilo-Taylor UFID: 49535835

### Instructions to compile/build the code:

* __Inside of git bash copy and past inside of the project directory__ 

`g++ -std=c++17 src/cache-eviction.cpp -o cache_sim`

This will create a executable called `cache_sim`

### Instructions to run the program:

* __Run the program by providing an input file containing the cache size and request sequence.__

`./cache_sim data/example.in`

Example output:

`FIFO  : 9` <br>
`LRU   : 10`<br>
`OPTFF : 7`

Assumptions:

### Question 1:

Use at least three nontrivial input files (each containing 50 or more requests).

For each file, report the number of cache misses for each policy.



| Input File | k | m  | FIFO | LRU | OPTFF |
|------------|---|----|------|-----|-------|
| test       | 3 | 60 | 60   | 60  | 32    |
| test2      | 3 | 60 | 35   | 35  | 19    |
| test3      | 3 | 56 | 37   | 42  | 25    |

Briefly comment:

* __Does OPTFF have the fewest misses?__

OPTFF always has the fewest misses since it has knowledge of the future requests

* __How does FIFO compare to LRU?__

FIFO and LRU behave similarly, but sometimes one can edge out the other as seen in the 
example out files and above inside of file test3 where FIFO edged out LRU

### Question 2:

For ( k = 3 ), investigate whether there exists a request sequence for which OPTFF incurs strictly fewer misses than LRU (or FIFO).

If such a sequence exists:
Construct one.
Compute and report the miss counts for both policies.

If you believe no such sequence exists for the policy you chose:
Provide a clear justification.
In either case, briefly explain your reasoning.

#### Answer:

Yes, there exists a request sequence where OPTFF incurs strictly fewer misses than LRU.

For cache size **k = 3**

`1 2 3 4 1 2 5 1 2 3`

#### Miss counts:

| Policy | Misses |
|------|------|
| LRU | 8 |
| OPTFF | 6 |

#### Explanation:

LRU evicts the least recently used item in the cache without considering future requests. When the 
sequence introduces new items such as 4 and 5, LRU evicts items that will soon be needed again.

OPTFF instead evicts the item whose next request occurs farthest in the future. Because it knows 
the entire request sequence, it can avoid evicting items that will be reused soon.

As a result, OPTFF produces fewer cache misses than LRU on this sequence.

### Question 3:

Let OPTFF be Belady’s Farthest-in-Future algorithm.
Let ( A ) be any offline algorithm that knows the full request sequence.
Prove that the number of misses of OPTFF is no larger than that of ( A ) on any fixed sequence.

__Answer:__ 
\
To prove that the misses of OPTFF is <= misses of (A) we can prove by contradiction
Let A be any caching algorithm for a fixed request sequence and cache can be called size n, if we find the first time t where A and OPTFF
make different eviction choice we can call that B. OPTFF evicts the item x containing B whose next request
is farthest while A evicts some other item z. if we were to use A' that is exactly like A exept it evicts x instead of z . Sense we know 
nextt(x) >= nextt(z) we know we need x first therefore keeping z cannot cause an extra miss before the request of z. This shows that A' cna only do the same or better. so Replacing A's choice by OPTFF choice does not increase misses, if there is a an exchange that does not match A turns into OPTFF without increasing the misses
so OPTFF has no more misses than A on any fixed Sequence.