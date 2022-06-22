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
    while(iCount != iSize-1)
    {
        iRemFuel += A[iIndex];
        iRemFuel -= B[iIndex];
        iIndex++;
        iCount++;
        if ((iRemFuel < 0) && (iCount != iSize-1))
        {
            iStart = iIndex;
            iRemFuel = 0;
            iCount = 0;
        }
        if ((iIndex == iSize) && (iCount < iSize))
        {
            iIndex = 0;
        }
    }
    if (iRemFuel < 0)
    {
        iStart = -1;
    }
    return iStart;
}
