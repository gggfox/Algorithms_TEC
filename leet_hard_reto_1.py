# Use binary search to find the left_end and right_end. Left_end is the last one with start less than newInterval[0]. Right_end is the first one with end larger than newInterval[1].


def insert(intervals, newInterval):
    def binarySearch(i, target):
        left = 0
        right = len(intervals)-1
        while left <= right:
            mid = left+(right-left)/2
            if intervals[mid][i] <= target:
                left = mid+1
            else:
                right = mid-1
        print(i)
        if not i:
            print("right: "+str(right))
        else:
            print("left: "+str(left))
        return right if not i else left

    # the first one with start < newInterval.start
    left_end = binarySearch(0, newInterval[0])
    # the first one with end > newInterval.end
    right_end = binarySearch(1, newInterval[1])
    print(left_end, right_end)
    res = []
    if left_end >= 0 and intervals[left_end][1] >= newInterval[0]:
        newInterval[0] = intervals[left_end][0]
        left_end -= 1
    if right_end <= len(intervals)-1 and intervals[right_end][0] <= newInterval[1]:
        newInterval[1] = intervals[right_end][1]
        right_end += 1
  #  print(newInterval)
    for i in range(0, left_end+1):
        res.append(intervals[i])
    res.append(newInterval)
    for i in range(right_end, len(intervals)):
        res.append(intervals[i])
    # print(res)
    return res

#:type intervals: List[List[int]]
#:type newInterval: List[int]
#:rtype: List[List[int]]
# binary search
# time: O(n)
# space: O(n)

   # if the input is not sorted, sort it first using O(NlogN) time


insert([[1, 3], [6, 9]], [2, 5])
print("###############################################")
insert([[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], [4, 8])
print("###############################################")
insert([], [5, 7])
