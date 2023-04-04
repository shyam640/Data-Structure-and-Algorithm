/*

There are N buckets (5 ≤ N ≤ 105), each with a certain capacity Ci (1 ≤ Ci ≤ 100). One
day, after a rainstorm, each bucket is filled with Ai units of water (1 ≤ Ai ≤ Ci). Charlie
then performs the following process: he pours bucket 1 into bucket 2, then bucket 2 into
bucket 3, and so on, up until pouring bucket N − 1 into bucket N. When Charlie pours
bucket B into bucket B + 1, he pours as much as possible until bucket B is empty or bucket
B + 1 is full. Find out how much water is in each bucket once Charlie is done pouring.

INPUT FORMAT:
The first line of the input contains N.
The second line of the input contains the capacities of the buckets, C1, C2, . . . , Cn.
The third line of the input contains the amount of water in each bucket A1, A2, . . . , An.

OUTPUT FORMAT:
Please print one line of output, containing N space-separated integers: the final amount of
water in each bucket once Charlie is done pouring.



*/