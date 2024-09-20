# OS_cpu_scheduler
운영체제설계_CPU 스케쥴러 설계

구현 알고리즘 : FCFS, 정책 1, 정책 2, 정책 3, (신규정책)
FCFS(샘플 소스로 제공.  구현 언어 : C#)
   Shortest-Job-First Scheduling, Priority Scheduling, Round-Robin Scheduling 등 
		학습한 스케줄링 정책 중 3가지 이상을 구현
   즉, 주어진 FCFS 정책 이외에 3가지 정책이 추가적으로 구현되어야 함
		
입력
   #Processes, Burst Time, Arrive Time, Priority, Time slice 등
   그 외, 해당 스케줄링 알고리즘이 필요로 하는 고유 입력 요소
출력
   전체 실행시간 (execution time)
   프로세스 별 실행시간(turnaround time)
   평균 대기시간, 프로세스 별 대기시간(waiting time)
   응답 시간 (response time)
   그 외, 해당 스케줄링 알고리즘의 고유 출력 요소
   throughput 혹은 CPU utilization ratio 등
   특정 알고리즘에서 요구하거나 매개변수로 넣은 값을 분석 결과에 포함시 킬 경우 가점 부여
   간트 차트를 통해 시각적으로 스케줄링 되는 순서를 제시할 것
   스케줄링 결과 분석에 있어서, 엑셀을 활용한 그래프 제시 및 해당 결 과에 대한 분석을 기술할 것 (중요 채점 고려 사항)
