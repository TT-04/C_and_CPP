#include <cstdlib>
#include <ostream>

template<class T, size_t ch_num = 2>
class NTree
{
    static_assert(ch_num >= 2);

  public:

    class Node
    {
        friend NTree<T, ch_num>;

        Node* parent = nullptr;
        Node* children[ch_num] = {}; 
        size_t myId = 0;
      public:
        T data;

        Node(T value)
        {
            data = value;
        }

        ~Node()
        {
            for (size_t i = 0; i < ch_num; i++)
                delete children[i];

            if (parent != nullptr)
                parent->children[myId] = nullptr;
        }

        Node* getChild(size_t id)
        {
            return children[id];
        }

        Node* getParent()
        {
            return parent;
        }

        size_t getId()
        {
            return myId;
        }

        void addChild(size_t id, T value)
        {
            if (children[id] != nullptr)
                delete children[id];

            Node* newChild = new Node(value);
            newChild->parent = this;
            newChild->myId = id;

            children[id] = newChild;
        }
        
        void out(std::ostream& oS)
        {
            size_t depth = 0;
            auto currNode = this;
            for (; currNode != nullptr; depth++, currNode = currNode->getParent());

            oS << std::string(depth, ' ') << myId << ": " << data << std::endl;

            for (size_t i = 0; i < ch_num; i++)
                if (children[i] != nullptr)
                    children[i]->out(oS);
        }
    };

  private:
    Node* root = new Node(T());


  public:
    NTree()
    {
    }

    ~NTree()
    {
        delete root;
    }

    Node* getRoot()
    {
        return root;
    }
};

template<class T, size_t ch_num>
std::ostream& operator<<(std::ostream& oS, NTree<T, ch_num>& toOut)
{
    if (toOut.getRoot() != nullptr)
        toOut.getRoot()->out(oS);
    return oS;
}