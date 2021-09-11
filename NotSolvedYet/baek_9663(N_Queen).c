#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

#define SUCCESS 1
#define FAIL 0

#define YES 1
#define NO 0

#define LENGTH 16
#define WIDTH 16

#define X 0
#define Y 1

#define QUEENRANGE 1
#define NOTINRANGE 0

/*
Using Stack , LET'S SOLVE N-QUEEN

Problem- Line 234, 243, 254, 255 
*/

typedef struct _QueenCorrdinate {
	int x; // ��
	int y; // ��
} Cor;

typedef struct _ChessBoard {
	int BoardState[LENGTH][WIDTH];
} ChessBoard;

 typedef struct _Node {
	 Cor *Corrdinate; // ���� ��ġ
	 ChessBoard *NodeChessBoard; // ü������ 
	 struct _Node *BeforeThisQueen; // ���� �� ��� 
	 int AbleLocationArray_y[WIDTH]; // ü�����带 �������� �� �࿡�� 0�� ������ ��ġ�� �����ϴ� ��. �׳� ���� ���ϼ� �ִ� ������ ��ġ�� ������ �迭�̴�. 
	 int y_index; // y ��ġ ����. 
	 int max_y_index; // ������ y ��ġ �� ����
} Node;

 typedef struct _Stack {
	 Node *Top; // ���� ���߿� ��ġ�� ��
	 Node *First; // ���� ���� ��ġ�� ��
	 ChessBoard *CurrentChessBoard; // ���� ��ġ�ɶ����� ������ ���� �׸�
	 int AbleQueenCount; // ���� ����� ���δ� ��ġ�ɶ����� queencount++
	 int QueenIndex; // ���� ���ö����� +1�� 
	 int QueenAbleCoordinatesArray[LENGTH][2]; // ���ݱ��� ��ġ�� ���� ��ǥ���� ����. ���߿� ���� ���� ��ǥ�� ������ ����� �ȴ���� �˻��ϴ� �뵵 
 } Stack;

 // ���� �ʱ�ȭ
void BoardClear(Stack *stack, int NumberofQueen) {

	 int i = 0;
	 int j = 0;

	 for (int i = 0; i < NumberofQueen; i++) {
		 for (int j = 0; j < NumberofQueen; j++) {
			stack->CurrentChessBoard->BoardState[i][j] = NOTINRANGE;
		 }
	 }
 }

// ������ �Լ� 
void printBoard(Stack *stack, int NumberofQueen) {
	for (int i = 0; i < NumberofQueen; i++) {
		for (int j = 0; j < NumberofQueen; j++) {
			printf("%d ", stack->CurrentChessBoard->BoardState[i][j]);
		}
		printf("\n");
	}
}

 // ���� �ʱ�ȭ 
 void stack_init(Stack *stack, int NumberofQueen) {
	 stack->AbleQueenCount = 0;
	 stack->Top = NULL;
	 stack->First = NULL;
	 stack->CurrentChessBoard = (ChessBoard*)malloc(sizeof(ChessBoard));
	 stack->QueenIndex = 0; 
	BoardClear(stack, NumberofQueen);
 }

 // ������ ������� ���� 
 int stack_is_empty(Stack *stack) {
	 if (stack->Top == NULL) return YES;

	 return NO;
 }

int DrawTopQueenRange(Stack *stack, int NumberofQueen) {

	// ������ ��������� top�� �����״� �����߻�
	 if (stack_is_empty(stack) == NO) {

		 int length = stack->Top->Corrdinate->x;
		 int width = stack->Top->Corrdinate->y;

		 // ���� 1�� �ٲٱ� 
		 // ��� ���� �ʿ����. ������ x�� 1�� ������ų�Ŷ� ��ĥ���� ������ �׷��� ���� 
		 for (int i = 0; i < NumberofQueen; i++) {
			 stack->CurrentChessBoard->BoardState[length][i] = QUEENRANGE;
		 }

		 // ���� 1�� �ٲٱ�
		 for (int j = 0; j < NumberofQueen; j++) {
			 stack->CurrentChessBoard->BoardState[j][width] = QUEENRANGE;
		 }

		 // �밢�� ������ �Ʒ� ����
		 while (length < NumberofQueen && width < NumberofQueen) {
			 stack->CurrentChessBoard->BoardState[length++][width++] = QUEENRANGE;
		 }

		 // �ٽ� �ʱ�ȭ ���ְ� 
		 length = stack->Top->Corrdinate->x;
		 width = stack->Top->Corrdinate->y;

		 // �밢�� ���ʾƷ����� 
		 while (length < NumberofQueen && width >= 0) {
			 stack->CurrentChessBoard->BoardState[length++][width--] = QUEENRANGE;
		 }
	 }

	 return SUCCESS;
 }

 // �� ��ǥ�� ����  
