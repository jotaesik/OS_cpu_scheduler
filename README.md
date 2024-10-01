# 🖥️ OS CPU Scheduler

## 📋 **프로젝트 설명 (Project Description)**
`OS_cpu_scheduler` 프로젝트는 운영체제 수업의 일환으로 다양한 CPU 스케줄링 알고리즘을 직접 구현한 프로젝트입니다.  
이 프로젝트에서는 **First-Come-First-Served (FCFS)**, **Shortest Job First (SJF)**, **Priority Scheduling**, **Round-Robin Scheduling (RR)**, 그리고 **사용자 정의 알고리즘 (TaeSik Algorithm)**을 구현하여 각 스케줄링 기법의 성능을 비교 및 분석하였습니다.

## 🛠 **구현된 스케줄링 알고리즘 (Implemented Algorithms)**

1. **FCFS (First-Come-First-Served)**  
   - 먼저 도착한 프로세스를 먼저 실행하는 기본적인 스케줄링 알고리즘입니다.
  
2. **SJF (Shortest Job First)**  
   - 버스트 타임이 짧은 프로세스를 우선적으로 처리하여 평균 대기 시간을 최소화하는 알고리즘입니다.
  
3. **Priority Scheduling**  
   - 프로세스의 우선순위를 기준으로 스케줄링합니다. 우선순위가 높을수록 먼저 실행됩니다.
  
4. **Round-Robin (RR) Scheduling**  
   - 일정한 타임 슬라이스(퀀텀)를 정하여 각 프로세스를 순서대로 실행하는 방식입니다. 모든 프로세스가 공평하게 CPU 시간을 할당받습니다.
  
5. **사용자 정의 알고리즘 (TaeSik Algorithm)**  
   - 버스트 타임과 우선순위를 곱한 값을 기준으로 낮은 순서대로 실행됩니다. 사용자 정의 알고리즘으로, 효율적인 스케줄링을 위해 설계되었습니다.

## 📂 **폴더 구조 (Folder Structure)**
```
OS_cpu_scheduler/
├── cpu_scheduler.c # C 언어로 작성된 CPU 스케줄링 소스 코드
├── cpu_scheduler.exe # 컴파일된 실행 파일
├── cpu_scheduler.pdf # 프로젝트 보고서 파일
└── README.md # 프로젝트 설명 파일
```


