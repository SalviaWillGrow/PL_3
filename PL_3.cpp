#include <iostream>
#include <list>
using namespace std;

int InputInteger()
{
    int integer;
    scanf_s("%i", &integer);
    return integer;
}

void FillList(list<int>& listToFill)
{
    printf("Input elements to sum (finish by inputting 0):\n");

    int a = 1;
    for (int i = 0; a != 0; i++) {
        printf("A[%i] = ", i);
        scanf_s("%i", &a);
        listToFill.push_back(a);
    }
    listToFill.pop_back();
}

void ShowList(list<int> listToShow)
{
    list<int>::iterator it;
    cout << "{ ";
    for (it = listToShow.begin(); it != listToShow.end(); ++it)
        cout << *it << ", ";
    cout << "}\n";
}

void IterateCombinations(list<int> listToLookThrough, int valueToFind)
{

    int listSize = listToLookThrough.size();
    int sum = 0;

    for (int i = 0; i < (1 << listSize); i++)
    {
        sum = 0;
        list<int>::iterator listIt;

        listIt = listToLookThrough.begin();
        for (int j = 0; j < listSize; j++)
        {
            if ((i & (1 << j)) != 0) {
                sum += *listIt;
            }
            listIt++;
        }
        if (valueToFind != sum) continue;

        listIt = listToLookThrough.begin();
        for (int j = 0; j < listSize; j++)
        {
            if ((i & (1 << j)) != 0) {
                cout << " +" << *listIt;
            }
            listIt++;
        }
        printf(" = %i\n", valueToFind);
    }
}

int main()
{
    printf("K = ");
    int K = InputInteger();
    
    list<int> numbersToSumList {};
    FillList(numbersToSumList);

    ShowList(numbersToSumList);

    IterateCombinations(numbersToSumList, K);

} // Next task: 21.var.
