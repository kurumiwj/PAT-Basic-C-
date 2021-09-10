#include <iostream>
#include <string>
using namespace std;

int main(){
	int n,m,cnt_n=0,cnt_m=0;
	bool flag[10000]={false};
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int tmp;
		scanf("%d",&tmp);
		flag[tmp]=true;
	}
	for(int i=0;i<n;i++){
		string name;
		cin>>name;
		int items;
		scanf("%d",&items);
		bool isQuestion=false;	//��¼ѧ���Ƿ�������
		for(int j=0;j<items;j++){
			int item;
			scanf("%d",&item);
			if(flag[item]){
				if(!isQuestion){
					isQuestion=true;
					cnt_n++;
					cout<<name<<":";
				}
				printf(" %04d",item);
				cnt_m++;
			}
		}
		if(isQuestion) printf("\n");
	}
	printf("%d %d",cnt_n,cnt_m);
	return 0;
}
