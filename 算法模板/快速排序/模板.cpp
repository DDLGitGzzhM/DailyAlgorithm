void quick_sort(int q[], int l, int r)
{
    // 递归的终止情况
    if (l >= r)
        return;

    // 第一步：分成子问题
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    // 第二步 : 递归处理子问题
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}