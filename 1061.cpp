#include <iostream>
#define MAXN 105
using namespace std;

int main(){
	int n,m;
	int score[MAXN],ans[MAXN],opt[MAXN];	//ÿ����ķ���,ÿ����Ĵ�,ѧ��ѡ��
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&score[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&ans[i]);
	}
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<m;j++){
			int tmp;
			scanf("%d",&tmp);
			if(tmp==ans[j]) sum+=score[j];
		}
		printf("%d%s",sum,i!=m-1?"\n":"");
	}
	return 0;
}
