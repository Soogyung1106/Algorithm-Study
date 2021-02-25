import sys

if __name__=="__main__":

    while True:
        flag = True
        str = sys.stdin.readline().rstrip().split(' ')
        if str == ['.']:
            break

        str = ' '.join(str)
        brackets = []
        for s in str:
            if s == '(':
                brackets.append(s)
            elif s == ')':
                if brackets and brackets[-1] == '(':
                    brackets.pop()
                else:
                    brackets.append(s)
                    break
            elif s == '[':
                brackets.append(s)
            elif s == ']':
                if brackets and brackets[-1] == '[':
                    brackets.pop()
                else:
                    brackets.append(s)
                    break

        if len(brackets) == 0:
            print('yes')
        else:
            print('no')
