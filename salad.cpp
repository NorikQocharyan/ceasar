#include <iostream>
#include <fstream>
#include <string>

class caeser
{
public:
    void set_in(std::string _in)
    {
        in_s = _in;
    }
    void set_out(std::string _out)
    {
        out_s = _out;
    }
    void set_key(int _key)
    {
        key = _key;
    }
    void cin_key()
    {
        std::cin >> key;
    }
    void encrypt()
    {
        std::string message;
        std::ifstream in(in_s);
        if (in.is_open()) while (getline(in, message));
        in.close();
        char ch;
        int i;
        for (i = 0; i < message.size(); ++i) {
            ch = message[i];
            if (ch >= 'a' && ch <= 'z') {
                ch = ch + key;
                if (ch > 'z') {
                    ch = ch - 'z' + 'a' - 1;
                }
                message[i] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch + key;
                if (ch > 'Z') {
                    ch = ch - 'Z' + 'A' - 1;
                }
                message[i] = ch;
            }
        }
        std::ofstream out; 
        out.open(out_s); 
        if (out.is_open()) out << message << std::endl;
    }
    void decrypt()
    {
        std::string message;
        std::ifstream in(in_s);
        if (in.is_open()) while (getline(in, message));
        in.close();
        char ch;
        int i;
        for (i = 0; i < message.size(); ++i) {
            ch = message[i];
            if (ch >= 'a' && ch <= 'z') {
                ch = ch - key;
                if (ch < 'a') {
                    ch = ch + 'z' - 'a' + 1;
                }
                message[i] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch - key;
                if (ch > 'a') {
                    ch = ch + 'Z' - 'A' + 1;
                }
                message[i] = ch;
            }
        }
        std::ofstream out;  
        out.open(out_s); 
        if (out.is_open()) out << message << std::endl;
    }
protected:
    std::string in_s,out_s;
    int key;
};
int main()
{

    std::string i = "C:\\Users\\mrche\\OneDrive\\Desktop\\in.txt", o = "C:\\Users\\mrche\\OneDrive\\Desktop\\out.txt";
    caeser test;
    test.set_in(i);
    test.set_out(o);
    test.set_key(6);
    test.encrypt();
    
}


