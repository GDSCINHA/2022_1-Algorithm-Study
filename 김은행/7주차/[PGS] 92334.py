'''
사용된 반복문의 수              :   8
한 반복문에서 수행되는 연산       :  5(#1) + 2(#2) + 2(#3) + 4(#4) = 13
report 배열의 길이            :   n

        O ( 104n ) = O( n ) time
'''

def solution(id_list, report, k):
    ##### 1 #####
    answer = [ 0 for _ in range(len(id_list)) ]
    user_dic = { id_list[_] : _ for _ in range(len(id_list)) }
    modified_report = { _ : 1 for _ in report }                     # 중복이 삭제된 딕셔너리
    report_log = [ key for key in modified_report.keys() ]          # 중복이 삭제된 리스트
    report_count = { id_list[_] : 0 for _ in range(len(id_list)) }  # 0으로 초기화된 카운트 딕셔너리
    
    ##### 2 #####
    for _ in report_log: # 신고 횟수를 닉네임이 key인 딕셔너리에 +1
        reported_id = _.split()[1]
        report_count[reported_id] += 1
    
    ##### 3 #####
    for key in report_count: # #2의 결과가 k와 같거나 클 경우 bool인 1로 바꾸기 아니라면 0으로
        if report_count[key] >= k:
            report_count[key] = 1
        else:
            report_count[key] = 0
    
    ##### 4 #####
    for log in report_log: # 모든 log 를 확인하고 report_count가 1인 유저를 신고했다면 메일 받을 횟수 +1
        reporter_id = log.split()[0]
        reported_id = log.split()[1]
        if report_count[reported_id] == 1:
            answer[user_dic[reporter_id]] += 1
    
    return answer
