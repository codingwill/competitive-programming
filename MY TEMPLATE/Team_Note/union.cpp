int find_set(int v) 
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
vector<int> parent(200500, 0);

//BY SIZE
void make_set(int v) 
{
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) 
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

//BY DEPTH OF THE TREES
void make_set(int v) 
{
    parent[v] = v;
    rank[v] = 0;
}

void union_sets(int a, int b) 
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) 
    {
        if (rank[a] < rank[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        if (rank[a] == rank[b])
        {
            rank[a]++;
        }
    }
}