#include<iostream>
#include <string.h>
#include"huffmanCode.h"
using namespace std;

HuffmanTree create_HuffmanTree(int n)
/*
weight:���Ȩ��
n����ŵ�Ȩ�ظ���
*/

{
	char info;
	int j=0;
	int total = 2 * n - 1;//�ܽ����
	int weights[] = { 186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1 };
	char codes[] = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char code;
	HuffmanTree HT = (HuffmanTree)malloc(total * sizeof(HTNode));

	if (!HT)
	{
		printf("HuffmanTree malloc faild!");
		exit(-1);
	}

	//��ʼ������HT[0]��HT[n-1]��Ҷ�ӽڵ�
	cout << "�������ַ���"<<endl;
	for (int i = 0; i < n; i++)
	{
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		cin>> code;
		HT[i].info = code;
		while (codes[j] != code)
			j++;
		HT[i].weight = weights[j];
		j = 0;
		
	}

	//��ʼ���������ɶ������ĸ��ڵ�
	for (int i = n; i < total; i++)
	{
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = 0;
	}

	int min1, min2;

	for (int i = n; i < total; i++)
	{
		select_minium(HT, i, min1, min2);
		HT[min1].parent = i;
		HT[min2].parent = i;
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight = HT[min1].weight + HT[min2].weight;
	}
	return HT;

}

void select_minium(HuffmanTree HT, int k, int& min1, int& min2)
/*
HT:���ж������ļ���
k:�ȽϷ�Χ��0��k
min1/min2:�����÷���Ȩ����С���������
*/
{
	min1 = min(HT, k);
	min2 = min(HT, k);
}

int min(HuffmanTree HT, int k) {
	int i = 0;
	int min, min_weight;

	while (HT[i].parent != -1)
		i++;
	min = i;
	min_weight = HT[i].weight;

	for (; i < k; i++) {
		if (HT[i].weight < min_weight && HT[i].parent == -1) {
			min = i;
			min_weight = HT[i].weight;
		}
	}

	//��Ȩ����С�Ľ���parent��Ϊ1�����´αȽ�ʱ�ų�����
	HT[min].parent = 1;
	return min;
}
void HuffmanCoding(HuffmanTree& HT, HuffmanCode& HC, int n) {

	HC = (HuffmanCode)malloc(n * sizeof(char*));
	if (!HC)
	{
		printf("HuffmanCode malloc faild!");
		exit(-1);
	}

	char* code = (char*)malloc(n * sizeof(char));
	if (!code)
	{
		printf("code malloc faild!");
		exit(-1);
	}
	code[n - 1] = '\0';

	for (int i = 0; i < n; i++)
	{
		int current = i;
		int father = HT[i].parent;
		int start = n - 1;

		while (father != -1)
		{
			if (HT[father].lchild == current)   //��������ӣ������Ϊ0
				code[--start] = '0';
			else                              //������Һ��ӣ������Ϊ1       
				code[--start] = '1';
			current = father;
			father = HT[father].parent;
		}

		HC[i] = (char*)malloc((n - start) * sizeof(char));
		if (!HC[i])
		{
			printf("HC[i] malloc faild!");
			exit(-1);
		}
		strcpy(HC[i], code + start);
	}
	for (int i = 0; i < n; ++i)
		cout << HC[i] << endl;
}
void HuffmanDecoding(HuffmanTree& HT, HuffmanCode& HC,int len) {
	int n,m;
	cout << "��������������";
	cin >> n;
	HC = (HuffmanCode)malloc(n * sizeof(char*));
	cout << "���������ͳ���"<<endl;
	for (int i = 0; i < n; i++) {
		cin >> m;
		HC[i] = (char*)malloc(m* sizeof(char));
		cin >> HC[i];
	}
		
	int i = 0,j=0;
	while (i < n) {
		int current = len * 2 - 2;
		while (HT[current].lchild != -1 && HT[current].rchild != -1) {
			if (HC[i][j] =='0')
				current = HT[current].lchild;
			else
				current = HT[current].rchild;
			j++;
		}
		i++;
		j = 0;
		cout << HT[current].info;
	}
}