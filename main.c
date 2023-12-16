#include <stdio.h>
#include <stdlib.h>
 
//定义训练用的数据
double data1[2]={1,1};
double data2[2]={-1,-1};
//定义数据的标准分类
double data1_class=1;      
//假设data1的类型为
double data2_class=0;      
//假设data2的类型为0//定义权重和偏置
double w[2]={0,0};         
//这里用任意值初始化即可，训练的目的就是自动调整这个值的大小
double b=0;  
//加权求和
double sumfun(double *data,double *weight,double bias)
{    
	return (data[0]*weight[0]+data[1]*weight[1]+bias);
}
//这里采用阶跃函数作为激活函数
double step(double sum)
{    
	if(sum>0)        
		return 1;    
	else
        return 0;
}
int main(){ 
   
	double sum=0;                //存放加权求和的值
    double output1=0,output2=0;  //把加权求和的值代入激活函数而得到的输出值
    int count=0;                 //训练次数的计数变量
    double err=0;                //计算的误差，用于对权值和偏置的修正
    int flag1=0,flag2=0;         //训练完成的标志，如果某组数据训练结果达标，则把标志置1，否则置0
 
    while(1)
    {
        sum=sumfun(data1,w,b);  //代入第一组data进行计算
        output1=step(sum);        
		if(output1==data1_class)//判断输出是否达标，若达标则把标志置1，否则修正权值和偏置
            flag1=1;        
		else
        {
            flag1=0;
            err=data1_class-output1;
            w[0]=w[0]+err*data1[0];
            w[1]=w[1]+err*data1[1];
            b=b+err;
        }
 
        sum=sumfun(data2,w,b);  //代入第二组data进行计算
        output2=step(sum);        
		if(output2==data2_class)//判断输出是否达标，若达标则把标志置1，否则修正权值和偏置
            flag2=1;        
		else
        {
            flag2=0;
            err=data2_class-output2;
            w[0]=w[0]+err*data2[0];
            w[1]=w[1]+err*data2[1];
            b=b+err;
        }        
		printf("The %d's training output:\n",count+=1);       //输出训练结果
        printf("    First Group's data belongs to %1.0f class.\n",output1);        
		printf("    First Group's data belongs to %1.0f class.\n",output2);        
		if(flag1==1&&flag2==1)   //如果所有数据都训练达标，则直接跳出循环
        {           
			break;
        }
    }    
	printf("\n\nThe traning done!\n\n");    return 0;
}
