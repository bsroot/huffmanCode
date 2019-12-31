#include<iostream>
using namespace std;

typedef struct Node
{
	char info;                 //存放信息
	int weight;                //权值    
	int parent;                //父节点的序号，为-1的是根节点    
	int lchild, rchild;         //左右孩子节点的序号，为-1的是叶子节点    
}HTNode, * HuffmanTree;          //用来存储赫夫曼树中的所有节点   
typedef char** HuffmanCode;//存储叶子节点的哈夫曼树编码


HuffmanTree create_HuffmanTree(int n);
void select_minium(HuffmanTree HT, int k, int& min1, int& min2);
int min(HuffmanTree HT, int k);
void HuffmanCoding(HuffmanTree& HT, HuffmanCode& HC, int n);
void HuffmanDecoding(HuffmanTree& HT, HuffmanCode& HC,int len);
