// [swea D4] 8568 3으로 나눈 순열  
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW1B8rJq3NUDFARC&categoryId=AW1B8rJq3NUDFARC&categoryType=CODE
#include <iostream>
#include <queue>
using namespace std;

int testcase;
int N, num, p[1000], dp[1000];

void result() {
	for(int i = 1; i <= N; i++) {
		cout<< "#" << i << dp[i] << endl;	
	}
	
}


int main(void) {
	queue<int> q;
	queue<int> q2;
	cin >> testcase;
	for(int i = 0; i < testcase; i++) {
		int cnt = 0;
		cin >> N;
		for(int j = 1; j <= N; j++) {
			cin >> num;
			p[j] = num;
			if(j%3 == p[j]%3) {
				dp[j] = 1;
			} else {
				dp[j] = -1;
				q.push(j);
			}
		}
		// 우선 교 체  
		while(!q.empty()){
			int tmp, b = 0;
			int front = q.front();
			q.pop();

			if(dp[front] == -1) {
				for(int j = 1; j <= N; j++) {
					if(dp[j] == -1 && p[front] % 3 == j%3 ) {
						if(p[j]%3 == front % 3) {
							tmp = p[front];
							p[front] = p[j];
							p[j] = tmp;
							
							dp[front] = 1;
							dp[j] = 1;
							cnt++;
							
							break;
						} else {
							q2.push(front);
						}
					}
				}
			}		
		}
		// 후순위 교체 
		while(!q2.empty()){
			int tmp, b = 0;
			int front = q2.front();
			q2.pop();
			if(dp[front] == -1) {
				for(int j = 1; j <= N; j++){
					if(dp[j] == -1 && p[front] % 3 == j%3 ) {
						if(p[j]%3 == front % 3) {
							tmp = p[front];
							p[front] = p[j];
							p[j] = tmp;
										
							dp[front] = 1;
							dp[j] = 1;
							cnt++;
		
							break;
							
						} else {
							tmp = p[front];
							p[front] = p[j];
							p[j] = tmp;
				
							dp[j] = 1;
							cnt++;
	
							break;
						}
					}	
				}
			}
		}
		
		cout << "#" << i+1 << " " << cnt << endl;
	}
	
	return 0;
}


