#include <iostream>
using namespace std;

int arr[100001];
int inOrder[100001];
int postOrder[100001];
int idx[100001];

void preOrder(int inBegin, int inEnd, int postBegin, int postEnd) {
	//모순
	if (inBegin > inEnd || postBegin > postEnd) return;


	//막힘

	int root = postOrder[postEnd];

	cout << root << " ";

	//왼쪽

	preOrder(inBegin, idx[root] - 1, postBegin, postBegin + (idx[root] - inBegin) - 1);

	//오른쪽

	preOrder(idx[root] + 1, inEnd, postBegin + (idx[root] - inBegin), postEnd - 1);




	
}

int main() {
	int arr[100001];
	int i;
	cin >> i;
	;
	
	//inOrder
	for (int j = 0; j < i; j++) {
		cin >> inOrder[j];
	}
	
	//postOrder
	for (int j = 0; j < i; j++) {
		cin >> postOrder[j];
	}

	//inOrder
	for (int j = 0; j < i; i++) {
		idx[inOrder[j]] = j;
	}

	preOrder(0, i - 1, 0, i - 1);
	cout << '\n';
	return 0;
}

//하다가 막혀서 그냥 구글링 해버렸어요
//https://jaimemin.tistory.com/1156