import sys

if __name__=="__main__":
    N = int(sys.stdin.readline())
    sequence = [int(sys.stdin.readline()) for _ in range(N)]
    make_sequence = []
    answer = []

    num = 1
    for seq in sequence:
        while num <= seq:
            make_sequence.append(num)
            answer.append('+')
            num += 1

        if make_sequence[-1] == seq:
            make_sequence.pop()
            answer.append('-')
        else:
            answer.append('False')
            break

    if 'False' in answer:
        print('NO')
    else:
        print('\n'.join(answer))
