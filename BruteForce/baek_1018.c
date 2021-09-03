#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
https://www.acmicpc.net/problem/1018
�����̴� �ڽ��� ���ÿ��� MN���� ���� ���簢������ �������� �ִ� M*N ũ���� ���带 ã�Ҵ�. � ���簢���� ���������� ĥ���� �ְ�, �������� ������� ĥ���� �ִ�. �����̴� �� ���带 �߶� 8*8 ũ���� ü�������� ������� �Ѵ�.

ü������ �������� ����� �����Ƽ� ĥ���� �־�� �Ѵ�. ��ü������, �� ĭ�� �������� ��� �� �ϳ��� ��ĥ�Ǿ� �ְ�, ���� �����ϴ� �� ���� �簢���� �ٸ� ������ ĥ���� �־�� �Ѵ�. ���� �� ���Ǹ� ������ ü������ ��ĥ�ϴ� ���� �� �������̴�. �ϳ��� �� ���� �� ĭ�� ����� ���, �ϳ��� �������� ����̴�.

���尡 ü����ó�� ĥ���� �ִٴ� ������ ���, �����̴� 8*8 ũ���� ü�������� �߶� �Ŀ� �� ���� ���簢���� �ٽ� ĥ�ؾ߰ڴٰ� �����ߴ�. �翬�� 8*8 ũ��� �ƹ������� ��� �ȴ�. �����̰� �ٽ� ĥ�ؾ� �ϴ� ���簢���� �ּ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���ü� �ִ� ������ ����� �� 

(N - 7) * (M - 7)
*/

#define MAX 55

int main() {

	char Input_WhiteBlack_Board[MAX][MAX];
	int BasicBoard[MAX][MAX] = { 0 }; 
	// W,B�� ���ǻ� 0�� 1�� �ٲ� ���� 
	// White = 0, Black = 1

	int width;
	int length;
	
	scanf("%d %d", &length, &width);

	for (int len = 0; len < length; len++) {
		scanf("%s", Input_WhiteBlack_Board[len]);
	}
		
	for (int len = 0; len < length; len++) {
		for (int wid = 0; wid < width; wid++) {
			if (Input_WhiteBlack_Board[len][wid] == 'B') {
				BasicBoard[len][wid] = 1;
			}
		}
	}

	int StoreNumberofColored[MAX][MAX];

	for (int len = 0; len + 7 < length; len++) {
		for (int wid = 0; wid + 7 < width; wid++) {

			int NumberOfColored = 0;
			int StartNum = BasicBoard[len][wid];
			int Cur_len = len; // Cur == current
			int Cur_wid = wid;
			int StartLocation = (len + wid) % 2;

			// White ������ ���
			if (StartNum == 0) {

				for (Cur_len = len; Cur_len < len + 8; Cur_len++) {
					for (Cur_wid = wid; Cur_wid < wid + 8; Cur_wid++) {
						int Cur_num = BasicBoard[Cur_len][Cur_wid];
						int Cur_location = (Cur_len + Cur_wid) % 2;

						if (Cur_location == StartLocation) {
							if (Cur_num != StartNum) {
								NumberOfColored++;
							}
						}
						else if (Cur_location != StartLocation) {
							if (Cur_num == StartNum) {
								NumberOfColored++;
							}
						}		
					}
				}							
			}

			else if (StartNum == 1) {

				for (Cur_len = len; Cur_len < len + 8; Cur_len++) {
					for (Cur_wid = wid; Cur_wid < wid + 8; Cur_wid++) {
						int cur_num = BasicBoard[Cur_len][Cur_wid];
						int curlocation = (Cur_len + Cur_wid) % 2;

						if (curlocation == StartLocation) {
							if (cur_num != StartNum) {
								NumberOfColored++;
							}
						}
						else if (curlocation != StartLocation) {
							if (cur_num == StartNum) {
								NumberOfColored++;
							}
						}
					}
				}
			}

			// ���������, 64���߿��� ������ �Ѱ� �ٲ�ߵȴٸ� �װ� �׳� �������� �ٲ��ָ� ���� ������? 
			if (NumberOfColored > 32) {
				NumberOfColored = 64 - NumberOfColored;
			}
			StoreNumberofColored[len][wid] = NumberOfColored;
			if (NumberOfColored == 0) {
				printf("%d", NumberOfColored);
				return 0;
			}
		}
	}

	int MinimumNumber = StoreNumberofColored[0][0];

	for (int len = 0; len + 7 < length; len++) {
		for (int wid = 0; wid + 7 < width; wid++) {

			if (MinimumNumber > StoreNumberofColored[len][wid]) {
				MinimumNumber = StoreNumberofColored[len][wid];
			}
		}
	}

	printf("%d", MinimumNumber);

	return 0;
} // �¾ҽ��ϴ�!!!!