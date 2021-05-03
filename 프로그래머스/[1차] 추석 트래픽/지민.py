def calc_process(time, log):
    count = 0
    start, end = time, time + 1000
    
    for l_start, l_end in log:
        if l_end >= start and l_start < end:
            count += 1
    
    return count
    

def solution(lines):
    answer = 0
    
    log_lines = []
    for l in lines:
        day, time, duration = l.split()
        h, m, s = time.split(':')
        duration_time = float(duration[:-1])*1000
        end_time = (int(h)*3600 + int(m)*60 + float(s))*1000
        start_time = end_time - duration_time + 1
        
        log_lines.append((start_time, end_time))
        
    for start, end in log_lines:
        answer = max(answer, calc_process(start, log_lines), calc_process(end, log_lines))
        
    return answer
