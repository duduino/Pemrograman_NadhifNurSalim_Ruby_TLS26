#include <cstdio>
#include <iostream>
#include <string>



int main(){
    std::string oldname;
    std::string newname;
    
    std::cout<<"massage: ";
    std::cin>>oldname;
    std::cout<<"real: ";

    for (std::size_t i = 0; i<oldname.size(); i++){
        static char prevbet = 0;
        static char realbet;
        char bet = oldname[i] - 64;
        printf("%d\n", bet + 64);
    }

    std::cout<<std::endl;
    std::cout<<"encrypt: ";

    for (std::size_t i = 0; i<oldname.size(); i++){
        static char prevbet = 0;
        static char realbet;
        char bet = oldname[i] - 64;
        
        realbet = bet + prevbet;

        realbet = (realbet > 26) ? (realbet - 26) : realbet; 
        
        printf("%c\n", realbet + 64);
        prevbet = bet;
    }

    std::cout<<std::endl;
    
    return 0;
}