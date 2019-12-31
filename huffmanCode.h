#include<iostream>
using namespace std;

typedef struct Node
{
	char info;                 //�����Ϣ
	int weight;                //Ȩֵ    
	int parent;                //���ڵ����ţ�Ϊ-1���Ǹ��ڵ�    
	int lchild, rchild;         //���Һ��ӽڵ����ţ�Ϊ-1����Ҷ�ӽڵ�    
}HTNode, * HuffmanTree;          //�����洢�շ������е����нڵ�   
typedef char** HuffmanCode;//�洢Ҷ�ӽڵ�Ĺ�����������


HuffmanTree create_HuffmanTree(int n);
void select_minium(HuffmanTree HT, int k, int& min1, int& min2);
int min(HuffmanTree HT, int k);
void HuffmanCoding(HuffmanTree& HT, HuffmanCode& HC, int n);
void HuffmanDecoding(HuffmanTree& HT, HuffmanCode& HC,int len);
