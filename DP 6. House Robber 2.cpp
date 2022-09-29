//https://bit.ly/3F6q83P

long long int houseRobberUtil(vector<int> valueInHouse, int start, int end){

    long long int IthHouse[valueInHouse.size()];
    // Check if the thief may steal the first house or not.
    if (start == 0){
        IthHouse[0] = valueInHouse[0];
        IthHouse[1] = max(valueInHouse[0], valueInHouse[1]);
    }
    else{
        IthHouse[0] = 0;
        IthHouse[1] = valueInHouse[1];
    }
    for (int i = 2; i < end; i++){
        IthHouse[i] = max(IthHouse[i - 2]+valueInHouse[i],IthHouse[i - 1]);
    }
    return IthHouse[end - 1];
}
long long int houseRobber(vector<int>& valueInHouse)
{
    if (valueInHouse.size() == 0)
    {
        return 0;
    }

    if (valueInHouse.size() == 1)
    {
        return valueInHouse[0];
    }

    return max(houseRobberUtil(valueInHouse, 0, valueInHouse.size() - 1), houseRobberUtil(valueInHouse, 1, valueInHouse.size()));
}
