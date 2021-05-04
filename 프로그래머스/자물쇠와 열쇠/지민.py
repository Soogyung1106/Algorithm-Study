def solution(key, lock):
    answer = False
    n = len(lock)
    m = len(key)
    
    rotate_key = key
    for _ in range(4):
        rotate_key = list(zip(*rotate_key[::-1]))
        
        for r_r in range(n+m-1):
            for r_c in range(n+m-1):
                match_cnt = 0
                bump = False
                for r in range(n):
                    for c in range(n):
                        key_r = r+m-1-r_r
                        key_c = c+m-1-r_c
                        
                        if 0 <= key_r < m and 0 <= key_c < m:
                            if lock[r][c] == 0 and rotate_key[key_r][key_c] == 0:
                                continue
                            elif lock[r][c] == 1 and rotate_key[key_r][key_c] == 1:
                                bump = True
                                break
                            else:
                                match_cnt += 1
                        else:
                            match_cnt += lock[r][c]
                                
                    if bump:
                        break
                
                if match_cnt == n*n:
                    return True                     
    
    return answer
