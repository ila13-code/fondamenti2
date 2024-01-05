#include "FakeList.h"
#include <iostream>
using namespace std;

int main()
{
    FakeList miaLst;
    miaLst.insertEl(3);
    miaLst.insertEl(6);
    miaLst.insertEl(7);
    miaLst.insertEl(3);
    miaLst.fakeSort(false);
    miaLst.fakeClear(true);
    if(miaLst.getFakeSize()==0)
        cout<<"VUOTO"<<endl;
    cout<<miaLst.size();
}