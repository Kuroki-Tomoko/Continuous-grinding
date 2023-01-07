/*程序中默认期末成绩=平时分的百分之40+实验成绩的百分之60*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<stdbool.h>
#define NUM 100
struct Stu                    //定义学生结构体
{
    char name[30];            //姓名
    char gender[20];          //性别
    long long number;         //学号
    double Uscore;            //平时分数
    double Escore;            //实验成绩
    double Fscore;            //期末成绩
};

struct Stu Student[100];           //一共可以储存100个学生的信息

int n;                             //全局变量
int allfuction;

void Exit()                        //显示退出程序函数（结束）
{
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t****************************************************************\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t||                     Thank you to                           ||\n");
    printf("\t\t\t||                   use this programme !                     ||\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t****************************************************************\n");
}

void Menu()                       //菜单
{

	printf("                    *************************Student achievement management system************************\n");
	printf("                                        Please select the operation to be performed\n                                        \n");
	printf("                                     1 : Enter the information of students you want.\n");
	printf("                                     2 : Show all students information.\n");
	printf("                                     3 : Sort students information.\n");
	printf("                                     4 : Find students information.\n");
	printf("                                     5 : Delete students information.\n");
	printf("                                     6 : Modify students information\n");
	printf("                                     7 : Exit this system.\n");
	printf("Please enter your options: \n");
	scanf("%d",&allfuction);
}

int InputStudent()              //学生基本信息输入int组
{
    int again;
    int i=1;
    while(i)
    {
        system("cls");
        printf("--------------Please enter students\' information--------------\n\n\n");     //人机交互
        printf("Please enter the score of the number %d student:\n",i);                      //提示用户输入
        printf("Please enter student\'s ID:");
        scanf("%lld",&Student[i].number);                                                    //结构体的数据输入number
        printf("Please enter student\'s name:");
        scanf("%s",Student[i].name);                                                         //结构体的数据输入name
        printf("Please enter student\'s gender:");
        scanf("%s",&Student[i].gender);                                                      //结构体的数据输入gender
        printf("Please enter student\'s Semester work:");
        scanf("%lf",&Student[i].Uscore);                                                     //结构体的数据输入Uscore
        printf("Please enter student\'s Experimental results:");
        scanf("%lf",&Student[i].Escore);                                                     //结构体的数据输入Escore
        i++;                                                                                 //计数器
        n++;
        printf("Success!\n");
        printf("Continue to decide whether to enter information ? 1.Continue 2.Exit\n");
        scanf("%d",&again);                                                                  //让用户决定是否继续输入
        if(again == 2)
        {
            system("cls");                                                                   //清屏结束此次操作
            break;
        }

    }
}

void DisplayStudent()                          //显示学生信息
{
    int i = 0;                                 //初始化i计数器
    int pass = 0;
    int n_pass = 0;
    double percent=0.0;
    double percent1=0.0;
        system("cls");                       //清屏实现后续操作
    printf("--------------Display students\' information--------------\n\n\n");
    printf("ID====name====semester work====Experimental results====Final Examination====\n\n\n");

    for(i = 1;i <= n; i++)
    {
        Student[i].Fscore = (0.4*Student[i].Uscore) + (0.6*Student[i].Escore);      //期末成绩的计算
        printf("Student ID:%lld\nStudent name:%s\nSemester work:%.3lf\nExperimental results:%.3lf\nFinal examination:%.3lf\n\n",
               Student[i].number,Student[i].name,Student[i].Uscore,Student[i].Escore,Student[i].Fscore);  //输出学生的成绩信息
    }
    if(Student[i].Fscore < 60)
    {
        ++n_pass;
    }
    else
    {
        ++pass;
    }
    percent=(double)pass/(double)n;
    percent1=(double)n_pass/(double)n;
    printf("%d students pass the assessment. %.3lf%% of the total number of students\n",pass,percent);
    printf("%d students not pass the assessment. %.3lf%% of the total number of students\n",n_pass,percent1);
}

void mysort()                       //根据成绩排序名次
{
	struct Stu t;                   //新的结构体
	        system("cls");
    printf("--------------Ranked according to final examination--------------\n\n\n");
	for(int i = 1; i < n; i++)
	    for(int j = 1; j < n; j++)
	        if(Student[j].Fscore > Student[j-1].Fscore)       //互换
	        {
	        	t = Student[j];
	        	Student[j] = Student[j-1];
	        	Student[j-1] = t;
			}
    for(int i = 1; i <= n; i++)                              //按照成绩的大小来输出具体的信息
    {
        Student[i].Fscore = (0.4*Student[i].Uscore) + (0.6*Student[i].Escore);
        printf("Student ID: %d\n",Student[i].number);
        printf("Student name: %s\n",Student[i].name);
        printf("Gender: %s\n",Student[i].gender);
        printf("Semester work: %.3lf\n",Student[i].Uscore);
        printf("Experimental results: %.3lf\n",Student[i].Escore);
        printf("Final examination: %.3lf\n\n",Student[i].Fscore);
    }
    printf("\n");
}

void FindStudent()                           //根据学号查找录入学生的信息
{
    int i=0;                                 //计数器
    long long ID;                            //定位学号的一个标记
    system("cls");
    printf("--------------Search by student\'s ID--------------\n\n\n");
    printf("Please enter the student\'s ID: ");
    scanf("%lld",&ID);
    for(i=1;i<=n;i++)
    {
        if(ID==Student[i].number)      //如果输入的学号和存入学生信息的学号相等，进入下面的程序
        {
            Student[i].Fscore = (0.4*Student[i].Uscore) + (0.6*Student[i].Escore);
            printf("Student ID: %lld\n",Student[i].number);
            printf("Student name: %s\n",Student[i].name);
            printf("Gender: %s\n",Student[i].gender);
            printf("Semester work: %.3lf\n",Student[i].Uscore);
            printf("Experimental results: %.3lf\n",Student[i].Escore);
            printf("Final examination: %.3lf\n",Student[i].Fscore);
        }
    }
}

void DeleteStudent()              //删除一个学生的信息
{
        long long nums;                 //定义一个学号的标记
		int i=0;
		int j=0;
		int decide;
		system("cls");
		printf("\n============Delete information by student\' ID===========\n");
		printf("Enter the student ID of the student you want to delete: ");
		scanf("%lld",&nums);

		for(i=1;i<=n;i++)
		{
			if(nums==Student[i].number)            //输入的学号与存入的学号相等进行删除工作
			{
             Student[i].Fscore = (0.4*Student[i].Uscore) + (0.6*Student[i].Escore);
			 printf("ID\tname\tSemester work\tExperimental results\tFinal examination\t\n");
			 printf("%lld\t%s\t%.3lf\t%.3lf\t%.3lf\t\n",
                    Student[i].number,Student[i].name,Student[i].Uscore,Student[i].Escore,Student[i].Fscore);

			 printf("Confirm the deletion !(1.Yes 2.No)\n");
			 scanf("%d",&decide);
			if(decide==1)                         //输入1则进行删除工作
			{
					for(j=i;j<=n;j++)
					{
						Student[j].number=Student[j+1].number;
					    strcpy(Student[j].name,Student[j+1].name);
						Student[i].Uscore=Student[i].Uscore;
						Student[i].Escore=Student[i].Escore;
						Student[i].Fscore=Student[i].Fscore;
					}
					n--;
			}
			if(decide==2)                        //输入2则取消删除工作
			{
			    printf("Cancel deletion.");
			}
		}
	}
}

void ModifyStudent()                             //修改学生的信息
{
    int i=0;
    long long IDs;
    system("cls");
    printf("--------------Please enter the student\'s ID you want to modify--------------\n\n\n");
    printf("Please enter the student\'s ID you want to modify:");
    scanf("%lld",&IDs);
    for(i = 1; i <= n; i++)
    {
        if(IDs==Student[i].number)
        {
            printf("Please re-enter the student's information.\n");
            printf("ID: \n");
            scanf("%lld",&Student[i].number);
            printf("name: \n");
            scanf("%s",Student[i].name);
            printf("Semester work: \n");
            scanf("%lf",&Student[i].Uscore);
            printf("Experimental results: \n");
            scanf("%lf",&Student[i].Escore);
            printf("Final examination: \n");
            scanf("%lf",&Student[i].Fscore);
            printf("Successful modification !\n\n");
        }
    }
}

int main()
{
    while(true)
    {
        Menu();                         //显示菜单

    switch(allfuction)                  //选择swtich来进行菜单的选择
    {
        case 1:
        InputStudent(Student,NUM);        //输入学生信息
        break;

        case 2:
        DisplayStudent(Student,NUM);      //显示学生信息
        break;

        case 3:
        mysort(Student,NUM);              //根据期末成绩排序，并展示及格和不及格的人数
        break;

        case 4:
        FindStudent(Student,NUM);         //查找某个学生的信息
        break;

        case 5:
        DeleteStudent(Student,NUM);       //删除某个学生的信息
        break;

        case 6:
        ModifyStudent(Student,NUM);      //修改某个学生的信息
        break;

        case 7:                          //退出整个程序
        Exit();
        return 0;
     }
    }
}