int setQueen(Stack *stack, int NumberofQueen) {

	// ���������� ù ���� y��ǥ�� ù ���� �߰��� �̻� ������ ���̴�. 
	// �ֳ�? �Էµ� �� ���� ���ݱ����� �ϰ� �ι����ָ� �Ǵϱ�.. �ð��ι�� ���� �� �ִ�. ���� Ȧ�����̸� �ι��ϰ� ����� �ѹ� ���ָ� �ȴ�.

	// ������ ������ �׳� ������ ������Ѻ��ڰ�~
	do {

	// 1. ���� ���� ���� ���� ���� ���ٸ�, (�� �� ó�� ������ ���) ���� ������ ��ġ �߿� ���� ���� ���� ���� ��ġ�Ѵ�. ����, ù ���� 0�̴�. 
	if (stack_is_empty(stack) == YES) {

		// �ϴ� ���� ���� ���� ������ 
		Node *NewQueen = (Node*)malloc(sizeof(Node));
		memset(NewQueen, -1, sizeof(Node));

		// ������ �� ó�� ���� 0,y���� ������ ���̴� 
		NewQueen->Corrdinate = (Cor*)malloc(sizeof(Cor));
		NewQueen->Corrdinate->x = 0;
		// nullptr�������� 
		// �׷� �̰� �� ��Ե� ���� �־�����Ѵٴ� �Ҹ��ε�...?
		// NewQueen->Corrdinate = (Cor*)malloc(sizeof(Cor)); �� �ذ�..?


		// �ϴ� 0���� �Էµ� �� ��-1 ��ŭ �迭�� �ִ´�. ������ ù���� ��� y���� �����ϴϱ�, 0���� 0, 1���� 1... 
		int index = 0;

		while (index < NumberofQueen) {
			NewQueen->AbleLocationArray_y[index] = index;
			index++;
		}

		// ���� ���� �� �ִ� y �ε����� �Ѱ����� ���Ѵ�.
		NewQueen->max_y_index = index;

		// �� ó���̴ϱ� y �ε��� ��ġ�� 0���� ��´�. 
		NewQueen->y_index = 0;

		// �׸����� arr���� ���� �տ��ִ°ź��� ���� 
		NewQueen->Corrdinate->y = NewQueen->AbleLocationArray_y[NewQueen->y_index];

		// // �� ù��° �� �ε����� 0
		//NewQueen->QueenIndex = 0;

		// ������ �� ��ǥ ����迭�� ù���� ��ǥ���� �ִ´� 
		stack->QueenAbleCoordinatesArray[NewQueen->Corrdinate->x][X] = NewQueen->Corrdinate->x;
		stack->QueenAbleCoordinatesArray[NewQueen->Corrdinate->x][Y] = NewQueen->Corrdinate->y;

		// �� ó���� ���ؼ�, ���� �ʱ����, �������� ���带 �����ϱ����� ��带 ���� �����. 
		Node *SaveNullBoard = (Node*)malloc(sizeof(Node));
		memset(SaveNullBoard, 0, sizeof(Node));

		SaveNullBoard->NodeChessBoard = stack->CurrentChessBoard;

		// �� ó�� ���� Ư���� �������� ���带 ����Ų��. ���߿� ������ �����ϵ��� 
		NewQueen->BeforeThisQueen = SaveNullBoard;

		//// �� ��ȣ�� �ο����ش�.  // �̰� �ʿ��ϳ�?
		//NewQueen->QueenIndex = NewQueen->Corrdinate->x;

		// ���� �� ���� ���ÿ� �¾Ƶ��� �غ� �Ǿ���
		stack->Top = NewQueen;

		// �� ������ First�� ������ �������̴�. 
		stack->First = NewQueen;

		// �� ��ǥ���� ���� ���忡 ����ǥ�����ش�.
		DrawTopQueenRange(stack, NumberofQueen);

		// �� ������ �׷��� ü�����带 ù���� ��忡 ������� 
		NewQueen->NodeChessBoard = stack->CurrentChessBoard;

		stack->QueenIndex++;

	}
	else {  // ���� ���� ù������ �������� �ƴ϶��..

		// 2. ���� ������ �� ������ ��� ���� �ʴ� y_index���� ã�ƺ���.  ���� �̶� ���� ����� ���� �� ��� ���� x��+1���� ������ش�. 

		// �� ������ 
		Node *NewQueen = (Node*)malloc(sizeof(Node));
		memset(NewQueen, -1, sizeof(Node));

		// 3. ���� �̹� x���� ó������ �����ϸ�, ���� �������� ��������, �̹� x��° �࿡�� 0�������� ��� ���ʴ�� �����Ѵ�. �� ������ �� ���� ��尡 �����Ǳ� �������� �ѹ��� ����ȴ�. 
		// �� �̰� �����̳� �ϸ� ���� ���� �� �࿡ �������� �ʴٴ� ��
		if (stack->Top->Corrdinate->x == stack->QueenIndex - 1) {
			int index = 0;
			// w

			for (int width = 0; width < NumberofQueen; width++) {
				if (stack->CurrentChessBoard->BoardState[stack->Top->Corrdinate->x + 1][width] != 1) {
					NewQueen->AbleLocationArray_y[index++] = width;
				}
			}

			// ������ �ึ�� y�ε��� �������� 0�̴�. // y�� ���� ������ �̻� ������ �ʴ´�. 
			NewQueen->y_index = 0;

			// �� ���� ���� �� �ִ� y �ε��� �Ѱ����� ���Ѵ�. // y�� ���� ������ �̻� ������ �ʴ´�. 
			NewQueen->max_y_index = index;
		}

		// 4. ���� ������ 0�� ���� ���, �� ���� ���ư���. **************���� ������ �ϸ� �ɵ� 
		if (NewQueen->AbleLocationArray_y[NewQueen->y_index] == NULL) {

			// ���� ���� �� �����Ƿ� free���ش�. 
			free(NewQueen);

			// �ٷ� ���� ���� ���� y�ε��� ��ġ�� +1���ش� 
			stack->Top->y_index++;

			// 5. �� ���� ���ư��µ�, ���� y�ε������� �������̾��ٸ�? �ٽ� ���� �÷������
			if (stack->Top->AbleLocationArray_y[stack->Top->y_index] == NULL) {

				// �� �����ִ� �� ��带 ���ְ� �Ǵٽ� �� ������ ���ư�����. 

				// ���� �� ��带 ���־� �ϴϱ� ������ ��带 ������ְ�, �̸� ���� top ���� ����. 
				Node *DeleteQueen = stack->Top;

				// �� �� ��尡 �����ִ� �����͵��� ���ÿ� ���� �ʱ�ȭ ���������



				stack->QueenAbleCoordinatesArray[stack->Top->Corrdinate->x][X] = NULL;
				stack->QueenAbleCoordinatesArray[stack->Top->Corrdinate->x][Y] = NULL;

				//(*stack->QueenAbleCoordinatesArray[stack->Top->Corrdinate->x]) = NULL;



				// ���� top�� ��ġ�� �������ش�. 
				stack->Top = stack->Top->BeforeThisQueen;

				// ������ ���� TOP�� Y�ε����� 1 �÷��ش�. 
				stack->Top->y_index++;

				// ü���� ���� �ٲ������. 
				// ������ 0��° �� ������ ��带 �ϳ� �������ν� ���� 0���� ���� Y��ġ�� �ٲ𶧵� ���������� �������� �۵��ǵ��� �ߴ�. 
				stack->CurrentChessBoard = stack->Top->BeforeThisQueen->NodeChessBoard;

				stack->QueenIndex--;

				// ���� ��������..
				free(DeleteQueen);
			}
		}
		else {  // 6. ������ �������� ��� ����, �� 0�� ���� ��� 

			// NewQueen->QueenIndex = ?
			// �̰� ���� �ϳ�>?? 

			// �� ���� x���� �� �� ���� x��+1�̴�. 		
			NewQueen->Corrdinate = (Cor*)malloc(sizeof(Cor));

			NewQueen->Corrdinate->x = stack->Top->Corrdinate->x + 1;

			// �� �� ��带 ������ ������ �� ���� �������ش�. 
			NewQueen->BeforeThisQueen = stack->Top;

			// �ٵ� ���� �� ������ ���̸� ���⼭ ī��Ʈ �÷�����Ѵ�. 
			if (NewQueen->Corrdinate->x == NumberofQueen - 1) {
				stack->AbleQueenCount++;
			}
			//TODO �̰� �� ó�� ��쿡 �߰��Ұ� ���� �Ѱ��ϼ��� ���� 

			// ���� ��ǥ ����ϰ� 
			NewQueen->Corrdinate->y = NewQueen->AbleLocationArray_y[NewQueen->y_index];

			stack->QueenAbleCoordinatesArray[NewQueen->Corrdinate->x][X] = NewQueen->Corrdinate->x;
			stack->QueenAbleCoordinatesArray[NewQueen->Corrdinate->x][Y] = NewQueen->Corrdinate->y;

			// top�� newqueen���� �������ְ� 
			stack->Top = NewQueen;

			// ���� �׸���
			DrawTopQueenRange(stack, NumberofQueen);

			// ���� ����ϰ� 
			NewQueen->NodeChessBoard = stack->CurrentChessBoard;

			stack->QueenIndex++;

		}
	}
} while (stack->First->Corrdinate->y < NumberofQueen);

		 return stack->AbleQueenCount; 
 }

 // 

 
 int main() {

	int Queen;
	Stack stack;

	scanf("%d", &Queen);

	stack_init(&stack, Queen);

	printf("%d",setQueen(&stack, Queen));


	return 0;
}
 // ����� 