pair<int, int> getMinMax(vector<int>& arr, int low, int high) {
    if (low == high)
        return { arr[low], arr[low]};

    int mid = (low + high) >> 1;
    pair<int, int> left = getMinMax(arr, low, mid);
    pair<int, int> right = getMinMax(arr, mid + 1, high);

    return { min(left.first, right.first), max(left.second, right.second)};
}

int maxMin(vector<int> arr, int N){
    pair<int, int> minMax = getMinMax(arr, 0, N - 1);

    return minMax.first + minMax.second;
}