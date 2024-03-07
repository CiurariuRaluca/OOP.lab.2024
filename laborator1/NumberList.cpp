#include<stdio.h>
#include "NumberList.h"

/*
class NumberList
{
    int numbers[10];
    int count;
public:
    void Init();          // count will be 0
    bool Add(int x);      // adds X to the numbers list and increase the data member count.
    // if count is bigger or equal to 10, the function will return false
    void Sort();          // will sort the numbers vector
    void Print();         // will print the current vector
}
*/


void NumberList::Init()
{
    this->count = 0;
}
bool NumberList::Add(int x)
{
    if (count >= 10)
        return 0;
    this->numbers[count++] = x;
    return 1;

}
void NumberList::Sort()
{
    bool ok = 1;
    while (ok)
    {
        ok = 0;
        for (int i = 0; i < this->count - 1; i++)
        {
            if (this->numbers[i] > this->numbers[i + 1])
            {
                int aux;
                aux = this->numbers[i];
                this->numbers[i] = this->numbers[i + 1];
                this->numbers[i + 1] = aux;
                ok = 1;
            }

        }
    }
}
void NumberList::Print()
{
    for (int i = 0; i < this->count; i++)
        printf("%d ", this->numbers[i]);
}