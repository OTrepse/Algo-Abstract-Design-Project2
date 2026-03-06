Students names: 
Ryan Esperto UFID: 49218645
Derek Camilo-Taylor UFID:

Instructions to compile/build the code:


Instructions to run the program:


Assumptions:

Question 1:
Use at least three nontrivial input files (each containing 50 or more requests).

For each file, report the number of cache misses for each policy.

Input File	k	m	FIFO	LRU	OPTFF
File1					
File2					
File3					


Question 2:
For ( k = 3 ), investigate whether there exists a request sequence for which OPTFF incurs strictly fewer misses than LRU (or FIFO).

If such a sequence exists:
Construct one.
Compute and report the miss counts for both policies.

If you believe no such sequence exists for the policy you chose:
Provide a clear justification.
In either case, briefly explain your reasoning.

Question 3:
Let OPTFF be Belady’s Farthest-in-Future algorithm.
Let ( A ) be any offline algorithm that knows the full request sequence.
Prove that the number of misses of OPTFF is no larger than that of ( A ) on any fixed sequence.

Answer: To prove that the misses of OPTFF is <= misses of (A) we can prove by contradiction

Let A be any caching algorithm for a fixed request sequence and cache can be called size n, if we find the first time t where A and OPTFF
make different eviction choice we can call that B. OPTFF evicts the item x containing B whose next request
is farthest while A evicts some other item z. if we were to use A' that is exactly like A exept it evicts x instead of z . Sense we know 
nextt(x) >= nextt(z) we know we need x first therefore keeping z cannot cause an extra miss before the request of z. This shows that A' cna only do the same or better. so Replacing A's choice by OPTFF choice does not increase misses, if there is a an exchange that does not match A turns into OPTFF without increasing the misses
so OPTFF has no more misses than A on any fixed Sequence.