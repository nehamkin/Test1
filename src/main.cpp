
#include "../Include/Session.h"

#include "../Include/Agent.h"



#define JSON_PATH "output.json"

using namespace std;

int main(int argc, char** argv) {
    if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }
    nlohmann::json j;
    Session sess(argv[1]);
    sess.simulate();
    sess.output();
}
