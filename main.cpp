#include<iostream>
#include"huffmanCode.h"

using namespace std;

int main() {
	HuffmanTree HT;
	HuffmanCode HC;
	int len;
	cout << "����" << endl;
	cout<<"�������ַ����ȣ�" << endl;
	cin >> len;
	HT = create_HuffmanTree(len);
	HuffmanCoding(HT, HC, len);
	cout << "����" << endl;
	HuffmanDecoding(HT, HC, len);
	return 0;
}
