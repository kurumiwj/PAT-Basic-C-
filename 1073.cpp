#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct question{
	set<char> ans;	//��ȷѡ��
	map<char,int> wrongCount;	//��¼ÿ��ѡ��Ĵ������
	int rightNum=0,maxWrongCount=0,score=0;	//��¼��ȷѡ��ĸ����ʹ��������Ŀѡ���ÿ����ķ���
};

int main(){
	int n,m,Max=0;
	scanf("%d%d",&n,&m);
	question q[m];
	bool allTrue=true;	//�ж��Ƿ�ȫ��
	double stuScore[1005]={0};	//ÿ��ѧ���ķ���
	for(int i=0;i<m;i++){
		int tmp;
		char tmpOpt;
		scanf("%d%d%d",&q[i].score,&tmp,&q[i].rightNum);
		for(int j=0;j<q[i].rightNum;j++){
			scanf(" %c",&tmpOpt);
			q[i].ans.insert(tmpOpt);
		}
	}
	getchar();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			set<char> opt;
			int option;
			char stuOption;
			scanf("(%d",&option);
			bool flag=true;	//�ж�ÿ������©ѡ���Ǵ�ѡ
			for(int k=0;k<option;k++){
				scanf(" %c",&stuOption);
				opt.insert(stuOption);
			}
			scanf(")");
			getchar();
			if(opt==q[j].ans)
				stuScore[i]+=q[j].score;
			else{
				for(auto k:opt){
					if(q[j].ans.find(k)==q[j].ans.end()){	//ѡ��
						flag=false;
						allTrue=false;
						q[j].wrongCount[k]++;
					}
				}
				for(auto k:q[j].ans){
					if(opt.find(k)==opt.end()){
						q[j].wrongCount[k]++;
					}
				}
				if(flag) stuScore[i]+=q[j].score*0.5;	//©ѡ
				else{
					q[j].maxWrongCount++;
					if(q[j].maxWrongCount>Max) Max=q[j].maxWrongCount;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%.1lf\n",stuScore[i]);
	}
	if(allTrue) printf("Too simple");
	else
		for(int i=0;i<m;i++){
			if(q[i].maxWrongCount==Max){
				char start='a';
				while(start<='e'){
					if(q[i].wrongCount.find(start)!=q[i].wrongCount.end()){
						if(q[i].wrongCount[start]==Max){
							printf("%d %d-%c\n",Max,i+1,start);
						}
					}
					start++;
				}
			}
		}
	return 0;
}
