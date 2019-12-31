#include<iostream>
#include <string.h>
#include"huffmanCode.h"
using namespace std;

HuffmanTree create_HuffmanTree(int n)
/*
weight:存放权重
n：存放的权重个数
*/

{
	char info;
	int j=0;
	int total = 2 * n - 1;//总结点数
	int weights[] = { 186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1 };
	char codes[] = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char code;
	HuffmanTree HT = (HuffmanTree)malloc(total * sizeof(HTNode));

	if (!HT)
	{
		printf("HuffmanTree malloc faild!");
		exit(-1);
	}

	//初始化所有HT[0]至HT[n-1]的叶子节点
	cout << "请输入字符："<<endl;
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

	//初始化所有生成二叉树的根节点
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
HT:所有二叉树的集合
k:比较范围：0—k
min1/min2:用引用返回权重最小的两个结点
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

	//将权重最小的结点的parent设为1，在下次比较时排除在外
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
			if (HT[father].lchild == current)   //如果是左孩子，则编码为0
				code[--start] = '0';
			else                              //如果是右孩子，则编码为1       
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
	cout << "请输入编码个数：";
	cin >> n;
	HC = (HuffmanCode)malloc(n * sizeof(char*));
	cout << "请输入编码和长度"<<endl;
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