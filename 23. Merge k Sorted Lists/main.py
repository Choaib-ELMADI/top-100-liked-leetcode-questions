def kway(lists):
    k = len(lists)
    n = sum([len(lst) for lst in lists])

    output = []
    pos = [0]*k

    while len(output) < n:
        list_idx = min(range(len(pos)), key=lambda i: lists[i][pos[i]] if pos[i] < len(lists[i]) else float("inf")) 
        output.append(lists[list_idx][pos[list_idx]])
        pos[list_idx] += 1

    return output

lists = [[1, 2, 3], [2, 4, 7], [4, 9]]
res = kway(lists)
print(res)