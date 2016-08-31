#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
class Person
{
     public:
        Person(){};
		void new_card(char *card_type);
		void log_off(char *card_type);
		void show_person_information(char *card_type);
     private:
   	    string name;
		string sex;
		string work;
		string unit;
		string number;
		int riding_number; 
};
void Person::new_card(char *card_type)
{
   	 FILE *fp,*fp1,*fp2;int flag=0,i=0,palce_initialize=-1;
   	 char s[100][100],se[100][100],wo[100][100],un1[100][100],num[100][100];int ri1[100];
   	 int onecard_number,balance,valid_period;
     cout<<"姓名：";
     cin>>name;
     cout<<"性别：";
     cin>>sex;
     cout<<"职位：";
     cin>>work;
	 cout<<"所属单位：";
	 cin>>unit;
	 cout<<"工资号/学号：";
	 cin>>number;
	 riding_number=0;
	 if((fp1=fopen("person.txt","r"))==NULL)
	 {
	    cout<<"无法打开文件"<<endl;
		exit(0);	
	 }
	 while(!feof(fp1))
	 {
	 	fscanf(fp1,"%s %s %s %s %s %d\n",s[i],se[i],wo[i],un1[i],num[i],&ri1[i]);
	 	if(num[i]==number) {flag=1;break;}
	 	i++;
	 }
	 fclose(fp1);
	 if(flag==0)
	 { 
		 if((fp=fopen("person.txt","a+"))==NULL)
		 {
	        cout<<"无法打开文件"<<endl;
			exit(0);
		 }
		fprintf(fp,"%s %s %s %s %s %d\n",name.c_str(),sex.c_str(),work.c_str(),unit.c_str(),number.c_str(),riding_number);
		fclose(fp);
	 }
	 cout<<"一卡通号：";
	 cin>>onecard_number;
	 cout<<"有效期：";
	 cin>>valid_period; 
     if((fp2=fopen(card_type,"a+"))==NULL)
	 {
	 
        cout<<"无法打开文件"<<endl;
		exit(0);
	 }
	 if(card_type=="teacher.txt")
	 {
	 	fprintf(fp2,"%s %ld %s %ld %d %d\n",name.c_str(),onecard_number,unit.c_str(),valid_period,riding_number,palce_initialize);
	 }
	 else
	 { 
	    cout<<"余额：";
		cin>>balance; 
	    fprintf(fp2,"%s %ld %s %ld %d %d %d\n",name.c_str(),onecard_number,unit.c_str(),valid_period,balance,riding_number,palce_initialize);
	 } 
	 fclose(fp2);
}
void Person::log_off(char *card_type)
{
    FILE *fp1,*fp;
	int i=0,j=0,k=0,on,flag=-1,flag1=-1,times=0;string name;
	char s[100][100];long onc[100];char un[100][100];long va[100];int ba[100],ri[100],p[100];
	char s1[100][100],se[100][100],wo[100][100],un1[100][100],num[100][100];int ri1[100];
	cout<<"输入卡号：";
	cin>>on;
    if((fp1=fopen(card_type,"r"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	while(!feof(fp1))
	{
		if(card_type=="teacher.txt")
		{
		    fscanf(fp1,"%s %ld %s %ld %d %d\n",s[i],&onc[i],un[i],&va[i],&ri[i],&p[i]);
		}
		else 
		{
			fscanf(fp1,"%s %ld %s %ld %d %d %d\n",s[i],&onc[i],un[i],&va[i],&ba[i],&ri[i],&p[i]);
		}
		if(onc[i]==on)
		{
			flag=i;
			name=s[i];
		}
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(name==s[j])
		{
			times++;
		}
	}
	fclose(fp1);
	if((fp1=fopen(card_type,"w"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	for(j=0;j<i;j++)
	{
		if(j!=flag)
		{
			if(card_type=="teacher.txt")
			{
				fprintf(fp1,"%s %ld %s %ld %d %d\n",s[j],onc[j],un[j],va[j],ri[j],p[j]);
			}
			else
		        fprintf(fp1,"%s %ld %s %ld %d %d %d\n",s[j],onc[j],un[j],va[j],ba[j],ri[j],p[j]);
		}
	}
	fclose(fp1);
	if(times<=1)
	{
	    if((fp=fopen("person.txt","r"))==NULL)
	    {
           cout<<"无法打开文件"<<endl;
		   exit(0);
	    }
		while(!feof(fp))
		{
		   fscanf(fp,"%s %s %s %s %s %d\n",s1[k],se[k],wo[k],un1[k],num[k],&ri1[k]);
		   if(name==s1[k])
		   {
		   	  flag1=k;
		   }
		   k++;
		}
		fclose(fp);
	    if((fp=fopen("person.txt","w"))==NULL)
	    {
           cout<<"无法打开文件"<<endl;
		   exit(0);
	    }
	    for(j=0;j<k;j++)
	    {
	       if(j!=flag1)
	    	{
	    	   fprintf(fp,"%s %s %s %s %s %d\n",s1[j],se[j],wo[j],un1[j],num[j],ri1[j]);
	    	}
	    }
	    fclose(fp);
	}
	cout<<"已注销"<<endl; 
}
void Person::show_person_information(char *card_type)
{
	FILE *fp,*fp1;int k=0,i=0,sum=0,j=0,flag=0;
	string num,nam;
	char s[100][100];long onc[100];char un[100][100];long va[100];int ba[100],ri[100],p[100];
	char s1[100][100],se[100][100],wo[100][100],un1[100][100],nu[100][100];int ri1[100];
	cout<<"工资号/学号：";
	cin>>num; 
	if((fp=fopen("person.txt","r"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %s %s %s %d\n",s1[k],se[k],wo[k],un1[k],nu[k],&ri1[k]);
		if(num==nu[k])
		{
		   nam=s1[k];
		}
		k++;
	}
	fclose(fp);
	k=0;
    if((fp1=fopen(card_type,"r"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	while(!feof(fp1))
	{
		if(card_type=="teacher.txt")
		{
		    fscanf(fp1,"%s %ld %s %ld %d %d\n",s[i],&onc[i],un[i],&va[i],&ri[i],&p[i]);
		}
		else 
		{
			fscanf(fp1,"%s %ld %s %ld %d %d %d\n",s[i],&onc[i],un[i],&va[i],&ba[i],&ri[i],&p[i]);
		}
		if(nam==s[i])
		{
			sum+=ri[i];
		}
		i++;
	}
	fclose(fp1);
	if((fp=fopen("person.txt","r"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %s %s %s %d\n",s1[k],se[k],wo[k],un1[k],nu[k],&ri1[k]);
		if(num==nu[k])
		{
		   ri1[k]=sum;
		   cout<<"姓名："<<s1[k]<<endl;
		   cout<<"性别："<<se[k]<<endl;
		   cout<<"职务："<<wo[k]<<endl;
		   cout<<"所属单位："<<un1[k]<<endl;
		   cout<<"工资号："<<nu[k]<<endl; 
		   cout<<"乘车次数："<<sum<<endl;
		   flag=1; 
		}
		k++;
	}
	fclose(fp);
	if(flag==0)
	{
		cout<<"查无此人"<<endl; 
	}
	if((fp=fopen("person.txt","r+"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	for(j=0;j<k;j++)
	{
	    fprintf(fp,"%s %s %s %s %s %d\n",s1[j],se[j],wo[j],un1[j],nu[j],ri1[j]);
    }
	fclose(fp);
} 
class Bus
{
	public:
		Bus(){}
		void new_bus();
		void show_basic_information();
		void get_actual_time();
        void show_run_information();
    private:
    	string bus_number;
    	string bus_type;
    	string driver_name;
    	string bus_run_time;
    	int bus_load;
    	int bus_runtime;
    	string leave_arrive_time[24];
        string actual_leave_arrive_time[24];
    	int actual_bus_load;
};
void Bus::new_bus()
{
	    FILE *fp;int i,j;
        cout<<"车牌号:";
        cin>>bus_number;
        cout<<"型号:";
        cin>>bus_type;
        cout<<"驾驶员姓名:";
        cin>>driver_name;
	    cout<<"运行时间段:";
	    cin>>bus_run_time;
		cout<<"载乘人数:";
		cin>>bus_load;
		cout<<"预计全程运行时间:";
		cin>>bus_runtime;
		for(j=1;j<=2;j++)
		{
			cout<<"班次"<<j<<"："<<endl; 
			i=12*(j-1);
			while(i<12*j)
			{
			    if(i==0||i==12)
			    {
			    	cout<<"去程:"<<endl; 
			    }
			    else cout<<"回程:"<<endl; 
			    cout<<"离开起点的时间:";
				cin>>leave_arrive_time[i];
				i++;
				cout<<"到达中途停车点1的时间:";
				cin>>leave_arrive_time[i];
				i++;
				cout<<"离开中途停车点1的时间:";
				cin>>leave_arrive_time[i];
				i++;
				cout<<"到达中途停车点2的时间:";
				cin>>leave_arrive_time[i];
				i++; 
				cout<<"离开中途停车点2的时间:";
				cin>>leave_arrive_time[i]; 
				i++; 
				cout<<"到达终点的时间:";
				cin>>leave_arrive_time[i];
				i++; 
		    }
		}
		if((fp=fopen("bus.txt","a+"))==NULL)
	    {
            cout<<"无法打开文件"<<endl;
		    exit(0);
	    }
	    fprintf(fp,"%s %s %s %s %d %d",bus_number.c_str(),bus_type.c_str(),driver_name.c_str(),bus_run_time.c_str(),bus_load,bus_runtime);
	    for(i=0;i<24;i++)
	    {
	    	fprintf(fp," %s",leave_arrive_time[i].c_str());
	    }
	    fprintf(fp,"\n");
		fclose(fp);
}
void Bus::show_basic_information()
{
	 FILE *fp;
     string on;
     char nu[20],ty[20],na[20],ru[20],le_ar_ti[24][100];
     int lo,rut,i,j,flag=0;
     cout<<"输入要查询的车牌号:";
	 cin>>on;
	 if((fp=fopen("bus.txt","r"))==NULL)
	 {
         cout<<"无法打开文件"<<endl;
		 exit(0);
	 }
	 while(!feof(fp))
	 {
	 	fscanf(fp,"%s %s %s %s %d %d",nu,ty,na,ru,&lo,&rut);
	 	for(i=0;i<24;i++)
	 	{
	 		if(i==23)
	 		{
	 				fscanf(fp," %s\n",le_ar_ti[i]);
	 		}
	 		else    fscanf(fp," %s",le_ar_ti[i]);
	 	}
	 	if(nu==on)
	 	{
	 		cout<<"车牌号:"<<nu<<endl;
	 		cout<<"型号:"<<ty<<endl;
			cout<<"驾驶员姓名:"<<na<<endl;
			cout<<"运行时间段:"<<ru<<endl;
			cout<<"载乘人数:"<<lo<<endl;
			cout<<"预计全程运行时间:"<<rut<<endl;
			flag=1;
			for(j=1;j<=2;j++)
			{
				cout<<"班次"<<j<<"："<<endl; 
				i=12*(j-1);
				while(i<12*j)
				{
					if(i==0||i==12)
					{
					    	cout<<"去程:"<<endl; 
					}
					else cout<<"回程:"<<endl; 
					cout<<"离开起点的时间:"<<le_ar_ti[i]<<endl;
					i++;
					cout<<"到达中途停车点1的时间:"<<le_ar_ti[i]<<endl;
					i++;
					cout<<"离开中途停车点1的时间:"<<le_ar_ti[i]<<endl;
					i++;
					cout<<"到达中途停车点2的时间:"<<le_ar_ti[i]<<endl;
					i++; 
				    cout<<"离开中途停车点2的时间:"<<le_ar_ti[i]<<endl;
				    i++; 
					cout<<"到达终点的时间:"<<le_ar_ti[i]<<endl;
				    i++; 
			   }
		   }
		}
	 }
	 if(flag==0)
	 {
	 	cout<<"查无此车"<<endl; 
	 }
	 fclose(fp);
}
void Bus::get_actual_time()
{
	int i,j;
	for(j=1;j<=2;j++)
	{
		cout<<"班次"<<j<<"："<<endl; 
		i=12*(j-1);
		while(i<12*j)
		{
		    if(i==0||i==12)
			{
			    cout<<"去程:"<<endl; 
			}
			else cout<<"回程:"<<endl; 
			cout<<"离开起点的时间:";
			cin>>actual_leave_arrive_time[i];
			i++;
			cout<<"到达中途停车点1的时间:";
			cin>>actual_leave_arrive_time[i];
			i++;
			cout<<"离开中途停车点1的时间:";
			cin>>actual_leave_arrive_time[i];
			i++;
			cout<<"到达中途停车点2的时间:";
			cin>>actual_leave_arrive_time[i];
			i++; 
			cout<<"离开中途停车点2的时间:";
			cin>>actual_leave_arrive_time[i]; 
			i++; 
			cout<<"到达终点的时间:";
			cin>>actual_leave_arrive_time[i];
			i++; 
		}
	}	
}
void Bus::show_run_information()
{
	FILE *fp,*fp1;
	string on;
	int k=0,i,j;
	char nu[20][20],ty[20][20],na[20][20],ru[20][20],le_ar_ti[24][20],ac_le_ar_ti[24][20];int lo[20],rut[20];
	char bus[20][20];float ap[20];float di[20],di1[20],di2[20];
	float time1=0,time2=0,di_1,di_2,load;
	cout<<"输入要查询的车牌号:"<<endl;
	cin>>on;
	Bus::get_actual_time(); 
	if((fp=fopen("bus.txt","r"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
    }
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %s %s %d %d",nu[k],ty[k],na[k],ru[k],&lo[k],&rut[k]);
		for(i=0;i<24;i++)
	 	{
	 		if(i==23)
	 		{
	 				fscanf(fp," %s\n",le_ar_ti[i]);
	 		}
	 		else    fscanf(fp," %s",le_ar_ti[i]);
	 	}
	    if(on==nu[k])
		{
			for(i=0;i<24;i++)
			{
				if(i%2==0&&le_ar_ti[i]==actual_leave_arrive_time[i])
				{
					time1++;
				}
				if(i%2==1&&le_ar_ti[i]==actual_leave_arrive_time[i])
				{
					time2++;
				}
			}
			di_1=time1/(float)12;
			di_2=time2/(float)12;
			load=lo[k];
			break; 
		}
		k++;
	}
	fclose(fp);
	k=0;
	if((fp1=fopen("busactual.txt","r"))==NULL)
	{
		cout<<"无法打开文件"<<endl;
		exit(0);
	}
	while(!feof(fp1))
	{
		fscanf(fp1,"%s",bus[k]);
		for(i=0;i<24;i++)
		{
			fscanf(fp1," %s",ac_le_ar_ti[i]);
		}
		fscanf(fp1," %f %f %f %f\n",&ap[k],&di[k],&di1[k],&di2[k]);
		if(bus[k]==on)
		{
		    di[k]=ap[k]/load;
		    di1[k]=di_1;
		    di2[k]=di_2;
		    cout<<"实际乘车人数："<<ap[k]<<endl;
		    cout<<"满座率："<<di[k]*100<<"%"<<endl;
			cout<<"按时发车率："<<di1[k]*100<<"%"<<endl;
			cout<<"按时到达率："<<di2[k]*100<<"%"<<endl;
		}
	    k++;
	}
    fclose(fp1);
	if((fp1=fopen("busactual.txt","w"))==NULL)
	{
		cout<<"无法打开文件"<<endl;
		exit(0);
	}
	for(j=0;j<k;j++)
	{
		fprintf(fp1,"%s",bus[j]);
		for(i=0;i<24;i++)
		{
			fprintf(fp1," %s",actual_leave_arrive_time[i].c_str());
		}
		fprintf(fp1," %f %.2f %.2f %.2f\n",ap[j],di[j],di1[j],di2[j]);
	}
	fclose(fp1);
}
class Onecard
{
	public:
		Onecard(){} 
		void get_off(int get_off_place); 
	protected:
		string name;
		long onecard_number;
		string unit;
		long valid_period;
};
void Onecard::get_off(int get_off_place)
{
	FILE *fp1,*fp2,*fp3;
	char s[100][100];long onc[100];char un[100][100];long va[100];int ba[100],ri[100],p[100];
    int i=0,k=0;
    if((fp1=fopen("student.txt","r"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	while(!feof(fp1))
	{
        fscanf(fp1,"%s %ld %s %ld %d %d %d\n",s[i],&onc[i],un[i],&va[i],&ba[i],&ri[i],&p[i]);
        if(p[i]==get_off_place)
        {
        	p[i]=-1;
        }
        i++;
    }
    fclose(fp1);
    if((fp1=fopen("student.txt","w"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	for(k=0;k<i;k++)
	{
	    fprintf(fp1,"%s %ld %s %ld %d %d %d\n",s[k],onc[k],un[k],va[k],ba[k],ri[k],p[k]);
	}
	fclose(fp1);
    i=0;
    if((fp2=fopen("teacher.txt","r"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	while(!feof(fp2))
	{
        fscanf(fp2,"%s %ld %s %ld %d %d\n",s[i],&onc[i],un[i],&va[i],&ri[i],&p[i]);
        if(p[i]==get_off_place)
        {
            p[i]=-1;
        }
        i++;
    }
    fclose(fp2);
    if((fp2=fopen("teacher.txt","w"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	for(k=0;k<i;k++)
	{
	    fprintf(fp2,"%s %ld %s %ld %d %d\n",s[k],onc[k],un[k],va[k],ri[k],p[k]);
	}
	fclose(fp2);
    i=0;
	if((fp3=fopen("limit.txt","r"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	while(!feof(fp3))
	{
        fscanf(fp3,"%s %ld %s %ld %d %d %d\n",s[i],&onc[i],un[i],&va[i],&ba[i],&ri[i],&p[i]);
        if(p[i]==get_off_place)
        {
        	p[i]=-1;
        }
        i++;
    }
    fclose(fp3);
    if((fp3=fopen("limit.txt","w"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	for(k=0;k<i;k++)
	{
	    fprintf(fp3,"%s %ld %s %ld %d %d %d\n",s[k],onc[k],un[k],va[k],ba[k],ri[k],p[k]);
	}
	fclose(fp3);
}
class Student:protected Onecard
{
	public:
		Student(){}
	    void set_student();
		void display(); 
		bool balance_waring();
		void balance_show();
		void balance_reduce();
		void riding_number();
		void input();
		void swiping_card();
		void log_off();
    private:
		int balance;
		int rided_number;
};
void Student::display()
{
	cout<<"姓名："<<name<<endl;
	cout<<"一卡通号："<<onecard_number<<endl;
	cout<<"所属单位："<<unit<<endl;
	cout<<"有效日期："<<valid_period<<endl;
}
bool Student::balance_waring()
{
	if(balance<2)
    {
	   cout<<"余额不足,无法乘车"<<endl;
	   return 0;
	}
	return 1;
}
void Student::balance_show()
{
    cout<<"余额："<<balance<<endl;
    if(balance<=5)
    {
       cout<<"余额过低，请及时充值"<<endl; 	
    }
}
void Student::balance_reduce()
{
	balance-=2;
}
void Student::riding_number()
{
	rided_number+=1;
	cout<<"乘车次数："<<rided_number<<endl;
}
void Student::swiping_card()
{
	FILE *fp1,*fp,*fp2;
	int i=0,j=0,on,flag=0,rand_number=-1;
	char s[100][100],un[100][100];long onc[100],va[100];int ba[100],ri[100],p[100];
	string n;char num[20],typ[20],nam[20],run[20],le_ar_ti[24][20],ac_le_ar_ti[24][20];int lo,rut,load;
	char bus[20][20];int ap[20],k=0,m=0;float di[20],di1[20],di2[20];
    cout<<"输入车牌号：";
	cin>>n; 
    if((fp=fopen("bus.txt","r"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	if((fp2=fopen("busactual.txt","r"))==NULL)
	{
		cout<<"无法打开文件"<<endl;
		exit(0);
	}
	while(!feof(fp))
	{
	    fscanf(fp,"%s %s %s %s %d %d",num,typ,nam,run,&lo,&rut);
	    for(i=0;i<24;i++)
	    {
	    	if(i==23)
	    	{
	    		fscanf(fp," %s\n",le_ar_ti[i]);
	    	}
	    	else fscanf(fp," %s",le_ar_ti[i]);
	    }
	    if(n==num)
	    {
	    	load=lo;
	    	break;
	    }
	}
	while(!feof(fp2))
	{
		fscanf(fp2,"%s",bus[k]);
		for(i=0;i<24;i++)
		{
			fscanf(fp2," %s",ac_le_ar_ti[i]);
		}
	    fscanf(fp2," %d %f %f %f\n",&ap[k],&di[k],&di1[k],&di2[k]);
	    i=0;
		if(bus[k]==n)
		{
			if(ap[k]==load) cout<<"禁止乘车"<<endl;
			else
	        {  
                cout<<"当前车上人数："<<ap[k]<<endl; 
			    if((fp1=fopen("student.txt","r"))==NULL)
			    {
		            cout<<"无法打开文件"<<endl;
				    exit(0);
			    }
			    cout<<"输入卡号："; 
			    cin>>on;
			    while(!feof(fp1))
			    {
				    fscanf(fp1,"%s %ld %s %ld %d %d %d\n",s[i],&onc[i],un[i],&va[i],&ba[i],&ri[i],&p[i]);
				    if(onc[i]==on)
				    {
					    flag=1;
					    name=s[i];onecard_number=onc[i];unit=un[i];
					    valid_period=va[i];balance=ba[i];rided_number=ri[i];
			            Student::display();
					    if(Student::balance_waring())
					    {
						    Student::balance_reduce();
					        Student::riding_number();
					        Student::balance_show();
					        srand((unsigned)time(NULL));
					        rand_number=rand()%3;
					        if(rand_number!=2) 
					        {
					        	cout<<"停车点"<<rand_number+1<<"下车"<<endl; 
					        }
					        else cout<<"终点下车"<<endl; 
					        ap[k]++;
					    }
					    ba[i]=balance;
					    ri[i]=rided_number;
					    p[i]=rand_number;
					}
				    i++;
			    }
			    fclose(fp1);
			    if(flag)
			    {
				    if((fp1=fopen("student.txt","w"))==NULL)
			        {
		                cout<<"无法打开文件"<<endl;
				        exit(0);
			        }
			        for(j=0;j<i;j++)
			        {
			            fprintf(fp1,"%s %ld %s %ld %d %d %d\n",s[j],onc[j],un[j],va[j],ba[j],ri[j],p[j]);	
			        }
			        fclose(fp1);
			    }
			    else
			        cout<<"查无此人"<<endl;
			}
		} 
		k++;
    }
	fclose(fp);
	fclose(fp2);
	if((fp2=fopen("busactual.txt","w"))==NULL)
	{
		cout<<"无法打开文件"<<endl;
		exit(0);
	}
	for(m=0;m<k;m++)
	{
		fprintf(fp2,"%s",bus[m]);
		for(i=0;i<24;i++)
		{
			fprintf(fp2," %s",ac_le_ar_ti[i]);
		}
		fprintf(fp2," %d %.2f %.2f %.2f\n",ap[m],di[m],di1[m],di2[m]);
	}
	fclose(fp2);
} 
class Teacher:protected Onecard
{
	public:
		Teacher(){}
	    void riding_number1();
		void display1();
		void swiping_card1();
	private:
		int rided_number1;
};
void Teacher::display1()
{
	cout<<"教师卡免费乘车"<<endl; 
	cout<<"姓名："<<name<<endl;
	cout<<"一卡通号："<<onecard_number<<endl;
	cout<<"所属单位："<<unit<<endl;
	cout<<"有效日期："<<valid_period<<endl;
}
void Teacher::riding_number1()
{
	rided_number1+=1;
	cout<<"乘车次数："<<rided_number1<<endl;
}
void Teacher::swiping_card1()
{
	FILE *fp1,*fp,*fp2;
	int i=0,j=0,on,flag=0,rand_number=-1;
	char s[100][100],un[100][100];long onc[100],va[100];int ri[100],p[100];
	string n;char num[20],typ[20],nam[20],run[20],le_ar_ti[24][20],ac_le_ar_ti[24][20];int lo,rut,load;
	char bus[20][20];int ap[20],k=0,m=0;float di[20],di1[20],di2[20];
    cout<<"输入车牌号：";
	cin>>n; 
    if((fp=fopen("bus.txt","r"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	if((fp2=fopen("busactual.txt","r"))==NULL)
	{
		cout<<"无法打开文件"<<endl;
		exit(0);
	}
	while(!feof(fp))
	{
	    fscanf(fp,"%s %s %s %s %d %d",num,typ,nam,run,&lo,&rut);
	    for(i=0;i<24;i++)
	    {
	    	if(i==23)
	    	{
	    		fscanf(fp," %s\n",le_ar_ti[i]);
	    	}
	    	else fscanf(fp," %s",le_ar_ti[i]);
	    }
	    {
	    	load=lo;
	    	break;
	    }
	}
	while(!feof(fp2))
	{
		fscanf(fp2,"%s",bus[k]);
		for(i=0;i<24;i++)
		{
			fscanf(fp2," %s",ac_le_ar_ti[i]);
		}
		fscanf(fp2," %d %f %f %f\n",&ap[k],&di[k],&di1[k],&di2[k]);
		i=0;
		if(bus[k]==n)
		{
		    if(ap[k]==load) cout<<"禁止乘车"<<endl;
			else
			{  
			    cout<<"当前车上人数："<<ap[k]<<endl; 
			    ap[k]++;
		        if((fp1=fopen("teacher.txt","r"))==NULL)
				{
			        cout<<"无法打开文件"<<endl;
					exit(0);
				}
				cout<<"输入卡号："; 
				cin>>on;
				while(!feof(fp1))
				{
					fscanf(fp1,"%s %ld %s %ld %d %d\n",s[i],&onc[i],un[i],&va[i],&ri[i],&p[i]);
					if(onc[i]==on)
					{
						flag=1;
						name=s[i];onecard_number=onc[i];unit=un[i];
						valid_period=va[i];rided_number1=ri[i];
						Teacher::display1();
						Teacher::riding_number1();
						srand((unsigned)time(NULL));
						rand_number=rand()%3;
					    if(rand_number!=2) 
					    {
					        cout<<"停车点"<<rand_number+1<<"下车"<<endl; 
					    }
					    else cout<<"终点下车"<<endl; 
					    ri[i]=rided_number1;
					    p[i]=rand_number;
					}
					i++;
				}
				fclose(fp1);
				if(flag)
				{ 
				    if((fp1=fopen("teacher.txt","w"))==NULL)
				    {
			            cout<<"无法打开文件"<<endl;
					    exit(0);
				    }
				    for(j=0;j<i;j++)
			    	{
				         fprintf(fp1,"%s %ld %s %ld %d %d\n",s[j],onc[j],un[j],va[j],ri[j],p[j]);	
				    }
				    fclose(fp1);
				}
				else
				    cout<<"查无此人"<<endl;
			}
		}
		k++;
	}
	fclose(fp);
	fclose(fp2);
	if((fp2=fopen("busactual.txt","w"))==NULL)
	{
		cout<<"无法打开文件"<<endl;
		exit(0);
	}
	for(m=0;m<k;m++)
	{
		fprintf(fp2,"%s",bus[m]);
		for(i=0;i<24;i++)
		{
			fprintf(fp2," %s",ac_le_ar_ti[i]);
		}
		fprintf(fp2," %d %.2f %.2f %.2f\n",ap[m],di[m],di1[m],di2[m]);
	}
	fclose(fp2);
} 
class Limit:protected Onecard
{
	public:
		Limit(){}
	    void display2();
		bool balance_waring2();
		void balance_show2();
		void balance_reduce2();
		bool riding_number2();
		void swiping_card2();
	private:
		int balance2;
		int rided_number2;
};
void Limit::display2()
{
	cout<<"姓名："<<name<<endl;
	cout<<"一卡通号："<<onecard_number<<endl;
	cout<<"所属单位："<<unit<<endl;
	cout<<"有效日期："<<valid_period<<endl;
}
bool Limit::balance_waring2()
{
	if(balance2<2)
	{
	    cout<<"余额不足，无法乘车"<<endl;
	    return 0;
	}
	return 1; 
}
void Limit::balance_show2()
{
	cout<<"余额："<<balance2<<endl;
    if(balance2<=5)
    {
        cout<<"余额过低，请及时充值"<<endl; 	
    }
}
void Limit::balance_reduce2()
{
    balance2-=2;
}
bool Limit::riding_number2()
{
	rided_number2+=1;
	cout<<"乘车次数："<<rided_number2<<endl;
	if(rided_number2>20)
	{
		return 1;
	}
	cout<<"免费乘车"<<endl;
	if(rided_number2==20)
	{
		cout<<"乘车次数已满20次，下次乘车将会收费!"<<endl;
	}
	return 0;
}
void Limit::swiping_card2()
{
    FILE *fp1,*fp,*fp2;
	int i=0,j=0,on,flag=0,rand_number=-1;
	char s[100][100],un[100][100];long onc[100],va[100];int ba[100],ri[100],p[100];
	string n;char num[20],typ[20],nam[20],run[20],le_ar_ti[24][20],ac_le_ar_ti[24][20];int lo,rut,load;
	char bus[20][20];int ap[20],k=0,m=0;float di[20],di1[20],di2[20];
    cout<<"输入车牌号：";
	cin>>n; 
    if((fp=fopen("bus.txt","r"))==NULL)
	{
        cout<<"无法打开文件"<<endl;
		exit(0);
	}
	if((fp2=fopen("busactual.txt","r"))==NULL)
	{
		cout<<"无法打开文件"<<endl;
		exit(0);
	}
	while(!feof(fp))
	{
	    fscanf(fp,"%s %s %s %s %d %d",num,typ,nam,run,&lo,&rut);
	    for(i=0;i<24;i++)
	    {
	    	if(i==23)
	    	{
	    		fscanf(fp," %s\n",le_ar_ti[i]);
	    	}
	    	else fscanf(fp," %s",le_ar_ti[i]);
	    }
	    if(n==num)
	    {
	    	load=lo;
	    	break;
	    }
	}
	while(!feof(fp2))
	{
	    fscanf(fp2,"%s",bus[k]);
		for(i=0;i<24;i++)
		{
			fscanf(fp2," %s",ac_le_ar_ti[i]);
		}
		fscanf(fp2," %d %f %f %f\n",&ap[k],&di[k],&di1[k],&di2[k]);
		i=0;
		if(bus[k]==n)
		{
			if(ap[k]==load) cout<<"禁止乘车"<<endl;
			else
	        {   cout<<"当前车上人数："<<ap[k]<<endl; 
			    if((fp1=fopen("limit.txt","r"))==NULL)
			    {
		            cout<<"无法打开文件"<<endl;
				    exit(0);
			    }
			    cout<<"输入卡号："; 
			    cin>>on;
			    while(!feof(fp1))
			    {
				   fscanf(fp1,"%s %ld %s %ld %d %d %d\n",s[i],&onc[i],un[i],&va[i],&ba[i],&ri[i],&p[i]);
				   if(onc[i]==on)
				   {
					    flag=1;
						name=s[i];onecard_number=onc[i];unit=un[i];
						valid_period=va[i];balance2=ba[i];rided_number2=ri[i];
						Limit::display2();
					    if(Limit::balance_waring2()&&Limit::riding_number2())
						{
							 Limit::balance_reduce2();
						     Limit::balance_show2();
						     srand((unsigned)time(NULL));
						     rand_number=rand()%3;
					         if(rand_number!=2) 
					         {
					        	 cout<<"停车点"<<rand_number+1<<"下车"<<endl; 
					         }
					         else cout<<"终点下车"<<endl;  
						     ap[k]++;
						}
						if(ri[i]<20)
				        {
				   	         ap[k]++;
				   	         srand((unsigned)time(NULL));
				   	         rand_number=rand()%3;
					         if(rand_number!=2) 
					         {
					             cout<<"停车点"<<rand_number+1<<"下车"<<endl; 
					         }
					         else cout<<"终点下车"<<endl;     
				        }
				        p[i]=rand_number;
				        ba[i]=balance2;
						ri[i]=rided_number2;
				    }
					i++;
			    }
			    fclose(fp1);
			    if(flag)
			    {
				    if((fp1=fopen("limit.txt","w"))==NULL)
			        {
		                cout<<"无法打开文件"<<endl;
				        exit(0);
			        }
			        for(j=0;onc[j]!='\0';j++)
			        {
			            fprintf(fp1,"%s %ld %s %ld %d %d %d\n",s[j],onc[j],un[j],va[j],ba[j],ri[j],p[j]);	
			        }
			        fclose(fp1);
			    }
			    else
			        cout<<"查无此人"<<endl;
			} 
		} 
		k++;
    }
	fclose(fp);
	fclose(fp2);
	if((fp2=fopen("busactual.txt","w"))==NULL)
	{
		cout<<"无法打开文件"<<endl;
		exit(0);
	}
	for(m=0;m<k;m++)
	{
		fprintf(fp2,"%s",bus[m]);
		for(i=0;i<24;i++)
		{
			fprintf(fp2," %s",ac_le_ar_ti[i]);
		}
		fprintf(fp2," %d %.2f %.2f %.2f\n",ap[m],di[m],di1[m],di2[m]);
	}
	fclose(fp2);
} 
void menu()
{
	cout<<"请选择："<<endl;
	cout<<"1.申请新卡"<<endl;
	cout<<"2.刷卡乘车"<<endl;
	cout<<"3.下车"<<endl; 
	cout<<"4.注销"<<endl;
	cout<<"5.持卡人信息查询"<<endl; 
	cout<<"6.班车信息管理"<<endl;
    cout<<"7.退出"<<endl; 
}
void menu2()
{
	cout<<"请选择："<<endl;
	cout<<"1.学生卡"<<endl;
	cout<<"2.教师卡"<<endl;
	cout<<"3.限制卡"<<endl; 
}
void menu3()
{
	cout<<"请选择："<<endl;
	cout<<"1.新增班车"<<endl;
	cout<<"2.查询班车信息"<<endl;
	cout<<"3.查询班车运行信息"<<endl; 
}
void menu4()
{
	cout<<"当前下车地点为："<<endl;
	cout<<"1.停车点1"<<endl;
	cout<<"2.停车点2"<<endl;
	cout<<"3.终点"<<endl; 
}
void create_card()
{
	Person p;
	int flag;
	char *s="student.txt",*t="teacher.txt",*l="limit.txt";
	menu2();
	cin>>flag;
	if(flag==1)     {p.new_card(s);}
	else if(flag==2){p.new_card(t);}
	else if(flag==3){p.new_card(l);}
	else cout<<"错误"<<endl; 
}
void swip_card()
{
	Student s;Teacher t;Limit l;
	int flag;
	menu2();
	cin>>flag;
	if(flag==1)     {s.swiping_card();}
	else if(flag==2){t.swiping_card1();}
	else if(flag==3){l.swiping_card2();}
	else cout<<"错误"<<endl; 
}
void get_offf()
{
	int place_get_off;
	Onecard o;
	menu4();
	cin>>place_get_off;
	if(place_get_off<=3) {o.get_off(place_get_off-1);}
	else cout<<"错误"<<endl;
	cout<<"到该乘车点的乘客已下车"<<endl; 
}
void log_offf()
{
	Person p;
	int flag;
	char *s="student.txt",*t="teacher.txt",*l="limit.txt";
	menu2();
	cin>>flag;
	if(flag==1)     {p.log_off(s);}
	else if(flag==2){p.log_off(t);}
	else if(flag==3){p.log_off(l);}
	else cout<<"错误"<<endl; 
}
void search_inf()
{
	Person p;
	int flag;
	char *s="student.txt",*t="teacher.txt",*l="limit.txt";
	menu2();
	cin>>flag;
	if(flag==1)     {p.show_person_information(s);}
	else if(flag==2){p.show_person_information(t);}
	else if(flag==3){p.show_person_information(l);}
	else cout<<"错误"<<endl; 
}
void bus_manage()
{
	Bus b;
	int flag;
	menu3();
	cin>>flag;
	if(flag==1)     {b.new_bus();}
	else if(flag==2){b.show_basic_information();}
	else if(flag==3){b.show_run_information();}
	else cout<<"错误"<<endl; 
}
main()
{
   int flag,flag1;
   menu();
   cin>>flag;
   while(flag!=7)
   {   
       switch(flag)
       {
       	   case 1:create_card();break;
		   case 2:swip_card();break;
		   case 3:get_offf();break;
		   case 4:log_offf();break; 
		   case 5:search_inf();break;
		   case 6:bus_manage();break; 
		   default:cout<<"错误"<<endl;
       }
       menu();
       cin>>flag;
   }	
} 


  
