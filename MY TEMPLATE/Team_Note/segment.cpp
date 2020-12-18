vector<int> tree(200500, 0);
vector<bool> alive(200500, true);
//NEED TO BE MODIFIED

//builder
void segmentTree(int i, int left, int right)
{
    if (left == right)
    {
        tree[i] = 0;
    }
    else
    {
        int mid = (left + right) / 2;
        segmentTree(i*2, left, mid);
        segmentTree(i*2 + 1, mid + 1, right);
        tree[i] = 0;
    }
}

void update(int i, int left, int right, int queryLeft, int queryRight, int winner)
{
    if (queryLeft > queryRight) return;
    if (!alive[i]) return;
    if (left == right)
    {
        if (left == winner) return;
        tree[left] = winner;
        alive[i] = false;
        //cout << left << '\n';
    }
    else
    {
        int mid = (left + right) / 2;
        update(i*2, left, mid, queryLeft, min(queryRight, mid), winner);
        update(i*2 + 1, mid + 1, right, max(queryLeft, mid + 1), queryRight, winner);
        alive[i] = alive[i*2] || alive[i*2 + 1];
    }
}

/* BROKEN GET LOL
int get(int i, int left, int right, int pos)
{
    if (left == right) return tree[i];
    if (pos > right || pos < left) return 0;
    if (left > right) return 0;
    int mid = (left + right) / 2;
    get(i*2, left, mid, pos);
    get(i*2 + 1, mid + 1, right, pos);
}