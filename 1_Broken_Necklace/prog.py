# wwwbbrwrbrbrrbrbrwrwwrbwrwrrb

def findBreakPoint(N, arr):
    i = 0
    maxBeadsCount = 0
    beads1Count = 1
    beads2Count = 0
    breakPointIndex = -1
    wIs = None
    wIndex = 0
    while i < N-1:
        while (arr[i] == arr[i+1]) or (arr[i] == 'w'):
            i += 1
            beads1Count += 1

        # print('Stoped after : i =', i+1, ', max beads count : ', beads1Count+beads2Count)
        i += 1

        if (beads1Count + beads2Count) > maxBeadsCount:
            maxBeadsCount = beads1Count + beads2Count
            breakPointIndex = i - beads1Count

        beads2Count = beads1Count
        beads1Count = 1
        # print('Break point index : ', breakPointIndex, (beads1Count+beads2Count))
        # break
    # print('Break point index : ', breakPointIndex, maxBeadsCount)
    return maxBeadsCount

if __name__ == '__main__':
    N = int(input().strip())
    arr = input().strip()

    # for i in range(N):
    #     print(i+1, arr[i], ' ', end = ' ')
    # print()

    print(findBreakPoint(N, arr))
