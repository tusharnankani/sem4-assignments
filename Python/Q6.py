def addAll(nums):
    total = 0
    for num in nums:
        total += num
    print("\nAddition is:", total)
    
def multiplyAll(nums):
    total = 1
    for num in nums:
        total *= num
    print("\nProduct is:",  total)
    
def addAllEven(nums):
    total = 0
    for i in range(0, len(nums), 2):
        total += nums[i]
    print("\nAddition at even indices is:", total)
    
def insertItems(nums):
    num = int(input("Enter a number to be appended: "))
    nums.append(num)
    print("\nThe final list is:", nums)