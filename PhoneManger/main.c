#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Phone
{
	char name[1024];	//����	
	char Address[1024];	//סַ
	char phone[1024];		//�绰����
	struct Phone *next;		//ָ����һ���ڵ�ָ��
}Info_Phone;

void faca()
{

	printf("****************************\n");
	printf("1����ʾͨѶ¼������Ϣ(����������Ϣ�������ʹ��)��\n");
	printf("2�����ͨѶ¼��Ա��Ϣ��\n");
	printf("3��ɾ��ͨѶ¼��Ա��Ϣ��\n");
	printf("4���޸�ͨѶ¼��Ա��Ϣ��\n");
	printf("5������ͨѶ¼��Ա��Ϣ��\n");
	printf("0���˳�ͨѶ¼��\n");
	printf("****************************\n");
	
};

Info_Phone *print(Info_Phone *head)	//���������⣬��֪��Ϊʲô��ָ���ʼ��ΪNULL�������ڴ��е�����Ϊ������
{
	/*�˹��������⣬��ʼ�����ʼ��Ϊ�����ͣ�ʹ��ָ��ָ���ʱ��ָ����Ϊ������Ҳ�����ݣ�����ʹ���������һ���ᱼ��*/
	//�����ѽ����ʹ��memset�������ڴ��е�����ȫ����ʼ��Ϊ0
	Info_Phone *p;	//�ṹ��ָ��
	p = head;
	
	if (head != NULL)	//�жϵ�ǰ�׶��Ƿ�Ϊ�գ����Ϊ�գ��򲻽���ѭ��
	{
		printf("��ǰͨѶ¼��");
		while (p != NULL)
		{
			printf("����:%s\r\n", p->name);
			printf("סַ:%s\r\n", p->Address);
			printf("�绰����:%s\r\n", p->phone);
			p = p->next;	//ָ����һ���ڵ�
		}
	}
	else
	{
		printf("��ǰΪ��");
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
	printf("���Ƿ���Ҫ����û�,1Ϊ��ӣ�2Ϊ�����");
	scanf("%d", &Input);
	switch (Input)
	{
	case 1:
		printf("��������Ҫ��ӵ�����:");
		scanf("%s", p0->name);
		getchar();	//�����һ���س�����������Կո񣬵���������ôд
		printf("�������ͥסַ:");
		scanf("%s", p0->Address);
		getchar();
		printf("������绰һ��Ϊ11λ:");
		scanf("%s", p0->phone);

		if (head == NULL)
		{
			head = p0;
			p0->next = NULL;	//�ѽڵ���Ϣ��գ��ܿӣ���ʱ�����������������
		}
		else
		{
			while ((strcmp(p0->name, p1->name)>0) && (p1->next != NULL))	//��p1��p2���бȽϣ���ν������0����p1����һ���ڵ㲻Ϊ��
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
			printf("��ӳɹ�");
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

	printf("������Ҫɾ��������");
	scanf("%s", name);

	if (head != NULL)	//�жϵ�ǰ����Ľṹ����û������
	{
		while (p1 != NULL)	//�ҽ�β
		{
			if (strcmp(p1->name, name) == 0)	//strcmp�������ֵ��ȣ�����ֵΪ0
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
				printf("ɾ���ɹ�");
				return head;
			}
			else
			{
				p2 = p1;
				p2->next = p1;
			}
			printf("�Ҳ��������\r\n");
			return head;
		}
	}
	else
	{
		printf("ͨѶ¼�ǿյ�");
		return head;
	}
}

Info_Phone *Phone_Revise(Info_Phone *head)
{
	Info_Phone *p1, *p2;
	char name[1024];
	p1 = head;
	p2 = head;

	printf("������Ҫ�޸�����������");

	scanf("%s", name);
	if (head != NULL)
	{
		while (p1 != NULL)
		{
			if (strcmp(p1->name, name) == 0)
			{
				printf("�������޸ĺ������:");
				scanf("%s", p1->name);
				printf("�������޸ĺ�ĵ�ַ:");
				scanf("%s", p1->Address);
				printf("�������޸ĺ�ĵ绰����:");
				scanf("%s", p1->phone);
				printf("�޸ĳɹ�");
				return head;
			}

			else
			{
				p2 = p1;
				p2->next = p1;
			}
		}
		printf("�Ҳ�������ϵ��");
		return head;
	}
	else
	{
		printf("��ǰͨѶ¼�ǿյ�");
		return head;
	}
}


Info_Phone *Phone_Search(Info_Phone *head)
{
	Info_Phone *p1, *p2;
	char name[1024];
	p1 = head;
	p2 = head;
	printf("������Ҫ��ѯ������");
	scanf("%s", name);
	if (head != NULL)
	{
		while (p1 != NULL)
		{
			if (strcmp(p1->name, name) == 0)
			{
				printf("��ǰ�û�������Ϊ:");
				printf("%s", p1->name);
				printf("��ǰ�û��ĵ�ַΪ:");
				printf("%s", p1->Address);
				printf("��ǰ�û��ĵ绰Ϊ:");
				printf("%s", p1->phone);
				printf("������\r\n");
				return head;
			}

			else
			{
				p2 = p1;
				p2->next = p1;
			}
		}
		printf("�Ҳ�������ϵ��");
	}
	else
	{
		printf("��ǰͨѶ¼�ǿյ�");
	}
}

int main()
{
	int input = 0;
	Info_Phone *head = NULL;
	head = (Info_Phone *)malloc(sizeof(Info_Phone));
	memset(head, 0, sizeof(Info_Phone));
	while (1)
	{
		printf("���������ѡ��\r\n");
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
			printf("�������");
		}
		
	}
	system("pause");
}