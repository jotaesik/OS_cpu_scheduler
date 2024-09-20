#define _CRT_SECURE_NO_WARNINGS
#include <Stdio.h>
#include <string.h>
int process_number0[50] = { 0, };	//프로세스 개수
int burst_time0[50] = { 0, };	//버스트타임
int waiting_time0[50] = { 0, };	//대기시간이면서 실행시작시간이기도
int arrive_time0[50] = { 0, };	//도착시간
int prioirty1[50] = { 0, };
int order[50] = { 0, };//순서함수 하지만 프1이 무조건 먼저되게
int priority1[50] = { 0, };
int priority0[50] = { 0, };
int who[50] = { 0, };
int multi[50] = { 0, };
int multi1[50] = { 0, };

int main(void) {
	printf("스케쥴링 기법을 고르세요:\n1.fcfs기법\n2.sjf기법\n3.ps기법\n4.RR기법\n5.태식쓰 기법\n");
	int choice = 0;
	printf("당신의 선택?");
	scanf("\n%d", &choice);
	if (choice == 1) {
		printf("fcfs기법선택함. 몇개의 프로세스를 입력하실건가?");
		int number = 0;
		scanf("%d", &number);
		printf("P\t실행시간(숫자하나입력하고 tab을 눌러주세요)\n");
		for (int i = 0; i < number; i++) {
			int burst_time = 0;
			int process_number = 0;
			scanf("%d", &process_number);
			process_number0[i] = process_number;
			scanf("%d", &burst_time);
			burst_time0[i] = burst_time;
		}
		printf("전체실행시간은?");
		int full_time = 0;
		for (int i = 0; i < number; i++) {
			full_time = full_time + burst_time0[i];
		}
		printf("%d\n", full_time);
		int awaiting_time = 0;
		printf("프로세스별 실행시작시간은?\n");
		for (int i = 0; i < number; i++) {
			printf("프로세스번호%d  ", process_number0[i]);
			int waiting_time = 0;
			for (int j = 0; j < i; j++) {
				waiting_time = waiting_time + burst_time0[j];
			}
			waiting_time0[i] = waiting_time;
			awaiting_time = awaiting_time + waiting_time;
			printf("%d\n", waiting_time);

		}
		printf("평균 프로세스 실행시작시간:%d", awaiting_time / number);
		printf("\n");
		for (int i = 0; i < full_time; i++) {
			printf("%-2d ",i);
		}
		printf("\n\n");
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < burst_time0[i]; j++) {
				printf("%-2d ", process_number0[i]);
			}
		}
	}
	else if (choice == 2) {
		printf("몇개의 프로세스를 입력하실건가?");
		int number = 0;
		scanf("%d", &number);
		printf("sjf기법을 선택\n");
		printf("P\t도착시간 실행시간(숫자하나입력하고 tab을 눌러주세요\n");
		for (int i = 0; i < number; i++) {
			int burst_time = 0;
			int process_number = 0;
			int arrive_time = 0;
			scanf("%d", &process_number);
			process_number0[i] = process_number;
			order[i] = process_number;
			scanf("%d", &arrive_time);
			arrive_time0[i] = arrive_time;
			scanf("%d", &burst_time);
			burst_time0[i] = burst_time;
		}
		int full_time = 0;
		for (int i = 0; i < number; i++) {
			full_time = full_time + burst_time0[i];
		}
		printf("전체 걸리는시간: %d", full_time);
		order[0] = process_number0[0];
		int temp = 0;
		for (int i = 1; i < number; i++) {
			for (int j = 1; j < i; j++) {
				if (burst_time0[j] > burst_time0[j + 1]) {
					temp = order[burst_time0[j]];
					order[burst_time0[j]] = order[burst_time0[j + 1]];
					order[burst_time0[j + 1]] = temp;
				}
			}
		}
	
		
		temp = 0;
		for (int i = 1; i < number; i++) {
			for (int j = 1; j < i; j++) {
				if (burst_time0[j] > burst_time0[i]) {
					temp = order[i];
					order[i] = order[j];
					order[j] = temp;
				}
			}
		}
		
		printf("\n");
		int r[100] = { 0, };
		int time = 0;
		int q = 0;

		printf("\n프로그램시작시간\n");

		for (int i = 0; i < number; i++) {
			if (i == 0) {
				printf("%d의 시작시간은 0입니다.", order[i]);
				r[i] = 0;
			}
			else {
				time = 0;
				for (int j = 0; j < i; j++) {
					time = time + burst_time0[order[j] - 1];
				}
				r[i] = time;
				printf("\n%d의 시작시간은 %d입니다.", order[i], time);
			}
		}
		printf("\n\n\n");
		int s = 0;
		int z[100] = { 0, };
		for (int i = 0; i < number; i++) {
			if (i == 0) {
				printf("%d의 기다리는 시간은 0입니다\n", order[i]);
				z[i] = 0;
			}
			else {
				printf("%d의 기다리는 시간은 %d입니다.\n", order[i], r[i] - arrive_time0[order[i] - 1]);
				z[i] = r[i] - arrive_time0[order[i] - 1];
			}
		}
		printf("\n");
		printf("평균 기다리는 시간은?");
		double av = 0;
		for (int i = 0; i < number; i++) {
			av = av + z[i];
		}
		printf("%lf\n", av / number);
		
		printf("\n");
		for (int i = 0; i < full_time; i++) {
			printf("%-2d ", i);
		}
		printf("\n\n");
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < burst_time0[order[i]-1]; j++) {
				printf("%-2d ", order[i]);
			}
		}
	}
	else if (choice == 3) {
		printf("몇개의 프로세스를 입력하실건가?");
		int number = 0;
		scanf("%d", &number);
		printf("ps기법선택\n");
		printf("P\t실행시간 우선순위(숫자하나입력하고 tab을 눌러주세요\n");
		for (int i = 0; i < number; i++) {
			int burst_time = 0;
			int process_number = 0;
			int priority = 0;
			scanf("%d", &process_number);
			process_number0[i] = process_number;
			scanf("%d", &burst_time);
			burst_time0[i] = burst_time;
			scanf("%d", &priority);
			priority1[i] = priority;
		}
		printf("전체실행시간은?");
		int full_time = 0;
		for (int i = 0; i < number; i++) {
			full_time = full_time + burst_time0[i];
		}
		printf("%d\n", full_time);
		double waiting_time = 0;
		int min = 1;
		int a = 0;
		for (int j = 0; j < number; j++) {
			for (int i = 0; i < number; i++) {
				if (min == priority1[i]) {
					who[a] = i + 1;
					break;
				}
			}
			min++;
			a++;
		}
		for (int i = 0; i < number; i++) {
			printf("%d ", who[i]);
		}
		printf("\n프로세스당 기다리는 시간은?\n");
		int b = 0;

		for (int i = 0; i < number; i++) {
			int time = 0;
			if (b == 0) {
				printf("%d의 실행시간은 0이다.\n", who[b]);
				waiting_time0[b] = 0;
			}
			else {
				for (int i = 0; i < b; i++) {
					time = time + burst_time0[who[i] - 1];
				}
				printf("%d의 실행시간은 %d이다.\n", who[b], time);
				waiting_time0[b] = time;
			}
			b++;
		}
		printf("프로세스별 평균대기시간은?\n");
		for (int i = 0; i < number; i++) {
			waiting_time = waiting_time + waiting_time0[i];
		}
		printf("%lf입니다.", waiting_time / number);
		printf("\n");
		printf("\n");
		for (int i = 0; i < full_time; i++) {
			printf("%-2d ", i);
		}
		printf("\n\n");
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < burst_time0[who[i] - 1]; j++) {
				printf("%-2d ", who[i]);
			}
		}

	}
	else if (choice == 4) {
		printf("4번당첨\n");
		printf("몇개의 프로세스를 입력하실건가?");
		int number = 0;
		int quantum = 0;
		scanf("%d", &number);
		int who[100] = { 0, };
		printf("P\t실행시간(숫자하나입력하고 tab을 눌러주세요\n");
		for (int i = 0; i < number; i++) {
			int burst_time = 0;
			int process_number = 0;
			scanf("%d", &process_number);
			process_number0[i] = process_number;
			scanf("%d", &burst_time);
			burst_time0[i] = burst_time;
		}
		printf("퀀텁을 입력해주세요");
		scanf("%d", &quantum);
		printf("전체실행시간은? ");
		int full_time = 0;
		for (int i = 0; i < number; i++) {
			full_time = full_time + burst_time0[i];
		}
		printf("%d\n", full_time);
		int p = 0;
		int q = 0;
		int check = 0;
		int t[100][100] = { 0, };
		int a = 0;
		for (int i = 0; i < number; i++) {
			t[i][a] = burst_time0[i];
		}
		int big = 0;
		for (int i = 0; i < number; i++) {
			if (big < burst_time0[i]) {
				big = burst_time0[i];
			}
		}
		for (int d = 0; d < number; d++) {
			a++;
			for (int i = 0; i < big / quantum + 1; i++) {
				if (t[i][a - 1] - quantum>= 0) {
					t[i][a] = t[i][a - 1] - quantum;
				}
				else {
					t[i][a] = 0;
				}
			}
		}
		int z = 1;
	
		
		printf("\n");
	

		int x = 0;
		int y = 0;
		int z1 = 1;


		printf("\n");
		for (int y = 0; y < big / quantum + 1; y++) {
			for (int x = 0; x < number; x++) {
				if ((t[x][y] - t[x][y + 1]) != 0) {
					waiting_time0[z1] = waiting_time0[z1 - 1] + t[x][y] - t[x][y + 1];

					printf("%d 에서 %d까지는 %d가 사용\n", waiting_time0[z1 - 1], waiting_time0[z1], process_number0[x]);
					z1++;
				}

			}
		}
	}

	else if (choice == 5) {
		printf("5번선택\n");
		printf("몇개의 프로세스를 입력하실건가?");
		int number = 0;
		scanf("%d", &number);
		printf("P\t실행시간 우선순위(숫자하나입력하고 tab을 눌러주세요\n");
		for (int i = 0; i < number; i++) {
			int process_number = 0;
			int burst_time = 0;
			int prioirty = 0;
			int arrive_time = 0;
			scanf("%d", &process_number);
			process_number0[i] = process_number;
			order[i] = process_number;
			scanf("%d", &burst_time);
			burst_time0[i] = burst_time;
			scanf("%d", &prioirty);
			prioirty1[i] = prioirty;
		}
		for (int i = 0; i < number; i++) {
			multi[i] =	burst_time0[i] * prioirty1[i];
		}
		int temp = 0;
	
		for (int a = 0; a < number; a++) {
			multi1[a] = multi[a];
			printf("%d ", multi1[a]);
		}
		
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number-1; j++) {
				if (multi1[j] > multi1[j + 1]) {
					temp = multi1[j];
					multi1[j] = multi1[j + 1];
					multi1[j + 1] = temp;
				}
			}
		}
		for (int k = 0; k < number; k++) {
			printf("%d ", multi1[k]);	//3 5 6 10 32
		}




		printf("\n");
		int full_time = 0;
		for (int i = 0; i < number; i++) {
			full_time = full_time + burst_time0[i];
		}

		int z = 0;
		printf("\n전체소모시간은:%d\n", full_time);
		printf("우선순위와 실행시간에 따른 프로세스 실행순서는:\n ");
		for (int j = 0; j < number; j++) {
			for (int i = 0; i < number; i++) {
				if (multi1[z] == multi[i]) {
					order[z] = i + 1;
					z++;
				}
			}
		}
		for (int i = 0; i < number; i++) {
			printf("%d ", order[i]);
		}
		z = 0;
		int wait = 0;
		for (int i = 0; i < number; i++) {
			if (i == 0) {
				printf("\n%d는 시작시간은0입니다.", order[i]);
				waiting_time0[i] = 0;
			}
			else {
				wait = 0;
				for (int j = 0; j < i; j++) {
					wait = wait + burst_time0[order[j] - 1];
				}
				printf("\n%d는 시작시간은%d입니다.", order[i], wait);
				waiting_time0[i] = wait;
			}
		}


		printf("\n");
	
		








	}

	else {
		printf("당신이 선택한 기법 번호가 읎네요. 끝\n");
	}

	return 0;
}