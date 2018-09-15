#include <stdio.h>
#include <stdlib.h>


typedef struct Node *PtrToNode;
struct Node {
    int Data;
    PtrToNode Next;
};


PtrToNode Read();
PtrToNode AddToList(PtrToNode P, int x);
void ShowData(PtrToNode P);
PtrToNode Merge(PtrToNode *l1, PtrToNode *l2);


int main()
{
	PtrToNode L1, L2, L;

	L1 = Read();
	L2 = Read();
	L = Merge(&L1, &L2);
	ShowData(L);
	ShowData(L1);
	ShowData(L2);

	return 0;
}


PtrToNode Read()
{
	int x, n;
	PtrToNode P = NULL;
	scanf("%d", &n);

	while (n--) {
		scanf("%d", &x);
		P = AddToList(P, x);
	}

	return P;
}


PtrToNode AddToList(PtrToNode P, int x)
{
	PtrToNode pnew;
	pnew = malloc(sizeof(struct Node));
	pnew->Data = x;
	pnew->Next = P;
	return pnew;
}


void ShowData(PtrToNode P)
{
	while (P) {
		printf("%d ", P->Data);
		P = P->Next;
	}
	printf("\n");
}


PtrToNode Merge(PtrToNode *l1, PtrToNode *l2)
{
	PtrToNode pmerge;
	pmerge = NULL;

	while ((*l1) && (*l2)) {
		if ((*l1)->Data > (*l2)->Data) {
			pmerge = AddToList(pmerge, (*l1)->Data);
			(*l1) = (*l1)->Next;
		} else {
			pmerge = AddToList(pmerge, (*l2)->Data);
			(*l2) = (*l2)->Next;
		}
	}

	if ((*l1) == NULL) {
		while ((*l2)) {
			pmerge = AddToList(pmerge, (*l2)->Data);
			(*l2) = (*l2)->Next;
		}
	} else {
		while ((*l1)) {
			pmerge = AddToList(pmerge, (*l1)->Data);
			(*l1) = (*l1)->Next;
		}
	}

	return pmerge;
}