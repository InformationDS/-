#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int lifeA,defA,atkA,atksA;
float critA,dodgeA;//定义智障小人A生命，护甲，攻击力，攻速，暴击，闪避 
int lifeB,defB,atkB,atksB;
float critB,dodgeB;//定义智障小人B生命，护甲，攻击力，攻速，暴击，闪避 

void attribute(){//设定A和B初始属
	lifeA=500;
	lifeB=500;
	defA=1;
	defB=1;
	critA=0.1;
	critB=0.1;
	dodgeA=0;
	dodgeB=0;
	printf("现在请玩家A和玩家B依次设定攻击力和攻速，二者相加为10\n");
	printf("玩家A设定\n");
	scanf("%d %d",&atkA,&atksA);\
	printf("玩家B设定\n");
	scanf("%d %d",&atkB,&atksB);
	printf("玩家A初始属性为：生命%d 护甲%d 攻击力%d 攻速%d 暴击%f 闪避%f\n",lifeA,defA,atkA,atksA,critA,dodgeA);
	printf("玩家B初始属性为：生命%d 护甲%d 攻击力%d 攻速%d 暴击%f 闪避%f\n",lifeB,defB,atkB,atksB,critB,dodgeB);
} 
void equipment(){//玩家选择装?
	int a,b,c,d,e,f;
	printf("每名玩家可以选择一件武器一件防具和一个宝石，装备名称、属性和编号如下：\n");
	printf("武器 Excalibur(1)暴击率50%% EA(2)攻击力10 UBW(3)攻速10\n");
	printf("防具 god_hand(4)生命250 Lor_Camelot(5)护甲5\n");
	printf("宝石 生命宝石(6)生命250 回避宝石(7)回避率30%%\n");
	printf("玩家A选择装备：");
	scanf("%d %d %d",&a,&b,&c);
	if(a==1){critA+=0.5;printf("Excalibur ");}
	if(a==2){atkA+=10;printf("EA ");}
	if(a==3){atksA+=10;printf("UBW ");}
	if(b==4){lifeA+=250;printf("god_hand ");}
	if(b==5){defA+=5;printf("Lord_Camelot ");}
	if(c==6){lifeA+=250;printf("生命宝石\n");}
	if(c==7){dodgeA+=0.3;printf("回避宝石\n");}
	printf("玩家B选择装备：");
	scanf("%d %d %d",&d,&e,&f);
	if(d==1){critB+=0.5;printf("Excalibur ");}
	if(d==2){atkB+=10;printf("EA ");}
	if(d==3){atksB+=10;printf("UBW ");}
	if(e==4){lifeB+=250;printf("god_hand ");}
	if(e==5){defB+=5;printf("Lord_Camelot ");}
	if(f==6){lifeB+=250;printf("生命宝石\n");}
	if(f==7){dodgeB+=0.3;printf("回避宝石\n");} 
} 
int pandin(float n){//判定暴击与回避，返回0不暴击不回避，返回1暴击回
    int a,i;
    int x=0;
    srand((unsigned int)time(NULL));
    a=rand()%100+1;
	if(a<=100*n)x=1;
	return x;	
} 
void process(){//作战过?
	printf("Game start!\n");
	int n=1;
	int crit=0;
	int dodge=0;
	for(;lifeA>0&&lifeB>0;n++){
		int m;
		int A=lifeA;
		int B=lifeB;
		printf("Round%d\n",n);
		for(m=0;m<2;m++){
		crit=pandin(critA);
		}
		for(m=0;m<2;m++){
		dodge=pandin(dodgeB);
		}
		if(dodge==0){
			if(crit==1){lifeB=lifeB-atkA*atksA*2+defB;printf("B生命值%d,受到暴击伤害%d   ",lifeB,B-lifeB);}
			else if(crit==0){lifeB=lifeB-atkA*atksA+defB;printf("B生命值%d,受到非暴击伤害%d   ",lifeB,B-lifeB);}
		}
		else if(dodge==1)printf("B闪避了此次攻击   ");
		for(m=0;m<2;m++){
		crit=pandin(critB);
		}
		for(m=0;m<2;m++){
		dodge=pandin(dodgeA);
		}
		if(dodge==0){
			if(crit==1){lifeA=lifeA-atkB*atksB*2+defA;printf("A生命值%d,受到暴击伤害%d   ",lifeA,A-lifeA);}
			else if(crit==0)lifeA=lifeA-atkB*atksB+defA;printf("A生命值%d,受到非暴击伤害%d   ",lifeA,A-lifeA);
		}
		else if(dodge==1){printf("A闪避了此次攻击   ");}
		printf("\n");	
	}
} 

int main()
{
	attribute();
	equipment();
	process();
	printf("\n");
	if(lifeA>0&&lifeB<=0)printf("A获胜");
	if(lifeA<=0&&lifeB>0)printf("B获胜");
	if(lifeA<=0&&lifeB<=0)printf("平局");
	return 0;
} 
