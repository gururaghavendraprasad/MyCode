#include <map>
#include <iostream>
#include <vector>
#include <set>


using namespace std;
int solution(vector<int>& A) {
    multiset<int, greater<int> > mSet;
    int iLargest = 0, iSmallest = 0, iTmp = 0, iOutput = 0;
    for (auto& it : A)
    {
        mSet.insert(it);
    }
    auto itrLarge = mSet.begin();
    auto itrSmall = mSet.rbegin();
    iLargest = *itrLarge;
    iSmallest = *itrSmall;
    iTmp = iLargest;
    cout << "largest is " << iTmp << " smallest is " << iSmallest << "\n";
    while (mSet.find(iTmp) != mSet.end())
    {
        iTmp--;
    }
    if ((iTmp + 1) == iSmallest)
    {
        iOutput = iLargest + 1;
    }
    else
    {
        if (iTmp)
        iOutput = iTmp;
    }
    
    if (iOutput <= 0)
    {
        iOutput = 1;
    }
    
    return iOutput;
}

int main()
{
    vector <int> test1 = { 1,2,3,6,4,1 };
    int output = solution(test1);
    cout << "test1 out : " << output << endl;
    vector <int> test2 = { 1,2,3 };
    output = solution(test2);
    cout << "test2 out : " << output << endl;
    vector <int> test3 = { -1, -3 };
    output = solution(test3);
    cout << "test3 out : " << output << endl;
    return 0;
}
