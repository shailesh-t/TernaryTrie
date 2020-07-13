#ifndef _TERNARY_TRIE_H_
#define _TERNARY_TRIE_H_
#include <memory>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::shared_ptr;

class Node {
	int dVal =-1;
	char dChar;
	shared_ptr<Node> dMidPtr = nullptr;
	shared_ptr<Node> dLeftPtr = nullptr;
	shared_ptr<Node> dRightPtr = nullptr;
	using node = shared_ptr<Node>;
public:
	int mGetVal() const { return dVal; }
	void mSetVal(int xVal) { dVal = xVal; }
	void mSetChar(char xChar) { dChar = xChar; }
	char mGetChar() const { return dChar; }
	void mSetLeftPtr(node xP) { dLeftPtr = xP; }
	void mSetMidPtr(node xP) { dMidPtr = xP; }
	void mSetRightPtr(node xP) { dRightPtr = xP; }
	node mGetLeftPtr() const { return dLeftPtr; }
	node mGetMidPtr() const { return dMidPtr; }
	node mGetRightPtr() const { return dRightPtr; }
	void mPrint() { cout << mGetChar() << " : " << mGetVal() << "\n"; }
};

class TernaryTrie {
	using node = shared_ptr<Node>;
	node dRoot = nullptr;
	void _mPrint(node);
	node _mGet(node, string xKey, size_t xPos);
	node _mPut(node, string xKey, size_t xPos, int xVal);
	node _mDelete(node, string, size_t);
public:
	node mGetRootPtr() const { return dRoot; }
	void mSetRootPtr(node xP) { dRoot = xP; }
	void mPrint();
	void mDelete(string xKey);
	void mPut(string xKey, int xVal);
	int mGet(string xKey);
};


#endif
