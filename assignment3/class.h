#include <string>
class MyItem {

    public:

        MyItem();
        MyItem(int s, const std::string& n);
        ~MyItem();

        int getData() const;
        void setData(int s);
        void modifyName();

    private:
        int _size ;
        std::string _name;
        void modifyName(std::string& n);
};

