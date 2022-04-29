#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//[BOJ] 2263. 트리의 순회 / 골드 2 / 답 보고 직접 구현 대충 2~3시간 걸린듯

int n, here = 0;
int inorder[100001], postorder[100001], preorder[100001];

void dnc(int inS, int inE, int postS, int postE) {
	preorder[here] = postorder[postE];
	here++;
	//종료 조건
	if (inS == inE)
		return;

	int rootidx = -1;
	for (int i = 0; i < n; i++) {
		if (inorder[i] == postorder[postE]) {
			rootidx = i;
			break;
		}
	}

	//오른쪽 왼쪽 서브트리의 원소 갯수
	int numR = inE - rootidx, numL = rootidx - inS;

	//왼쪽 서브트리
	if (numL > 0) //이거 빼먹음;;; 안하면 메모리 초과남
		dnc(inS, rootidx - 1, postS, postS + numL - 1);
	//오른쪽 서브트리
	if (numR > 0)
		dnc(rootidx + 1, inE, postE - 1 - (numR - 1), postE - 1);
}
//반례 한쪽 서브트리 크기가 0인 경우 

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inorder[i];
	for (int i = 0; i < n; i++)
		cin >> postorder[i];

	/*
	post는 맨 뒤는 최상단 루트노드임
	이거 써먹으면서 inorder 왼쪽 서브트리, 루트, 오른쪽 서브트리로 나눠서 접근

	분할정복 재귀로
	*/

	dnc(0, n - 1, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << preorder[i] << " ";
}