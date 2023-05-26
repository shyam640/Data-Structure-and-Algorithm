def pairSum(nums, k):
	st = set()
	for  num in nums:
		if k-num in st:
			return True
		st.add(num)
	return False

n = int(input())
# nums = list(map(int, input().split()))
nums = []
for i in range (n):
	num = int(input())
	nums.add(num)
k  = int(input())

if pairSum:
	print("Yes")
else:
	print("No")
