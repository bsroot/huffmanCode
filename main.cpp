#include<iostream>
#include"huffmanCode.h"

using namespace std;

int main() {
	HuffmanTree HT;
	HuffmanCode HC;
	int len;
	cout << "±àÂë" << endl;
	cout<<"ÇëÊäÈë×Ö·û³¤¶È£º" << endl;
	cin >> len;
	HT = create_HuffmanTree(len);
	HuffmanCoding(HT, HC, len);
	cout << "ÒëÂë" << endl;
	HuffmanDecoding(HT, HC, len);
	return 0;
}
