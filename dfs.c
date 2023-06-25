#include <stdio.h>

int stack[5], top=-1, known[10], n, a[10][10];

void push(int val){
	stack[++top]=val;
}

int pop(){
	int ver = stack[top--];
	printf("%d-> ",ver);
	return ver;
}

int stackempty(){
	if(top==-1)
		return 1;
	return 0;
}

void dfs(int sv){
	push(sv);
	known[sv]=1;
	while(!stackempty()){
		int v = pop();
		for(int i=n; i>0; i--){
			if(a[v][i] && !known[i]){
				push(i);
				known[i]=1;
			}
		}
	}
}

int main() {
	int sv;
	printf("Enter number of vertices: ");
	scanf("%d", &n);
	printf("Enter %d elements into adjcency matrix:\n", n*n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			scanf("%d", &a[i][j]);
	printf("Enter start vertex: ");
	scanf("%d", &sv);

	dfs(sv);
	printf("\n");
}


