
#include <iostream>
#include "TernaryTrie.h"

using node = shared_ptr<Node>;
void TernaryTrie::_mPrint(node xPtr) 
{
    if (xPtr == nullptr) return;
    _mPrint(xPtr->mGetLeftPtr());
    xPtr->mPrint();
    _mPrint(xPtr->mGetMidPtr());
    _mPrint(xPtr->mGetRightPtr());
}
node TernaryTrie::_mGet(node xPtr, string xKey, size_t xPos)
{
    if (xPtr == nullptr) return nullptr;
    
    char lX = xKey.at(xPos);
    char xX = xPtr->mGetChar();

    if (lX > xX) return _mGet(xPtr->mGetRightPtr(), xKey, xPos);
    else if (lX < xX)  return _mGet(xPtr->mGetLeftPtr(), xKey, xPos);
    else if ((xKey.length() - 1)>xPos) return _mGet(xPtr->mGetMidPtr(), xKey, xPos+1);
    else
        return xPtr;

}
node TernaryTrie::_mPut(node xPtr, string xKey, size_t xPos, int xVal)
{
    if (xPtr == nullptr) {
        xPtr = std::make_shared<Node>();
        xPtr->mSetChar(xKey.at(xPos));
    }
    char lX = xKey.at(xPos);
    char xX = xPtr->mGetChar();

    if (lX > xX)
        xPtr->mSetRightPtr(_mPut(xPtr->mGetRightPtr(), xKey, xPos, xVal));
    else if (xX > lX)
        xPtr->mSetLeftPtr(_mPut(xPtr->mGetLeftPtr(), xKey, xPos, xVal));
    else if ((xKey.length() - 1) > xPos) 
        xPtr->mSetMidPtr(_mPut(xPtr->mGetMidPtr(), xKey, xPos + 1, xVal));
    else 
        xPtr->mSetVal(xVal);

    return xPtr;
}
node TernaryTrie::_mDelete(node xPtr, string xKey, size_t xPos)
{
    if (xPtr == nullptr) return nullptr;

    char lX = xKey.at(xPos);
    char xX = xPtr->mGetChar();

    if (lX > xX)
        xPtr->mSetRightPtr(_mDelete(xPtr->mGetRightPtr(), xKey, xPos));
    else if (xX > lX)
        xPtr->mSetLeftPtr(_mDelete(xPtr->mGetLeftPtr(), xKey, xPos));
    else if ((xKey.length() - 1) > xPos)
        xPtr->mSetMidPtr(_mDelete(xPtr->mGetMidPtr(), xKey, xPos + 1));
    else
        xPtr->mSetVal(-1);

    if ((xPtr->mGetVal() == -1) &&
        (xPtr->mGetLeftPtr() == nullptr) &&
        (xPtr->mGetMidPtr() == nullptr) &&
        (xPtr->mGetRightPtr() == nullptr))
        return nullptr;
    else
        return xPtr;
}
void TernaryTrie::mPrint()
{
    auto lPtr = mGetRootPtr();
    _mPrint(lPtr);
}
void TernaryTrie::mDelete(string xKey)
{
    mSetRootPtr(_mDelete(mGetRootPtr(), xKey,0));
}
void TernaryTrie::mPut(string xKey, int xVal)
{
    mSetRootPtr(_mPut(mGetRootPtr(), xKey, 0, xVal));
}
int TernaryTrie::mGet(string xKey)
{
    auto lPtr = _mGet(mGetRootPtr(), xKey, 0);
    if (lPtr)
        return lPtr->mGetVal();
    else
        return -1;
}

int main()
{
    TernaryTrie lTrie;
    lTrie.mPut("she", 0);
    lTrie.mPut("sells", 1);
    lTrie.mPut("sea", 2);
    lTrie.mPut("shells", 3);
    lTrie.mPut("by", 4);
    lTrie.mPut("the", 5);
    lTrie.mPut("sea", 6);
    lTrie.mPut("shore", 7);
    lTrie.mPrint();
    cout << lTrie.mGet("shore") << '\n';
    cout << lTrie.mGet("she") << '\n';
    lTrie.mDelete("she");
    cout << lTrie.mGet("she") << '\n';
    cout << lTrie.mGet("shells") << '\n';
}

