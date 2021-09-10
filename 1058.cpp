#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
	int n,m,Max=0;
	scanf("%d%d",&n,&m);
	vector<set<char>> ans(m);
	bool allTrue=true;	//�ж��Ƿ�ȫ��
	int score[105]={0},rightNum[105]={0},wrongCount[105]={0},stuScore[1005]={0};	//ÿ���������ȷѡ��ĸ�����ÿ��������������ÿ��ѧ���ķ���
	for(int i=0;i<m;i++){
		int tmp;
		char tmpOpt;
		scanf("%d%d%d",&score[i],&tmp,&rightNum[i]);
		for(int j=0;j<rightNum[i];j++){
			scanf(" %c",&tmpOpt);
			ans[i].insert(tmpOpt);
		}
	}
	getchar();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			set<char> opt;
			int option;
			char stuOption;
			scanf("(%d",&option);
			bool flag=true;	//�ж�ÿ�����Ƿ�����
			for(int k=0;k<option;k++){
				scanf(" %c",&stuOption);
				opt.insert(stuOption);
			}
			scanf(")");
			getchar();
			if(option!=rightNum[j]){	//������ȷѡ�������һ����һ������
				wrongCount[j]++;
				allTrue=false;
				continue;
			}
			if(opt!=ans[j]){
				flag=false;
				allTrue=false;
			}
			if(flag)
				stuScore[i]+=score[j];
			else{
				wrongCount[j]++;
				if(Max<wrongCount[j]) Max=wrongCount[j];
			}
		}
	}
	if(allTrue) printf("Too simple");
	else{
		for(int i=0;i<n;i++){
			printf("%d\n",stuScore[i]);
		}
		printf("%d",Max);
		for(int i=1;i<=m;i++){
			if(wrongCount[i]==Max) printf(" %d",i+1);
		}
	}
	return 0;
}
