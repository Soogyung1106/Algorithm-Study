from itertools import permutations

def solution(user_id, banned_id):
    comb_user_id = list(permutations(user_id, len(banned_id)))
    
    answer_list = []
    for comb in comb_user_id:
        is_match = True
        for uid in range(len(comb)):
            compare_bid = banned_id[uid]
            compare_uid = comb[uid]
            
            if len(compare_uid) != len(compare_bid):
                is_match = False
                break
            else:
                for idx in range(len(compare_bid)):
                    if compare_bid[idx] == '*':
                        continue
                    elif compare_uid[idx] != compare_bid[idx]:
                        is_match = False
                        break
            
            if not is_match:
                break

        if is_match and set(comb) not in answer_list:
            answer_list.append(set(comb))
    
    print(answer_list)
    
    answer = len(answer_list)
    return answer
