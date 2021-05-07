import datetime


def solution(n, t, m, timetable):
    
    shuttlebus = datetime.datetime.strptime("09:00", "%H:%M")
    last_time = shuttlebus + datetime.timedelta(minutes = t*(n-1))
    
    timetable.sort()
    crew_timetable = [datetime.datetime.strptime(tt, "%H:%M") for tt in timetable if tt != '24:00']
    crew_timetable = [tt for tt in crew_timetable if not tt > last_time]
    for num in range(n):
        if len(crew_timetable) < m:
            return last_time.strftime("%H:%M")
        
        if num == n-1:
            if crew_timetable[0] > shuttlebus:
                return shuttlebus.strftime("%H:%M")
            else:
                calc_time = crew_timetable[m-1]-datetime.timedelta(minutes = 1)
                return calc_time.strftime("%H:%M")
        
        for c in range(m-1, -1, -1):
            if crew_timetable[c] <= shuttlebus:
                del crew_timetable[c]
        
        shuttlebus += datetime.timedelta(minutes = t)
