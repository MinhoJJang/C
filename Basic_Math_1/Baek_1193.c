#include <stdio.h> //ǥ�� �������� 
#pragma warning(disable:4996) //scanf()�� ANSI C�Լ� ���� �޼��� ����

//���� https://www.acmicpc.net/problem/1193

/*					��
		1   2   6   7   15
		3   5   8   14
	    4   9   13
�Ʒ�	10 12
		11
�밢�� ������� ���� 

X��° ��.. 1+2+...+n<=X< 1+2+...+(n+1)
X���� ���� ���鼭 n�� ã�� 
*/

int main() {

	int X;
	int count = 0;
	//printf("���ڸ� �Է��ϼ���");
	scanf("%d", &X);

	int sum = 0;
	int n;

	for (n = 1; ; n++) //���ѷ���
	{
		sum += n; //n�� 1���� ��� ���� ���� sum
		if (X - sum > 0) //�Է¹��� �� X���� sum�� ���� ����ϰ��
		{
			count++; //count�� 0���� 1��ŭ �÷��ش� 
		}
		else if (X - sum <= 0) //�Է¹��� �� X���� sum�� ���� �����̰ų� 0�ϰ��
		{
			break; 
			//�Լ�����
			//�� ���� ó������ 0���� ������ �Ǿ����Ƿ� break�� ������ n����
			//1+2+...+(n-1)<= X < 1+2+...+n �� ������ 
		}
	}
	//printf("%d\n", count); //1���� n���� ���� ����. ���° ������ �˷���.
	//printf("%d\n", X - (sum - n)); //�� �ٿ��� ���������� ���° ���ΰ�?
	int diff = X - (sum - n); 

	//n�� Ȧ���� �Ʒ����� ���� , ¦���� ������ �Ʒ��� 
	if (n % 2 == 0) {
		printf("%d/%d", diff, count + 2 - diff);
	}
	else {
		printf("%d/%d", count+2-diff, diff);
	}

	return 0;
} //�¾ҽ��ϴ�!