import multiprocessing
from concurrent import futures
import random
import time


def merge(L,R):
    i = j = 0
    res = []

    while i < len(L) and j < len(R):
        if L[i] < R[j]:
            res.append(L[i])
            i += 1
        else:
            res.append(R[j])
            j += 1

    res.extend(L[i:])
    res.extend(R[j:])

    return res



def mergeSort(arr):
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    L, R = mergeSort(arr[:mid]), mergeSort(arr[mid:])
    return merge(L, R)



def parallelMergeSort(arr,cpu_count=multiprocessing.cpu_count()):
        mid = len(arr) // 2
        full = [arr[mid:], arr[:mid]]

        if cpu_count == 1:
            l, r = mergeSort(arr[mid:]), mergeSort(arr[:mid])
            return merge(l,r)
        else:
            result = []
            with futures.ProcessPoolExecutor(cpu_count) as p:
                cpu_count = cpu_count // 2
                if cpu_count > 0:

                    cpu_countlist = [cpu_count,cpu_count]
                    future = p.map(parallelMergeSort,full,cpu_countlist)
                    for value in future:
                        result.append(value)

            return merge(result[0],result[1])


def main():
    randomlist1 = []
    for i in range(0, 10):
        randomlist1.append(random.randint(1, 2000000))
    randomlist2 = randomlist1

    startTime = time.time()
    sorted = mergeSort(randomlist1)
    print(sorted)
    print("Merge Sort: %s seconds" % (time.time() - startTime))

    print("------------------------------------------------")

    startTime = time.time()
    sorted = parallelMergeSort(randomlist2)
    #print(sorted)
    print("Parallel Merge Sort: %s seconds" % (time.time() - startTime))



if __name__ == '__main__':
    main()