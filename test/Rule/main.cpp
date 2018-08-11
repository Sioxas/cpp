#include <iostream>
#include <algorithm>
using namespace std;

char *facts[]={"",
	"反刍","有蹄","哺乳类","眼向前方","有爪",      //1-5
	"犬齿","吃肉","下蛋","能飞","有羽毛",
	"蹄类","食肉类","鸟类","有奶","毛发",
	"善飞","黑色白条纹","游泳","长腿","长脖子",
	"黑条纹","暗斑点","黄褐色"
};

char *resultSet[]={"",
	"信天翁","企鹅","鸵鸟","斑马","长颈鹿","虎","豹"  //1-7
};

struct factDB{         //综合数据库中的已知事实
	 int curNum;
	 int fact[30];
	 int initNum;
}factDb;

struct Rule{          //规则 结构体
	int factNum;      
	int fact[5];
	bool endResult;     //是否为结果集
	int resultID;       //推出的结果ID
	bool used;			//已使用过标志
	bool possible;      //是否可能标志，针对-9（不能飞）若Rule中有9，而综合数据库中有-9 则该规则标记不可能
	int needFactPos;    //通过事实比较，记录下一个需要的事实位置，方便下次比较开始点后移和首先寻找该位置值是否新增即可
}*rule;

bool findNeedFact(int factID,int pos)     //寻找needFactPos位置值是否存在于综合事实库中
{
	int i=pos;
	for(;i<factDb.curNum;i++) 
	{
		if(factID==factDb.fact[i])return true;
		if(factID<factDb.fact[i])return false;
	}
	return false;
}

bool cmpArray(Rule &r)      //两个数组的事实比较
{
	int i,j;
	i=r.needFactPos;
	j=i;
	while(i<r.factNum)
	{
		while(j<factDb.curNum)
		{
			if(r.fact[i]==factDb.fact[j])
			{
				i++;
				if(i==r.factNum)return true;
			}
			else if(r.fact[i]<factDb.fact[j])
			{
				if(r.fact[i]<0 && findNeedFact(-r.fact[i],i))r.possible=false;   //当存在相反情况时，标记不可能
				r.needFactPos=i;
				return false;
			}
			j++;
		}
		if(i<r.factNum){r.needFactPos=i;return false;}
	}
	return true;
}

int cmpFact(Rule &r)
{
	if(r.factNum>factDb.curNum)return 0;        //已知事实还没有该规则事实多
	if(r.needFactPos)
	{
		if(!findNeedFact(r.fact[r.needFactPos],r.needFactPos))return 0; //需要的值还不存在
		else r.needFactPos++;
	}
	if(cmpArray(r))
	{
		r.used=true;
		if(r.endResult)return 1;     //得到了最终结果
		else return 2;               //得到中间结果
	}else return 0;
}

int main()
{
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	rule=(Rule *)malloc(sizeof(Rule)*n);
	int i,j;
	for(i=0;i<n;i++)
	{
		cin>>rule[i].factNum;
		for(j=0;j<rule[i].factNum;j++)
			cin>>rule[i].fact[j];
		sort(rule[i].fact,rule[i].fact+rule[i].factNum);
		cin>>rule[i].endResult>>rule[i].resultID;
		rule[i].used=false;
		rule[i].possible=true;
		rule[i].needFactPos=0;
	}
	
	cin>>factDb.initNum;
	factDb.curNum=factDb.initNum;
	cout<<"原始事实综合数据库："<<endl;
	for(i=0;i<factDb.initNum;i++)
	{
		cin>>factDb.fact[i];
		cout<<facts[factDb.fact[i]]<<"\t";
	}
	cout<<endl<<endl;
	sort(factDb.fact,factDb.fact+factDb.curNum);

	int res;
	bool isEnd=false;
	while(!isEnd)
	{
		isEnd=true;
		for(i=0;i<n;i++) 
		{
			if(rule[i].used || !rule[i].possible)continue;
			res=cmpFact(rule[i]); 
			if(res==0)continue;//不匹配
			else if(res==1)   //匹配成功，得到最终结果
			{
				cout<<"得到最终结果："<<resultSet[rule[i].resultID]<<endl;
				return 0;
			}
			else if(res==2)//匹配成功，得到中间结果
			{
				cout<<"得到中间结果："<<facts[rule[i].resultID]<<endl;
				cout<<"\t将其加入到现有的事实数据库中。。。"<<endl<<endl;
				factDb.fact[factDb.curNum]=rule[i].resultID;
				factDb.curNum++;
				sort(factDb.fact,factDb.fact+factDb.curNum);      //这里是在有序数组里插入，应使用插入排序为宜
				isEnd=false;
			}
		}
	}
	cout<<"现有事实无法推断出结果！"<<endl;

	return 0;
}
