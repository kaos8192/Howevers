#include "howeves.hpp"

using namespace std;

void iscorsc(string what, bool &a)
{
    int o = 0;
    while(what[o])
    {
        if(what[o] == ',' || what[o] == ';')
        {
            a = true;
            break;
        }
        else
        {
            o++;
        }
    }
}

int main(int argc, char* argv[])
{
    ifstream cur_file;
    string here;
    string there;
    int i = 0;
    int cou = 0;
    bool a = false;
   // cout << argc << endl;
    for(int f = 1; f < argc; f++)
    {
        i = 0;
        cou = 0;
        cur_file.open(argv[f]);
        while(cur_file >> here)
        {
            a = false;
            iscorsc(here, a);
            if(here == "However" && here != "However,") //All starts of however are supposedly not good pratice if not using a comma
            {
                i++;
            }
            else if(a == true && here != "However,")
            {
                if((cur_file >> here) && here == "however")
                {
                    i++;
                }
                else
                {
                }
            }
            else
            {
            }
            if(here == "however" ||here == "However" ||here == "however," ||here == "However,")
            {
                cou++;
            }
        }
        cout << argv[f] << "   :   " << i << "    :   " << cou << endl;
    }
    return 0;
}
