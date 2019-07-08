#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Phone
{
	char name[1024];	//名字	
	char Address[1024];	//住址
	char phone[1024];		//电话号码
	struct Phone *next;		//指向下一个节点指针
}Info_Phone;

void faca()
{

	printf("****************************\n");
	printf("1：显示通讯录已有信息(需在已有信息的情况下使用)。\n");
	printf("2：添加通讯录人员信息。\n");
	printf("3：删除通讯录人员信息。\n");
	printf("4：修改通讯录人员信息。\n");
	printf("5：查找通讯录人员信息。\n");
	printf("0：退出通讯录。\n");
	printf("****************************\n");

};

Info_Phone *print(Info_Phone *head)	//功能有问题，不知道为什么，指针初始化为NULL，但是内存中的数据为屯屯屯
{
	/*此功能有问题，初始化会初始化为屯屯屯，使用指针指向的时候，指针认为屯屯屯也是数据，所以使用这个功能一定会奔溃*/
	//问题已解决，使用memset函数将内存中的数据全部初始化为0
	Info_Phone *p;	//结构体指针
	p = head;

	if (head != NULL)	//判断当前阶段是否为空，如果为空，则不进入循环
	{
		printf("当前通讯录：");
		while (p != NULL)
		{
			printf("姓名:%s\r\n", p->name);
			printf("住址:%s\r\n", p->Address);
			printf("电话号码:%s\r\n", p->phone);
			p = p->next;	//指向下一个节点
		}
	}
	else
	{
		printf("当前为空");
	}

	return head;

}

Info_Phone *Phone_Add(Info_Phone *head)
{
	Info_Phone *p0 = NULL;
	Info_Phone *p1, *p2;
	p1 = head;
	p2 = head;

	p0 = (Info_Phone *)malloc(sizeof(Info_Phone));
	int Input = 0;
	printf("您是否需要添加用户,1为添加，2为不添加");
	scanf("%d", &Input);
	switch (Input)
	{
	case 1:
		printf("请输入您要添加的名称:");
		scanf("%s", p0->name);
		getchar();	//这里吃一个回车，本来是想吃空格，但是忘了怎么写
		printf("请输入家庭住址:");
		scanf("%s", p0->Address);
		getchar();
		printf("请输入电话一般为11位:");
		scanf("%s", p0->phone);

		if (head == NULL)
		{
			head = p0;
			p0->next = NULL;	//把节点信息清空，很坑，当时忘了这个，后来补的
		}
		else
		{
			while ((strcmp(p0->name, p1->name)>0) && (p1->next != NULL))	//对p1和p2进行比较，如何结果大于0或者p1的下一个节点不为空
			{
				p2 = p1;
				p1 = p1->next;
			}
			if ((strcmp(p0->name, p1->name)) <= 0)
			{
				if (head == p1)
				{
					head = p0;
				}
				else
				{
					p2->next = p0;
				}
				p0->next = p1;
			}

			else
			{
				p1->next = p0;
				p0->next = NULL;
			}
			printf("添加成功");
		}

	}
	return(head);
}


Info_Phone *Phone_Delete(Info_Phone *head)
{
	Info_Phone *p1, *p2;
	char name[1024];
	p1 = head;
	p2 = head;

	printf("请输入要删除的名字");
	scanf("%s", name);

	if (head != NULL)	//判断当前传入的结构体有没有数据
	{
		while (p1 != NULL)	//找结尾
		{
			if (strcmp(p1->name, name) == 0)	//strcmp如果两个值相等，返回值为0
			{
				if (head != p1)
				{
					p2->next = p1->next;
				}
				else
				{
					head = p1->next;
				}
				free(p1);
				printf("删除成功");
				return head;
			}
			else
			{
				p2 = p1;
				p2->next = p1;
			}
			printf("找不到这个人\r\n");
			return head;
		}
	}
	else
	{
		printf("通讯录是空的");
		return head;
	}
}

Info_Phone *Phone_Revise(Info_Phone *head)
{
	Info_Phone *p1, *p2;
	char name[1024];
	p1 = head;
	p2 = head;

	printf("请输入要修改人名的名称");

	scanf("%s", name);
	if (head != NULL)
	{
		while (p1 != NULL)
		{
			if (strcmp(p1->name, name) == 0)
			{
				printf("请输入修改后的名字:");
				scanf("%s", p1->name);
				printf("请输入修改后的地址:");
				scanf("%s", p1->Address);
				printf("请输入修改后的电话号码:");
				scanf("%s", p1->phone);
				printf("修改成功");
				return head;
			}

			else
			{
				p2 = p1;
				p2->next = p1;
			}
		}
		printf("找不到此联系人");
		return head;
	}
	else
	{
		printf("当前通讯录是空的");
		return head;
	}
}


Info_Phone *Phone_Search(Info_Phone *head)
{
	Info_Phone *p1, *p2;
	char name[1024];
	p1 = head;
	p2 = head;
	printf("请输入要查询的名字");
	scanf("%s", name);
	if (head != NULL)
	{
		while (p1 != NULL)
		{
			if (strcmp(p1->name, name) == 0)
			{
				printf("当前用户的名字为:");
				printf("%s", p1->name);
				printf("当前用户的地址为:");
				printf("%s", p1->Address);
				printf("当前用户的电话为:");
				printf("%s", p1->phone);
				printf("输出完毕\r\n");
				return head;
			}

			else
			{
				p2 = p1;
				p2->next = p1;
			}
		}
		printf("找不到此联系人");
	}
	else
	{
		printf("当前通讯录是空的");
	}
}

int main()
{
	int input = 0;
	Info_Phone *head = NULL;
	head = (Info_Phone *)malloc(sizeof(Info_Phone));
	//memset(head, 0, sizeof(Info_Phone));
	while (1)
	{
		printf("请输入你的选择\r\n");
		faca();
		scanf("%d", &input);

		if (input <= 5)
		{
			switch (input)
			{
			case 1:
				head = print(head);
				break;

			case 2:
				head = Phone_Add(head);
				break;
			case 3:
				head = Phone_Delete(head);
				break;
			case 4:
				head = Phone_Revise(head);
				break;
			case 5:
				head = Phone_Search(head);
				break;
			case 0:
				break;
			default:
				break;
			}
		}
		else
		{
			printf("输入错误");
		}

	}
	system("pause");
}
