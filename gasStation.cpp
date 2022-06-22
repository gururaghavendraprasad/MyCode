/*
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    if ((A.size() == 0) || (B.size() == 0))
    {
        return -1;
    }
    int iRemFuel = 0;
    int iStart = 0;
    int iCount = 0;
    int iIndex = 0;
    int iSize = B.size();
    cout << "starting... " << iSize << endl;
    while(iCount != iSize)
    {
        iRemFuel += A[iIndex];
        iRemFuel -= B[iIndex];
        iIndex++;
        iCount++;
        if ((iRemFuel < 0) && (iCount != iSize))
        {
            cout << "updating the iStart and index " << iStart << " " << iCount << " " << iIndex << " " << iRemFuel << endl;
            iStart = iIndex;
            iRemFuel = 0;
            iCount = 0;
        }
        cout << "counting ..." << iStart << " " << iCount << " " << iIndex << " " << iRemFuel << endl;
        if ((iIndex == iSize) && (iCount <= iSize))
        {
            // cout << "updating Index ..." << endl;
            iIndex = 0;
        }
    }
    // cout << "end ..." << iRemFuel << endl;
    if (iRemFuel < 0)
    {
        iStart = -1;
    }
    return iStart;
}
*/

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
     int tank = 0, start = 0, sumGas = 0, sumCost = 0;
    if ((A.size() == 0) || (B.size() == 0))
    {
        return -1;
    }
    for (auto i = 0; i<A.size(); ++i)
    {
        sumGas += A[i];
        sumCost += B[i];
        tank += (A[i] - B[i]);
        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }
    
    if (sumGas < sumCost)
        return -1;
    return start;
}
