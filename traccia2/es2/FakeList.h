#ifndef FakeList_h
#define FakeList_h
#include <list>
#include <functional>
using namespace std;

class FakeList:protected list<int>
{
    public:
        FakeList() {}
        int getFakeSize() const
        {
            return this->size()*2;
        }
        void insertEl(int el)
        {
            list<int>::const_iterator it;
            bool Trovato=false;
            for(it=this->begin(); it!=this->end(); it++)
                if(*it==el)
                    Trovato=true;
            if(Trovato)
                this->push_back(el);
            else
                this->push_front(el);
        }
        void fakeSort(bool s)
        {
            if(s) //ordine crescente
                this->sort();
            else //ordine decrescente
                this->sort(std::greater<int>());
        }
        void fakeClear(bool c)
        {
            if(c)
                this->clear();
        }
};
#endif