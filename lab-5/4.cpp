#include <iostream>
#include <queue>
#include <fstream>
#include <map>
#include <vector>
 
using namespace std;
 
int main()
{
 
    ifstream fin("quack.in");
    ofstream fout("quack.out");
 
    string str;
 
    vector<string> Vector;
 
    queue <unsigned short> CurNum; // от 0 до 65536
    map <char,unsigned short> Register; // можем обратиться сразу к ключу
 
    char c;
 
    for(int i = 0, c = 'a'; i < 26 ; i++, c++)
    {
        Register.insert(pair<char,unsigned short> (c,0));
    }
 
    while(!fin.eof())
    {
        fin >> str;
        if(fin.eof())
            break;
        Vector.push_back(str);
    }
 
    for(int i = 0; i < Vector.size(); i++)
    {
        string search = ":";
 
        if (Vector[i][0] == '+')
        {
            unsigned short x = CurNum.front();
            CurNum.pop();
            unsigned short y = CurNum.front();
            CurNum.pop();
            CurNum.push(x + y);
        }
 
        else if (Vector[i][0] == '-')
        {
            unsigned short x = CurNum.front();
            CurNum.pop();
            unsigned short y = CurNum.front();
            CurNum.pop();
            CurNum.push(x - y);
        }
 
        else if (Vector[i][0] == '*')
        {
            unsigned short x = CurNum.front();
            CurNum.pop();
            unsigned short y = CurNum.front();
            CurNum.pop();
            CurNum.push(x * y);
        }
 
        else if (Vector[i][0] == '/')
        {
            unsigned short x = CurNum.front();
            CurNum.pop();
            unsigned short y = CurNum.front();
            CurNum.pop();
 
            if (y == 0)
                CurNum.push(0);
            else
                CurNum.push(x / y);
        }
 
        else if (Vector[i][0] == '%')
        {
            unsigned short x = CurNum.front();
            CurNum.pop();
            unsigned short y = CurNum.front();
            CurNum.pop();
 
            if(y == 0)
                CurNum.push(0);
            else
                CurNum.push(x % y);
        }
 
        else if (Vector[i][0] == '>')
        {
            unsigned short x = CurNum.front();
            Register[Vector[i][1]] = x; // i - row, 1 - first el of row
            CurNum.pop();
        }
 
        else if (Vector[i][0] == '<')
        {
            CurNum.push(Register[Vector[i][1]]);
        }
 
        else if (Vector[i][0] == 'P')
        {
            if (Vector[i].size() == 1)
            {
                unsigned short x = CurNum.front();
                CurNum.pop();
                fout << x << '\n';
            }
            else{
                fout << Register[Vector[i][1]] << '\n';
            }
        }
 
        else if (Vector[i][0] == 'C')
        {
            if (Vector[i].size() == 1)
            {
                unsigned short x = CurNum.front();
                CurNum.pop();
                fout << char(x);
            }
            else{
                unsigned short x = Register[Vector[i][1]];
                fout << char(x);
            }
 
        }
 
        else if (Vector[i][0] == ':')
        {
            continue;
        }
 
        else if (Vector[i][0] == 'J')
        {
            search += Vector[i].substr(1, Vector[i].size() - 1); // дописываю слово после ":"
            for(i = 0; i < Vector.size(); i++)
            {
                if (Vector[i] == search)
                    break;
            }
            continue;
        }
 
        else if (Vector[i][0] == 'Z')
        {
            if (Register[Vector[i][1]] == 0)
            {
                search += Vector[i].substr(2, Vector[i].size() - 1); // дописываю слово после ":". 2, тк со 2 идет label
                for(i = 0; i < Vector.size(); i++)
                {
                    if (Vector[i] == search)
                        break;
                }
                continue;
            }
        }
 
        else if (Vector[i][0] == 'E')
        {
            if (Register[Vector[i][1]] == Register[Vector[i][2]])
            {
                search += Vector[i].substr(3, Vector[i].size() - 1); // дописываю слово после ":". 3, тк со 3 идет label
                for(i = 0; i < Vector.size(); i++)
                {
                    if (Vector[i] == search)
                        break;
                }
                continue;
            }
        }
 
        else if (Vector[i][0] == 'G')
        {
            if (Register[Vector[i][1]] > Register[Vector[i][2]])
            {
                search += Vector[i].substr(3, Vector[i].size() - 1); // дописываю слово после ":". 2, тк со 2 идет label
                for(i = 0; i < Vector.size(); i++)
                {
                    if (Vector[i] == search)
                        break;
                }
                continue;
            }
        }
 
        else if (Vector[i][0] == 'Q')
            return 0;
 
        else
        {
            unsigned short x = atoi(Vector[i].c_str()); // c_str - разобьет посимвольно и переведет в число
            CurNum.push(x);
        }
    }
 
    fin.close();
    fout.close();
 
    return 0;
}
