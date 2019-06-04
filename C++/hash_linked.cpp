struct Node
{
    int key;
    char data;
    Node *link;
    public:
        Node() {}
        Node(char data) : key(-1), link(0) { this->data = data; }
        Node(char data, int key) : link(0)
        {
            this->data = data;
            this->key = key;
        }
};

const int HASH_SIZE = 100;
class Hash
{
    Node* hash_table;
    int hashFunction(char) const;

    public:
        Hash() { hash_table = new Node[HASH_SIZE]; } // Make also overflow area
};
int Hash::hashFunction(char data) const
{
    int key = (int)data;
    if (key >= 65 && key <= 90) key += 32;
    return (key - 97);
}

int main()
{
    return 0;
}